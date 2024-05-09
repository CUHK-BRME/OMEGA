//reference https://lp-research.atlassian.net/wiki/spaces/LKB/pages/1941864458/LPMS3+Command+List

//LPBus packet format
//little endian 8N1 Uart
// 1st byte 0x3a
// 2nd - 3rd bytes uint16 device ID(default 1)
// 4th - 5th bytes uint16 command ID
// 6th - 7th bytes uint16 number of bytes for command parameters x
// 8th - 7+x bytes command parameters
// 7+x+1 - 7+x+2 checksum uint16 sum of 2nd to 7+x bytes
// 7+x+3 0x0d
// 7+x+4 0x0a
// SOURCE: https://blog.mbedded.ninja/programming/operating-systems/linux/linux-serial-ports-using-c-cpp/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <iostream>
// additional libraries for wiringpi
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "lpms_be2_USB.h"

char receiveBuf[128];
char sendBuf[128];
int sendBufNum;
int receiveBufNum;
int receiveState;
float imu_time;
float imu_acc[3];
float imu_gyro[3];
float imu_quat[4];
unsigned int encoder_bytes_ang;
float encoder_ang;

char buffer[4096];
int receiveBufNum_log[4096];
int receiveState_log[4096];

typedef union {
  uint8_t u8vals[4];
  uint32_t u32val;
  float fval;
} data_decoder;

int comm_init_usb() {
    struct termios newtio;
    bzero(&newtio, sizeof(newtio)); /* clear struct for new port settings */
    /* BAUDRATE: Set bps rate. You could also use cfsetispeed and cfsetospeed.
        CS8     : 8n1 (8bit,no parity,1 stopbit)
        CLOCAL  : local connection, no modem contol
        CREAD   : enable receiving characters */
    newtio.c_cflag = SERIAL_BAUDRATE | CS8 | CLOCAL | CREAD;
    newtio.c_iflag = IGNPAR;

    /*  Raw output  */
    newtio.c_oflag = 0;

    newtio.c_cc[VTIME] = 0;
    newtio.c_cc[VMIN] = 1;

    /* ICANON  : enable canonical input
        disable all echo functionality, and don't send signals to calling program */
    newtio.c_lflag = 0;

    // Load the pin configuration
    /* Open modem device for reading and writing and not as controlling tty
    because we don't want to get killed if linenoise sends CTRL-C. */
    int fd = open("/dev/ttyAMA0", O_RDWR | O_NOCTTY | O_NONBLOCK);
    if (fd < 0) { perror("/dev/ttyAMA0"); exit(-1); }

    /* now clean the modem line and activate the settings for the port */
    tcflush(fd, TCIFLUSH);
    tcsetattr(fd, TCSANOW, &newtio);

    return fd;
}

int comm_init() { // from wiringpi
    struct termios options ;
    int status, fd ;

    if ((fd = open ("/dev/serial0", O_RDWR | O_NOCTTY | O_NDELAY | O_NONBLOCK)) == -1)
        return -1 ;

    fcntl (fd, F_SETFL, O_RDWR) ;

    // Get and modify current options:

    tcgetattr (fd, &options) ;

        cfmakeraw   (&options) ;
        cfsetispeed (&options, SERIAL_BAUDRATE) ;
        cfsetospeed (&options, SERIAL_BAUDRATE) ;

        options.c_cflag |= (CLOCAL | CREAD) ;
        options.c_cflag &= ~PARENB ;
        options.c_cflag &= ~CSTOPB ;
        options.c_cflag &= ~CSIZE ;
        options.c_cflag |= CS8 ;
        options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG) ;
        options.c_oflag &= ~OPOST ;

        options.c_cc [VMIN]  =   0 ;
        options.c_cc [VTIME] = 100 ;	// Ten seconds (100 deciseconds)

    tcsetattr (fd, TCSANOW, &options) ;

    ioctl (fd, TIOCMGET, &status);

    status |= TIOCM_DTR ;
    status |= TIOCM_RTS ;

    ioctl (fd, TIOCMSET, &status);

    usleep (10000) ;	// 10mS

    return fd ;
}

