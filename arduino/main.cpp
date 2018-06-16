#include <Arduino.h>
#include "Stepper.hpp"

using namespace stepper1;

constexpr float speed = 1000.0f;

Stepper leftStepper;
Stepper rightStepper;
int i;

void forwards(Stepper *right, Stepper *left) {
  right->setSpeed(-speed);
  left->setSpeed(speed);
}
void backwards(Stepper *right, Stepper *left) {
  right->setSpeed(speed);
  left->setSpeed(-speed);
}
void right(Stepper *right, Stepper *left) {
  right->setSpeed(0);
  left->setSpeed(speed);
}
void left(Stepper *right, Stepper *left) {
  right->setSpeed(-speed);
  left->setSpeed(0);
}
void stop(Stepper *right, Stepper *left) {
  right->setSpeed(0);
  left->setSpeed(0);
}

void checkSerialInput() {
int incomingByte = Serial.read();
  if (incomingByte != -1) {
    Serial.println(incomingByte);
    if (incomingByte == 0) {
      stop(&rightStepper, &leftStepper);
    } else if (incomingByte == 1) {
      forwards(&rightStepper, &leftStepper);
    } else if (incomingByte == 2) {
      left(&rightStepper, &leftStepper);
    } else if (incomingByte == 3) {
      right(&rightStepper, &leftStepper);
    } else if (incomingByte == 4) {
      backwards(&rightStepper, &leftStepper);
    }
  }
}

void setup() {
  Serial.begin(9600);
  Serial.print("setup");

  i = 0;

  leftStepper.setup(10, 11, 12, 13);
  rightStepper.setup(4, 5, 6, 7);

  stop(&rightStepper, &leftStepper);
}

void loop() {

  leftStepper.move();
  rightStepper.move();

  if (Serial.available() > 0) {
    checkSerialInput();
  }
}