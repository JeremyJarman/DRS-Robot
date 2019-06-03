/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int val; // initial value of in


void setup() {
  Serial.begin(9600); // Serial comm begin at 9600bps
    // attaches the servo on pin 9 to the servo object
  myservo.attach(9);
  
}




void loop() {

 
  if (Serial.available()) // if serial value is available 
  {
    
    val = Serial.parseInt();// then read the serial value

  

  if (val == 1) //if value input is equals to a
      {
       myservo.detach();
      }

   else {
       
       myservo.write(val);
    }
       
  }//End of Serial Read
}//Endd of Loop

void openHand()
{
  
}
