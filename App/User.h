#ifndef User_H
#define User_H


#include "common.h"
#include "include.h"
#include "math.h"

typedef struct DS3231
{
    int16_t  Temperature;
    
    uint8_t Year;
    uint8_t Month;
    uint8_t Day;
    uint8_t Hour;
    uint8_t Minute;
    uint8_t Second;

}DS3231;        //DS3231数据结构体


#define  LED_INIT()    gpio_init (PTA15, GPO,1)      //初始化板上LED
#define  LED_TURN()    gpio_turn (    PTA15   )      //板上 LED 闪烁

#define  DelayMs(ms)   lptmr_delay_ms(ms)            //延时毫秒函数




#include "TFT.h"           // 显示屏头文件
#include "Password.h"      //密码头文件
#include "DS3231.h"        //时钟芯片头文件
#include "Display.h"       //屏幕显示内容头文件
#include "DOOR.h"          //门扣头文件
#include "Key.h"           //按键头文件
                

//系统配置
void System_Config(void);






#endif