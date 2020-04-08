import serial
import time


ard= serial.Serial("COM3",9600)
time.sleep(3)
while(True):
    n = int(input())
    if(n==5):
        break
    ard.write([n])
