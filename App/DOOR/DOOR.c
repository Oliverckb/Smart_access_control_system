#include "DOOR.h"



//门锁控制检测初始化
//状态监测  PD0
//门锁控制  PB0
void Door_Init(void)
{
    //门锁控制
    gpio_init (PTB0, GPO,0);      
    port_init (PTB0,  PF | ALT1 | PULLUP ); 
    
    //状态监测    
    gpio_init (PTD0, GPI,1);     
    port_init (PTD0,  PF | ALT1 | PULLUP ); 
    

}
//

//门锁控制
void Door_Control(void)
{
    uint8_t Status=0;           //密码校验状态
    Status=Password_Check();    //校验密码   
    
    if(Status==0)           //错误密码
    {
        Password_Reset();
        Password_Wrong();
        gpio_set (PTB0,0); 
        EnableInterrupts;   //开中断
    }
    if(Status==1)          //正确密码
    { 
        Password_Reset();
        Password_Right();
        gpio_set (PTB0,1);
        DelayMs(500);
        gpio_set (PTB0,0); 
        EnableInterrupts;   //开中断   
    }
    if(Status==2)      //未检测到密码
    {
        gpio_set (PTB0,0); 
    }


}
//



//门口状态检测
uint8_t STATUS_FLAG=0;
void Door_Status(void)
{
    if( 0==gpio_get (PTD0) )  //开门状态
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
    else                     //关门状态
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





