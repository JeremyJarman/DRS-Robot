// Henry's Bench
// 1st CAN Network - CAN TRANSMIT

#include <mcp_can.h>
#include <SPI.h>


const int SPI_CS_PIN = 9;


long unsigned int RightArmID = 0x1881ABBA; // This format is typical of a 29 bit identifier.. the most significant digit is never greater than one.
long unsigned int LeftArmID = 0x1881AAAA;
//unsigned char rate[8] = {'r', 0, 0, 0, 0, 0, 0, 0};
unsigned char pos[8] = {'p',0,0,0,0,0,0,0};
unsigned char Stop[8] ={'s',0,0,0,0,0,0,0};

//LeftEblow Arduino is responsible for middle index thumb ring little bicep
//At pins 3,5,6,9,10,11
//We need to send six servo values to this arduino

unsigned char LeftArm [6] = {0,0,0,0,0,65};


//Left Shoulder is responsible for Flex and Circumduction
//At pins 10 and 11 respectively

unsigned char LeftShoulder [2] = {0,90};


//Head and Transmitter Arduinio is responsible for Head movement Pan and Tilt and CAN msg distribution
//At Pins 3 and 5

unsigned char Head [2] = {50,90};

//Right Shoulder is responsible for Flex and Circumduction
//At pins 10 and 11 respectively

unsigned char RightShoulder [2] = {0,90};

//RightArm Arduino is responsible for 
//At pins???????????????????????????
//We need to send six servo values to this arduino

unsigned char RightArm [6] = {0,0,0,0,0,65};

//Now we need an array for all the values combined as recieved from C#

unsigned char AllPos [22] = {10,0,0,0,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};



int val;
int led = 13; // the pin the LED is connected to



  


//Construct a MCP_CAN Object and set Chip Select to 10.

MCP_CAN CAN(SPI_CS_PIN);                            

void PrintMovements ()
{
       for(int i = 1; i<8; i++)    // print the data
        {
          Serial.print("Servo");
          Serial.print(i);
          Serial.print("Servo Position");
          Serial.print(pos[i]);
          //Serial.print("Servo Rate");
          //Serial.print(rate[i]);
          Serial.println();
          //myservo.write(buf[i]);              // tell servo to go to position in variable 'pos'
          delay(30);
        }
}
     
void setMovement(int servo, char p, char r)
{
  pos[servo] = p;
  //rate[servo] = r;
}



void setup()
{
//    pinMode(led, OUTPUT); // Declare the LED as an output
   Serial.begin(115200);
//
    while (CAN_OK != CAN.begin(CAN_250KBPS))              // init can bus : baudrate = 250K
    {
        Serial.println("CAN BUS Module Failed to Initialized");
        Serial.println("Retrying....");
        delay(200);
    }
    Serial.println("CAN BUS Shield init ok!");
    digitalWrite(led, HIGH); // Turn the LED on


}


void loop()
{   
}// End of Loop

//"Tilt", "Pan","LFlex", "LAdd","LCirc", "LBicep", "LWrist", "LThumb", "LIndex","LMiddle", "LRing", "LLittle", "Flex", "Add","Circ", "Bicep", "Wrist", "Thumb", "Index","Middle", "Ring", "Little"

void Decode (String msgIn)
{
  String msg = msgIn;
  //msg.remove(msg.lastIndexOf("1"));
  
//   #35#85#0#0#110#65#0#0#0#0#0#0#0#0#110#65#0#0#0#0#0#0
   int arraySize = sizeof(AllPos) / sizeof(AllPos[0]);
   
   for(int i = arraySize; i>0; i--)    // print the data
     {
          
          String msgRemainder = msg;
          //Serial.println("Msg at start" + msgRemainder);
          msgRemainder.remove(msgRemainder.lastIndexOf("#"));
          //Serial.println("Trimmed Msg " + msgRemainder);
          String target = msg;
          target.remove(0,target.lastIndexOf("#")+1); 
          
          //Serial.println("Target" + target);
          //Serial.println(target.toInt());
          
          
          UpdateAllPos(i-1,target.toInt());
          msg = msgRemainder;
       }

      PrintAllPos();
}


void serialEvent()
{
   String incommingMsg = Serial.readString();
   Decode(incommingMsg); 
   AsignValues();
   DistributeMsgs ();
}

void UpdateAllPos(int i , int p)
{
  char y = p;
  AllPos[i] = y;
} 

void PrintAllPos()
{
    for(int i = 0; i < 22; i++)
    {
      Serial.println(AllPos[i]);
    }
}


//"Tilt", "Pan","LFlex", "LAdd","LCirc", "LBicep", "LWrist", "LThumb", "LIndex","LMiddle", "LRing", "LLittle", "Flex", "Add","Circ", "Bicep", "Wrist", "Thumb", "Index","Middle", "Ring", "Little"
void AsignValues ()
{

Head[0] = AllPos[1];//Pan
Head[1] = AllPos[0];//Tilt
LeftShoulder[0] = AllPos[2];//LFLex
LeftShoulder[1] = AllPos[4];//LCirc
LeftArm[0] = AllPos[5];//LBicep
LeftArm[1] = AllPos[7];//LThumb
LeftArm[2] = AllPos[8];//LIndex
LeftArm[3] = AllPos[9];//LMiddle
LeftArm[4] = AllPos[10];//LRing
LeftArm[5] = AllPos[11];//LLittle
RightShoulder[0] = AllPos[12];//RFlex
RightShoulder[1]= AllPos[14];//RCirc
RightArm[0] = AllPos[15];//LBicep
RightArm[1] = AllPos[17];//LThumb
RightArm[2] = AllPos[18];//LIndex
RightArm[3] = AllPos[19];//LMiddle
RightArm[4] = AllPos[20];//LRing
RightArm[5] = AllPos[21];//LLittle
Serial.println("Values Assigned");
}

void DistributeMsgs () 
{
    CAN.sendMsgBuf(RightArmID,1, 6, RightArm);  
    CAN.sendMsgBuf(LeftArmID,1,6, LeftArm);
    Serial.println("Message Sent");
}
