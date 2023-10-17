from pyfirmata import Arduino, util
import time
from time import sleep
import serial
import cv2

from pyfirmata import Arduino, util, Stepper
import time
import serial
from pyfirmata import Arduino, util
import time
import serial
from pyfirmata.util import Iterator
from AccelStepper import AccelStepper, Adafruit_MotorShield, Adafruit_StepperMotor


def setup():
    myStepper2.setMaxSpeed(250)
    board.serial = serial.Serial('COM4', 9600)
    board.pass_time(2)  # wait for the serial connection to be established
    iterator = Iterator(board)
    iterator.start()


def loop():
    # Get the current time
    currentTime = int(round(time.time() * 1000))

    # Set a variable to hold the duration of rotation (in milliseconds)
    rotationDuration = 2000  # 10 seconds

    # Rotate the motor in the specified direction
    if clockwise:
        myStepper2.runSpeed()
    else:
        myStepper2.runSpeed(-myStepper2.maxSpeed())

    # Check if the rotation duration has passed
    if currentTime - startTime >= rotationDuration:
        # Change the direction after 10 seconds
        clockwise = not clockwise
        # Reset the start time for the next rotation
        startTime = currentTime
board = Arduino('COM4')  # open serial port that Arduino is using

myStepper2 = board.get_pin('d:8:o,d:9:o,d:10:o,d:11:o')  # create a stepper motor object for motor 2
stepsPerRevolution = 200
myStepper2 = Stepper(stepsPerRevolution, 8, 9, 10, 11)
startTime = 0
clockwise = True  # Variable to track the direction

def setup():
    myStepper2.setSpeed(250)
    board.serial = serial.Serial('COM4', 9600)
    board.pass_time(2)  # wait for the serial connection to be established

def loop():
    # Get the current time
    currentTime = int(round(time.time() * 1000))

    # Set a variable to hold the duration of rotation (in milliseconds)
    rotationDuration = 2000  # 10 seconds

    # Rotate the motor in the specified direction
    if clockwise:
        myStepper2.step(1)
    else:
        myStepper2.step(-1)  # Move in the opposite direction

    # Check if the rotation duration has passed
    if currentTime - startTime >= rotationDuration:
        # Change the direction after 10 seconds
        clockwise = not clockwise
        # Reset the start time for the next rotation
        startTime = currentTime