#include "User.h"       //�û�ͷ�ļ�



//ϵͳ����
void System_Config(void)
{
    DisableInterrupts;
    LED_INIT();             //��ʼ������LED   PA15
    DS3231_Config();        //��ʼ��DS3231
    TFT_Init();             //��ʾ����ʼ��
    Back_image();           //��ʾ����ͼƬ
    Wait_Start();           //�ȴ��������
    Show_Time();            //��ʾʱ��
    Show_StaticText();      //��ʾ����ʾ��̬����
    Show_Temperature();     //��ʾ�¶�
    Password_Config();      //��ʼ������ɼ�
    Door_Init();            //��ʼ���ſۿ��Ƽ����
    Key_Config();           //��ʼ������
    EnableInterrupts;
}
//

