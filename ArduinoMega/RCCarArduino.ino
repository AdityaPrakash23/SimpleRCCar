#include <AFMotor.h>

//Motor declarations
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

//Motor rotations direction variables
int motor1Dir = 0;
int motor2Dir = 0;
int motor3Dir = 0;
int motor4Dir = 0;

//Encoder interrupt pin declarations
int motor1Interrupt=18;
int motor2Interrupt=19;
int motor3Interrupt=20;
int motor4Interrupt=21;

//Angle storing variables
int angle1=0;
int angle2=0;
int angle3=0;
int angle4=0;

void setup()
{
  Serial.begin(9600);
  Serial2.begin(9600);

  //Setting motor speed
  motor1.setSpeed(80);
  motor2.setSpeed(80);
  motor3.setSpeed(80);
  motor4.setSpeed(80);

  //Setting up interrupt pins for encoder interfacing
  pinMode(motor1Interrupt, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(motor1Interrupt), encoder1, CHANGE);
  pinMode(motor2Interrupt, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(motor2Interrupt), encoder2, CHANGE);
  pinMode(motor3Interrupt, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(motor3Interrupt), encoder3, CHANGE);
  pinMode(motor4Interrupt, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(motor4Interrupt), encoder4, CHANGE);
}

void loop()
{
  //If command is being received on Serial2 bus
  if (Serial2.available() > 0) 
  {
    //Read and print data on Serial0 bus
    String dat = Serial2.readStringUntil('\n');
    Serial.print(dat);
    Serial.print("\t");
    Serial.print(angle1); 
    Serial.print("\t");
    Serial.print(angle2);
    Serial.print("\t");
    Serial.print(angle3);
    Serial.print("\t");
    Serial.println(angle4);

    //If Forward command
    if(dat == "F-1")
    {
      motor1Dir = 1;
      motor2Dir = 1;
      motor3Dir = 1;
      motor4Dir = 1;
      
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
      delay(500);

      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
      dat = " ";
    }
    
    else if(dat == "F-0")
    {
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
      dat = " ";
    }

    //If backward command
    else if(dat == "B-1")
    {
      motor1Dir = 2;
      motor2Dir = 2;
      motor3Dir = 2;
      motor4Dir = 2;
      
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      motor3.run(BACKWARD);
      motor4.run(BACKWARD);
      delay(500);

      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
      dat = " ";
    }
    
    else if(dat == "B-0")
    {
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
      dat = " ";
    }

    //If left turn command
    else if(dat == "L-1")
    {
      motor1Dir = 1;
      motor2Dir = 1;
      motor3Dir = 2;
      motor4Dir = 2;
       
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor3.run(BACKWARD);
      motor4.run(BACKWARD);
      delay(500);

      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
      dat = " ";
    }
    
    else if(dat == "L-0")
    {
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
      dat = " ";
    }

    //If right turn command
    else if(dat == "R-1")
    {
      motor1Dir = 2;
      motor2Dir = 2;
      motor3Dir = 1;
      motor4Dir = 1;
      
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
      delay(500);

      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
      dat = " ";
    }
    
    else if(dat == "R-0")
    {
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
      dat = " ";
    }

    //If horizonatal left command
    else if(dat == "LL-1")
    {
      motor1Dir = 2;
      motor2Dir = 1;
      motor3Dir = 2;
      motor4Dir = 1;
      
      motor1.run(BACKWARD);
      motor2.run(FORWARD);
      motor3.run(BACKWARD);
      motor4.run(FORWARD);
      delay(500);

      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
      dat = " ";
    }
    
    else if(dat == "LL-0")
    {
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
      dat = " ";
    }

    //If horizontal right command
    else if(dat == "LR-1")
    {
      motor1Dir = 1;
      motor2Dir = 2;
      motor3Dir = 1;
      motor4Dir = 2;
      
      motor1.run(FORWARD);
      motor2.run(BACKWARD);
      motor3.run(FORWARD);
      motor4.run(BACKWARD);
      delay(500);

      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
      dat = " ";
    }
    
    else if(dat == "LR-0")
    {
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
      dat = " ";
    }

    //If motors needs to stop
    else if(dat == "Stop")
    {
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
      dat = " ";
    }
  }
}

//Encoder counter functions
void encoder1()
{
  if(motor1Dir == 1){angle1 = angle1+10;}
  else if(motor1Dir == 2){angle1 = angle1-10;}
}

void encoder2()
{
  if(motor2Dir == 1){angle2 = angle2+10;}
  else if(motor2Dir == 2){angle2 = angle2-10;}
}

void encoder3()
{
  if(motor3Dir == 1){angle3 = angle3+10;}
  else if(motor3Dir == 2){angle3 = angle3-10;}
}

void encoder4()
{
  if(motor4Dir == 1){angle4 = angle4+10;}
  else if(motor4Dir == 2){angle4 = angle4-10;}
}
