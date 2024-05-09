
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
#define u_width 4
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
void CAN_BUS_MULTISTATE_SF_Start_wrapper(real_T *xD,
			void **pW,
			const uint8_T *device_num, const int_T p_width0,
			const uint8_T *can_port, const int_T p_width1,
			const uint8_T *safe_mode, const int_T p_width2)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE

pW[0] = new canChannel;
((canChannel *) pW[0]) -> comm_init( * can_port, * device_num);

// if(*can_port-1 == 0){
// system("sudo ip link set can0 type can bitrate 1000000");
// system("sudo ifconfig can0 up");
// system("sudo ifconfig can0 txqueuelen 65536");
// } else {
// system("sudo ip link set can1 type can bitrate 1000000");
// system("sudo ifconfig can1 up");
// system("sudo ifconfig can1 txqueuelen 65536");
// }
// 
// int ret;
// struct sockaddr_can addr;
// struct ifreq ifr;
// float zero_cmd[5] = {0, 0, 0, 0, 0};
// 
// //1.Create socket
// pW[0] = socket(PF_CAN, SOCK_RAW, CAN_RAW);
// if (pW[0] < 0) {
//     return;
// }
// 
// 
// //2.Specify can0 device
// if(*can_port-1 == 0){
//     strcpy(ifr.ifr_name, "can0");
// }
// else{
//     strcpy(ifr.ifr_name, "can1");
// }
// ret = ioctl(pW[0], SIOCGIFINDEX, &ifr);
// if (ret < 0) {
//     return;
// }
// 
// //3.Bind the socket to can0
// addr.can_family = AF_CAN;
// addr.can_ifindex = ifr.ifr_ifindex;
// ret = bind(pW[0], (struct sockaddr *)&addr, sizeof(addr));
// if (ret < 0) {
//     return;
// }
// 
// //4.Define receive rules
// struct can_filter rfilter[6];
// rfilter[0].can_id = 0x00;
// rfilter[1].can_id = 0x01;
// rfilter[2].can_id = 0x02;
// rfilter[3].can_id = 0x03;
// rfilter[4].can_id = 0x04;
// rfilter[5].can_id = 0x05;
// rfilter[0].can_mask = CAN_SFF_MASK;
// rfilter[1].can_mask = CAN_SFF_MASK;
// rfilter[2].can_mask = CAN_SFF_MASK;
// rfilter[3].can_mask = CAN_SFF_MASK;
// rfilter[4].can_mask = CAN_SFF_MASK;
// rfilter[5].can_mask = CAN_SFF_MASK;
// //rfilter[0].can_mask = 0xFFF;
// // setsockopt(pW[0], SOL_CAN_RAW, CAN_RAW_FILTER, NULL, 0);
// // setsockopt(pW[0], SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter, sizeof(rfilter));
// setsockopt(pW[0], SOL_CAN_RAW, CAN_RAW_JOIN_FILTERS, &rfilter, sizeof(rfilter));
// 
// /*
// timeval tv;
// tv.tv_sec = 0;
// tv.tv_usec = 10000;
// setsockopt(pW[0], SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv));
// */
// 
// //5. set NON BLOCK
// fcntl(pW[0], F_SETFL, O_NONBLOCK);
// //fcntl(pW[0], F_GETFL, O_NONBLOCK);
// 
// //Initiallize
// struct can_frame tx_frame;
// tx_frame.can_dlc = 8;
// for(int i=0; i<*device_num; i++){ 
//     tx_frame.can_id = i + 1;  
//     ExitMotorMode(&tx_frame);
//     write(pW[0], &tx_frame, sizeof(struct can_frame));
// }
// 
// 
// //usleep(1000);

    
#endif
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void CAN_BUS_MULTISTATE_SF_Outputs_wrapper(real32_T *m1_out,
			real32_T *m2_out,
			real32_T *m3_out,
			real_T *m4_out,
			const real_T *xD,
			void **pW,
			const uint8_T *device_num, const int_T p_width0,
			const uint8_T *can_port, const int_T p_width1,
			const uint8_T *safe_mode, const int_T p_width2)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE

 m4_out[0] = 0;
 m4_out[1] = 0;
 m4_out[2] = ((canChannel *) pW[0]) -> execution_timer(0);
