#ifndef stepper1_header
#define stepper1_header

#include <AccelStepper.h>

namespace stepper1 {
  struct Stepper {
    // public:
      // Stepper::Stepper(int pin1, int pin2, int pin3, int pin4);
      // Stepper::Stepper();
      // Stepper::~Stepper();
      void move();
      void setSpeed(float speed);
      void setup(int pin1, int pin2, int pin3, int pin4);
      AccelStepper _accelStepper;
  };
}

#endif 