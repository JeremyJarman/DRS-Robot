/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo flex;
Servo circum;
Servo bicep;// create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int val; // initial value of in
String msgReceived = "";
//unsigned char pos[5] = {0,0,0,0,0};

void setup() {
  Serial.begin(9600); // Serial comm begin at 9600bps
    // attaches the servo on pin 9 to the servo object
  
  //flex.attach(6);
  //circum.attach(0);
  bicep.attach(11);
  
  
  //flex.write(50);
  circum.write(90);
  bicep.write(65);

//    flex.detach();
//       circum.detach();
//      bicep.detach();

  
}




void loop() {

}//Endd of Loop


//void serialEvent() {
//   if (Serial.available()) // if serial value is available 
//  {
//  int val = Serial.read();
//  
//  if (val == 'k') //if value input is equals to a
//      {
//       flex.detach();
//       circum.detach();
//       bicep.detach();
//      }
//      
//   else 
//      {
//        flex.attach(6);
//        circum.attach(9);
//        bicep.attach(13);
//      doMove();  
//      }
//      
//  }
//}
//
//void doMove(){
//
//  for (int i = 0; i <=60; i++)
//    {
//      bicep.write(i+10);
//      if(i<=50)
//      {
//        //circum.write(i);
//        flex.write(i);
//      }
//  }  
//}


//void serialEvent(){
//     
// String NewMsg  = Serial.readString();
// Serial.print(NewMsg); 
//  if (NewMsg == 'p')
//  {
//    Serial.print(msgReceived);
//  }
//
//  else {
//    msgReceived = NewMsg;
//    }
//}
//
//myString.indexOf(val, from)
//
//
//for(int i = 5; i<1; i--)    
//{
//
//}
//          






//
//void openHand()
//{
//  
//}
