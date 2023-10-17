#from cvzone.SerialModule import SerialObject
from time import sleep
import serial
import cv2

print ("Start")

arduino=serial.Serial('COM8',9600)    # open serial port that Arduino is using
print (arduino.name)           # check which port was really used

ILOn= cv2.imread('led-on.png')
ILOff= cv2.imread('led_off_icon_138425.png')

while True:
    arduino.write(b'H')     # turn the LED on
    sleep(3)            # wait for 1 second
    arduino.write(b'L')     # turn the LED off
    sleep(3)