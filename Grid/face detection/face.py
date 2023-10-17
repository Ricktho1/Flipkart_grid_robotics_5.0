import cv2
#import cvzone
import serial
import pyfirmata 
from pyfirmata import Arduino, util

arduino=serial.Serial('COM8',9600)    # open serial port that Arduino is using

cap=cv2.VideoCapture(0)
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

#myStepper1 = arduino.get_pin('d:8:o,d:9:o,d:10:o,d:11:o')  # create a stepper motor object for motor 1
#myStepper2 = arduino.get_pin('d:1:o,d:2:o,d:3:o,d:4:o')  # create a stepper motor object for motor 2

while True:
    ret, img = cap.read()
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5)

    for (x, y, w, h) in faces:
        cv2.rectangle(img, (x, y), (x+w, y+h), (0, 255, 0), 2)
        arduino.write(b'H')     # turn the LED on
    cv2.imshow('img', img)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

arduino.write(b'L')     # turn the LED off
cap.release()
cv2.destroyAllWindows()
"""def setup():
    # set the speed at 60 rpm:
    #myStepper1.setSpeed(60)
    myStepper1.setSpeed(120)
    # initialize the serial port:
    arduino.serial = serial.Serial('COM4', 9600)
    arduino.pass_time(2)  # wait for the serial connection to be established

def loop():
    # step one revolution in one direction:
    arduino.serial.write(b'Clockwise\n')
    #myStepper1.step(stepsPerRevolution)
    myStepper1.step(200)
    #delay(1000)
    # step one revolution in the other direction:
    #Serial.println("counterclockwise");
    #myStepper1.step(-stepsPerRevolution);
    #myStepper2.step(-stepsPerRevolution);"""