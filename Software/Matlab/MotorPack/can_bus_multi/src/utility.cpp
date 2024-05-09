#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <fcntl.h>
#include <sys/time.h>
#include <chrono>
#include "utility.h"

canChannel::canChannel() {
    tx_frame.can_dlc = 8;
    zero_cmd[5] = { };
    //end_time = std::chrono::high_resolution_clock::now();;
}

uint64_t canChannel::execution_timer(int state){
    using namespace std::chrono;    
    static high_resolution_clock::time_point currentStamp;
    static high_resolution_clock::time_point startStamp;
    static bool _init;

    if (!_init) {
        startStamp = std::chrono::high_resolution_clock::now();
        currentStamp = std::chrono::high_resolution_clock::now();
        _init = true;
    }
    if (state == 1) {
        startStamp = std::chrono::high_resolution_clock::now();
    }
    if (state > 0) {
        currentStamp = std::chrono::high_resolution_clock::now();
    }
    auto elapsed = currentStamp - startStamp;

    long long elapsed_microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    uint64_t us = 0.000001 * elapsed_microseconds;
    return us;
}
/*
void canChannel::start_execution() {
    start_time = std::chrono::high_resolution_clock::now();
}

void canChannel::end_execution() {
    end_time = std::chrono::high_resolution_clock::now();
}

uint64_t canChannel::get_execution_time() {
    uint64_t us = std::chrono::duration_cast<std::chrono::microseconds>(start_time-end_time).count();
    return us;
}*/

void canChannel::comm_init(uint8_t port_num, uint8_t device_num) {
    channelNum = port_num-1;
    numOfDevice = device_num;
    if(channelNum == 0){
    system("sudo ip link set can0 type can bitrate 1000000");
    system("sudo ifconfig can0 up");
    system("sudo ifconfig can0 txqueuelen 65536");
    }
    else {
    system("sudo ip link set can1 type can bitrate 1000000");
    system("sudo ifconfig can1 up");
    system("sudo ifconfig can1 txqueuelen 65536");
    }

    int ret;
    struct sockaddr_can addr;
    struct ifreq ifr;

    //1.Create socket
    fd = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if (fd < 0) {
        return;
    }

    //2.Specify can0 device
    if(channelNum == 0){
        strcpy(ifr.ifr_name, "can0");
    }
    else{
        strcpy(ifr.ifr_name, "can1");
    }
    ret = ioctl(fd, SIOCGIFINDEX, &ifr);
    if (ret < 0) {
        return;
    }

    //3.Bind the socket to can0
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
    ret = bind(fd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret < 0) {
        return;
    }

    //4.Define receive rules
    struct can_filter rfilter[5];
    rfilter[0].can_id = 0x00;
    rfilter[1].can_id = 0x01;
    rfilter[2].can_id = 0x02;
    rfilter[3].can_id = 0x03;
    rfilter[4].can_id = 0x04;
    rfilter[0].can_mask = CAN_SFF_MASK;
    rfilter[1].can_mask = CAN_SFF_MASK;
    rfilter[2].can_mask = CAN_SFF_MASK;
    rfilter[3].can_mask = CAN_SFF_MASK;
    rfilter[4].can_mask = CAN_SFF_MASK;
    //rfilter[0].can_mask = 0xFFF;
    // setsockopt(pW[0], SOL_CAN_RAW, CAN_RAW_FILTER, NULL, 0);
    // setsockopt(pW[0], SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter, sizeof(rfilter));
    setsockopt(fd, SOL_CAN_RAW, CAN_RAW_JOIN_FILTERS, &rfilter, sizeof(rfilter));

    //5. set NON BLOCK
    fcntl(fd, F_SETFL, O_NONBLOCK);
    //fcntl(pW[0], F_GETFL, O_NONBLOCK);

    //Initiallize
    for(uint8_t i=0; i<numOfDevice; i++){ 
        send_ExitMotorMode(i+1);
    }
}

void canChannel::comm_close() {
    for(uint8_t i=0; i<numOfDevice; i++){ 
        send_ExitMotorMode(i+1);
    }

    usleep(50000);

    close(fd);        
    if(channelNum == 0) {
    system("sudo ifconfig can0 down");
    }
    else {
    system("sudo ifconfig can1 down");
    }     
}

void canChannel::send_frame(int device_id) {    
    tx_frame.can_id = device_id;
    write(fd, &tx_frame, sizeof(tx_frame));
}

void canChannel::send_EnterMotorMode(int device_id) {
    tx_frame.data[0] = 0xFF;
    tx_frame.data[1] = 0xFF;
    tx_frame.data[2] = 0xFF;
    tx_frame.data[3] = 0xFF;
    tx_frame.data[4] = 0xFF;
    tx_frame.data[5] = 0xFF;
    tx_frame.data[6] = 0xFF;
    tx_frame.data[7] = 0xFC;
    send_frame(device_id);
}
void canChannel::send_ExitMotorMode(int device_id) {
    tx_frame.data[0] = 0xFF;
    tx_frame.data[1] = 0xFF;
    tx_frame.data[2] = 0xFF;
    tx_frame.data[3] = 0xFF;
    tx_frame.data[4] = 0xFF;
    tx_frame.data[5] = 0xFF;
    tx_frame.data[6] = 0xFF;
    tx_frame.data[7] = 0xFD;
    send_frame(device_id);
}

