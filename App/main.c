#include "User.h"               //�û�ͷ�ļ�


void  main(void)
{
    System_Config();       //��ʼ��ϵͳ����
    for(;;) 
    {
        Door_Control();   //��������
        Door_Status();    //�ſ�״̬���
        Update_Data();    //����ʱ�䡢�¶�����
        Set_Time();       //����ʱ��
        Set_Base();       //���û�վ��
        LED_TURN();       //����ָʾ
    }
    //
}
//









