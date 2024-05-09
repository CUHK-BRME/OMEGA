
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
#include "linmot_util.cpp"
#include "linmot_util.h"



#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
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
void LINMOT_CAN_TEST_Start_wrapper(real_T *xD,
			void **pW,
			const uint8_T *can_port, const int_T p_width0,
			const real_T *max_vel, const int_T p_width1,
			const real_T *accel, const int_T p_width2,
			const real_T *decel, const int_T p_width3,
			const uint8_T *safe_mode, const int_T p_width4)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Start code goes here.
 */
#ifndef MATLAB_MEX_FILE

if(*can_port-1 == 0){
    system("sudo ip link set can0 type can bitrate 1000000");
    system("sudo ifconfig can0 up");
    system("sudo ifconfig can0 txqueuelen 65535");
}else{
    system("sudo ip link set can1 type can bitrate 1000000");
    system("sudo ifconfig can1 up");
    system("sudo ifconfig can1 txqueuelen 65535");
}


int ret;
struct sockaddr_can addr;
struct ifreq ifr;

//1.Create socket
pW[0] = socket(PF_CAN, SOCK_RAW, CAN_RAW);
if (pW[0] < 0) {
    return;
}


//2.Specify can0 device
if(*can_port-1 == 0){
    strcpy(ifr.ifr_name, "can0");
}else{
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
rfilter[0].can_id = 0x1BF;
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

struct can_frame tx_frame;
tx_frame.can_dlc = 2;
tx_frame.can_id = 0x0;
tx_frame.data[0] = 1;
tx_frame.data[1] = 0;
write(pW[0], &tx_frame, sizeof(struct can_frame));
usleep(1000);


struct can_frame RxPDO1;
RxPDO1.can_dlc = 8;
RxPDO1.can_id = 0x23F; 

//toggle on off
enter_operation(&RxPDO1);
write(pW[0], &RxPDO1, sizeof(struct can_frame));
usleep(1000);
exit_operation(&RxPDO1);
write(pW[0], &RxPDO1, sizeof(struct can_frame));
usleep(1000);

struct can_frame rx_frame;
read(pW[0], &rx_frame, sizeof(rx_frame));

int homed;
homed = ((rx_frame.data[1]>>3) & 0x1);

if(!homed){
//Homing
homing(&RxPDO1);
    while(!homed){       
        write(pW[0], &RxPDO1, sizeof(struct can_frame));
        read(pW[0], &rx_frame, sizeof(rx_frame));
        homed = ((rx_frame.data[1]>>3) & 0x1);
    }
    sleep(1);
}

    
#endif
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void LINMOT_CAN_TEST_Outputs_wrapper(uint8_T *status_word,
			uint8_T *state_var,
			int32_T *position,
			real_T *err_no,
			const real_T *xD,
			void **pW,
			const uint8_T *can_port, const int_T p_width0,
			const real_T *max_vel, const int_T p_width1,
			const real_T *accel, const int_T p_width2,
			const real_T *decel, const int_T p_width3,
			const uint8_T *safe_mode, const int_T p_width4)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE

int nbytes;
int sendnbytes;



//read and unpack
struct can_frame rx_frame;
nbytes = 1;

while(nbytes > 0){
    nbytes = read(pW[0], &rx_frame, sizeof(rx_frame));
    if(nbytes > 0){
        status_word[0] = rx_frame.data[0];
        status_word[1] = rx_frame.data[1];

        state_var[0] = rx_frame.data[2];
        state_var[1] = rx_frame.data[3];

        position[0] = *(int *)&rx_frame.data[4];
    }      
}

if(state_var[1] == 4){
    err_no[0] = 1;
}else{
    err_no[0] = 0;
}

//debug


#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
void LINMOT_CAN_TEST_Update_wrapper(const uint8_T *mode,
			const int16_T *pos_cmd,
			const int32_T *current_cmd,
			uint8_T *status_word,
			uint8_T *state_var,
			int32_T *position,
			real_T *err_no,
			real_T *xD,
			void **pW,
			const uint8_T *can_port, const int_T p_width0,
			const real_T *max_vel, const int_T p_width1,
			const real_T *accel, const int_T p_width2,
			const real_T *decel, const int_T p_width3,
			const uint8_T *safe_mode, const int_T p_width4)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Code example
 *   xD[0] = u0[0];
 */

#ifndef MATLAB_MEX_FILE

struct can_frame RxPDO1;
RxPDO1.can_dlc = 8;
RxPDO1.can_id = 0x23F; 

struct can_frame RxPDO2;
RxPDO2.can_dlc = 8;
RxPDO2.can_id = 0x33F; 

static int tog;
static bool _init;

if (!_init){
    tog = 0;
    _init = true;
}


if(*safe_mode == 0){
    xD[1] = 1;
}


if (xD[1] == 0){
    if(mode[0] == 0){
        exit_operation(&RxPDO1);
        write(pW[0], &RxPDO1, sizeof(struct can_frame));
        xD[1] = 1;
    }else{
        exit_operation(&RxPDO1);
        write(pW[0], &RxPDO1, sizeof(struct can_frame));
    }
} 
else { 
    
switch ((unsigned int)xD[0]) {
default: // idle
    exit_operation(&RxPDO1);
    write(pW[0], &RxPDO1, sizeof(struct can_frame));
    
    switch (mode[0]){
        case 1: 
            enter_operation(&RxPDO1);
            write(pW[0], &RxPDO1, sizeof(struct can_frame)); //enter motor mode on exit;
            usleep(100000);
            xD[0] = 1;
            break;
           
        case 2:
            enter_operation(&RxPDO1);
            write(pW[0], &RxPDO1, sizeof(struct can_frame)); //enter motor mode on exit;
            usleep(100000);
            xD[0] = 2;
            break;
            
        case 3:
            xD[0] = 3;
            break;
            
        default:
            break;
    }
    break;
case 1: //position control
    if(mode[0] == 1){
        position_rxpdo1(&RxPDO1, tog, pos_cmd[0], (*max_vel)*1000);
        position_rxpdo2(&RxPDO2, (*accel)*10, (*decel)*10);  
        write(pW[0], &RxPDO1, sizeof(struct can_frame));
        write(pW[0], &RxPDO2, sizeof(struct can_frame));
    } else if(mode[0] == 2){
        current_rxpdo1(&RxPDO1, tog, current_cmd[0]);
        write(pW[0], &RxPDO1, sizeof(struct can_frame));
        xD[0] = 2;
    } else {
        exit_operation(&RxPDO1);
        write(pW[0], &RxPDO1, sizeof(struct can_frame));
        xD[0] = 0;
    }
    break;

case 2: //current control
    if(mode[0] == 2){
        current_rxpdo1(&RxPDO1, tog, current_cmd[0]);
        write(pW[0], &RxPDO1, sizeof(struct can_frame));
    } else if(mode[0] == 1){
        exit_current_rxpdo1(&RxPDO1, tog);
        write(pW[0], &RxPDO1, sizeof(struct can_frame));
        /*
        usleep(1000);
        position_rxpdo1(&RxPDO1, tog, pos_cmd[0], (*max_vel)*1000);
        position_rxpdo2(&RxPDO2, (*accel)*10, (*decel)*10);  
        write(pW[0], &RxPDO1, sizeof(struct can_frame));
        write(pW[0], &RxPDO2, sizeof(struct can_frame)); 
         */
        xD[0] = 1;
    } else {
        exit_operation(&RxPDO1);
        write(pW[0], &RxPDO1, sizeof(struct can_frame));
        xD[0] = 0;
    }
    break;
    
case 3: //acknowledge error
    if(mode[0] == 3){
        ack_error(&RxPDO1);
        write(pW[0], &RxPDO1, sizeof(struct can_frame));
        usleep(100000);
        xD[0] = 0;
    } else {
        exit_operation(&RxPDO1);
        write(pW[0], &RxPDO1, sizeof(struct can_frame));
        xD[0] = 0;
    }
    break;
}
}

tog = tog + 1;

#endif
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Terminate function
 *
 */
void LINMOT_CAN_TEST_Terminate_wrapper(real_T *xD,
			void **pW,
			const uint8_T *can_port, const int_T p_width0,
			const real_T *max_vel, const int_T p_width1,
			const real_T *accel, const int_T p_width2,
			const real_T *decel, const int_T p_width3,
			const uint8_T *safe_mode, const int_T p_width4)
{
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Terminate code goes here.
 */

#ifndef MATLAB_MEX_FILE



struct can_frame RxPDO1;
RxPDO1.can_dlc = 8;
RxPDO1.can_id = 0x23F; 

for(int i=0; i<5; i++){
    exit_operation(&RxPDO1);
    write(pW[0], &RxPDO1, sizeof(struct can_frame));
}

//wait before closing socket
usleep(50000);

int j;
for(j=0; j<1; j++){
    close(pW[0]);
    
    if(*can_port-1 == 0){
    system("sudo ifconfig can0 down");
    }else{
    system("sudo ifconfig can1 down");
    }     
}

#endif
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_END --- EDIT HERE TO _BEGIN */
}

