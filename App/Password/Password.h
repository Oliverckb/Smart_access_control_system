#ifndef Password_H
#define Password_H



#include "User.h"




//��ʼ������ɼ�
void Password_Config(void);

//����У��    0:��������  1����ȷ����   2��δ�ɼ�������
uint8_t Password_Check(void);

//��λ���뼰���־λ
void Password_Reset(void);


#endif