int comm_init_uart1() { // from medium
    int serial_port = open("/dev/serial0", O_RDWR);
    struct termios tty;
    if(tcgetattr(serial_port, &tty) != 0) {
        printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
        return 1;
    }
    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag &= ~CRTSCTS;
    tty.c_cflag |= CREAD | CLOCAL;
    tty.c_lflag &= ~ICANON;
    tty.c_lflag &= ~ECHO;
    tty.c_lflag &= ~ECHOE;
    tty.c_lflag &= ~ECHONL;
    tty.c_lflag &= ~ISIG;
    tty.c_iflag &= ~(IXON | IXOFF | IXANY);
    tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL);
    tty.c_oflag &= ~OPOST;
    tty.c_oflag &= ~ONLCR;
    tty.c_cc[VTIME] = 10;
    tty.c_cc[VMIN] = 0;
    cfsetispeed(&tty, B115200);
    cfsetospeed(&tty, B115200);
    if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
        printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
        return 1;
    }
    return serial_port;
}

void imu_init(int fd) {
    imu_time = 0;
    for (int i=0;i<3;i++) {
        imu_acc[i] = 0;
        imu_gyro[i] = 0;
        imu_quat[i] = 0;
    }
    imu_quat[3] = 0;
    /*
    setGyroCommandMode(fd);
    sleep(1);
    tcflush(fd, TCIOFLUSH);
    setGyroStreamFreq(fd, LPMS_STREAM_FREQ_500HZ);
    sleep(1);
    setGyroDataEnable(fd, LPMS_RAW_ACC_OUTPUT_ENABLED | LPMS_RAW_GYR_OUTPUT_ENABLED);
    //setGyroDataEnable(fd, LPMS_QUAT_OUTPUT_ENABLED);
    sleep(1);
    setFilterMode(fd);
    sleep(1);
    setAccRange(fd);
    sleep(1);
    setGyroDataFast(fd);
    sleep(1);
    setGyroStreamMode(fd);
    */
    return;
}

void encoder_init() {
    encoder_bytes_ang = 0;
    encoder_ang = 0;
}

