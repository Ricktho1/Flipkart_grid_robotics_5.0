#include <Stepper.h>

const int stepsPerRevolution = 100;
Stepper myStepper1(stepsPerRevolution, 2, 3, 4, 5);
Stepper myStepper2(stepsPerRevolution, 8, 9, 10, 11);

unsigned long startTime = 0;
const unsigned long rotationDuration = 1000;

char currentKey;

void setup() {
  myStepper1.setSpeed(300);
  myStepper2.setSpeed(300);
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

  // Check if the current key is pressed
  if (Serial.available()) {
    currentKey = Serial.read();
  }

  // Depending on the current key, call the appropriate move function
  switch (currentKey) {
    case 'w':
      moveUp();
      break;
    case 's':
      moveDown();
      break;
    case 'd':
      moveRight();
      break;
    case 'a':
      moveLeft();
      break;
  }

  // Add a delay to prevent the stepper motors from moving too quickly
}
