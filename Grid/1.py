from pyfirmata import Arduino, util
import time
import serial

board = Arduino('COM8')  # open serial port that Arduino is using
myStepper1 = board.get_pin('d:2:o,d:3:o,d:4:o,d:5:o')  # create a stepper motor object
myStepper2 = board.get_pin('d:8:o,d:9:o,d:10:o,d:11:o')  # create a stepper motor object
stepsPerRevolution = 100

ser = serial.Serial('COM3', 9600)  # open serial port for communication

def moveLeft():
    myStepper1.write(0)
    myStepper2.write(1)

def moveRight():
    myStepper1.write(1)
    myStepper2.write(0)

def moveUp():
    myStepper1.write(1)
    myStepper2.write(1)

def moveDown():
    myStepper1.write(0)
    myStepper2.write(0)

def loop():
    global currentKey
    currentTime = int(round(time.time() * 1000))

    # Check if the current key is pressed
    if ser.in_waiting > 0:
        currentKey = ser.read().decode()

    # Depending on the current key, call the appropriate move function
    if currentKey == 'w':
        moveUp()
    elif currentKey == 's':
        moveDown()
    elif currentKey == 'd':
        moveRight()
    elif currentKey == 'a':
        moveLeft()

    # Add a delay to prevent the stepper motors from moving too quickly
    time.sleep(0.01)

try:
    while True:
        loop()

finally:
    board.exit()
    ser.close()