void imu_read(int fd) {
    /*
    char dummy = 'a';
    write(fd, &dummy, 1);
    usleep(1000);
    read(fd, &buffer, 1);
    imu_time = imu_time + 0.002;*/
    //usleep(1000);
    int result, ret, i;
    char receive_byte;
    //ret = read(fd, &buffer, sizeof(buffer));
    if (ioctl (fd, FIONREAD, &result) == -1) {
        ret = -1;
    }
    else {
        ret = result;
    }
    imu_time = ret*1.0;
    if (ret > 0) {
        //receiveBufNum = 0;
        for (i = 0; i < ret; i++) {
            read(fd, &receive_byte, 1);
            buffer[i] = receive_byte;
            receiveBufNum_log[i] = receiveBufNum;
            receiveState_log[i] = receiveState;
            //receive_byte = buffer[i];
            switch (receiveState) {
                case 0:
                    if (receive_byte == 0x3a) {
                        receiveState++;
                    }
                    break;
                case 1:
                    if (receive_byte == 0x01) {  // device ID low byte
                        receiveState++;
                        receiveBuf[receiveBufNum++] = receive_byte;
                    }
                    else {
                        receiveState = 0;
                        receiveBufNum = 0;
                    }
                    break;
                case 2:
                    if (receive_byte == 0x00) { // device ID high byte
                        receiveState++;
                        receiveBuf[receiveBufNum++] = receive_byte;
                    }
                    else {
                        receiveState = 0;
                        receiveBufNum = 0;
                    }
                    break;
                case 3:
                    if (receive_byte == 0x09) {  // get data command ID low byte
                    receiveState++;
                    receiveBuf[receiveBufNum++] = receive_byte;
                    }
                    else {
                    receiveState = 0;
                    receiveBufNum = 0;
                    }
                    break;
                case 4:
                    if (receive_byte == 0x00) {  // get data command ID high byte
                        receiveState++;
                        receiveBuf[receiveBufNum++] = receive_byte;
                    }
                    else {
                        receiveState = 0;
                        receiveBufNum = 0;
                    }
                    break;
                case 5:
                    if (receive_byte == 0x1A) {   // number of data byte low byte (16 byte, 4 for timestamp, 12 for 6 acc/gyro data, 2 for checksum)
                    //if (receive_byte == 0x0C) {   // number of data byte low byte (12 byte, 4 for timestamp, 8 for 4 quat data, 2 for checksum)
                        receiveState++;
                        receiveBuf[receiveBufNum++] = receive_byte;
                    }
                    else {
                        receiveState = 0;
                        receiveBufNum = 0;
                    }
                    break;
                case 6:
                    if (receive_byte == 0x00) {   // number of data byte HIGH byte
                        receiveState++;
                        receiveBuf[receiveBufNum++] = receive_byte;
                    }
                    else {
                        receiveState = 0;
                        receiveBufNum = 0;
                    }
                    break;
                case 7:
                    receiveBuf[receiveBufNum++] = receive_byte;  //get 12 data byte for quat output //get 16 data byte for acc/gyro output
                    if (receiveBufNum >= 32) {
                    //if (receiveBufNum >= 18) {
                        receiveState++;
                    }
                    break;
                case 8:
                    receiveBuf[receiveBufNum++] = receive_byte;   // get checksum byte
                    if (receiveBufNum >= 34) {
                    //if (receiveBufNum >= 20) {
                        receiveState++;
                    }
                    break;
                case 9:
                    if (receive_byte == 0x0d) {  // ending indicator
                        receiveState++;
                        receiveBuf[receiveBufNum++] = receive_byte;
                    }
                    else {
                        receiveState = 0;
                        receiveBufNum = 0;
                    }
                    break;
                case 10:
                    receiveBuf[receiveBufNum++] = receive_byte;
                    receiveState = 0;
                    receiveBufNum = 0;
                    if (receive_byte == 0x0a) {                  // ending indicator
                        uint16_t checksum = receiveBuf[32] | (receiveBuf[33] << 8);
                        //uint16_t checksum = receiveBuf[18] | (receiveBuf[19] << 8);
                        uint16_t checksum1 = 0;
                        for (int j = 0; j < 32; j++) {
                        //for (int j = 0; j < 18; j++) {
                            checksum1 += receiveBuf[j];
                        }
                        if (checksum1 == checksum) {
                            //imu_time = ((uint32_t)(receiveBuf[6] | (receiveBuf[7] << 8) | (receiveBuf[8] << 16) | (receiveBuf[9] << 24)))*0.002;
                            for (int j = 0; j < 3; j++) {
                            //for (int j = 0; j < 4; j++) {
                                imu_acc[j] = uint8_to_float(receiveBuf[6 + 4*j],receiveBuf[7 + 4*j],receiveBuf[8 + 4*j],receiveBuf[9 + 4*j]);
                                imu_gyro[j] = uint8_to_float(receiveBuf[6 + 12 + 4*j],receiveBuf[7 + 12 + 4*j],receiveBuf[8 + 12 + 4*j],receiveBuf[9 + 12 + 4*j]);
                                //imu_acc[j] = (float)((int16_t)((receiveBuf[10 + 2*j] | (receiveBuf[11 + 2*j] << 8)))) / 1000;
                                //imu_gyro[j] = (float)((int16_t)((receiveBuf[10 + 6 + 2*j] | (receiveBuf[11 + 6 + 2*j] << 8))))/10;
                                //imu_quat[j] = (float)((int16_t)((receiveBuf[10 + 2*j] | (receiveBuf[11 + 2*j] << 8)))) / 10000;
                            }
                            encoder_bytes_ang = (receiveBuf[6 + 12 + 12] << 8) | receiveBuf[6 + 12 + 12 + 1];
                            encoder_ang = ((unsigned long) encoder_bytes_ang)*360.0/16384.0;

                        }
                        else {
                            // no update
                        }
                    }
                    break;
            }
        }
    }
}

void comm_close(int fd) {
	close(fd);
}

void setGyroCommandMode(int fd) {
  initGyroBuf();
  gyroBufferAppendInt16(GOTO_COMMAND_MODE);
  gyroBufferAppendInt16(0);
  gyroBufferAppendCheckSum();
  endGyroBuf();
  sendGyroBuf(fd);
  return;
}

