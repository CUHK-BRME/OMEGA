/***********************************************************************
**
** Copyright (C) 2020 LP-Research
** All rights reserved.
** Contact: LP-Research (info@lp-research.com)
**
***********************************************************************/

#ifndef LPMS_BE1_H
#define LPMS_BE1_H

#include "Arduino.h"




/* Interface selection */
//#define BE1_USE_SPI
#define BE1_USE_I2C


/* SPI interface configuration */
#define BE1_SPI_CS                  10
#define BE1_SPI_FREQUENCY           4000000


/* I2C interface configuration */ 
#define BE1_I2C_FREQUENCY           400000
#define BE1_I2C_ADRRESS             0x32




/*
 *  System Register {
 */

// Memory map
#define LPMS_SYS_REG_BASE                       0
#define LPMS_SYS_REG_SIZE                       128
#define LPMS_CONFIG_BASE                        LPMS_SYS_REG_BASE
#define LPMS_CONFIG_SIZE                        32
#define LPMS_DATA_BASE                          (LPMS_SYS_REG_BASE + LPMS_CONFIG_SIZE)
#define LPMS_DATA_SIZE                          84
#define LPMS_INFO_BASE                          (LPMS_SYS_REG_BASE + LPMS_CONFIG_SIZE + LPMS_DATA_SIZE)
#define LPMS_INFO_SIZE                          (LPMS_SYS_REG_SIZE - LPMS_CONFIG_SIZE - LPMS_DATA_SIZE)


//Config registers
#define STATUS                                  (LPMS_CONFIG_BASE + 0)
#define FUN_CONFIG                              (LPMS_CONFIG_BASE + 1)
#define SYS_CONFIG                              (LPMS_CONFIG_BASE + 2)
#define DATA_CTRL                               (LPMS_CONFIG_BASE + 3)
#define DATA_ENABLE                             (LPMS_CONFIG_BASE + 4)
#define CTRL_0_A                                (LPMS_CONFIG_BASE + 5)
#define CTRL_1_G                                (LPMS_CONFIG_BASE + 6)
#define FILTER_CONFIG                           (LPMS_CONFIG_BASE + 7)
#define OFFSET_SETTING                          (LPMS_CONFIG_BASE + 8)

//Data registers
#define TIMESTAMP_0                             (LPMS_DATA_BASE + 0)
#define TIMESTAMP_1                             (LPMS_DATA_BASE + 1)
#define TIMESTAMP_2                             (LPMS_DATA_BASE + 2)
#define TIMESTAMP_3                             (LPMS_DATA_BASE + 3)
#define ACC_X_0                                 (LPMS_DATA_BASE + 4)
#define ACC_X_1                                 (LPMS_DATA_BASE + 5)
#define ACC_X_2                                 (LPMS_DATA_BASE + 6)
#define ACC_X_3                                 (LPMS_DATA_BASE + 7)
#define ACC_Y_0                                 (LPMS_DATA_BASE + 8)
#define ACC_Y_1                                 (LPMS_DATA_BASE + 9)
#define ACC_Y_2                                 (LPMS_DATA_BASE + 10)
#define ACC_Y_3                                 (LPMS_DATA_BASE + 11)
#define ACC_Z_0                                 (LPMS_DATA_BASE + 12)
#define ACC_Z_1                                 (LPMS_DATA_BASE + 13)
#define ACC_Z_2                                 (LPMS_DATA_BASE + 14)
#define ACC_Z_3                                 (LPMS_DATA_BASE + 15)
#define GYR_X_0                                 (LPMS_DATA_BASE + 16)
#define GYR_X_1                                 (LPMS_DATA_BASE + 17)
#define GYR_X_2                                 (LPMS_DATA_BASE + 18)
#define GYR_X_3                                 (LPMS_DATA_BASE + 19)
#define GYR_Y_0                                 (LPMS_DATA_BASE + 20)
#define GYR_Y_1                                 (LPMS_DATA_BASE + 21)
#define GYR_Y_2                                 (LPMS_DATA_BASE + 22)
#define GYR_Y_3                                 (LPMS_DATA_BASE + 23)
#define GYR_Z_0                                 (LPMS_DATA_BASE + 24)
#define GYR_Z_1                                 (LPMS_DATA_BASE + 25)
#define GYR_Z_2                                 (LPMS_DATA_BASE + 26)
#define GYR_Z_3                                 (LPMS_DATA_BASE + 27)

