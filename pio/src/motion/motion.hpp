#include <Arduino.h>

#include <conf.h>

void motion_init(void);
void motion_home(void);
void motion_moveLinear(float x, float y, int feed);
