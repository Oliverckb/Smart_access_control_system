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

}DS3231;        //DS3231���ݽṹ��


#define  LED_INIT()    gpio_init (PTA15, GPO,1)      //��ʼ������LED
#define  LED_TURN()    gpio_turn (    PTA15   )      //���� LED ��˸

#define  DelayMs(ms)   lptmr_delay_ms(ms)            //��ʱ���뺯��




#include "TFT.h"           // ��ʾ��ͷ�ļ�
#include "Password.h"      //����ͷ�ļ�
#include "DS3231.h"        //ʱ��оƬͷ�ļ�
#include "Display.h"       //��Ļ��ʾ����ͷ�ļ�
#include "DOOR.h"          //�ſ�ͷ�ļ�
#include "Key.h"           //����ͷ�ļ�
                

//ϵͳ����
void System_Config(void);






#endif