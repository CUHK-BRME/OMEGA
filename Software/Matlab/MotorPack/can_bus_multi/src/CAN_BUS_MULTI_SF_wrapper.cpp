
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE

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
#include "utility.h"
#include "utility.cpp"


#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 5
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Start function
 *
 */
void CAN_BUS_MULTI_SF_Start_wrapper(void **pW,
			const uint8_T *device_num, const int_T p_width0,
			const uint8_T *can_port, const int_T p_width1)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Start code goes here.
 */
#ifndef MATLAB_MEX_FILE

if(*can_port-1 == 0){
system("sudo ip link set can0 type can bitrate 1000000");
system("sudo ifconfig can0 up");
system("sudo ifconfig can0 txqueuelen 65536");
} else {
system("sudo ip link set can1 type can bitrate 1000000");
system("sudo ifconfig can1 up");
system("sudo ifconfig can1 txqueuelen 65536");
}

int ret;
struct sockaddr_can addr;
struct ifreq ifr;
float zero_cmd[5] = {0, 0, 0, 0, 0};

//1.Create socket
pW[0] = socket(PF_CAN, SOCK_RAW, CAN_RAW);
if (pW[0] < 0) {
    return;
}


//2.Specify can0 device
if(*can_port-1 == 0){
    strcpy(ifr.ifr_name, "can0");
}
else{
    strcpy(ifr.ifr_name, "can1");
}
ret = ioctl(pW[0], SIOCGIFINDEX, &ifr);
if (ret < 0) {
    return;
}

//3.Bind the socket to can0
addr.can_family = AF_CAN;
addr.can_ifindex = ifr.ifr_ifindex;
ret = bind(pW[0], (struct sockaddr *)&addr, sizeof(addr));
if (ret < 0) {
    return;
}

//4.Define receive rules
struct can_filter rfilter[1];
rfilter[0].can_id = 0x00;
rfilter[0].can_mask = CAN_SFF_MASK;
//rfilter[0].can_mask = 0xFFF;
setsockopt(pW[0], SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter, sizeof(rfilter));

/*
timeval tv;
tv.tv_sec = 0;
tv.tv_usec = 10000;
setsockopt(pW[0], SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv));
*/

//5. set NON BLOCK
fcntl(pW[0], F_SETFL, O_NONBLOCK);
//fcntl(pW[0], F_GETFL, O_NONBLOCK);

//Initiallize
if(*device_num > 0){
    struct can_frame m1_tx_frame;
    m1_tx_frame.can_id = 0x01;
    m1_tx_frame.can_dlc = 8;
    EnterMotorMode(&m1_tx_frame);
    write(pW[0], &m1_tx_frame, sizeof(struct can_frame));
}

if(*device_num > 1){
    struct can_frame m2_tx_frame;
    m2_tx_frame.can_id = 0x02;
    m2_tx_frame.can_dlc = 8;
    EnterMotorMode(&m2_tx_frame);
    write(pW[0], &m2_tx_frame, sizeof(struct can_frame));
}

if(*device_num > 2){
    struct can_frame m3_tx_frame;
    m3_tx_frame.can_id = 0x03;
    m3_tx_frame.can_dlc = 8;
    EnterMotorMode(&m3_tx_frame);
    write(pW[0], &m3_tx_frame, sizeof(struct can_frame));
}

if(*device_num > 3){
    struct can_frame m4_tx_frame;
    m4_tx_frame.can_id = 0x04;
    m4_tx_frame.can_dlc = 8;
    EnterMotorMode(&m4_tx_frame);
    write(pW[0], &m4_tx_frame, sizeof(struct can_frame));
}

//usleep(1000);

    
#endif
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void CAN_BUS_MULTI_SF_Outputs_wrapper(const real32_T *m1_cmd,
			const real32_T *m2_cmd,
			const real32_T *m3_cmd,
			const real32_T *m4_cmd,
			real32_T *m1_out,
			real32_T *m2_out,
			real32_T *m3_out,
			real32_T *m4_out,
			uint8_T *err_no,
			uint8_T *device_err,
			void **pW,
			const uint8_T *device_num, const int_T p_width0,
			const uint8_T *can_port, const int_T p_width1)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE

