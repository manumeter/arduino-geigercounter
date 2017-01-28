#!/usr/bin/python

import serial
import time

ser = serial.Serial('/dev/ttyACM0', 9600)

ser.write(1);
ser.readline();

# realize as cronjob!

while 1:
  time.sleep(60);
  ser.write(1);
  val = ser.readline().rstrip()
  with open('/var/www/geiger/stats.log', 'a') as log:
  log.write('\n' + time.strftime('%Y-%m-%d %H:%M:%S') + ' ' + val)
