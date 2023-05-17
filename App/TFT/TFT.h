#ifndef TFT_H
#define TFT_H

#include "User.h"


//CS  -- PTE0   RST -- PTE1   A0  -- PTE2    SDI -- PTE3  SCK -- PTE4  LED -- PTE5

#define TFT_CS_H()   gpio_set (PTE0,1)        //TFT_CS输出高
#define TFT_CS_L()   gpio_set (PTE0,0)        //TFT_CS输出低

#define TFT_RST_H()   gpio_set (PTE1,1)       //TFT_RST输出高
#define TFT_RST_L()   gpio_set (PTE1,0)        //TFT_RST 输出低

#define TFT_A0_H()    gpio_set (PTE2,1)        //TFT_A0输出高
#define TFT_A0_L()    gpio_set (PTE2,0)        //TFT_A0输出低

#define TFT_SDI_H()   gpio_set (PTE3,1)        //TFT_SDI 输出高
#define TFT_SDI_L()   gpio_set (PTE3,0)        //TFT_SDI 输出低

#define TFT_SCK_H()   gpio_set (PTE4,1)        //TFT_SCK输出高
#define TFT_SCK_L()   gpio_set (PTE4,0)        //TFT_SCK 输出低


#define LED_ON()      gpio_set (PTE5,1)        //背光亮
#define LED_OFF()     gpio_set (PTE5,0)        //背光灭







#define White          0xFFFF
#define Black          0x0000
#define Blue           0x001F
#define Blue2          0x051F
#define Red            0xF800
#define Magenta        0xF81F
#define Green          0x07E0
#define Cyan           0x7FFF
#define Yellow         0xFFE0


void  write_command(uint8_t c);
void  write_data(uint8_t d);
void wr_com16(uint16_t d);
void addset(uint16_t x,uint16_t y);
void LCD_SetPos(uint16_t x0,uint16_t x1,uint16_t y0,uint16_t y1);





//初始化屏幕
//CS  -- PTE0   RST -- PTE1   A0  -- PTE2    SDI -- PTE3  SCK -- PTE4  LED -- PTE5
void TFT_Init(void);


//显示单色
void dsp_single_colour(uint16_t color);


/************************************************************
函数名：LCD_PutChar8x16
  参数：x,y：显示字符的坐标  c:待显示字符   fColor，bColor：前景，背景颜色
  功能：在屏幕指定位置显示8X16的字符
*************************************************************/
void LCD_PutChar8x16(uint16_t x, uint16_t y, uint8_t c, uint16_t fColor, uint16_t bColor);



/************************************************************
函数名：LCD_PutChar16x16
  参数：x,y：显示字符的坐标  c:待显示字符   fColor，bColor：前景，背景颜色    
  功能：在屏幕指定位置显示16X16的汉字字符
*************************************************************/
void LCD_PutChar16x16(uint16_t x, uint16_t y, uint8_t c[2], uint16_t fColor,uint16_t bColor);







#endif