((canChannel *) pW[0]) -> execution_timer(1);

((canChannel *) pW[0]) -> receive_process_frame();
for (int i=0; i<3; i++) {
    m1_out[i] = ((canChannel *) pW[0]) -> motor_state[1][i];
    m2_out[i] = ((canChannel *) pW[0]) -> motor_state[2][i];
    m3_out[i] = ((canChannel *) pW[0]) -> motor_state[3][i];
//     m4_out[i] = ((canChannel *) pW[0]) -> motor_state[4][i];
}

// int nbytes;
// struct can_frame rx_frame;
// 
// 
// /*
// //send cmd to devices
// if(*device_num > 0){
//     struct can_frame m1_tx_frame;
//     m1_tx_frame.can_id = 0x01;
//     m1_tx_frame.can_dlc = 8;
//     pack_cmd(&m1_tx_frame, m1_cmd);
//     write(pW[0], &m1_tx_frame, sizeof(struct can_frame)); 
// }
// 
// if(*device_num > 1){
//     struct can_frame m2_tx_frame;
//     m2_tx_frame.can_id = 0x02;
//     m2_tx_frame.can_dlc = 8;
//     pack_cmd(&m2_tx_frame, m2_cmd);
//     write(pW[0], &m2_tx_frame, sizeof(struct can_frame));
// }
// 
// if(*device_num > 2){
//     struct can_frame m3_tx_frame;
//     m3_tx_frame.can_id = 0x03;
//     m3_tx_frame.can_dlc = 8;
//     pack_cmd(&m3_tx_frame, m3_cmd);
//     write(pW[0], &m3_tx_frame, sizeof(struct can_frame));
// }
// 
// if(*device_num > 3){
//     struct can_frame m4_tx_frame;
//     m4_tx_frame.can_id = 0x04;
//     m4_tx_frame.can_dlc = 8;
//     pack_cmd(&m4_tx_frame, m4_cmd);
//     write(pW[0], &m4_tx_frame, sizeof(struct can_frame));
// }
// */
// 
// //read and unpack
// nbytes = 1;
// while(nbytes > 0){
//     nbytes = read(pW[0], &rx_frame, sizeof(rx_frame));
//     if(rx_frame.data[0] == 0x01)
//         unpack_reply(rx_frame, m1_out);
//     if(rx_frame.data[0] == 0x02)
//         unpack_reply(rx_frame, m2_out);
//     if(rx_frame.data[0] == 0x03)
//         unpack_reply(rx_frame, m3_out);
//     if(rx_frame.data[0] == 0x04)
//         unpack_reply(rx_frame, m4_out);
// }
// 
// //debug
// //debug[0] = *safe_mode;



#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
void CAN_BUS_MULTISTATE_SF_Update_wrapper(const uint8_T *mode,
			const real32_T *m1_cmd,
			const real32_T *m2_cmd,
			const real32_T *m3_cmd,
			const real32_T *m4_cmd,
			real32_T *m1_out,
			real32_T *m2_out,
			real32_T *m3_out,
			real_T *m4_out,
			real_T *xD,
			void **pW,
			const uint8_T *device_num, const int_T p_width0,
			const uint8_T *can_port, const int_T p_width1,
			const uint8_T *safe_mode, const int_T p_width2)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Code example
 *   xD[0] = u0[0];
 */

#ifndef MATLAB_MEX_FILE

// struct can_frame motor_tx_frame;
// motor_tx_frame.can_dlc = 8;
// float zero_cmd[5] = {0, 0, 0, 0, 0};

if(*safe_mode == 0){
    xD[4] = 1;
}

