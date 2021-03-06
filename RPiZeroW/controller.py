from evdev import InputDevice, categorize, ecodes, KeyEvent
import serial
import time
import sys

if __name__ == '__main__':

	print("Starting the program...")

	ser = serial.Serial('/dev/ttyS0', 9600, timeout=1)						#Opening a serial communication channel to Arduino
	ser.flush()

	gamepad = InputDevice('/dev/input/event0')						#Opening connection to Redgear gamepad
	enable = False

	for event in gamepad.read_loop():								#Starting signal reading loop
		if event.type == ecodes.EV_KEY:								#Checking for Button press events
			keyevent = categorize(event)							#Storing a button press in variable 'Keyevent'
			if keyevent.scancode == 310:							#Checking for L1 button press
				if keyevent.keystate == KeyEvent.key_down:
					enable = True									#If pressed, enable movement
					print('Movement enabled!')
				elif keyevent.keystate == KeyEvent.key_up:
					enable = False									#If unpressed, disable movement
					ser.write("Stop\n".encode('utf-8'))
					print('Movement disabled!')
			
			elif enable == True:									#If Movement is enabled, check for direction commands
				
				if keyevent.scancode == 308:						#Checking for front command
					if keyevent.keystate == KeyEvent.key_down:
						ser.write("F-1\n".encode('utf-8'))							#Sending msg to Arduino
						print('F-1\n')								#Move front
					elif keyevent.keystate == KeyEvent.key_up:
						ser.write("F-0\n".encode('utf-8'))							#Sending msg to Arduino
						print('F-0\n')								#Stop front
				
				elif keyevent.scancode == 304:						#Check for back command				
					if keyevent.keystate == KeyEvent.key_down:
						ser.write("B-1\n".encode('utf-8'))							#Sending msg to Arduino
						print('B-1\n')								#Move back
					elif keyevent.keystate == KeyEvent.key_up:
						ser.write("B-0\n".encode('utf-8'))							#Sending msg to Arduino
						print('B-0\n')								#Stop back

				elif keyevent.scancode == 307:						#Check for turn left command
					if keyevent.keystate == KeyEvent.key_down:
						ser.write("L-1\n".encode('utf-8'))							#Sending msg to Arduino
						print('L-1\n')								#Turn left
					elif keyevent.keystate == KeyEvent.key_up:
						ser.write("L-0\n".encode('utf-8'))							#Sending msg to Arduino
						print('L-0\n')								#Stop left turn

				elif keyevent.scancode == 305:						#Check for turn right command
					if keyevent.keystate == KeyEvent.key_down:
						ser.write("R-1\n".encode('utf-8'))							#Sending msg to Arduino
						print('R-1\n')								#Turn right
					elif keyevent.keystate == KeyEvent.key_up:
						ser.write("R-0\n".encode('utf-8'))							#Sending msg to Arduino
						print('R-0\n')								#Stop right turn
				
				elif keyevent.scancode == 317:						#Check for linear left command
					if keyevent.keystate == KeyEvent.key_down:
						ser.write("LL-1\n".encode('utf-8'))							#Sending msg to Arduino
						print('LL-1\n')								#Linear Left
					elif keyevent.keystate == KeyEvent.key_up:
						ser.write("LL-0\n".encode('utf-8'))							#Sending msg to Arduino
						print('LL-0\n')								#Stop linear left
				
				elif keyevent.scancode == 318:						#Check for linear right command
					if keyevent.keystate == KeyEvent.key_down:
						ser.write("LR-1\n".encode('utf-8'))							#Sending msg to Arduino
						print('LR-1\n')								#Linear right
					elif keyevent.keystate == KeyEvent.key_up:
						ser.write("LR-0\n".encode('utf-8'))							#Sending msg to Arduino
						print('LR-0\n')								#Stop linear right

				#Code left for R1 button's future use
				#elif keyevent.scancode == 311:						
				
			elif keyevent.scancode == 314:
				if keyevent.keystate == KeyEvent.key_down:
					print('Exiting.....')
					sys.exit(0)
