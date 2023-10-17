#include <Stepper.h>

const int stepsPerRevolution = 100;
Stepper myStepper1(stepsPerRevolution, 2, 3, 4, 5);
Stepper myStepper2(stepsPerRevolution, 8, 9, 10, 11);

unsigned long startTime = 0;
bool clockwise = true; // Variable to track the direction

void setup() {
   myStepper1.setSpeed(400);
   myStepper2.setSpeed(400);
   Serial.begin(9600);
}

void loop() {
   // Get the current time
   unsigned long currentTime = millis();
  
   // Set a variable to hold the duration of rotation (in milliseconds)
   const unsigned long rotationDuration = 1000; // 10 seconds

   // Rotate the motor in the specified direction
   if (clockwise) {
     myStepper1.step(1);
     myStepper2.step(1);
   } else {
     myStepper1.step(-1);
     myStepper2.step(-1); // Move in the opposite direction
   }

   // Check if the rotation duration has passed
   if (currentTime - startTime >= rotationDuration) {
     // Change the direction after 10 seconds
     //clockwise = !clockwise;
     myStepper1.step(0);
     myStepper2.step(0);
     // Reset the start time for the next rotation
     startTime = currentTime;
   }

   // Do other tasks here if needed
}
