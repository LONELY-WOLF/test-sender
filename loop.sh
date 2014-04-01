#!/bin/sh
stty -F /dev/ttyUSB0 57600
while true
do
	./test-sender 0 0 150
	sleep 0.03s
done
