#ifndef DS3231_H
#define DS3231_H



#include "User.h"

#define DS3231_WriteAddress  0xD0    //DS3231器件写地址 
#define DS3231_ReadAddress   0xD1    //DS3231器件读地址

#define DS3231_WriteAddress  0xD0    //器件写地址 
#define DS3231_ReadAddress   0xD1    //器件读地址

#define DS3231_SECOND        0x00    //秒
#define DS3231_MINUTE        0x01    //分
#define DS3231_HOUR          0x02    //时
#define DS3231_WEEK          0x03    //星期
#define DS3231_DAY           0x04    //日
#define DS3231_MONTH         0x05    //月
#define DS3231_YEAR          0x06    //年

//闹铃1            
#define DS3231_SALARM1ECOND  0x07    //秒
#define DS3231_ALARM1MINUTE  0x08    //分
#define DS3231_ALARM1HOUR    0x09    //时
#define DS3231_ALARM1WEEK    0x0A    //星期/日

//闹铃2
#define DS3231_ALARM2MINUTE  0x0b    //分
#define DS3231_ALARM2HOUR    0x0c    //时
#define DS3231_ALARM2WEEK    0x0d    //星期/日
#define DS3231_CONTROL       0x0e    //控制寄存器
#define DS3231_STATUS        0x0f    //状态寄存器
#define BSY                  2       //忙
#define OSF                  7       //振荡器停止标志
#define DS3231_XTAL          0x10    //晶体老化寄存器
#define DS3231_TEMPERATUREH  0x11    //温度寄存器高字节(8位)
#define DS3231_TEMPERATUREL  0x12    //温度寄存器低字节(高2位) 


//       SCL -- PTC10         SDA -- PTC11

#define DS3231_SCL_H()   gpio_set (PTC10,1)     //拉高时钟线
#define DS3231_SCL_L()   gpio_set (PTC10,0)     //拉低时钟线

#define DS3231_SDA_H()   gpio_set (PTC11,1)     //拉高数据线 
#define DS3231_SDA_L()   gpio_set (PTC11,0)     //拉低数据线 




//初始化DS3231
void DS3231_Config(void);


//设置时间
void ModifyTime(uint8_t yea,uint8_t mon,uint8_t da,uint8_t hou,uint8_t min,uint8_t sec);

//获取DS3231的时间，温度数据
DS3231 get_DS3231_Data(void);




#endif


