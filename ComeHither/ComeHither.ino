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
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  
}




void loop() {

  
  if (Serial.available()) // if serial value is available 
  {
    val = Serial.read();// then read the serial value
    if (val == 'd') //if value input is equals to d
    {
      for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
         // in steps of 1 degree
         myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
       }
     }
    if (val == 'a') //if value input is equals to a
    {
        for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(40);                       // waits 15ms for the servo to reach the position
        }
    }
  }
}//Endd of Loop

void openHand()
{
  
}