#define QUAT_W_0                                (LPMS_DATA_BASE + 40)
#define QUAT_W_1                                (LPMS_DATA_BASE + 41)
#define QUAT_W_2                                (LPMS_DATA_BASE + 42)
#define QUAT_W_3                                (LPMS_DATA_BASE + 43)
#define QUAT_X_0                                (LPMS_DATA_BASE + 44)
#define QUAT_X_1                                (LPMS_DATA_BASE + 45)
#define QUAT_X_2                                (LPMS_DATA_BASE + 46)
#define QUAT_X_3                                (LPMS_DATA_BASE + 47)
#define QUAT_Y_0                                (LPMS_DATA_BASE + 48)
#define QUAT_Y_1                                (LPMS_DATA_BASE + 49)
#define QUAT_Y_2                                (LPMS_DATA_BASE + 50)
#define QUAT_Y_3                                (LPMS_DATA_BASE + 51)
#define QUAT_Z_0                                (LPMS_DATA_BASE + 52)
#define QUAT_Z_1                                (LPMS_DATA_BASE + 53)
#define QUAT_Z_2                                (LPMS_DATA_BASE + 54)
#define QUAT_Z_3                                (LPMS_DATA_BASE + 55)
#define EULER_X_0                               (LPMS_DATA_BASE + 56)
#define EULER_X_1                               (LPMS_DATA_BASE + 57)
#define EULER_X_2                               (LPMS_DATA_BASE + 58)
#define EULER_X_3                               (LPMS_DATA_BASE + 59)
#define EULER_Y_0                               (LPMS_DATA_BASE + 60)
#define EULER_Y_1                               (LPMS_DATA_BASE + 61)
#define EULER_Y_2                               (LPMS_DATA_BASE + 62)
#define EULER_Y_3                               (LPMS_DATA_BASE + 63)
#define EULER_Z_0                               (LPMS_DATA_BASE + 64)
#define EULER_Z_1                               (LPMS_DATA_BASE + 65)
#define EULER_Z_2                               (LPMS_DATA_BASE + 66)
#define EULER_Z_3                               (LPMS_DATA_BASE + 67)
#define LIN_ACC_X_0                             (LPMS_DATA_BASE + 68)
#define LIN_ACC_X_1                             (LPMS_DATA_BASE + 69)
#define LIN_ACC_X_2                             (LPMS_DATA_BASE + 70)
#define LIN_ACC_X_3                             (LPMS_DATA_BASE + 71)
#define LIN_ACC_Y_0                             (LPMS_DATA_BASE + 72)
#define LIN_ACC_Y_1                             (LPMS_DATA_BASE + 73)
#define LIN_ACC_Y_2                             (LPMS_DATA_BASE + 74)
#define LIN_ACC_Y_3                             (LPMS_DATA_BASE + 75)
#define LIN_ACC_Z_0                             (LPMS_DATA_BASE + 76)
#define LIN_ACC_Z_1                             (LPMS_DATA_BASE + 77)
#define LIN_ACC_Z_2                             (LPMS_DATA_BASE + 78)
#define LIN_ACC_Z_3                             (LPMS_DATA_BASE + 79)
#define TEMP_0                                  (LPMS_DATA_BASE + 80)
#define TEMP_1                                  (LPMS_DATA_BASE + 81)
#define TEMP_2                                  (LPMS_DATA_BASE + 82)
#define TEMP_3                                  (LPMS_DATA_BASE + 83)

//System information registers
#define LP_WHO_AM_I                             (LPMS_INFO_BASE + 0)
#define FIRMWARE_VER_0                          (LPMS_INFO_BASE + 1)
#define FIRMWARE_VER_1                          (LPMS_INFO_BASE + 2)

/*
 *  } System Register
 */




/*
 *  Register define {
 */

//Status
#define LPMS_DATA_READY                         ((uint8_t)0x01 << 0)
#define LPMS_GYR_IS_CALIBRATING                 ((uint8_t)0x01 << 4)


//Function config
#define LPMS_FUN_CONFIG_MASK                    ((uint8_t)0x80)
#define LPMS_FUN_CFG_EN                         ((uint8_t)0x01 << 7)


//System config
#define LPMS_SYS_CONFIG_MASK                    ((uint8_t)0xC0)
#define LPMS_SYS_REBOOT                         ((uint8_t)0x01 << 6)
#define LPMS_SYS_RESET                          ((uint8_t)0x01 << 7)


//Data control
#define LPMS_DATA_CTRL_MASK                     ((uint8_t)0x6F)

#define LPMS_DATA_FREQ_MASK                     ((uint8_t)0x0F << 0)
#define LPMS_DATA_FREQ_5HZ                      ((uint8_t)0x00 << 0)
#define LPMS_DATA_FREQ_10HZ                     ((uint8_t)0x01 << 0)
#define LPMS_DATA_FREQ_50HZ                     ((uint8_t)0x02 << 0)
#define LPMS_DATA_FREQ_100HZ                    ((uint8_t)0x03 << 0)
#define LPMS_DATA_FREQ_250HZ                    ((uint8_t)0x04 << 0)
#define LPMS_DATA_FREQ_500HZ                    ((uint8_t)0x05 << 0)

