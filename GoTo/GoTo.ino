/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#include <Stream.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

//int pos = 0;    // variable to store the servo position
//int val = 0; // initial value of in


void setup() {
  Serial.begin(9600); // Serial comm begin at 9600bps
    // attaches the servo on pin 9 to the servo object
  myservo.attach(9);
  myservo.write(0);
  //myservo.detach();
}




void loop() {
//
//   if (Serial.available()) // if serial value is available 
//  {
//    
//    int val = Serial.read();
//
//    val = val - 48;
//    Serial.println(val);
//
//    
//    if (val >= 0)
//    {
//    Serial.println(val);
//    updatepos (val);
//    }
//  //  val = value.toInt();
//   
//
//     
//  }//End of Serial Read
//

  
}//End of Loop



//void updatepos (int newval) {
//
//  
//  if (newval == 1) //if value input is equals to a
//      {
//       myservo.detach();
//      }
//
//   else {
//       
//       myservo.write(newval);
//    }
//  
//}
