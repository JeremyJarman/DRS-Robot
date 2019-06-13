
#include <Servo.h>


#define node  11 //Digital pin used by Thumb servo

//CAN BUS SET UP///////////////////////////////////////////////////////////////////////////

#include <mcp_can.h>
#include <SPI.h>
#include "mcp_can.h"
#include <mcp_can_dfs.h>
const int SPI_CS_PIN = 9;
MCP_CAN CAN(SPI_CS_PIN); 
unsigned char len = 0;
unsigned char buf[8];
long unsigned int MsgID;
long unsigned int rxID = 0x1881ABBA;
int led = 13; // the pin the LED is connected to
//////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////DEFINE START POSITIONS//////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////DEFINE START POSITIONS//////////////////////////////////
unsigned char rate[8] = {'r', 0, 0, 0, 0, 0, 0, 0};
unsigned char pos[8] = {'p',0,0,0,0,0,0,0};
//////////////////////////// {LF,RF,MF,IF,Thumb}//////////////////////
unsigned char StartPos[5] = {90,90,90,90,90};
unsigned char Min[5] = {1,1,1,1,1};
unsigned char Max[5] = {120,120,120,120,120};
unsigned char CurrentPos[5] = {90,90,90,90,90};

unsigned char NewPos[5];

unsigned char Rate[5] = {1,1,1,1,1};
unsigned int Complete[5] = {1,1,1,1,1};

#define ArduinoID 1
#define THRESHOLD 80   //In order to determine the state of the hand (opened/closed)
#define EMGPIN 3 //Analog pin connected to Muscle Sensor V3 Board
#define LITTLEPIN  3 //Digital pin used by Little servo
#define RINGPIN    5 //Digital pin used by Ring servo
#define MIDDLEPIN  6 //Digital pin used by Middle servo
#define INDEXPIN   9 //Digital pin used by Index servo
#define THUMBPIN  10 //Digital pin used by Thumb servo

//Constants used to open and close the fingers
#define LITTLE 1 
#define RING   2
#define MIDDLE 3
#define INDEX  4
#define THUMB  5


Servo servoLittleFinger;         // Define servo fingers
Servo servoRingFinger;         // Define servo fingers
Servo servoMiddleFinger;         // Define servo fingers
Servo servoIndexFinger;         // Define servo fingers
Servo servoThumbFinger;         // Define servo fingers


void setup(){
  pinMode(led, OUTPUT); // Declare the LED as an output
  Serial.begin(115200); //BAUDRATE set to 115200, remember it to set monitor serial properly (used this BaudRate and "NL&CR" option to visualize the values correctly)
  while (CAN_OK != CAN.begin(CAN_250KBPS))              // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS Module Failed to Initialized");
        Serial.println("Retrying....");
        delay(200);
    }    
    Serial.println("CAN BUS Module Initialized!");
    digitalWrite(led, LOW); // Turn the LED off

}//end setup

void loop() {// Nothing to do here, all is done in the interrupt function

     //CheckAnalogue();
     ReadCanMsg();
     //UpdateServos();
    // Feedback();

}//End of Loop



void ReadCanMsg(){  
 if(CAN_MSGAVAIL == CAN.checkReceive())            // check if data coming
    {
      Serial.println("CAN MSG RECIEVED");
      CAN.readMsgBuf(&len, buf);
      MsgID= CAN.getCanId();
   if(MsgID == rxID) // Include this check later when there are multiple arduinos
       {
                digitalWrite(led, HIGH); // Turn the LED on
                delay(5000);
//               if(buf[0] == 'r')
//                {
//                  for(int i = 1; i<6; i++)    // print the data
//                    {
//                    setRate(i-1,buf[i]);
//                    }
//                }//End of Rate update Loop
//
//              if(buf[0] == 'p')
//              {
//                for(int i = 1; i<6; i++)    // print the data
//                  {
//                  setPos(i-1,buf[i]);
//                  }
//             }//End of position update Loop
//
//             if(buf[0] == 's')
//             {
//              STOP();
//             }
        
      }
      
    }//End of Can_MSGAVAIL
}//End of ReadCanMsg


//updated Rate Matrix
void setRate(int servo,char r)
  {
   Rate[servo] = r;
  }

  
//Updates Position Matrix 
void setPos(int servo,char p)
  {
   NewPos[servo] = p;
  }


void STOP()
{
  servoLittleFinger.detach();  
  servoRingFinger.detach();  
  servoMiddleFinger.detach();  
  servoIndexFinger.detach();  
  servoThumbFinger.detach();  
   
  Serial.println("ALL Servos Detached"); // DEBUGGING
}


void UpdateServos(){

       for(int i = 0; i<5; i++)    
          {
                    if(NewPos[i]>Min[i]-1 && NewPos[i]<Max[i]+1)
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
 { servoLittleFinger.attach(LITTLEPIN);
   servoLittleFinger.write(p);
   delay(1);
 }
 else if (i == 4)
 {
  servoRingFinger.attach(RINGPIN);
  servoRingFinger.write(p);
  delay(1);
 }
 else if (i == 3)
 {
  servoMiddleFinger.attach(MIDDLEPIN);
  servoMiddleFinger.write(p);
  delay(1);
 }
 else if (i == 2)
 {
  servoIndexFinger.attach(INDEXPIN);
  servoIndexFinger.write(p);
  delay(1);
 }
 else 
 {
  servoThumbFinger.attach(THUMBPIN);
  servoThumbFinger.write(p);
  delay(1);
 }
}//End of Actuate Function


void Feedback(){
 for(int i = 0; i<5; i++)    
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
