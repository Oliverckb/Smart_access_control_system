#ifndef DS3231_H
#define DS3231_H



#include "User.h"

#define DS3231_WriteAddress  0xD0    //DS3231����д��ַ 
#define DS3231_ReadAddress   0xD1    //DS3231��������ַ

#define DS3231_WriteAddress  0xD0    //����д��ַ 
#define DS3231_ReadAddress   0xD1    //��������ַ

#define DS3231_SECOND        0x00    //��
#define DS3231_MINUTE        0x01    //��
#define DS3231_HOUR          0x02    //ʱ
#define DS3231_WEEK          0x03    //����
#define DS3231_DAY           0x04    //��
#define DS3231_MONTH         0x05    //��
#define DS3231_YEAR          0x06    //��

//����1            
#define DS3231_SALARM1ECOND  0x07    //��
#define DS3231_ALARM1MINUTE  0x08    //��
#define DS3231_ALARM1HOUR    0x09    //ʱ
#define DS3231_ALARM1WEEK    0x0A    //����/��

//����2
#define DS3231_ALARM2MINUTE  0x0b    //��
#define DS3231_ALARM2HOUR    0x0c    //ʱ
#define DS3231_ALARM2WEEK    0x0d    //����/��
#define DS3231_CONTROL       0x0e    //���ƼĴ���
#define DS3231_STATUS        0x0f    //״̬�Ĵ���
#define BSY                  2       //æ
#define OSF                  7       //����ֹͣ��־
#define DS3231_XTAL          0x10    //�����ϻ��Ĵ���
#define DS3231_TEMPERATUREH  0x11    //�¶ȼĴ������ֽ�(8λ)
#define DS3231_TEMPERATUREL  0x12    //�¶ȼĴ������ֽ�(��2λ) 


//       SCL -- PTC10         SDA -- PTC11

#define DS3231_SCL_H()   gpio_set (PTC10,1)     //����ʱ����
#define DS3231_SCL_L()   gpio_set (PTC10,0)     //����ʱ����

#define DS3231_SDA_H()   gpio_set (PTC11,1)     //���������� 
#define DS3231_SDA_L()   gpio_set (PTC11,0)     //���������� 




//��ʼ��DS3231
void DS3231_Config(void);


//����ʱ��
void ModifyTime(uint8_t yea,uint8_t mon,uint8_t da,uint8_t hou,uint8_t min,uint8_t sec);

//��ȡDS3231��ʱ�䣬�¶�����
DS3231 get_DS3231_Data(void);




#endif


