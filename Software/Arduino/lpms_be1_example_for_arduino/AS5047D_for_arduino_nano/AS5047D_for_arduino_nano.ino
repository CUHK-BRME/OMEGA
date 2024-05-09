/*AMS Rotary Sensor AS5047D

 Circuit
 UNO: MOSI pin 11
      MISO pin 12 
      CLK  pin 13
      CSN  pin 10

 */

#include <SPI.h>

//Set Slave Select Pin
//MOSI, MISO, CLK are handeled automatically
int CSN = 10;
int SO = 12;
int SI = 11;
int CLK = 13 ;
unsigned int angle;
uint8_t ang[2];

void setup() {
  
  Serial.begin(9600);

  //Set Pin Modes
  pinMode(CSN, OUTPUT);
  pinMode(SI, OUTPUT);
  pinMode(SO, INPUT);
  pinMode(CLK, OUTPUT);
  //Set Slave Select High to Start i.e disable chip
  digitalWrite(CSN, HIGH);
  //Initialize SPI 
  SPI.begin();
}

void loop() {

  SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE1));
  
  //Send the Command Frame
  digitalWrite(CSN, LOW);
  delayMicroseconds(1);
  SPI.transfer16(0xFFFF);
  digitalWrite(CSN,HIGH);

  //Read data frame
  digitalWrite(CSN, LOW);
  delayMicroseconds(1);
  angle = SPI.transfer16(0xC000);
  digitalWrite(CSN, HIGH);
  SPI.endTransaction();

  angle = (angle & (0x3FFF));
  ang[0] = ((angle >> 8) & (0x3F));
  ang[1] = (angle & (0xFF));
  
  //int pos = ((unsigned long) angle)*360UL/16384UL;
  float pos = ((unsigned long) angle)*360.0/16384.0;
  unsigned int number = (ang[0] << 8)| ang[1];
  float num = ((unsigned long) number)*360.0/16384.0;
  
  Serial.println(pos);
  Serial.println(num);
  Serial.println(' ');

  delay(20);
}
