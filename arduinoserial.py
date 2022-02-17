import serial
import time
arduino = serial.Serial('COM4', 9600, timeout=0)
while True:
    readval = arduino.readline().decode("utf-8").split(":")
    if(readval[0]=="data"):
        print(len(readval))
        # values[int(readval[0])] = readval[1]
        time.sleep(0.01)