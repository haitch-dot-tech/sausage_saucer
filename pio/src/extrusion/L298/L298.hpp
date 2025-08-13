#include <Arduino.h>

enum direction
{
    FORWARD,
    REVERSE
};

class L298 
{
    public:
        /**
         * @brief L298 Library Class
         */
        L298();

        /**
         * @brief Sets up motor driver pins.
         * @param in1 Motor driver IN1 connection
         * @param in2 Motor driver IN2 connection
         */
        void init(uint8_t high, uint8_t low);

        /**
         * @brief Changes the state of the motor
         * @param motor the motor your using (motor1 or motor2)
         * @param speed the speed you want to set the specified motor to (0-255)
         * @param direction the direction of the specified motor
         */
        void setMotor(uint8_t speed, direction direction);
    private:
        uint8_t hi, lo;
};
