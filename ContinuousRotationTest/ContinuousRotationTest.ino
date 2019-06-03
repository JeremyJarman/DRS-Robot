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

  
}




void loop() {


  
  if (Serial.available()) // if serial value is available 
  {
    val = Serial.read();// then read the serial value
    if (val == 'd') //if value input is equals to d
      {
       myservo.attach(9);
      for (int i=180;i>=0;i--)
        {      
         Serial.println(i);
         myservo.write(i);
         delay(500);
        }
      }

    if (val == 's') //if value input is equals to d
      {
       myservo.attach(9);
       myservo.write(0);
      }

      if (val == 't') //if value input is equals to d
      {
       myservo.attach(9);
       myservo.write(180);
      }
    
    if (val == 'g') //if value input is equals to d
      {
       myservo.attach(9);
       myservo.write(90);
      }

    
     
    if (val == 'a') //if value input is equals to a
      {
       myservo.attach(9);
        for (int i=0;i<=180;i++)
        {      
         Serial.println(i);
         myservo.write(i);
         delay(500);
         
        }
       }

  if (val == 'k') //if value input is equals to a
      {
       myservo.detach();
      }
       
  }//End of Serial Read
}//Endd of Loop

void openHand()
{
  
}
