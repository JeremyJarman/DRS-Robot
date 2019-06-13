
#include <Servo.h>


//CAN BUS SET UP///////////////////////////////////////////////////////////////////////////

#include <mcp_can.h>
#include <SPI.h>
#include "mcp_can.h"
#include <mcp_can_dfs.h>
const int SPI_CS_PIN = 9;
MCP_CAN CAN(SPI_CS_PIN); 
unsigned char len = 0;
unsigned char buf[8];
long unsigned int MsgId;
long unsigned int ArduinoID = 0x1881AAAA;
//////////////////////////////////////////////////////////////////////////////////////////
////
//void copyArray(char* src, char* dst, int len) {
//    memcpy(dst, src, sizeof(src[0])*len);
//}

/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////DEFINE START POSITIONS//////////////////////////////////
//////////////////////////// {Bicep,Thumb,Index,Middle,Ring,Little}//////////////////////
unsigned char StartPos[6] = {50,90,90,90,90,90};
unsigned char Min[6] = {14,0,0,0,0,0};
unsigned char Max[6] = {51,171,171,171,171,171};
unsigned char CurrentPos[6] = {50,90,90,90,90,90};

unsigned char NewPos[6];

//unsigned char Rate[5] = {1,1,1,1,1};
unsigned int Complete[6] = {1,1,1,1,1,1};

Servo Bicep;         // Define servo fingers
Servo Thumb;         // Define servo fingers
Servo Index;         // Define servo fingers
Servo Middle;         // Define servo fingers
Servo Ring;         // Define servo fingers
Servo Little;



#define LPin 10
#define RPin 9
#define MPin 3
#define IPin 5
#define TPin 6
#define BPin 11

int finger;

//Motion routines for handopen and handclose
//void openhand(){for(finger = 1; finger < 6; finger++){openFinger(finger);}}
//void closehand(){for(finger = 1; finger < 6 ; finger++){closeFinger(finger);}}

// You have to rewrite properly the functions to open and close the fingers 
// according of your assembly
// In my case, middle and index fingers are opened when servo is at 170 degrees and the others when servo is at 0 degrees
// I have used Towardpro MG996R servos

//void openFinger(int finger){
//  if(finger==LITTLE){servoLittleFinger.write(0);} // Little finger
//  else if(finger==RING){servoRingFinger.write(0);}// Ring finger
//  else if(finger==MIDDLE){servoMiddleFinger.write(0);}// Middle finger
//  else if(finger==INDEX){servoIndexFinger.write(0);}// Index finger
//  else if(finger==THUMB){servoThumbFinger.write(0);}//Thumb finger
// 
//
//}
//
//void closeFinger(int finger){
//  if(finger==LITTLE){servoLittleFinger.write(170);} // Little finger 
//  else if(finger==RING){servoRingFinger.write(170);}// Ring finger
//  else if(finger==MIDDLE){servoMiddleFinger.write(170);}// Middle finger
//  else if(finger==INDEX){servoIndexFinger.write(170);}// Index finger
//  else if(finger==THUMB){servoThumbFinger.write(170);}//Thumb finger
//  
//}

void setup(){
  
  Serial.begin(115200); //BAUDRATE set to 115200, remember it to set monitor serial properly (used this BaudRate and "NL&CR" option to visualize the values correctly)


Bicep.attach(BPin);Bicep.write(StartPos[0]);// Define servo fingers
Thumb.attach(TPin);Thumb.write(StartPos[1]);// Define servo fingers
Index.attach(IPin);Index.write(StartPos[2]);
Middle.attach(MPin);Middle.write(StartPos[3]);// Define servo fingers
Ring.attach(RPin);Ring.write(StartPos[4]);// Define servo fingers
Little.attach(LPin); Little.write(StartPos[5]);

  while (CAN_OK != CAN.begin(CAN_250KBPS))              // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS Module Failed to Initialized");
        Serial.println("Retrying....");
        delay(200);
    }    
    Serial.println("CAN BUS Module Initialized!");
  

}//end setup

