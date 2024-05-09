// LPMS-BE2 source code
// https://bitbucket.org/lpresearch/lpms_be1_example_for_arduino/src/master/
// AS5047D SPI source code
// https://forum.arduino.cc/t/rotation-count-for-magnetic-position-sensor-as5047d-14bit/521357
#include "Arduino.h"
#include "lpms_be1.h"
#include <stdio.h>
#include <SPI.h>

LPMS_BE1 lpms_be1;
sensor_data_t sensor_data;


void be1_config_test(void);
void be1_read_data(void);
void be1_print_data(void);
//functions added for as5047d encoder
void as5047d_init(void);
void as5047d_read_data(void);

unsigned long nowTime, lastTime;
//Set Slave Select Pin
//MOSI, MISO, CLK are handeled automatically
int AS5047D_SPI_CS = 10;
int AS5047D_SPI_SO = 12;
int AS5047D_SPI_SI = 11;
int AS5047D_SPI_CLK = 13 ;
unsigned int as5047d_ang16;
uint8_t as5047d_ang[2];

void setup() {
    Serial.begin(230400);
    lpms_be1.setup();
//    as5047d_int(); // 2D
    as5047d_ang[0] = 0;
    as5047d_ang[1] = 0;
    lastTime = millis();
}

void loop() {
    nowTime = millis();
    if((nowTime-lastTime) > 2) {
        be1_read_data();
//        as5047d_read_data(); // 2D
        be1_print_data();
        lastTime = nowTime;
    }
    
}

void be1_config_test(void)
{
    uint8_t buf[9] = { 0 };
    lpms_be1.get_reg_data(0x00, buf, 9);
    for (int i = 0; i < 9; i++) {
        if (buf[i] < 0x10) {
            Serial.print("0");
            Serial.print(buf[i], HEX);
        } else {
            Serial.print(buf[i], HEX);
        }
        Serial.print(" ");
        
    }
    Serial.println();

    lpms_be1.setup();

    lpms_be1.get_reg_data(0x00, buf, 9);
    for (int i = 0; i < 9; i++) {
        if (buf[i] < 0x10) {
            Serial.print("0");
            Serial.print(buf[i], HEX);
        } else {
            Serial.print(buf[i], HEX);
        }
        Serial.print(" ");
    }
    Serial.println();
    Serial.println();
}

void be1_read_data(void)
{
    //lpms_be1.get_timestamp(&sensor_data.timestamp);
    lpms_be1.get_acc(sensor_data.acc);
    lpms_be1.get_gyro(sensor_data.gyro);
    //lpms_be1.get_quat(sensor_data.quat);
    //lpms_be1.get_euler(sensor_data.euler);
}
void be1_print_data(void)
{
    uint16_t checksum = 0;
    if (Serial.availableForWrite()) {
      Serial.write(0x3A);
      Serial.write(0x01);
      Serial.write(0x00);
      Serial.write(0x09);
      Serial.write(0x00);
      Serial.write(0x1A);
      Serial.write(0x00);
      checksum = 0x01 + 0x09 + 0x1A;
      for(int i=0;i<12;i++) {
        Serial.write(sensor_data.acc[i]);
        checksum += sensor_data.acc[i];
      }
      for(int i=0;i<12;i++) {
        Serial.write(sensor_data.gyro[i]);
        checksum += sensor_data.gyro[i];
      }
      for(int i=0;i<2;i++) {
        Serial.write(as5047d_ang[i]);
        checksum += as5047d_ang[i];
      }
      Serial.write(checksum & 0xff);
      Serial.write(checksum >> 8);
      Serial.write(0x0D);
      Serial.write(0x0A);
    }
    /*
    float ts = (float)sensor_data.timestamp * 0.002;
    Serial.print("timestamp: ");
    Serial.println(ts, 3);

    Serial.print("acc: ");
    Serial.print(sensor_data.acc[0], 3);
    Serial.print(", ");
    Serial.print(sensor_data.acc[1], 3);
    Serial.print(", ");
    Serial.print(sensor_data.acc[2], 3);
    Serial.println();

    Serial.print("gyro: ");
    Serial.print(sensor_data.gyro[0], 3);
    Serial.print(", ");
    Serial.print(sensor_data.gyro[1], 3);
    Serial.print(", ");
    Serial.print(sensor_data.gyro[2], 3);
    Serial.println();

    Serial.print("quat: ");
    Serial.print(sensor_data.quat[0], 3);
    Serial.print(", ");
    Serial.print(sensor_data.quat[1], 3);
    Serial.print(", ");
    Serial.print(sensor_data.quat[2], 3);
    Serial.print(", ");
    Serial.print(sensor_data.quat[3], 3);
    Serial.println();

    Serial.print("euler: ");
    Serial.print(sensor_data.euler[0], 3);
    Serial.print(", ");
    Serial.print(sensor_data.euler[1], 3);
    Serial.print(", ");
    Serial.print(sensor_data.euler[2], 3);
    Serial.println();

    Serial.println();
    */
}

void as5047d_init(void)
{
  //Set Pin Modes
  pinMode(AS5047D_SPI_CS, OUTPUT);
  pinMode(AS5047D_SPI_SI, OUTPUT);
  pinMode(AS5047D_SPI_SO, INPUT);
  pinMode(AS5047D_SPI_CLK, OUTPUT);
  //Set Slave Select High to Start i.e disable chip
  digitalWrite(AS5047D_SPI_CS, HIGH);
  //Initialize SPI 
  SPI.begin();
}

void as5047d_read_data(void)
{
  SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE1));
  
  //Send the Command Frame
  digitalWrite(AS5047D_SPI_CS, LOW);
  delayMicroseconds(1);
  SPI.transfer16(0xFFFF);
  digitalWrite(AS5047D_SPI_CS,HIGH);

  //Read data frame
  digitalWrite(AS5047D_SPI_CS, LOW);
  delayMicroseconds(1);
  as5047d_ang16 = SPI.transfer16(0xC000);
  digitalWrite(AS5047D_SPI_CS, HIGH);
  SPI.endTransaction();

  as5047d_ang16 = (as5047d_ang16 & (0x3FFF));
  as5047d_ang[0] = ((as5047d_ang16 >> 8) & (0x3F));
  as5047d_ang[1] = (as5047d_ang16 & (0xFF));
}
