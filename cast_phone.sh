#!/bin/bash

echo "connect phone to via usb to laptop"
echo "enable usb debugging mode"
echo "enable transfer via files mode"
echo "connect laptop and phone to same wifi"
echo "get iPv4 address of phone from Setting->About Phone-> Status"

echo "enter iPv4 address of phone:"
read ip

adb usb
echo "ok"
adb tcpip 5555
echo "ok"
adb connect "$ip":5555
echo "disconnect usb now"
echo "done? [y/n]"
read check
if ["$check" == y ]; then
	scrcpy
else 
	echo "cancelling ... "
fi
