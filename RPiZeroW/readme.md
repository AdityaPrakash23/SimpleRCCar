Raspberry Pi Zero W code
------------------------------
This contains the only python file that needs to run on a Raspberry Pi Zero W running Raspberry Pi OS.

<b>Necessary Libraries and installation command</b>
1. Pyserial : sudo pip3 install pyserial
2. Evdev : sudo pip3 install evdev

The above are the only necessary libraries.

<b>The setup</b>  
The gamepad being used is a Redgear Elite Pro. After connecting the wireless dongle of the gamepad to the Pi and switching everything on, just run the code 
and command sending to the Arduino should begin. The different commands are  

1.Forward  
2.Backward  
3.Turn Left  
4.Turn Right  
5.Holonomic Left  
6.Holonomic Right   

Please go through the code to understand in detail how the command generation is happening. In short, the code is supposed to generate movement commands only when
L1 button is pressed down and a movement command button is pressed. If the L1 button is released by mistake, the robot will stop it's ongoing movement. Also there are 
holonomic left and right commands since I used mecanum wheels to challenge myself. Please make changes to the code as you see fit.

To understand the gamepad interfacing in linux, Evdev library and the rest of the working this is a good website to check out https://ericgoebelbecker.com/post/raspberry-pi-and-gamepad-programming-part-1-reading-the-device/.