#define LPMS_RESET_TIME                         ((uint8_t)0x01 << 5)
#define LPMS_RADIAN_OUTPUT                      ((uint8_t)0x01 << 6)


//Data enable
#define LPMS_DATA_EN_MASK                       ((uint8_t)0xF7)
#define LPMS_TIME_EN                            ((uint8_t)0x01 << 0)
#define LPMS_ACC_EN                             ((uint8_t)0x01 << 1)
#define LPMS_GYR_EN                             ((uint8_t)0x01 << 2)
#define LPMS_QUAT_EN                            ((uint8_t)0x01 << 4)
#define LPMS_EULER_EN                           ((uint8_t)0x01 << 5)
#define LPMS_LINACC_EN                          ((uint8_t)0x01 << 6)
#define LPMS_TEMP_EN                            ((uint8_t)0x01 << 7)
#define LPMS_ALL_DATA_EN                        ((uint8_t)0xF7)


//CONTROL 0 ACC
#define LPMS_ACC_MASK                           ((uint8_t)0x1C)

#define LPMS_ACC_FS_MASK                        ((uint8_t)0x03 << 2)
#define LPMS_ACC_FS_2G                          ((uint8_t)0x00 << 2)
#define LPMS_ACC_FS_4G                          ((uint8_t)0x01 << 2)
#define LPMS_ACC_FS_8G                          ((uint8_t)0x02 << 2)
#define LPMS_ACC_FS_16G                         ((uint8_t)0x03 << 2)

#define LPMS_ACC_OUTPUT_CALIBRATED              ((uint8_t)0x01 << 4)


//CONTROL 1 GYR
#define LPMS_GYR_MASK                           ((uint8_t)0xBE)

#define LPMS_GYR_FS_MASK                        ((uint8_t)0x07 << 1)
#define LPMS_GYR_FS_125DPS                      ((uint8_t)0x00 << 1)
#define LPMS_GYR_FS_250DPS                      ((uint8_t)0x01 << 1)
#define LPMS_GYR_FS_500DPS                      ((uint8_t)0x02 << 1)
#define LPMS_GYR_FS_1000DPS                     ((uint8_t)0x03 << 1)
#define LPMS_GYR_FS_2000DPS                     ((uint8_t)0x04 << 1)

#define LPMS_GYR_OUTPUT_MASK                    ((uint8_t)0x03 << 4)
#define LPMS_GYR_OUTPUT_RAW                     ((uint8_t)0x00 << 4)
#define LPMS_GYR_OUTPUT_BIAS_CALIBRATED         ((uint8_t)0x01 << 4)
#define LPMS_GYR_OUTPUT_ALIGNMENT_CALIBRATED    ((uint8_t)0x02 << 4)

#define LPMS_GYR_CALIBRA                        ((uint8_t)0x01 << 7)


//Filter config
#define LPMS_FILTER_CINFIG_MASK                 ((uint8_t)0x3F)

#define LPMS_FILTER_MODE_MASK                   ((uint8_t)0x07 << 0)
#define LPMS_FILTER_MODE_GYR                    ((uint8_t)0x00 << 0)
#define LPMS_FILTER_MODE_KALMAN_GYR_ACC         ((uint8_t)0x01 << 0)
#define LPMS_FILTER_MODE_DCM_GYR_ACC            ((uint8_t)0x03 << 0)

#define LPMS_LOW_PASS_MASK                      ((uint8_t)0x07 << 3)
#define LPMS_LOW_PASS_OFF                       ((uint8_t)0x00 << 3)
#define LPMS_LOW_PASS_ALPHA_01                  ((uint8_t)0x01 << 3)
#define LPMS_LOW_PASS_ALPHA_005                 ((uint8_t)0x02 << 3)
#define LPMS_LOW_PASS_ALPHA_001                 ((uint8_t)0x03 << 3)
#define LPMS_LOW_PASS_ALPHA_0005                ((uint8_t)0x04 << 3)
#define LPMS_LOW_PASS_ALPHA_0001                ((uint8_t)0x05 << 3)


//Offset Setting
#define LPMS_OFFSET_SETTING_MASK                ((uint8_t)0x0F)
#define LPMS_OBJECT_RESET                       ((uint8_t)0x01 << 0)
#define LPMS_HEADING_RESET                      ((uint8_t)0x01 << 1)
#define LPMS_ALIGNMENT_RESET                    ((uint8_t)0x01 << 2)
#define LPMS_RESET_OFFSET                       ((uint8_t)0x01 << 3)

