
#include <Servo.h>
#define ArduinoID 1
#define THRESHOLD 80   //In order to determine the state of the hand (opened/closed)
#define EMGPIN 3 //Analog pin connected to Muscle Sensor V3 Board
#define LITTLEPIN  3 //Digital pin used by Little servo
#define RINGPIN    5 //Digital pin used by Ring servo
#define MIDDLEPIN  6 //Digital pin used by Middle servo
#define INDEXPIN   9 //Digital pin used by Index servo
#define THUMBPIN  10 //Digital pin used by Thumb servo

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
long unsigned int rxId;

//////////////////////////////////////////////////////////////////////////////////////////

void copyArray(char* src, char* dst, int len) {
    memcpy(dst, src, sizeof(src[0])*len);
}

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



#define  posLFstart 150 //estimated servo location on powerup
#define  posLFmin 1 //minimum allowed 'angle' (must be at least 1)
#define  posLFmax 170 //maximum allowed 'angle' (must be 180 max)

#define  posRFstart 90 
#define  posRFmin 1 
#define  posRFmax 170 

#define  posMFstart 90
#define  posRFmin 1 
#define  posRFmax 170

#define  posIFstart 90
#define  posIFmin 1 
#define  posIFmax 170

#define  posTFstart 90
#define  posTFmin 1 
#define  posTFmax 170

int posLF = posLFstart;
int posRF = posRFstart;
int posMF = posMFstart;
int posIF = posIFstart;
int posTF = posTFstart;

int storedPosLF = posLFstart; //guestimate of rest 
int storedPosRF = posRFstart; //guestimate of rest
int storedPosMF = posMFstart; //guestimate of rest 
int storedPosIF = posIFstart; //guestimate of rest
int storedPosTF = posTFstart;


int servoLFCompleted = 1;
int servoRFCompleted = 1;
int servoMFCompleted = 1;
int servoIFCompleted = 1;
int servoTFCompleted = 1;

int finger;

// Motion routines for handopen and handclose
void openhand(){for(finger = 1; finger < 6; finger++){openFinger(finger);}}
void closehand(){for(finger = 1; finger < 6 ; finger++){closeFinger(finger);}}

// You have to rewrite properly the functions to open and close the fingers 
// according of your assembly
// In my case, middle and index fingers are opened when servo is at 170 degrees and the others when servo is at 0 degrees
// I have used Towardpro MG996R servos

void openFinger(int finger){
  if(finger==LITTLE){servoLittleFinger.write(0);} // Little finger
  else if(finger==RING){servoRingFinger.write(0);}// Ring finger
  else if(finger==MIDDLE){servoMiddleFinger.write(0);}// Middle finger
  else if(finger==INDEX){servoIndexFinger.write(0);}// Index finger
  else if(finger==THUMB){servoThumbFinger.write(0);}//Thumb finger
 

}

void closeFinger(int finger){
  if(finger==LITTLE){servoLittleFinger.write(170);} // Little finger 
  else if(finger==RING){servoRingFinger.write(170);}// Ring finger
  else if(finger==MIDDLE){servoMiddleFinger.write(170);}// Middle finger
  else if(finger==INDEX){servoIndexFinger.write(170);}// Index finger
  else if(finger==THUMB){servoThumbFinger.write(170);}//Thumb finger
  
}

void setup(){
  
  Serial.begin(115200); //BAUDRATE set to 115200, remember it to set monitor serial properly (used this BaudRate and "NL&CR" option to visualize the values correctly)
  copyArray(StartPos, CurrentPos, 5);
  copyArray(StartPos, NewPos, 5);
  
 // servoLittleFinger.attach(LITTLEPIN);  // Set Little finger servo to digital pin 3
 // servoRingFinger.attach(RINGPIN);  // Set Ring finger servo to digital pin 5
 // servoMiddleFinger.attach(MIDDLEPIN);  // Set Middle finger servo to digital pin 6
 // servoIndexFinger.attach(INDEXPIN);  // Set Index finger servo to digital pin 9
 // servoThumbFinger.attach(THUMBPIN);  // Set Thumb finger servo to digital pin 10

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


void CheckAnalogue (){
    int value = analogRead(EMGPIN); //Sampling analog signal
     if(value>THRESHOLD) //If the value of the sample is greater than THRESHOLD means that the hand has been closed
  
    {
      closehand();
    }
  
  else //Otherwise the hand is open
   {
    openhand();
    }
  Serial.println(value); //You can use serial monitor to set THRESHOLD properly, comparing the values shown when you open and close your hand
 
}



void ReadCanMsg(){  
 if(CAN_MSGAVAIL == CAN.checkReceive())            // check if data coming
    {
      Serial.println("CAN MSG RECIEVED");
      CAN.readMsgBuf(&len, buf);
      rxId= CAN.getCanId();
  //    if(rxId == ArduinoID) // Include this check later when there are multiple arduinos
  //      {
               if(buf[0] == 'r')
                {
                  for(int i = 1; i<6; i++)    // print the data
                    {
                    setRate(i-1,buf[i]);
                    }
                }//End of Rate update Loop

              if(buf[0] == 'p')
              {
                for(int i = 1; i<6; i++)    // print the data
                  {
                  setPos(i-1,buf[i]);
                  }
             }//End of position update Loop

             if(buf[0] == 's')
             {
              STOP();
             }
        
   //     }
      
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