void canChannel::send_SetZero(int device_id){
    tx_frame.data[0] = 0xFF;
    tx_frame.data[1] = 0xFF;
    tx_frame.data[2] = 0xFF;
    tx_frame.data[3] = 0xFF;
    tx_frame.data[4] = 0xFF;
    tx_frame.data[5] = 0xFF;
    tx_frame.data[6] = 0xFF;
    tx_frame.data[7] = 0xFE;
    send_frame(device_id);
    usleep(1000);
}

void canChannel::send_dummy(int device_id) {
    pack_cmd(zero_cmd);
    send_frame(device_id);
}

void canChannel::send_motor_cmd(int device_id, const float * motor_cmd) {
    pack_cmd(motor_cmd);
    send_frame(device_id);
}

void canChannel::receive_process_frame() {
    int nbytes = 1;
    while(nbytes > 0){
        nbytes = read(fd, &rx_frame, sizeof(rx_frame));
        if(rx_frame.data[0] <= numOfDevice) {
            unpack_reply();
        }
    }
}

void canChannel::pack_cmd(const float * motor_cmd){
     /// limit data to be within bounds ///
     float p_des = fminf(fmaxf(P_MIN, motor_cmd[0]), P_MAX);
     float v_des = fminf(fmaxf(V_MIN, motor_cmd[1]), V_MAX);
     float kp = fminf(fmaxf(KP_MIN, motor_cmd[2]), KP_MAX);
     float kd = fminf(fmaxf(KD_MIN, motor_cmd[3]), KD_MAX);
     float t_ff = fminf(fmaxf(T_MIN, motor_cmd[4]), T_MAX);
     /// convert floats to unsigned ints ///
     uint16_t p_int = float_to_uint(p_des, P_MIN, P_MAX, 16);
     uint16_t v_int = float_to_uint(v_des, V_MIN, V_MAX, 12);
     uint16_t kp_int = float_to_uint(kp, KP_MIN, KP_MAX, 12);
     uint16_t kd_int = float_to_uint(kd, KD_MIN, KD_MAX, 12);
     uint16_t t_int = float_to_uint(t_ff, T_MIN, T_MAX, 12);
     /// pack ints into the can buffer ///
     tx_frame.data[0] = p_int>>8;
     tx_frame.data[1] = p_int&0xFF;
     tx_frame.data[2] = v_int>>4;
     tx_frame.data[3] = ((v_int&0xF)<<4)|(kp_int>>8);
     tx_frame.data[4] = kp_int&0xFF;
     tx_frame.data[5] = kd_int>>4;
     tx_frame.data[6] = ((kd_int&0xF)<<4)|(t_int>>8);
     tx_frame.data[7] = t_int&0xff;
}

void canChannel::unpack_reply() {
    /// unpack ints from can buffer ///
    uint8_t id = rx_frame.data[0];
    uint16_t p_int = (rx_frame.data[1]<<8)|rx_frame.data[2];
    uint16_t v_int = (rx_frame.data[3]<<4)|(rx_frame.data[4]>>4);
    uint16_t i_int = ((rx_frame.data[4]&0xF)<<8)|rx_frame.data[5];
    /// convert uints to floats ///
    float p = uint_to_float(p_int, P_MIN, P_MAX, 16);
    float v = uint_to_float(v_int, V_MIN, V_MAX, 12);
    float t = uint_to_float(i_int, -T_MAX, T_MAX, 12);
    
    motor_state[id][0] = p;
    motor_state[id][1] = v;
    motor_state[id][2] = t;
}

int canChannel::float_to_uint(float x, float x_min, float x_max, unsigned int bits) {
    /// Converts a float to an unsigned int, given range and number of bits ///
    float span = x_max - x_min;
    if(x < x_min) x = x_min;
    else if(x > x_max) x = x_max;
    return (int) ((x- x_min)*((float)((1<<bits)/span)));
}

