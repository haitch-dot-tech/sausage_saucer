#include <Arduino.h>

/* TFT Display pins */
#define TFT_BL   PA1 // Active HIGH. Swap PCB jumper to allow for MCU control.
#define TFT_CS   PA2
#define TFT_DC   PA3
#define TFT_RST  PA4
#define TFT_SCLK PA5
#define TFT_MISO PA6
#define TFT_MOSI PA7

/* Touchscreen pins */
#define TS_IRQ  PB11
#define TS_CS   PB12
#define TS_CLK  PB13
#define TS_MISO PB14
#define TS_MOSI PB15

/* Status LED pins */
#define STAT1 PA0
#define STAT2 PB0
#define STAT3 PB1

/* Buzzer */
#define BUZZ PA15

/* Onboard I/O */
#define BTN PC13 // Active HIGH
#define LED PB2  // Does NOT support PWM

/* Pump driver pins */
#define M1_HI PB3
#define M1_LO PB4
#define M2_HI PB5
#define M2_LO PB6
#define M3_HI PB7
#define M3_LO PB8
#define M4_HI PB9
#define M4_LO PB10

/* Button pins */
#define BTN1  PC0
#define BTN2  PC1
#define BTN3  PC2
#define BTN4  PC3

/* Button LED feedback */
#define BLED1 PC6
#define BLED2 PC7
#define BLED3 PC8
#define BLED4 PC9

/* GRBL connection */
#define GRBL Serial1
