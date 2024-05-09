#ifndef LINMOT_UTIL_H
#define LINMOT_UTIL_H

#define PI 3.14159265359f
#define SQRT3 1.73205080757f

#include "math.h"
#include <linux/can.h>
#include <linux/can/raw.h>
#include <stdint.h>


void enter_operation(can_frame * msg);
void exit_operation(can_frame * msg);
void homing(can_frame * msg);
void position_rxpdo1(can_frame * msg, int toggle, int pos_cmd, int max_vel);
void position_rxpdo2(can_frame * msg, int max_acc, int max_dec);
void current_rxpdo1(can_frame * msg, int toggle, int cur_cmd);
void exit_current_rxpdo1(can_frame * msg, int toggle);
void ack_error(can_frame * msg);

#endif
