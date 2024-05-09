/***********************************************************************
**
** Copyright (C) 2020 LP-Research
** All rights reserved.
** Contact: LP-Research (info@lp-research.com)
**
***********************************************************************/

#include "lpms_be1.h"

#include <SPI.h>
#include <Wire.h>


LPMS_BE1::LPMS_BE1()
{
#if defined BE1_USE_SPI
    // Setup SPI CS Pin
    pinMode(BE1_SPI_CS, OUTPUT);
    digitalWrite(BE1_SPI_CS, HIGH);
    
    SPI.begin();
    SPI.setDataMode(SPI_MODE0);
    SPI.setBitOrder(MSBFIRST);

#elif defined BE1_USE_I2C

    Wire.begin();

#endif
}

void LPMS_BE1::setup(void)
{
    set_config_enable();

    set_data_output(LPMS_ALL_DATA_EN);
    wait_update();

    set_data_freq(LPMS_DATA_FREQ_500HZ);
    wait_update();

    // Some other configurations here
    set_acc_range(LPMS_ACC_FS_16G);
    wait_update();

    set_gyro_range(LPMS_GYR_FS_2000DPS);
    wait_update();
    
    set_config_disable();
}

void LPMS_BE1::set_config_enable(void)
{
    uint8_t data = 0x80;
    write_register(FUN_CONFIG, &data, 1);
    wait_update();
}

void LPMS_BE1::set_config_disable(void)
{
    uint8_t data = 0x00;
    write_register(FUN_CONFIG, &data, 1);
    wait_update();
}

be1_status_t LPMS_BE1::set_data_output(uint8_t data_en)
{
    if (data_en != LPMS_TIME_EN   && 
        data_en != LPMS_ACC_EN    && 
        data_en != LPMS_GYR_EN    && 
        data_en != LPMS_QUAT_EN   && 
        data_en != LPMS_EULER_EN  && 
        data_en != LPMS_LINACC_EN && 
        data_en != LPMS_TEMP_EN   && 
        data_en != LPMS_ALL_DATA_EN)
        return BE1_ERROR;
    
    uint8_t data = data_en & LPMS_DATA_EN_MASK;
    write_register(DATA_ENABLE, &data, 1);
    return BE1_OK;
}

be1_status_t LPMS_BE1::set_data_freq(uint8_t freq)
{
    if (freq != LPMS_DATA_FREQ_5HZ &&
        freq != LPMS_DATA_FREQ_10HZ &&
        freq != LPMS_DATA_FREQ_50HZ &&
        freq != LPMS_DATA_FREQ_100HZ &&
        freq != LPMS_DATA_FREQ_250HZ &&
        freq != LPMS_DATA_FREQ_500HZ)
        return BE1_ERROR;

    uint8_t data = 0;
    read_register(DATA_CTRL, &data, 1);
    data &= ~LPMS_DATA_FREQ_MASK;
    data |= freq;
    write_register(DATA_CTRL, &data, 1);
    return BE1_OK;
}

be1_status_t LPMS_BE1::set_acc_range(uint8_t range)
{
    if (range != LPMS_ACC_FS_2G &&
        range != LPMS_ACC_FS_4G &&
        range != LPMS_ACC_FS_8G &&
        range != LPMS_ACC_FS_16G)
        return BE1_ERROR;

    uint8_t data = 0;
    read_register(CTRL_0_A, &data, 1);
    data &= ~LPMS_ACC_FS_MASK;
    data |= range;
    write_register(CTRL_0_A, &data, 1);
    return BE1_OK;
}

be1_status_t LPMS_BE1::set_gyro_range(uint8_t range)
{
    if (range != LPMS_GYR_FS_125DPS &&
        range != LPMS_GYR_FS_250DPS &&
        range != LPMS_GYR_FS_500DPS &&
        range != LPMS_GYR_FS_1000DPS &&
        range != LPMS_GYR_FS_2000DPS)
        return BE1_ERROR;

    uint8_t data = 0;
    read_register(CTRL_1_G, &data, 1);
    data &= ~LPMS_GYR_FS_MASK;
    data |= range;
    write_register(CTRL_1_G, &data, 1);
    return BE1_OK;
}

be1_status_t LPMS_BE1::set_offset(uint8_t offset)
{
    if (offset != LPMS_OBJECT_RESET &&
        offset != LPMS_HEADING_RESET &&
        offset != LPMS_ALIGNMENT_RESET &&
        offset != LPMS_RESET_OFFSET)
        return BE1_ERROR;

    uint8_t data = 0;
    data = offset;
    write_register(OFFSET_SETTING, &data, 1);
    wait_update();

    return BE1_OK;
}

void LPMS_BE1::get_timestamp(uint32_t *ts)
{
    uint8_t buf[4] = { 0 };
    read_register(TIMESTAMP_0, buf, 4);
    *ts = uint8_to_uint32(buf);
}

