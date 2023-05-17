#ifndef TFT_H
#define TFT_H

#include "User.h"


//CS  -- PTE0   RST -- PTE1   A0  -- PTE2    SDI -- PTE3  SCK -- PTE4  LED -- PTE5

#define TFT_CS_H()   gpio_set (PTE0,1)        //TFT_CS�����
#define TFT_CS_L()   gpio_set (PTE0,0)        //TFT_CS�����

#define TFT_RST_H()   gpio_set (PTE1,1)       //TFT_RST�����
#define TFT_RST_L()   gpio_set (PTE1,0)        //TFT_RST �����

#define TFT_A0_H()    gpio_set (PTE2,1)        //TFT_A0�����
#define TFT_A0_L()    gpio_set (PTE2,0)        //TFT_A0�����

#define TFT_SDI_H()   gpio_set (PTE3,1)        //TFT_SDI �����
#define TFT_SDI_L()   gpio_set (PTE3,0)        //TFT_SDI �����

#define TFT_SCK_H()   gpio_set (PTE4,1)        //TFT_SCK�����
#define TFT_SCK_L()   gpio_set (PTE4,0)        //TFT_SCK �����


#define LED_ON()      gpio_set (PTE5,1)        //������
#define LED_OFF()     gpio_set (PTE5,0)        //������







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





//��ʼ����Ļ
//CS  -- PTE0   RST -- PTE1   A0  -- PTE2    SDI -- PTE3  SCK -- PTE4  LED -- PTE5
void TFT_Init(void);


//��ʾ��ɫ
void dsp_single_colour(uint16_t color);


/************************************************************
��������LCD_PutChar8x16
  ������x,y����ʾ�ַ�������  c:����ʾ�ַ�   fColor��bColor��ǰ����������ɫ
  ���ܣ�����Ļָ��λ����ʾ8X16���ַ�
*************************************************************/
void LCD_PutChar8x16(uint16_t x, uint16_t y, uint8_t c, uint16_t fColor, uint16_t bColor);



/************************************************************
��������LCD_PutChar16x16
  ������x,y����ʾ�ַ�������  c:����ʾ�ַ�   fColor��bColor��ǰ����������ɫ    
  ���ܣ�����Ļָ��λ����ʾ16X16�ĺ����ַ�
*************************************************************/
void LCD_PutChar16x16(uint16_t x, uint16_t y, uint8_t c[2], uint16_t fColor,uint16_t bColor);







#endif


