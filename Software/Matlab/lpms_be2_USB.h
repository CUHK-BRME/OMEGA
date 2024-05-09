#include <math.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <iostream>

#define MAX_BYTE_NUM 128
#define DEVICE_ID 1
//LPMS Command list
#define COMMAND_START_ADDRESS   0
//Acknowledged / Not-acknowledged Identifiers
#define REPLY_ACK                           (COMMAND_START_ADDRESS + 0)
#define REPLY_NACK                          (COMMAND_START_ADDRESS + 1)
//Register Value Save and Reset Command
#define WRITE_REGISTERS                     (COMMAND_START_ADDRESS + 4)
#define RESTORE_FACTORY_VALUE               (COMMAND_START_ADDRESS + 5)
//Mode Switching Commands
#define GOTO_COMMAND_MODE                   (COMMAND_START_ADDRESS + 6)
#define GOTO_STREAM_MODE                    (COMMAND_START_ADDRESS + 7)
//Sensor Status Command
#define GET_SENSOR_STATUS                   (COMMAND_START_ADDRESS + 8)
//Get Data Commands
#define GET_IMU_DATA                        (COMMAND_START_ADDRESS + 9)
//Device Info
#define GET_SENSOR_MODEL                    (COMMAND_START_ADDRESS + 20)
#define GET_FIRMWARE_INFO                   (COMMAND_START_ADDRESS + 21)
#define GET_SERIAL_NUMBER                   (COMMAND_START_ADDRESS + 22)
#define GET_FILTER_VERSION                  (COMMAND_START_ADDRESS + 23)

//Data Transmission Commands
#define SET_IMU_TRANSMIT_DATA               (COMMAND_START_ADDRESS + 30)
#define GET_IMU_TRANSMIT_DATA               (COMMAND_START_ADDRESS + 31)

//IMU ID Settings Commands
#define SET_IMU_ID                          (COMMAND_START_ADDRESS + 32)
#define GET_IMU_ID                          (COMMAND_START_ADDRESS + 33)

//Stream Frequency Commands
#define SET_STREAM_FREQ                     (COMMAND_START_ADDRESS + 34)
#define GET_STREAM_FREQ                     (COMMAND_START_ADDRESS + 35)

// Deg/Rad Output Commands
#define SET_DEGRAD_OUTPUT                   (COMMAND_START_ADDRESS + 36)
#define GET_DEGRAD_OUTPUT                   (COMMAND_START_ADDRESS + 37)

// Reference Setting and Offset Reset Commands
#define SET_ORIENTATION_OFFSET              (COMMAND_START_ADDRESS + 38)
#define RESET_ORIENTATION_OFFSET            (COMMAND_START_ADDRESS + 39)

//Accelerometer Settings Commands
#define SET_ACC_RANGE                       (COMMAND_START_ADDRESS + 50)
#define GET_ACC_RANGE                       (COMMAND_START_ADDRESS + 51)

// Gyroscope Settings Commands
#define SET_GYR_RANGE                       (COMMAND_START_ADDRESS + 60)
#define GET_GYR_RANGE                       (COMMAND_START_ADDRESS + 61)
#define START_GYR_CALIBRA                   (COMMAND_START_ADDRESS + 62)
#define SET_ENABLE_GYR_AUTOCALIBRATION      (COMMAND_START_ADDRESS + 64)
#define GET_ENABLE_GYR_AUTOCALIBRATION      (COMMAND_START_ADDRESS + 65)

// Magnetometer Settings Commands (no magnetometer for be1)
#define SET_MAG_RANGE                       (COMMAND_START_ADDRESS + 70)
#define GET_MAG_RANGE                       (COMMAND_START_ADDRESS + 71)
#define START_MAG_CALIBRATION               (COMMAND_START_ADDRESS + 84)
#define STOP_MAG_CALIBRATION                (COMMAND_START_ADDRESS + 85)
#define SET_MAG_CALIBRATION_TIMEOUT         (COMMAND_START_ADDRESS + 86)
#define GET_MAG_CALIBRATION_TIMEOUT         (COMMAND_START_ADDRESS + 87)

//Filter Settings Command
#define SET_FILTER_MODE                     (COMMAND_START_ADDRESS + 90)
#define GET_FILTER_MODE                     (COMMAND_START_ADDRESS + 91)

