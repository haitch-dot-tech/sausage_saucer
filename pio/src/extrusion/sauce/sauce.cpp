#include "sauce.hpp"

int _rt = 0;
int _tube = 0;

sauces pumps;

void sauce_init(int pins[], int retract, int tubeID)
{
    _rt = retract;
    _tube = sq((tubeID / 2)) * PI;

    pumps.tomato.init(pins[1], pins[2]);
    pumps.barbeque.init(pins[3], pins[4]);
    pumps.mustard.init(pins[5], pins[6]);
}

void sauce_dispense(flavour sauce, int amount)
{
    switch (sauce)
    {
        case (tomato): pumps.tomato.setMotor(255, FORWARD); break;
        case (barbeque): pumps.barbeque.setMotor(255, FORWARD); break;
        case (mustard): pumps.mustard.setMotor(255, FORWARD); break;
        default: break;
    }
}

void halt()
{
    pumps.tomato.setMotor(0, FORWARD);
    pumps.barbeque.setMotor(0, FORWARD);
    pumps.mustard.setMotor(0, FORWARD);
}
