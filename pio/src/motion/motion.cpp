#include "motion.hpp"

void motion_init(void)
{
    // GRBL.begin(115200);
    // GRBL.printf("G21 G90\n");
}

void motion_home(void)
{
    // GRBL.printf("$H\n");
}

void motion_moveLinear(float x, float y, int feed)
{
    // GRBL.printf("G1 X%f Y%f F%d\n", x, y, feed);
}
