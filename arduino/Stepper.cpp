#include <AccelStepper.h>
#include "Stepper.hpp"

using namespace stepper1;

static constexpr int HALFSTEP = 8;

static void setupStepper(AccelStepper *stepper) {
   stepper->setMaxSpeed(1000.0);
   stepper->setAcceleration(100.0);
   stepper->setSpeed(100);
}

void Stepper::move() {
    this->_accelStepper.runSpeed();
    // this->accelStepper->run();
}

void Stepper::setSpeed(float speed) {
  if (speed > 1000) {
    speed = 1000;
  }
  if (speed < -1000) {
    speed = -1000;
  }
  this->_accelStepper.setSpeed(speed);
}

void Stepper::setup(int pin1, int pin2, int pin3, int pin4) {
  this->_accelStepper = AccelStepper(HALFSTEP, pin1, pin3, pin2, pin4);
  setupStepper(&(this->_accelStepper));
}

// Stepper::~Stepper() {
//   delete this->accelStepper;
// }