//UART / RS232 Settings Command
#define SET_UART_BAUDRATE                   (COMMAND_START_ADDRESS + 130)
#define GET_UART_BAUDRATE                   (COMMAND_START_ADDRESS + 131)
#define SET_UART_FORMAT                     (COMMAND_START_ADDRESS + 132)
#define GET_UART_FORMAT                     (COMMAND_START_ADDRESS + 133)
#define SET_UART_ASCII_CHARACTER            (COMMAND_START_ADDRESS + 134)
#define GET_UART_ASCII_CHARACTER            (COMMAND_START_ADDRESS + 135)
#define SET_LPBUS_DATA_PRECISION            (COMMAND_START_ADDRESS + 136)
#define GET_LPBUS_DATA_PRECISION            (COMMAND_START_ADDRESS + 137)

// Software Sync
#define START_SYNC                          (COMMAND_START_ADDRESS + 150)
#define STOP_SYNC                           (COMMAND_START_ADDRESS + 151)

//Sensor Data Timestamp Manipulation
#define SET_TIMESTAMP                       (COMMAND_START_ADDRESS + 152)

// Stream frequency data values
#define LPMS_STREAM_FREQ_5HZ                    (uint32_t)5
#define LPMS_STREAM_FREQ_10HZ                   (uint32_t)10
#define LPMS_STREAM_FREQ_50HZ                   (uint32_t)50
#define LPMS_STREAM_FREQ_100HZ                  (uint32_t)100
#define LPMS_STREAM_FREQ_250HZ                  (uint32_t)250
#define LPMS_STREAM_FREQ_500HZ                  (uint32_t)500

#define LPMS_UART_BAUDRATE_MASK                 0x000000ff
#define LPMS_UART_BAUDRATE_19200                0x00
#define LPMS_UART_BAUDRATE_38400                0x01
#define LPMS_UART_BAUDRATE_57600                0x02
#define LPMS_UART_BAUDRATE_115200               0x03
#define LPMS_UART_BAUDRATE_230400               0x04
#define LPMS_UART_BAUDRATE_256000               0x05
#define LPMS_UART_BAUDRATE_460800               0x06
#define LPMS_UART_BAUDRATE_921600               0x07

#define LPMS_RAW_ACC_OUTPUT_ENABLED              (uint32_t)(0x00000001 << 0)
#define LPMS_ACC_OUTPUT_ENABLED                  (uint32_t)(0x00000001 << 1)
#define LPMS_RAW_GYR_OUTPUT_ENABLED              (uint32_t)(0x00000001 << 3)
#define LPMS_BIAS_CAL_GYRO_OUTPUT_ENABLED        (uint32_t)(0x00000001 << 5)
#define LPMS_BIAS_ALG_CAL_GYR_OUTPUT_ENABLED     (uint32_t)(0x00000001 << 7)
#define LPMS_ANG_VEL_OUTPUT_ENABLED              (uint32_t)(0x00000001 << 10)
#define LPMS_QUAT_OUTPUT_ENABLED                 (uint32_t)(0x00000001 << 11)
#define LPMS_EULER_OUTPUT_ENABLED                (uint32_t)(0x00000001 << 12)
#define LPMS_LIN_ACC_OUTPUT_ENABLED              (uint32_t)(0x00000001 << 13)
#define LPMS_TEMP_OUTPUT_ENABLED                 (uint32_t)(0x00000001 << 16)

#define SERIAL_BAUDRATE B230400   // Change as needed, keep B

int comm_init();
void comm_close(int fd);
void imu_init(int fd);
void imu_read(int fd);
void encoder_init(void);

void setGyroCommandMode(int fd);
void setGyroStreamMode(int fd);
void setGyroStreamFreq(int fd, uint32_t target);
void setGyroDataEnable(int fd, uint32_t target);
void setFilterMode(int fd);
void setGyroDataFast(int fd);
void setAccRange(int fd);
void initGyroBuf(void);
void gyroBufferAppendInt16(uint16_t target);
void gyroBufferAppendInt32(uint32_t target);
void gyroBufferAppendCheckSum(void);
void endGyroBuf(void);
void sendGyroBuf(int fd);
float uint8_to_float(uint8_t a,uint8_t b,uint8_t c,uint8_t d);