for(int i=0; i<*device_num; i++){
//     motor_tx_frame.can_id = i + 1;

if (xD[4] == 0){
    if(mode[0]==0 && mode[1]==0 && mode[2]==0 && mode[3]==0){
        ((canChannel *) pW[0]) -> send_dummy(i+1);
//         pack_cmd(&motor_tx_frame, zero_cmd); //send 0 cmd in exitmotormode to get motor feedback
//         write(pW[0], &motor_tx_frame, sizeof(struct can_frame));
        xD[4] = 1;
    }else{
        ((canChannel *) pW[0]) -> send_dummy(i+1);
//         pack_cmd(&motor_tx_frame, zero_cmd); //send 0 cmd in exitmotormode to get motor feedback
//         write(pW[0], &motor_tx_frame, sizeof(struct can_frame));
    }
} 
else {
    
switch ((unsigned int)xD[i]) {
default: // idle
    ((canChannel *) pW[0]) -> send_dummy(i+1);
//     pack_cmd(&motor_tx_frame, zero_cmd); //send 0 cmd in exitmotormode to get motor feedback
//     write(pW[0], &motor_tx_frame, sizeof(struct can_frame));
    
    switch (mode[i]){
        case 1:
            ((canChannel *) pW[0]) -> send_EnterMotorMode(i+1);
//             EnterMotorMode(&motor_tx_frame);
//             write(pW[0], &motor_tx_frame, sizeof(struct can_frame)); //enter motor mode on exit;
            xD[i] = 1;
            break;
        case 2:
            ((canChannel *) pW[0]) -> send_SetZero(i+1);
//             SetZero(&motor_tx_frame);
//             write(pW[0], &motor_tx_frame, sizeof(struct can_frame));
//             usleep(1000);
            //write(pW[0], &motor_tx_frame, sizeof(struct can_frame));
            xD[i] = 2;
            break;
        default:
            break;
    }
    break;
case 1: //
    if(mode[i] != 1){
        xD[i] = 0;
        ((canChannel *) pW[0]) -> send_ExitMotorMode(i+1);
//         ExitMotorMode(&motor_tx_frame);
//         write(pW[0], &motor_tx_frame, sizeof(struct can_frame));
    } else {
        switch (i){
            case 0:
                ((canChannel *) pW[0]) -> send_motor_cmd(i+1, m1_cmd);
//                 pack_cmd(&motor_tx_frame, m1_cmd);
                break;
            case 1:
                ((canChannel *) pW[0]) -> send_motor_cmd(i+1, m2_cmd);
//                 pack_cmd(&motor_tx_frame, m2_cmd);
                break;
            case 2:
                ((canChannel *) pW[0]) -> send_motor_cmd(i+1, m3_cmd);
//                 pack_cmd(&motor_tx_frame, m3_cmd);
                break;
            case 3:
                ((canChannel *) pW[0]) -> send_motor_cmd(i+1, m4_cmd);
//                 pack_cmd(&motor_tx_frame, m4_cmd);
                break;
            default:
                break;
        }
//         write(pW[0], &motor_tx_frame, sizeof(struct can_frame));
    }
    break;
case 2:
     if(mode[i] != 2){
        //SetZero(&motor_tx_frame);
        //write(pW[0], &motor_tx_frame, sizeof(struct can_frame));         
        xD[i] = 0;
    } else {
        //SetZero(&motor_tx_frame);
        //write(pW[0], &motor_tx_frame, sizeof(struct can_frame));
        //xD[i] = 0;
    }
    break;
}
}
}

// ((canChannel *) pW[0]) -> end_execution();
((canChannel *) pW[0]) -> execution_timer(2);

#endif
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Terminate function
 *
 */
void CAN_BUS_MULTISTATE_SF_Terminate_wrapper(real_T *xD,
			void **pW,
			const uint8_T *device_num, const int_T p_width0,
			const uint8_T *can_port, const int_T p_width1,
			const uint8_T *safe_mode, const int_T p_width2)
{
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Terminate code goes here.
 */

#ifndef MATLAB_MEX_FILE

((canChannel *) pW[0]) -> comm_close();

// float zero_cmd[5] = {0, 0, 0, 0, 0};
// 
// //Exit motor mode
// struct can_frame tx_frame;
// tx_frame.can_dlc = 8;
// for(int i=0; i<*device_num; i++){ 
//     tx_frame.can_id = i + 1;  
//     ExitMotorMode(&tx_frame);
//     write(pW[0], &tx_frame, sizeof(struct can_frame));
// }
// 
// 
// 
// //wait before closing socket
// usleep(50000);
// 
// int j;
// for(j=0; j<1; j++){
//     close(pW[0]);
//     
//     if(*can_port-1 == 0){
//     system("sudo ifconfig can0 down");
//     }else{
//     system("sudo ifconfig can1 down");
//     }     
// }

#endif
/* %%%-SFUNWIZ_wrapper_Terminate_Changes_END --- EDIT HERE TO _BEGIN */
}

