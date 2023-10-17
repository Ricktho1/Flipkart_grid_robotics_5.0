#include <Stepper.h>

const int stepsPerRevolution = 100;
Stepper myStepper1(stepsPerRevolution, 2, 3, 4, 5);
Stepper myStepper2(stepsPerRevolution, 8, 9, 10, 11);

unsigned long startTime = 0;
const unsigned long rotationDuration = 1000;

void setup() {
  myStepper1.setSpeed(400);
  myStepper2.setSpeed(400);
  Serial.begin(9600);
}

void moveLeft() {
  myStepper1.step(-1);
  myStepper2.step(1);
}

void moveRight() {
  myStepper1.step(1);
  myStepper2.step(-1);
}

void moveUp() {
  myStepper1.step(1);
  myStepper2.step(1);
}

void moveDown() {
  myStepper1.step(-1);
  myStepper2.step(-1);
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - startTime < rotationDuration) {
    // Move left for 1 second
    moveLeft();
  }
  else if (currentTime - startTime < 2 * rotationDuration) {
    // Move up for 1 second
    moveUp();
  }
  else if (currentTime - startTime < 3 * rotationDuration) {
    // Move right for 1 second
    moveRight();
  }
  else if (currentTime - startTime < 4 * rotationDuration) {
    // Move down for 1 second
    moveDown();
  }
  // Reset the start time after 4 seconds to repeat the pattern
  else if (currentTime - startTime >= 4 * rotationDuration) {
    startTime = currentTime;
  }
}
