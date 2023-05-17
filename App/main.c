#include "User.h"               //用户头文件


void  main(void)
{
    System_Config();       //初始化系统配置
    for(;;) 
    {
        Door_Control();   //门锁控制
        Door_Status();    //门口状态检测
        Update_Data();    //更新时间、温度数据
        Set_Time();       //设置时间
        Set_Base();       //设置基站号
        LED_TURN();       //运行指示
    }
    //
}
//