float canChannel::uint_to_float(int x_int, float x_min, float x_max, int bits){
    /// converts unsigned int to float, given range and number of bits ///
    float span = x_max - x_min;
    float offset = x_min;
    return ((float)x_int)*span/((float)((1<<bits)-1)) + offset;
}
/*
float fmaxf(float x, float y){
    /// Returns maximum of x, y ///
    return (((x)>(y))?(x):(y));
}

float fminf(float x, float y){
    /// Returns minimum of x, y ///
    return (((x)<(y))?(x):(y));
}

float fmaxf3(float x, float y, float z){
    /// Returns maximum of x, y, z ///
    return (x > y ? (x > z ? x : z) : (y > z ? y : z));
}

float fminf3(float x, float y, float z){
    /// Returns minimum of x, y, z ///
    return (x < y ? (x < z ? x : z) : (y < z ? y : z));
}

float roundf(float x){
    /// Returns nearest integer ///

    return x < 0.0f ? ceilf(x - 0.5f) : floorf(x + 0.5f);
}

void limit_norm(float *x, float *y, float limit){
    /// Scales the lenght of vector (x, y) to be <= limit ///
    float norm = sqrt(*x * *x + *y * *y);
    if(norm > limit){
        *x = *x * limit/norm;
        *y = *y * limit/norm;
        }
    }

void limit(float *x, float min, float max){
    *x = fmaxf(fminf(*x, max), min);
}

int float_to_uint(float x, float x_min, float x_max, int bits){
    /// Converts a float to an unsigned int, given range and number of bits ///
    float span = x_max - x_min;
    float offset = x_min;
    return (int) ((x-offset)*((float)((1<<bits)-1))/span);
}


float uint_to_float(int x_int, float x_min, float x_max, int bits){
    /// converts unsigned int to float, given range and number of bits ///
    float span = x_max - x_min;
    float offset = x_min;
    return ((float)x_int)*span/((float)((1<<bits)-1)) + offset;
}

void pack_cmd(can_frame * msg, float * motor_cmd){
    // float p_in,
    // float v_in,
    // float kp_in,
    // float kd_in,
    // float t_in

     /// limit data to be within bounds ///
     float p_des = fminf(fmaxf(P_MIN, motor_cmd[0]), P_MAX);
     float v_des = fminf(fmaxf(V_MIN, motor_cmd[1]), V_MAX);
     float kp = fminf(fmaxf(KP_MIN, motor_cmd[2]), KP_MAX);
     float kd = fminf(fmaxf(KD_MIN, motor_cmd[3]), KD_MAX);
     float t_ff = fminf(fmaxf(T_MIN, motor_cmd[4]), T_MAX);
     /// convert floats to unsigned ints ///
     uint16_t p_int = float_to_uint(p_des, P_MIN, P_MAX, 16);
     uint16_t v_int = float_to_uint(v_des, V_MIN, V_MAX, 12);
     uint16_t kp_int = float_to_uint(kp, KP_MIN, KP_MAX, 12);
     uint16_t kd_int = float_to_uint(kd, KD_MIN, KD_MAX, 12);
     uint16_t t_int = float_to_uint(t_ff, T_MIN, T_MAX, 12);
     /// pack ints into the can buffer ///
     msg->data[0] = p_int>>8;
     msg->data[1] = p_int&0xFF;
     msg->data[2] = v_int>>4;
     msg->data[3] = ((v_int&0xF)<<4)|(kp_int>>8);
     msg->data[4] = kp_int&0xFF;
     msg->data[5] = kd_int>>4;
     msg->data[6] = ((kd_int&0xF)<<4)|(t_int>>8);
     msg->data[7] = t_int&0xff;
}

void SetZero(can_frame * msg){
     msg->data[0] = 0xFF;
     msg->data[1] = 0xFF;
     msg->data[2] = 0xFF;
     msg->data[3] = 0xFF;
     msg->data[4] = 0xFF;
     msg->data[5] = 0xFF;
     msg->data[6] = 0xFF;
     msg->data[7] = 0xFE;
}

void EnterMotorMode(can_frame * msg){
     msg->data[0] = 0xFF;
     msg->data[1] = 0xFF;
     msg->data[2] = 0xFF;
     msg->data[3] = 0xFF;
     msg->data[4] = 0xFF;
     msg->data[5] = 0xFF;
     msg->data[6] = 0xFF;
     msg->data[7] = 0xFC;
}

void ExitMotorMode(can_frame * msg){
     msg->data[0] = 0xFF;
     msg->data[1] = 0xFF;
     msg->data[2] = 0xFF;
     msg->data[3] = 0xFF;
     msg->data[4] = 0xFF;
     msg->data[5] = 0xFF;
     msg->data[6] = 0xFF;
     msg->data[7] = 0xFD;
}

void unpack_reply(can_frame msg, float * motor_state){
    /// unpack ints from can buffer ///
    uint16_t id = msg.data[0];
    uint16_t p_int = (msg.data[1]<<8)|msg.data[2];
    uint16_t v_int = (msg.data[3]<<4)|(msg.data[4]>>4);
    uint16_t i_int = ((msg.data[4]&0xF)<<8)|msg.data[5];
    /// convert uints to floats ///
    float p = uint_to_float(p_int, P_MIN, P_MAX, 16);
    float v = uint_to_float(v_int, V_MIN, V_MAX, 12);
    float t = uint_to_float(i_int, -T_MAX, T_MAX, 12);

    motor_state[0] = p;
    motor_state[1] = v;
    motor_state[2] = t;
}
*/