/*
void LPMS_BE1::get_acc(float *acc)
{
    uint8_t buf[12] = { 0 };
    read_register(ACC_X_0, buf, 12);
    for (int i = 0; i < 3; i++) {
        acc[i] = uint8_to_float(&buf[i*4]);
    }
}
*/
void LPMS_BE1::get_acc(uint8_t *acc)
{
    uint8_t buf[12] = { 0 };
    read_register(ACC_X_0, buf, 12);
    for (int i = 0; i < 12; i++) {
        acc[i] = buf[i];
    }
}

/*
void LPMS_BE1::get_gyro(float *gyro)
{
    uint8_t buf[12] = { 0 };
    read_register(GYR_X_0, buf, 12);
    for (int i = 0; i < 3; i++) {
        gyro[i] = uint8_to_float(&buf[i*4]);
    }
}
*/
void LPMS_BE1::get_gyro(uint8_t *gyro)
{
    uint8_t buf[12] = { 0 };
    read_register(GYR_X_0, buf, 12);
    for (int i = 0; i < 12; i++) {
        gyro[i] = buf[i];
    }
}

void LPMS_BE1::get_quat(float *quat)
{
    uint8_t buf[16] = { 0 };
    read_register(QUAT_W_0, buf, 16);
    for (int i = 0; i < 4; i++) {
        quat[i] = uint8_to_float(&buf[i*4]);
    }
}

void get_linacc(float *linacc)
{
    // TODO
}

void get_temp(float *temp)
{
    // TODO
}

void LPMS_BE1::get_euler(float *euler)
{
    uint8_t buf[12] = { 0 };
    read_register(EULER_X_0, buf, 12);
    for (int i = 0; i < 3; i++) {
        euler[i] = uint8_to_float(&buf[i*4]);
    }
}

void LPMS_BE1::get_reg_data(uint8_t addr, uint8_t *buf, uint8_t len)
{
    read_register(addr, buf, len);
}


void LPMS_BE1::sys_reset(void)
{
    // TODO
}

void LPMS_BE1::sys_reboot(void)
{
    // TODO
}

be1_status_t LPMS_BE1::set_output_format(uint8_t format)
{
    // TODO
    return BE1_ERROR;
}

void LPMS_BE1::reset_timestamp(void)
{
    // TODO
}

be1_status_t LPMS_BE1::set_acc_output_type(uint8_t type)
{
    // TODO
    return BE1_ERROR;
}

be1_status_t LPMS_BE1::set_gyro_output_type(uint8_t type)
{
    // TODO
    return BE1_ERROR;
}

void LPMS_BE1::start_gyro_calibration(void)
{
    // TODO
}

be1_status_t LPMS_BE1::set_filter_mode(uint8_t mode)
{
    // TODO
    return BE1_ERROR;
}

   


///////////////////////////////////
// Private
///////////////////////////////////
float LPMS_BE1::uint8_to_float(uint8_t *pu8vals)
{
    data_decoder decoder;
    for(int i = 0; i < 4; i++) {
        decoder.u8vals[i] = *(pu8vals +i);
    }
    return decoder.fval;
}

uint32_t LPMS_BE1::uint8_to_uint32(uint8_t *pu8vals)
{
    data_decoder decoder;
    for(int i = 0; i < 4; i++) {
        decoder.u8vals[i] = *(pu8vals +i);
    }
    return decoder.u32val;
}









void LPMS_BE1::read_register(uint8_t addr, uint8_t *buf, uint8_t len)
{
#if defined BE1_USE_SPI

    addr |= 0x80;
    digitalWrite(BE1_SPI_CS, LOW);
    delayMicroseconds(10);

    SPI.transfer(addr);
    delayMicroseconds(10);
    for (int i = 0; i < len; i++) {
        buf[i] = SPI.transfer(0x00);
    }

    digitalWrite(BE1_SPI_CS, HIGH);
    delayMicroseconds(10);

#elif defined BE1_USE_I2C

    Wire.beginTransmission(BE1_I2C_ADRRESS);
    Wire.write(addr);
    Wire.endTransmission();
    Wire.requestFrom(BE1_I2C_ADRRESS, len);

    int i = 0;
    while(Wire.available()) {
        buf[i++] = Wire.read();
    }

#endif
}

void LPMS_BE1::write_register(uint8_t addr, uint8_t *buf, uint8_t len)
{
#if defined BE1_USE_SPI

    digitalWrite(BE1_SPI_CS, LOW);
    delayMicroseconds(10);

    SPI.transfer(addr);
    delayMicroseconds(10);
    for (int i = 0; i < len; i++) {
        SPI.transfer(buf[i]);
    }

    digitalWrite(BE1_SPI_CS, HIGH);
    delayMicroseconds(10);

#elif defined BE1_USE_I2C

    Wire.beginTransmission(BE1_I2C_ADRRESS);
    Wire.write(addr);
    Wire.write(buf, len);
    Wire.endTransmission();

#endif
}

void LPMS_BE1::wait_update(void)
{
    delay(2);  // wait at least 2ms for updating registers
}
void LPMS_BE1::wait_reset(void)
{
    delay(10); // wait at least 10ms for sensor reset
}
void LPMS_BE1::wait_reboot(void)
{
    delay(80); // wait at least 80ms for sensor reboot
}
