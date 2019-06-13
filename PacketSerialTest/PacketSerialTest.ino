#include <PacketSerial.h>

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
unsigned char LPos[6] ={0,0,0,0,0,0};
unsigned char RPos[6] ={0,0,0,0,0,0};

PacketSerial myPacketSerial;


void setup() {
  
  // We begin communication with our PacketSerial object by setting the
  // communication speed in bits / second (baud).
  myPacketSerial.begin(9600);

  // If we want to receive packets, we must specify a packet handler function.
  // The packet handler is a custom function with a signature like the
  // onPacketReceived function below.
  myPacketSerial.setPacketHandler(&onPacketReceived);
  
  flex.attach(6);
  circum.attach(9);
  bicep.attach(13);
  
  
  flex.write(50);
  circum.write(90);
 // bicep.write(20);

//    flex.detach();
//       circum.detach();
//      bicep.detach();

  
}




void loop() {
myPacketSerial.update();
}//Endd of Loop


void onPacketReceived(const uint8_t* buffer, size_t size)
{
  // In this example, we will simply reverse the contents of the array and send
  // it back to the sender.

  // Make a temporary buffer.
  uint8_t tempBuffer[size];

  // Copy the packet into our temporary buffer.
  memcpy(tempBuffer, buffer, size);

  // Reverse our temporaray buffer.
  process(tempBuffer, size);

  // Send the reversed buffer back to the sender. The send() method will encode
  // the whole buffer as as single packet, set packet markers, etc.
  // The `tempBuffer` is a pointer to the `tempBuffer` array and `size` is the
  // number of bytes to send in the `tempBuffer`.
  myPacketSerial.send(tempBuffer, size);
}

void process(uint8_t* buffer, size_t size)
{
    uint8_t tmp;
  for (size_t i = 0; i <= size; i++)
  {
    tmp = buffer[i];
    buffer[i] = buffer[size - i - 1];
    buffer[size - i - 1] = tmp;
  }
    
}



void reverse(uint8_t* buffer, size_t size)
{
  uint8_t tmp;

  for (size_t i = 0; i < size / 2; i++)
  {
    tmp = buffer[i];
    buffer[i] = buffer[size - i - 1];
    buffer[size - i - 1] = tmp;
  }
}

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