void setGyroStreamMode(int fd) {
  initGyroBuf();
  gyroBufferAppendInt16(GOTO_STREAM_MODE);
  gyroBufferAppendInt16(0);
  gyroBufferAppendCheckSum();
  endGyroBuf();
  sendGyroBuf(fd);
  return;
}

void setGyroStreamFreq(int fd, uint32_t target) {
  if (target == LPMS_STREAM_FREQ_5HZ || target == LPMS_STREAM_FREQ_10HZ || target == LPMS_STREAM_FREQ_50HZ || target == LPMS_STREAM_FREQ_100HZ || target == LPMS_STREAM_FREQ_250HZ || target == LPMS_STREAM_FREQ_500HZ) {
    initGyroBuf();
    gyroBufferAppendInt16(SET_STREAM_FREQ);
    gyroBufferAppendInt16(4);
    gyroBufferAppendInt32(target);
    gyroBufferAppendCheckSum();
    endGyroBuf();
    sendGyroBuf(fd);
  }
  return;
}

void setGyroDataEnable(int fd, uint32_t target) {
    initGyroBuf();
    gyroBufferAppendInt16(SET_IMU_TRANSMIT_DATA);
    gyroBufferAppendInt16(4);
    gyroBufferAppendInt32(target);
    gyroBufferAppendCheckSum();
    endGyroBuf();
    sendGyroBuf(fd);
    return;
}

void setFilterMode(int fd) { // set filter mode to gyro only
    initGyroBuf();
    gyroBufferAppendInt16(SET_FILTER_MODE);
    gyroBufferAppendInt16(4);
    gyroBufferAppendInt32(0);
    gyroBufferAppendCheckSum();
    endGyroBuf();
    sendGyroBuf(fd);
}

void setGyroDataFast(int fd) { //change precision from float 32 to uint16 for faster speed
    initGyroBuf();
    gyroBufferAppendInt16(SET_LPBUS_DATA_PRECISION);
    gyroBufferAppendInt16(4);
    gyroBufferAppendInt32(0);
    gyroBufferAppendCheckSum();
    endGyroBuf();
    sendGyroBuf(fd);
    return;
}

void setAccRange(int fd) {
  initGyroBuf();
  gyroBufferAppendInt16(SET_ACC_RANGE);
  gyroBufferAppendInt16(4);
  gyroBufferAppendInt32(16);
  gyroBufferAppendCheckSum();
  endGyroBuf();
  sendGyroBuf(fd);
}

void initGyroBuf() {
  sendBufNum = 0;
  sendBuf[sendBufNum++] = 0x3a;
  gyroBufferAppendInt16(DEVICE_ID);
  return;
}

void gyroBufferAppendInt16(uint16_t target) {
  sendBuf[sendBufNum++] = target & 0xff;
  sendBuf[sendBufNum++] = target >> 8;
  return;
}

void gyroBufferAppendInt32(uint32_t target) {
  sendBuf[sendBufNum++] = target & 0xff;
  sendBuf[sendBufNum++] = target >> 8;
  sendBuf[sendBufNum++] = target >> 16;
  sendBuf[sendBufNum++] = target >> 24;
  return;
}

void gyroBufferAppendCheckSum() {
  uint16_t sum = 0;
  for (int i = 1; i < sendBufNum; i++) {
    sum += sendBuf[i];
  }
  gyroBufferAppendInt16(sum);
  return;

}
void endGyroBuf() {
  sendBuf[sendBufNum++] = 0x0d;
  sendBuf[sendBufNum++] = 0x0a;
  return;
}

void sendGyroBuf(int fd) {
    write(fd, sendBuf, sendBufNum);
    return;
}

float uint8_to_float(uint8_t a,uint8_t b,uint8_t c,uint8_t d){
   data_decoder decoder;
   decoder.u8vals[0] = a;
   decoder.u8vals[1] = b;
   decoder.u8vals[2] = c;
   decoder.u8vals[3] = d;
   return decoder.fval;
}