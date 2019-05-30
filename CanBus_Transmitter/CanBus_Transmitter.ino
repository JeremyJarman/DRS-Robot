// Henry's Bench
// 1st CAN Network - CAN TRANSMIT

#include <mcp_can.h>
#include <SPI.h>


const int SPI_CS_PIN = 9;

// Build an ID or PGN

long unsigned int txID = 0x1881ABBA; // This format is typical of a 29 bit identifier.. the most significant digit is never greater than one.
unsigned char stmp[8] = {0x0E, 0x00, 0xFF, 0x22, 0xE9, 0xFA, 0xDD, 0x51};
unsigned char rate[8] = {'r', 0, 0, 0, 0, 0, 0, 0};
unsigned char pos[8] = {'p',0,0,0,0,0,0,0};
unsigned char Stop[8] ={'s',0,0,0,0,0,0,0};
int val;


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
          Serial.print("Servo Rate");
          Serial.print(rate[i]);
          Serial.println();
          //myservo.write(buf[i]);              // tell servo to go to position in variable 'pos'
          delay(30);
        }
}
     
void setMovement(int servo, char p, char r)
{
  pos[servo] = p;
  rate[servo] = r;
}

// We want to make 10 adjustments per second
// Rate is the degrees moved per time step



void GenerateMovementArray (char ServoNum, int startPos, int endPos, int rate, int Tdelay)
{
  int MovementLength = ((endPos - startPos)/rate) + Tdelay;
  Serial.println("MovementLength");
  Serial.println(MovementLength);
  
  int pos = startPos;
  //servoNum[0] = pos;
  Serial.println(pos);
  
  
  for(int i =1; i<MovementLength; i++)    // generate the MovementArray
        {
          if(i < Tdelay) {
            pos = pos;
            Serial.println(pos);
           // servoNum[i] = pos;
            }
           else{
          pos = pos  + rate;
          //ervoNum[i] = pos;
          Serial.println(pos);
           }
        }
}




void setup()
{
    Serial.begin(115200);

    while (CAN_OK != CAN.begin(CAN_250KBPS))              // init can bus : baudrate = 250K
    {
        Serial.println("CAN BUS Module Failed to Initialized");
        Serial.println("Retrying....");
        delay(200);
        
    }
    Serial.println("CAN BUS Shield init ok!");
}


void loop()
{   //Serial.println("In loop");

    // send the data:  id = 0x00, Extended Frame, data len = 8, stmp: data buf
    // Extended Frame = 1.
    // then read the serial value

//Prints the Current Movement Values

  if (Serial.available()) // if serial value is available 
  {
    val = Serial.read();
    if (val == 'p') //if value input is equals to d
    {
     PrintMovements();   
    }
  

// Updates the current Movement Values

    if (val == 'u') //if value input is equals to a
    {
      setMovement(1, 000, 2); 
      setMovement(2, 000, 2); 
      setMovement(3, 180, 1); 
      setMovement(4, 90, 2); 
      setMovement(5, 001, 3); 
    }

   if (val == 'q') //if value input is equals to a
    {
      setMovement(1, 1, 2); 
      setMovement(2, 1, 2); 
      setMovement(3, 1, 1); 
      setMovement(4, 1, 2); 
      setMovement(5, 1, 3); 
    }

   if (val == 'w') //if value input is equals to a
    {
      setMovement(1, 80, 2); 
      setMovement(2, 0, 2); 
      setMovement(3, 0, 1); 
      setMovement(4, 0, 2); 
      setMovement(5, 0, 3); 
    }

       if (val == 'e') //if value input is equals to a
    {
      setMovement(1, 120, 2); 
      setMovement(2, 120, 2); 
      setMovement(3, 120, 1); 
      setMovement(4, 120, 2); 
      setMovement(5, 120, 3); 
    }

       if (val == 'r') //if value input is equals to a
    {
      setMovement(1, 0, 2); 
      setMovement(2, 0, 2); 
      setMovement(3, 1, 1); 
      setMovement(4, 0, 2); 
      setMovement(5, 0, 3); 
    }

 
// Send Cunrrent Movement Values as CAN MSG

    if (val == 's')
    {
    CAN.sendMsgBuf(txID,1, 8, rate);
    CAN.sendMsgBuf(txID,1, 8, pos);  
    Serial.println("Message Sent");
    }

    if(val == 'k')
    {
    CAN.sendMsgBuf(txID,1,8, Stop);
    Serial.println("Kill Msg Sent");
    }
   // CAN.sendMsgBuf('a') ;
    delay(25);    // send data every 25mS
  }
  
  }