void loop() {// Nothing to do here, all is done in the interrupt function

     //CheckAnalogue();
     ReadCanMsg();
     UpdateServos();
     Feedback();

}//End of Loop


//void CheckAnalogue (){
//    int value = analogRead(EMGPIN); //Sampling analog signal
//     if(value>THRESHOLD) //If the value of the sample is greater than THRESHOLD means that the hand has been closed
//  
//    {
//      closehand();
//    }
//  
//  else //Otherwise the hand is open
//   {
//    openhand();
//    }
//  Serial.println(value); //You can use serial monitor to set THRESHOLD properly, comparing the values shown when you open and close your hand
// 
//}



void ReadCanMsg(){  
 if(CAN_MSGAVAIL == CAN.checkReceive())            // check if data coming
    {
      Serial.println("CAN MSG RECIEVED");
      CAN.readMsgBuf(&len, buf);
      MsgId= CAN.getCanId();
   if(MsgId == ArduinoID) // Include this check later when there are multiple arduinos
     {


            //If kill message recived then Stop
             if(buf[0] == 's')
             {
              STOP();
             }
            //Otherwise Update all servo positions
             else{
              for(int i = 0; i<6; i++)    // print the data
                  {
                  setPos(i,buf[i]);
                  }
             }//End of Else



      
//               if(buf[0] == 'r')
//                {
//                  for(int i = 1; i<6; i++)    // print the data
//                    {
//                    setRate(i-1,buf[i]);
//                    }
//                }//End of Rate update Loop

//              if(buf[0] == 'p')
//              {

 //            }//End of position update Loop


        
      }
      
    }//End of Can_MSGAVAIL
}//End of ReadCanMsg


//updated Rate Matrix
//void setRate(int servo,char r)
//  {
//   Rate[servo] = r;
//  }

  
//Updates Position Matrix 
void setPos(int servo,char p)
  {
   NewPos[servo] = p;
  }


void STOP()
{

Bicep.detach();         
Thumb.detach();        
Index.detach();         
Middle.detach();         
Ring.detach();        
Little.detach();
 
  Serial.println("ALL Servos Detached"); // DEBUGGING
}


void UpdateServos(){

       for(int i = 0; i<6; i++)    
          {
                    if(NewPos[i]>Min[i] && NewPos[i]<Max[i])
                    {
                      if(CurrentPos[i]>NewPos[i]){
                        Complete[i] = 0;
                        CurrentPos[i]= CurrentPos[i]-1;
                        Actuate(i,CurrentPos[i]);
                      }
                      if(CurrentPos[i]<NewPos[i])
                      {
                        Complete[i] = 0;
                        CurrentPos[i] = CurrentPos[i]+1;
                        Actuate(i,CurrentPos[i]);
                      }
                    }
           }//end of for loop
}//End of Update Servo



void Actuate(int i, char p)
{

 if(i ==5)
 { //Little.attach(LPin);
   Little.write(p);
   delay(1);
 } 
 if(i ==4)
 {// Ring.attach(RPin);
   Ring.write(p);
   delay(1);
 }
 else if (i == 3)
 {
  //Middle.attach(MPin);
  Middle.write(p);
  delay(1);
 }
 else if (i == 2)
 {
  Index.attach(IPin);
  Index.write(p);
  delay(1);
 }
 else if (i == 1)
 {
  //Thumb.attach(TPin);
  Thumb.write(p);
  delay(1);
 }
 else 
 {
  //Bicep.attach(BPin);
  Bicep.write(p);
  delay(1);
 }
}//End of Actuate Function


void Feedback(){
 for(int i = 0; i<6; i++)    
          {
            if(CurrentPos[i]==NewPos[i] && Complete[i] == 0)
            {
             Serial.print("Servo ");
             Serial.print(i);
             Serial.print(" Complete");
             Complete[i] = 1;
            }
          }
}//End Of FeedBack