int nbytes;
struct can_frame rx_frame;
float zero_cmd[5] = {0, 0, 0, 0, 0};
int sendnbytes;


//send cmd to devices
if(*device_num > 0){
    struct can_frame m1_tx_frame;
    m1_tx_frame.can_id = 0x01;
    m1_tx_frame.can_dlc = 8;
    pack_cmd(&m1_tx_frame, m1_cmd);
    write(pW[0], &m1_tx_frame, sizeof(struct can_frame)); 
}

if(*device_num > 1){
    struct can_frame m2_tx_frame;
    m2_tx_frame.can_id = 0x02;
    m2_tx_frame.can_dlc = 8;
    pack_cmd(&m2_tx_frame, m2_cmd);
    write(pW[0], &m2_tx_frame, sizeof(struct can_frame));
}

if(*device_num > 2){
    struct can_frame m3_tx_frame;
    m3_tx_frame.can_id = 0x03;
    m3_tx_frame.can_dlc = 8;
    pack_cmd(&m3_tx_frame, m3_cmd);
    write(pW[0], &m3_tx_frame, sizeof(struct can_frame));
}

if(*device_num > 3){
    struct can_frame m4_tx_frame;
    m4_tx_frame.can_id = 0x04;
    m4_tx_frame.can_dlc = 8;
    pack_cmd(&m4_tx_frame, m4_cmd);
    write(pW[0], &m4_tx_frame, sizeof(struct can_frame));
}


//read and unpack
nbytes = read(pW[0], &rx_frame, sizeof(rx_frame));
if(rx_frame.data[0] == 0x01)
    unpack_reply(rx_frame, m1_out);
if(rx_frame.data[0] == 0x02)
    unpack_reply(rx_frame, m2_out);
if(rx_frame.data[0] == 0x03)
    unpack_reply(rx_frame, m3_out);
if(rx_frame.data[0] == 0x04)
    unpack_reply(rx_frame, m4_out);


//debug
err_no[0] = *can_port;
device_err[0] = *device_num;

#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Terminate function
 *
 */
void CAN_BUS_MULTI_SF_Terminate_wrapper(void **pW,
			const uint8_T *device_num, const int_T p_width0,
			const uint8_T *can_port, const int_T p_width1)
{
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Terminate code goes here.
 */

#ifndef MATLAB_MEX_FILE

float zero_cmd[5] = {0, 0, 0, 0, 0};

//Exit motor mode
if(*device_num > 0){
    struct can_frame m1_tx_frame;
    m1_tx_frame.can_id = 0x01;
    m1_tx_frame.can_dlc = 8;
    ExitMotorMode(&m1_tx_frame);
    write(pW[0], &m1_tx_frame, sizeof(struct can_frame));
}

if(*device_num > 1){
    struct can_frame m2_tx_frame;
    m2_tx_frame.can_id = 0x02;
    m2_tx_frame.can_dlc = 8;
    ExitMotorMode(&m2_tx_frame);
    write(pW[0], &m2_tx_frame, sizeof(struct can_frame));
}

if(*device_num > 2){
    struct can_frame m3_tx_frame;
    m3_tx_frame.can_id = 0x03;
    m3_tx_frame.can_dlc = 8;
    ExitMotorMode(&m3_tx_frame);
    write(pW[0], &m3_tx_frame, sizeof(struct can_frame));
}

if(*device_num > 3){
    struct can_frame m4_tx_frame;
    m4_tx_frame.can_id = 0x04;
    m4_tx_frame.can_dlc = 8;
    ExitMotorMode(&m4_tx_frame);
    write(pW[0], &m4_tx_frame, sizeof(struct can_frame));
}

//wait before closing socket
usleep(50000);

int j;
for(j=0; j<1; j++){
    close(pW[0]);
    system("sudo ifconfig can0 down");
    system("sudo ifconfig can1 down");
}

#endif
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_END --- EDIT HERE TO _BEGIN */
}