/*
 *  } Register define
 */


typedef enum {
    BE1_ERROR = 0,
    BE1_OK = 1
} be1_status_t;

typedef union {
    uint8_t u8vals[4];
    uint32_t u32val;
    float fval;
} data_decoder;

/*
typedef struct {
    uint32_t timestamp;
    float acc[3];
    float gyro[3];
    float euler[3];
    float quat[4];
    float linAcc[3];
    float temp;
} sensor_data_t;
*/
typedef struct {
    uint32_t timestamp;
    uint8_t acc[12];
    uint8_t gyro[12];
    float euler[3];
    float quat[4];
    float linAcc[3];
    float temp;
} sensor_data_t;


class LPMS_BE1
{
public:   
    LPMS_BE1();

    void setup(void);

    void set_config_enable(void);
    void set_config_disable(void);

    /*
        Configure output data
        Param:
            - LPMS_TIME_EN    : enable timestamp output
            - LPMS_ACC_EN     : enable accelerometer output
            - LPMS_GYR_EN     : enable gyro output
            - LPMS_QUAT_EN    : enable quaternion output
            - LPMS_EULER_EN   : enable euler output
            - LPMS_LINACC_EN  : enable linear acceleration output
            - LPMS_TEMP_EN    : enable temperature output
            - LPMS_ALL_DATA_EN: enable all data output
        Return: 
            - BE1_OK: success
            - BE1_ERROR: fail
    */
    be1_status_t set_data_output(uint8_t data_en);
    /*
        Configure output data frequency
        Param:
            - LPMS_DATA_FREQ_5HZ
            - LPMS_DATA_FREQ_10HZ
            - LPMS_DATA_FREQ_50HZ
            - LPMS_DATA_FREQ_100HZ
            - LPMS_DATA_FREQ_250HZ
            - LPMS_DATA_FREQ_500HZ
        Return: 
            - BE1_OK: success
            - BE1_ERROR: fail
    */
    be1_status_t set_data_freq(uint8_t freq);

    /*
        Configure accelerometer output range
        Param:
            - LPMS_ACC_FS_2G
            - LPMS_ACC_FS_4G
            - LPMS_ACC_FS_8G
            - LPMS_ACC_FS_16G
        Return: 
            - BE1_OK: success
            - BE1_ERROR: fail
    */
    be1_status_t set_acc_range(uint8_t range);

    /*
        Configure gyroscope output range
        Param:
            - LPMS_GYR_FS_125DPS
            - LPMS_GYR_FS_250DPS
            - LPMS_GYR_FS_500DPS
            - LPMS_GYR_FS_1000DPS
            - LPMS_GYR_FS_2000DPS
        Return: 
            - BE1_OK: success
            - BE1_ERROR: fail
    */
    be1_status_t set_gyro_range(uint8_t range);

    /*
        Set offset settings 
        Param:
            - LPMS_OBJECT_RESET: performs object reset
            - LPMS_HEADING RESET: performs heading reset
            - LPMS_ALIGNMENT_RESET: performs alignment reset
            - LPMS_RESET_OFFSET: resets offset settings to default
        Return: 
            - BE1_OK: success
            - BE1_ERROR: fail
    */
    be1_status_t set_offset(uint8_t offset);

    void get_timestamp(uint32_t *ts);
    //void get_acc(float *acc);
    //void get_gyro(float *gyro);
    void get_acc(uint8_t *acc);
    void get_gyro(uint8_t *gyro);
    void get_quat(float *quat);
    void get_euler(float *euler);
    void get_linacc(float *linacc);          // TODO
    void get_temp(float *temp);              // TODO
    void get_reg_data(uint8_t addr, uint8_t *buf, uint8_t len);

    // TODO: functions for other settings
    void sys_reset(void);
    void sys_reboot(void);
    be1_status_t set_output_format(uint8_t format); // radian or degree
    void reset_timestamp(void);
    be1_status_t set_acc_output_type(uint8_t type);   // raw data or calibration data
    be1_status_t set_gyro_output_type(uint8_t type);  // raw data or bias/alignment calibration data
    void start_gyro_calibration(void);
    be1_status_t set_filter_mode(uint8_t mode); // GYR or KAIMAN_GYR_ACC or DCM_GYR_ACC mode
   

private:
    float uint8_to_float(uint8_t *pu8vals);
    uint32_t uint8_to_uint32(uint8_t *pu8vals);

    // low level functions
    void read_register(uint8_t addr, uint8_t *buf, uint8_t len);
    void write_register(uint8_t addr, uint8_t *buf, uint8_t len);
    void wait_update(void);
    void wait_reset(void);
    void wait_reboot(void);
};


#endif
