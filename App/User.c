#include "User.h"       //用户头文件



//系统配置
void System_Config(void)
{
    DisableInterrupts;
    LED_INIT();             //初始化板上LED   PA15
    DS3231_Config();        //初始化DS3231
    TFT_Init();             //显示屏初始化
    Back_image();           //显示背景图片
    Wait_Start();           //等待开机完成
    Show_Time();            //显示时间
    Show_StaticText();      //显示屏显示静态文字
    Show_Temperature();     //显示温度
    Password_Config();      //初始化密码采集
    Door_Init();            //初始化门扣控制及检测
    Key_Config();           //初始化按键
    EnableInterrupts;
}
//

