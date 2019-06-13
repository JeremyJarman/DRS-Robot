/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#include <Stream.h>


// RIGHT HAND TEST AND SERVO DEFINITION

Servo p3; //Little
Servo p5; // Ring
Servo p6; // Middle
Servo p9; // Index
Servo p10; //Digital pin used by Thumb servo
Servo p11; // Bicep

void setup() {
  Serial.begin(9600); // Serial comm begin at 9600bps
    // attaches the servo on pin 9 to the servo object
  p3.attach(3);
  p5.attach(5);
  p6.attach(6);
  p9.attach(9);
  p10.attach(10);
  p11.attach(11);

  p3.write(0);
  p5.write(0);
  p6.write(0);
  p9.write(0);
  p10.write(0);
 // p11.write(90);
 // GetServo();
}

char ServoPick = ' ';
char Pos = ' ';


void loop() {

//GetInput();

  
}//End of Loop

//void GetServo()
//{
//   Serial.println ("Pick a Servo");
//    if(Serial.read()>0)
//    {
//      ServoPick = Serial.read();
//      Serial.println ("You chose" + ServoPick);
//      GetPos();
//    }
//
//}
//void GetPos()
//{
//    Serial.println ("Set Value");
//    if(Serial.read()>0)
//    {
//      Pos = Serial.read();
//      Serial.println ("Going to" + Pos);
//      updatepos(ServoPick, Pos);
//    }
//
//}
//
//
//   
//void updatepos (char servo , char pos) {
//
//  
//  if (servo == 'a') //if value input is equals to a
//      {
//       p3.write(pos);
//      }
//
//  else if (servo == 'b') //if value input is equals to a
//      {
//       p5.write(pos);
//      }
//
//  else if (servo == 'c') //if value input is equals to a
//      {
//       p6.write(pos);
//      }
//  
//  else if (servo == 'd') //if value input is equals to a
//      {
//       p9.write(pos);
//      }  
//  
//  else if (servo == 'e') //if value input is equals to a
//      {
//       p10.write(pos);
//      }  
//      
//    GetServo();
//}
