#include "DOOR.h"



//�������Ƽ���ʼ��
//״̬���  PD0
//��������  PB0
void Door_Init(void)
{
    //��������
    gpio_init (PTB0, GPO,0);      
    port_init (PTB0,  PF | ALT1 | PULLUP ); 
    
    //״̬���    
    gpio_init (PTD0, GPI,1);     
    port_init (PTD0,  PF | ALT1 | PULLUP ); 
    

}
//

//��������
void Door_Control(void)
{
    uint8_t Status=0;           //����У��״̬
    Status=Password_Check();    //У������   
    
    if(Status==0)           //��������
    {
        Password_Reset();
        Password_Wrong();
        gpio_set (PTB0,0); 
        EnableInterrupts;   //���ж�
    }
    if(Status==1)          //��ȷ����
    { 
        Password_Reset();
        Password_Right();
        gpio_set (PTB0,1);
        DelayMs(500);
        gpio_set (PTB0,0); 
        EnableInterrupts;   //���ж�   
    }
    if(Status==2)      //δ��⵽����
    {
        gpio_set (PTB0,0); 
    }


}
//



//�ſ�״̬���
uint8_t STATUS_FLAG=0;
void Door_Status(void)
{
    if( 0==gpio_get (PTD0) )  //����״̬
    {
        lptmr_delay_ms(5);
        if( 0==gpio_get (PTD0) )  
        {
            if(STATUS_FLAG==0)
            {
                STATUS_FLAG=1;
                Show_Open();  
                ShowOpenTime();
            }  
        }
        //
    }
    else                     //����״̬
    {
        if(STATUS_FLAG==1)
        {
            if( 1==gpio_get (PTD0) )  
            {
                lptmr_delay_ms(5);
                if( 1==gpio_get (PTD0) )
                {
                    STATUS_FLAG=0;
                    Password_Wrong();
                    Show_Close();
                    ShowCloseTime();  
                }
                
            }
            //
        }
    
    }

}
//





