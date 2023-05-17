#ifndef Display_H
#define Display_H


#include "User.h"

/*****************************************************
函数名：Wait_Start
参数：无
功能：等待开机完成
******************************************************/
void Wait_Start(void);


/*****************************************************
函数名：Back_image
参数：无
功能：显示背景图片
******************************************************/
void Back_image(void);


/*****************************************************
函数名：Show_Time
参数：无
功能：显示实时时间
******************************************************/
void Show_Time(void);

/*****************************************************
函数名：Show_Temperature
参数：无
功能：显示实时温度
******************************************************/
void Show_Temperature(void);


//显示屏显示静态文字
void Show_StaticText(void);


//显示密码正确
void Password_Right(void);

//显示密码错误
void Password_Wrong(void);

//显示开门状态
void Show_Open(void);

//显示关门状态
void Show_Close(void);

//更新时间、温度数据
void Update_Data(void);

//显示开门时间
void ShowOpenTime(void);

//显示关门时间
void ShowCloseTime(void);



#endif


