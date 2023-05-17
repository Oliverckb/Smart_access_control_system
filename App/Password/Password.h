#ifndef Password_H
#define Password_H



#include "User.h"




//初始化密码采集
void Password_Config(void);

//密码校验    0:错误密码  1：正确密码   2：未采集完密码
uint8_t Password_Check(void);

//复位密码及其标志位
void Password_Reset(void);


#endif