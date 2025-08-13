#include "touch.hpp"

uint8_t csPin, rot;
int16_t xraw = 0, yraw = 0, zraw = 0;
uint32_t msraw = 0x80000000;

SPIClass TouchSPI(TS_MOSI, TS_MISO, TS_CLK);

static int16_t besttwoavg(int16_t x, int16_t y, int16_t z) {
  int16_t da, db, dc;
  int16_t reta = 0;
  if ( x > y ) da = x - y; else da = y - x;
  if ( x > z ) db = x - z; else db = z - x;
  if ( z > y ) dc = z - y; else dc = y - z;

  if ( da <= db && da <= dc ) reta = (x + y) >> 1;
  else if ( db <= da && db <= dc ) reta = (x + z) >> 1;
  else reta = (y + z) >> 1;   //    else if ( dc <= da && dc <= db ) reta = (x + y) >> 1;

  return (reta);
}

void update()
{
	int16_t data[6];
	uint32_t now = millis();

	if (now - msraw < 3 /* threshold*/ ) return;
	
	TouchSPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE0));
	digitalWrite(csPin, LOW);
	TouchSPI.transfer(0xB1 /* Z1 */);
	int16_t z1 = TouchSPI.transfer16(0xC1 /* Z2 */) >> 3;
	int z = z1 + 4095;
	int16_t z2 = TouchSPI.transfer16(0x91 /* X */) >> 3;
	z -= z2;
	if (z >= 400 /* threshold */) {
		TouchSPI.transfer16(0x91 /* X */);  // dummy X measure, 1st is always noisy
		data[0] = TouchSPI.transfer16(0xD1 /* Y */) >> 3;
		data[1] = TouchSPI.transfer16(0x91 /* X */) >> 3; // make 3 x-y measurements
		data[2] = TouchSPI.transfer16(0xD1 /* Y */) >> 3;
		data[3] = TouchSPI.transfer16(0x91 /* X */) >> 3;
	}
	else data[0] = data[1] = data[2] = data[3] = 0;	// Compiler warns these values may be used unset on early exit.
	data[4] = TouchSPI.transfer16(0xD0 /* Y */) >> 3;	// Last Y touch power down
	data[5] = TouchSPI.transfer16(0) >> 3;
	digitalWrite(csPin, HIGH);
	TouchSPI.endTransaction();
	if (z < 0) z = 0;
	if (z < 400 /* threshold */) {
		zraw = 0;
		return;
	}
	zraw = z;
	
	int16_t x = besttwoavg( data[0], data[2], data[4] );
	int16_t y = besttwoavg( data[1], data[3], data[5] );
	
	if (z >= 400 /* threshold */) {
		msraw = now;
		switch (rot) {
		  case 0:
			xraw = 4095 - y;
			yraw = x;
			break;
		  case 1:
			xraw = x;
			yraw = y;
			break;
		  case 2:
			xraw = y;
			yraw = 4095 - x;
			break;
		  default: // 3
			xraw = 4095 - x;
			yraw = 4095 - y;
		}
	}
}

void touch_begin(uint8_t cs, uint8_t rotation)
{
    csPin = cs;
    rot = rotation % 4;
	TouchSPI.begin();
	pinMode(csPin, OUTPUT);
	digitalWrite(csPin, HIGH);
}

void touch_point(int16_t *x, int16_t *y, uint8_t *z)
{
	update();
	*x = xraw;
	*y = yraw;
	*z = zraw;
}
