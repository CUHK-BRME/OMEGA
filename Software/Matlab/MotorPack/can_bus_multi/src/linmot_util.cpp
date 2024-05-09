
#include "linmot_util.h"
#include <linux/can.h>
#include <linux/can/raw.h>
#include <stdint.h>


// lin mot command
void enter_operation(can_frame * msg){
  msg->data[0] = 0x3F;
  msg->data[1] = 0x0;
  msg->data[2] = 0x0;
  msg->data[3] = 0x0;
  msg->data[4] = 0x0;
  msg->data[5] = 0x0;
  msg->data[6] = 0x0;
  msg->data[7] = 0x0;
}

void exit_operation(can_frame * msg){
  msg->data[0] = 0x3E;
  msg->data[1] = 0x0;
  msg->data[2] = 0x0;
  msg->data[3] = 0x0;
  msg->data[4] = 0x0;
  msg->data[5] = 0x0;
  msg->data[6] = 0x0;
  msg->data[7] = 0x0;
}

void homing(can_frame * msg){
  //msg->can_id = 0x23F;
  //msg->can_dlc = 8;
  msg->data[0] = 0x3F;
  msg->data[1] = 0x08;
  msg->data[2] = 0x0;
  msg->data[3] = 0x0;
  msg->data[4] = 0x0;
  msg->data[5] = 0x0;
  msg->data[6] = 0x0;
  msg->data[7] = 0x0;
}

void position_rxpdo1(can_frame * msg, int toggle, int pos_cmd, int max_vel){
  msg->data[0] = 0x3F;
  msg->data[1] = 0x00;
  msg->data[2] = (0x0<<4|toggle&0xF); //sub id | toggling
  msg->data[3] = 0x09; //master id
  msg->data[4] = pos_cmd&0xFF;  //cmd par 4 byte
  msg->data[5] = pos_cmd>>8;
  msg->data[6] = max_vel&0xFF;
  msg->data[7] = max_vel>>8;
}

void position_rxpdo2(can_frame * msg, int max_acc, int max_dec){
  msg->data[0] = max_acc&0xFF;
  msg->data[1] = max_acc>>8;
  msg->data[2] = max_dec&0xFF;
  msg->data[3] = max_dec>>8;
  msg->data[4] = 0x00;
  msg->data[5] = 0x00;
  msg->data[6] = 0x00;
  msg->data[7] = 0x00;
}

void current_rxpdo1(can_frame * msg, int toggle, int cur_cmd){
  msg->data[0] = 0x3F;
  msg->data[1] = 0x00;
  msg->data[2] = (0x0<<4|toggle&0xF); //sub id | toggling
  msg->data[3] = 0x39; //master id
  msg->data[4] = cur_cmd&0xFF;  //current cmd par 4 byte sint32
  msg->data[5] = (cur_cmd>>8) & 0xFF;
  msg->data[6] = (cur_cmd>>16) & 0xFF;
  msg->data[7] = (cur_cmd>>24) & 0xFF;
}

void exit_current_rxpdo1(can_frame * msg, int toggle){
  msg->data[0] = 0x3F;
  msg->data[1] = 0x00;
  msg->data[2] = (0xF<<4|toggle&0xF); //sub id | toggling
  msg->data[3] = 0x39; //master id
  msg->data[4] = 0x00;
  msg->data[5] = 0x00;
  msg->data[6] = 0x00;
  msg->data[7] = 0x00;
}

void ack_error(can_frame * msg){
  //msg->can_id = 0x23F;
  //msg->can_dlc = 8;
  msg->data[0] = 0xBE;
  msg->data[1] = 0x0;
  msg->data[2] = 0x0;
  msg->data[3] = 0x0;
  msg->data[4] = 0x0;
  msg->data[5] = 0x0;
  msg->data[6] = 0x0;
  msg->data[7] = 0x0;
}
