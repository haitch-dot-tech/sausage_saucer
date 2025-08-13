#include "pumps.hpp"

#define TOMATO_HI   M1_HI
#define TOMATO_LO   M1_LO
#define BARBEQUE_HI M2_HI
#define BARBEQUE_LO M2_LO
#define MUSTARD_HI  M3_HI
#define MUSTARD_LO  M3_LO

void pumps_init()
{
    pinMode(TOMATO_HI,   OUTPUT);
    pinMode(TOMATO_LO,   OUTPUT);
    pinMode(BARBEQUE_HI, OUTPUT);
    pinMode(BARBEQUE_LO, OUTPUT);
    pinMode(MUSTARD_HI,  OUTPUT);
    pinMode(MUSTARD_LO,  OUTPUT);

    digitalWrite(TOMATO_HI,   LOW);
    digitalWrite(TOMATO_LO,   LOW);
    digitalWrite(BARBEQUE_HI, LOW);
    digitalWrite(BARBEQUE_LO, LOW);
    digitalWrite(MUSTARD_HI,  LOW);
    digitalWrite(MUSTARD_LO,  LOW);
}

void pump(pumps sauce, bool en)
{
    int hi, lo;

    switch (sauce)
    {
        case TOMATO:
            hi = TOMATO_HI;
            lo = TOMATO_LO;
            break;
        case BARBEQUE:
            hi = BARBEQUE_HI;
            lo = BARBEQUE_LO;
            break;
        case MUSTARD:
            hi = MUSTARD_HI;
            lo = MUSTARD_LO;
            break;
        default:
            hi = M4_HI;
            lo = M4_LO;
            break;
    }
    
    if (en)
    {
        digitalWrite(hi, HIGH);
        digitalWrite(lo, LOW);
    }
    else
    {
        digitalWrite(hi, LOW);
        digitalWrite(lo, LOW);
    }
}
