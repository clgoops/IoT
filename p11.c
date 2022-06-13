Raspberry pi
import RPi_GPO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setup(13,GPIO.OUT)l
let = int(input(‘Press a key’)
If(let==1):
GPIO.output(13,GPIO.high)
time.sleep(1)
while(true):
let1 = int(input())
if let1 == 0:
GPIO.output(13,GPIO.LOW)
break
GPIO.cleanup()