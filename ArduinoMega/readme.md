Arduino Code
----------------------
This just contains the Arduino Code where the Mega receives the commands over serial from the Raspberry Pi Zero and uses the AFMotor library to run the 
4 BO motors of the robot car correctly. The code is pretty straight forward. This also has commands for Mecanum wheeled movement but I haven't tested it
due to unavailabilty of proper wheels. Also Opto Encoder for BO Motors are also being utilized here to keep track of the motor rotation angle. They aren't
being used in any major way.

<b>Resources</b>  
1.https://create.arduino.cc/projecthub/electropeak/arduino-l293d-motor-driver-shield-tutorial-c1ac9b  
2.https://create.arduino.cc/projecthub/electropeak/the-beginner-s-guide-to-control-motors-by-arduino-and-l293d-139307?ref=similar&ref_id=154505&offset=3  
3.https://create.arduino.cc/projecthub/electropeak/the-beginner-s-guide-to-control-motors-by-arduino-and-l293d-139307?ref=similar&ref_id=154505&offset=3
