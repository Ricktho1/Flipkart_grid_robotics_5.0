#include <Stepper.h>

int in3 = 7;
int enA = 6;
int in1 = 12;
int in2 = 13;

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

  pinMode(enA, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	
	// Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);


}

//void vaccumon(){
 // digitalwrite(in3, HIGH)
//}

//void vaccumoff(){
//  digitalwrite(in3, LOW)
//}

void directionControl1() {
	// Set motors to maximum speed
	// For PWM maximum possible values are 0 to 255
	analogWrite(enA, 255);
  int degrees=map(160,0,180,0,255);
	// Turn on motor A & B
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	delay(degrees);
	
	// Now change motor directions
	//digitalWrite(in1, LOW);
	//digitalWrite(in2, HIGH);
	//delay(1000);
	
	// Turn off motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
  
}

void directionControl2() {
	// Set motors to maximum speed
	// For PWM maximum possible values are 0 to 255
	analogWrite(enA, 255);
  int degrees=map(160,0,180,0,255);
	// Turn on motor A & B
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	delay(degrees);
	
	// Now change motor directions
	//digitalWrite(in1, LOW);
	//digitalWrite(in2, HIGH);
	//delay(1000);
	
	// Turn off motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
  
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
    
    case 'k':
      directionControl2();
      break;

    case 'u':
      directionControl1();
      break;      
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
