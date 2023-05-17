#ifndef DOOR_H
#define DOOR_H


#include "User.h"


//门锁控制检测初始化
//状态监测  PD0
//门锁控制  PB0
void Door_Init(void);


//门锁控制
void Door_Control(void);


//门口状态检测
void Door_Status(void);






#endif
