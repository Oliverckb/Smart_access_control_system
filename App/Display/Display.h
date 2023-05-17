#ifndef Display_H
#define Display_H


#include "User.h"

/*****************************************************
��������Wait_Start
��������
���ܣ��ȴ��������
******************************************************/
void Wait_Start(void);


/*****************************************************
��������Back_image
��������
���ܣ���ʾ����ͼƬ
******************************************************/
void Back_image(void);


/*****************************************************
��������Show_Time
��������
���ܣ���ʾʵʱʱ��
******************************************************/
void Show_Time(void);

/*****************************************************
��������Show_Temperature
��������
���ܣ���ʾʵʱ�¶�
******************************************************/
void Show_Temperature(void);


//��ʾ����ʾ��̬����
void Show_StaticText(void);


//��ʾ������ȷ
void Password_Right(void);

//��ʾ�������
void Password_Wrong(void);

//��ʾ����״̬
void Show_Open(void);

//��ʾ����״̬
void Show_Close(void);

//����ʱ�䡢�¶�����
void Update_Data(void);

//��ʾ����ʱ��
void ShowOpenTime(void);

//��ʾ����ʱ��
void ShowCloseTime(void);



#endif


