#include "Key.h"           //按键头文件

extern uint8_t Base_No[];   //基站号

//按键驱动初始化
void Key_Config(void)
{
    gpio_init(PTC4,GPI,1);port_init (PTC4, PF | ALT1 | PULLUP );
    gpio_init(PTC5,GPI,1);port_init (PTC5, PF | ALT1 | PULLUP );
    gpio_init(PTC6,GPI,1);port_init (PTC6, PF | ALT1 | PULLUP );
    gpio_init(PTC7,GPI,1);port_init (PTC7, PF | ALT1 | PULLUP );

}
//


//设置时间
uint8_t time=0;
uint8_t year,mon,day,hour,min,sec;
uint8_t temp=0;
void Set_Time(void)
{
    if(0==gpio_get (PTC4))     
    {
        lptmr_delay_ms(5);
        if(0==gpio_get (PTC4))
        {
            while(0==gpio_get (PTC4));
            lptmr_delay_ms(5);
            while(0==gpio_get (PTC4));
            time=1;
            
        }
    }
    //
    while(time==1)       //设置时间
    {
/**************************设置年************************************/        
        LCD_PutChar8x16(60,2,0 + 48, Black,Red);
        while(1==gpio_get (PTC4))     //设置年的十位
        {
            if(0==gpio_get (PTC5))     
            {
                lptmr_delay_ms(5);
                if(0==gpio_get (PTC5))
                {
                    while(0==gpio_get (PTC5));
                    lptmr_delay_ms(5);
                    while(0==gpio_get (PTC5));
                    temp++;
                    if(temp==11)
                    {
                        temp=0;
                        LCD_PutChar8x16(60,2,temp+48, Black,Red);
                    }
                    else
                    {
                        LCD_PutChar8x16(60,2,temp + 47, Black,Red);
                    }   
                }
            }
            //
            
        
        }
        //
        lptmr_delay_ms(5);while(0==gpio_get (PTC4));
        if(temp!=0){temp-=1;} LCD_PutChar8x16(60,2,temp+48, Black,0X95BB);
        year=temp*10;temp=0;
        
        
        LCD_PutChar8x16(68,2,0 + 48, Black,Red);
        while(1==gpio_get (PTC4))     //设置年的个位
        {
            if(0==gpio_get (PTC5))     
            {
                lptmr_delay_ms(5);
                if(0==gpio_get (PTC5))
                {
                    while(0==gpio_get (PTC5));
                    lptmr_delay_ms(5);
                    while(0==gpio_get (PTC5));
                    temp++;
                    if(temp==11)
                    {
                        temp=0;
                        LCD_PutChar8x16(68,2,temp+48, Black,Red);
                    }
                    else
                    {
                        LCD_PutChar8x16(68,2,temp + 47, Black,Red);
                    }   
                }
            }
            //
            
        
        }
        //
        lptmr_delay_ms(5);while(0==gpio_get (PTC4));
        if(temp!=0){temp-=1;} LCD_PutChar8x16(68,2,temp+48, Black,0X95BB); 
        year+=temp;temp=0;
        
        
        
        
/**************************设置月************************************/          
        LCD_PutChar8x16(84,2,0 + 48, Black,Red);
        while(1==gpio_get (PTC4))     //设置月的十位
        {
            if(0==gpio_get (PTC5))     
            {
                lptmr_delay_ms(5);
                if(0==gpio_get (PTC5))
                {
                    while(0==gpio_get (PTC5));
                    lptmr_delay_ms(5);
                    while(0==gpio_get (PTC5));
                    temp++;
                    if(temp==11)
                    {
                        temp=0;
                        LCD_PutChar8x16(84,2,temp+48, Black,Red);
                    }
                    else
                    {
                        LCD_PutChar8x16(84,2,temp + 47, Black,Red);
                    }   
                }
            }
            //
            
        
        }
        //
        lptmr_delay_ms(5);while(0==gpio_get (PTC4));
        if(temp!=0){temp-=1;} LCD_PutChar8x16(84,2,temp+48, Black,0X95BB);
        mon=temp*10;temp=0;
        
        
        LCD_PutChar8x16(92,2,0 + 48, Black,Red);
        while(1==gpio_get (PTC4))     //设置月的个位
        {
            if(0==gpio_get (PTC5))     
            {
                lptmr_delay_ms(5);
                if(0==gpio_get (PTC5))
                {
                    while(0==gpio_get (PTC5));
                    lptmr_delay_ms(5);
                    while(0==gpio_get (PTC5));
                    temp++;
                    if(temp==11)
                    {
                        temp=0;
                        LCD_PutChar8x16(92,2,temp+48, Black,Red);
                    }
                    else
                    {
                        LCD_PutChar8x16(92,2,temp + 47, Black,Red);
                    }   
                }
            }
            //
            
        
        }
        //
        lptmr_delay_ms(5);while(0==gpio_get (PTC4));
        if(temp!=0){temp-=1;} LCD_PutChar8x16(92,2,temp+48, Black,0X95BB); 
        mon+=temp;temp=0;
        
        
        
        
/**************************设置日************************************/          
        LCD_PutChar8x16(108,2,0 + 48, Black,Red);
        while(1==gpio_get (PTC4))     //设置日的十位
        {
            if(0==gpio_get (PTC5))     
            {
                lptmr_delay_ms(5);
                if(0==gpio_get (PTC5))
                {
                    while(0==gpio_get (PTC5));
                    lptmr_delay_ms(5);
                    while(0==gpio_get (PTC5));
                    temp++;
                    if(temp==11)
                    {
                        temp=0;
                        LCD_PutChar8x16(108,2,temp+48, Black,Red);
                    }
                    else
                    {
                        LCD_PutChar8x16(108,2,temp + 47, Black,Red);
                    }   
                }
            }
            //
            
        
        }
        //
        lptmr_delay_ms(5);while(0==gpio_get (PTC4));
        if(temp!=0){temp-=1;} LCD_PutChar8x16(108,2,temp+48, Black,0X95BB);
        day=temp*10;temp=0;
        
        
        LCD_PutChar8x16(116,2,0 + 48, Black,Red);
        while(1==gpio_get (PTC4))     //设置日的个位
        {
            if(0==gpio_get (PTC5))     
            {
                lptmr_delay_ms(5);
                if(0==gpio_get (PTC5))
                {
                    while(0==gpio_get (PTC5));
                    lptmr_delay_ms(5);
                    while(0==gpio_get (PTC5));
                    temp++;
                    if(temp==11)
                    {
                        temp=0;
                        LCD_PutChar8x16(116,2,temp+48, Black,Red);
                    }
                    else
                    {
                        LCD_PutChar8x16(116,2,temp + 47, Black,Red);
                    }   
                }
            }
            //
            
        
        }
        //
        lptmr_delay_ms(5);while(0==gpio_get (PTC4));
        if(temp!=0){temp-=1;} LCD_PutChar8x16(116,2,temp+48, Black,0X95BB); 
        day+=temp;temp=0;        
        
        
        
/**************************设置时************************************/          
        LCD_PutChar8x16(132,2,0 + 48, Black,Red);
        while(1==gpio_get (PTC4))     //设置时的十位
        {
            if(0==gpio_get (PTC5))     
            {
                lptmr_delay_ms(5);
                if(0==gpio_get (PTC5))
                {
                    while(0==gpio_get (PTC5));
                    lptmr_delay_ms(5);
                    while(0==gpio_get (PTC5));
                    temp++;
                    if(temp==11)
                    {
                        temp=0;
                        LCD_PutChar8x16(132,2,temp+48, Black,Red);
                    }
                    else
                    {
                        LCD_PutChar8x16(132,2,temp + 47, Black,Red);
                    }   
                }
            }
            //
            
        
        }
        //
        lptmr_delay_ms(5);while(0==gpio_get (PTC4));
        if(temp!=0){temp-=1;} LCD_PutChar8x16(132,2,temp+48, Black,0X95BB);
        hour=temp*10;temp=0;
        
        
        LCD_PutChar8x16(140,2,0 + 48, Black,Red);
        while(1==gpio_get (PTC4))     //设置时的个位
        {
            if(0==gpio_get (PTC5))     
            {
                lptmr_delay_ms(5);
                if(0==gpio_get (PTC5))
                {
                    while(0==gpio_get (PTC5));
                    lptmr_delay_ms(5);
                    while(0==gpio_get (PTC5));
                    temp++;
                    if(temp==11)
                    {
                        temp=0;
                        LCD_PutChar8x16(140,2,temp+48, Black,Red);
                    }
                    else
                    {
                        LCD_PutChar8x16(140,2,temp + 47, Black,Red);
                    }   
                }
            }
            //
            
        
        }
        //
        lptmr_delay_ms(5);while(0==gpio_get (PTC4));
        if(temp!=0){temp-=1;} LCD_PutChar8x16(140,2,temp+48, Black,0X95BB); 
        hour+=temp;temp=0;        
        
        
/**************************设置分************************************/          
        LCD_PutChar8x16(156,2,0 + 48, Black,Red);
        while(1==gpio_get (PTC4))     //设置分的十位
        {
            if(0==gpio_get (PTC5))     
            {
                lptmr_delay_ms(5);
                if(0==gpio_get (PTC5))
                {
                    while(0==gpio_get (PTC5));
                    lptmr_delay_ms(5);
                    while(0==gpio_get (PTC5));
                    temp++;
                    if(temp==11)
                    {
                        temp=0;
                        LCD_PutChar8x16(156,2,temp+48, Black,Red);
                    }
                    else
                    {
                        LCD_PutChar8x16(156,2,temp + 47, Black,Red);
                    }   
                }
            }
            //
            
        
        }
        //
        lptmr_delay_ms(5);while(0==gpio_get (PTC4));
        if(temp!=0){temp-=1;} LCD_PutChar8x16(156,2,temp+48, Black,0X95BB);
        min=temp*10;temp=0;
        
        
        LCD_PutChar8x16(164,2,0 + 48, Black,Red);
        while(1==gpio_get (PTC4))     //设置分的个位
        {
            if(0==gpio_get (PTC5))     
            {
                lptmr_delay_ms(5);
                if(0==gpio_get (PTC5))
                {
                    while(0==gpio_get (PTC5));
                    lptmr_delay_ms(5);
                    while(0==gpio_get (PTC5));
                    temp++;
                    if(temp==11)
                    {
                        temp=0;
                        LCD_PutChar8x16(164,2,temp+48, Black,Red);
                    }
                    else
                    {
                        LCD_PutChar8x16(164,2,temp + 47, Black,Red);
                    }   
                }
            }
            //
            
        
        }
        //
        lptmr_delay_ms(5);while(0==gpio_get (PTC4));
        if(temp!=0){temp-=1;} LCD_PutChar8x16(164,2,temp+48, Black,0X95BB); 
        min+=temp;temp=0;
        
        
        
/**************************设置秒************************************/          
        LCD_PutChar8x16(180,2,0 + 48, Black,Red);
        while(1==gpio_get (PTC4))     //设置秒的十位
        {
            if(0==gpio_get (PTC5))     
            {
                lptmr_delay_ms(5);
                if(0==gpio_get (PTC5))
                {
                    while(0==gpio_get (PTC5));
                    lptmr_delay_ms(5);
                    while(0==gpio_get (PTC5));
                    temp++;
                    if(temp==11)
                    {
                        temp=0;
                        LCD_PutChar8x16(180,2,temp+48, Black,Red);
                    }
                    else
                    {
                        LCD_PutChar8x16(180,2,temp + 47, Black,Red);
                    }   
                }
            }
            //
            
        
        }
        //
        lptmr_delay_ms(5);while(0==gpio_get (PTC4));
        if(temp!=0){temp-=1;} LCD_PutChar8x16(180,2,temp+48, Black,0X95BB);
        sec=temp*10;temp=0;
        
        
        LCD_PutChar8x16(186,2,0 + 48, Black,Red);
        while(1==gpio_get (PTC4))     //设置秒的个位
        {
            if(0==gpio_get (PTC5))     
            {
                lptmr_delay_ms(5);
                if(0==gpio_get (PTC5))
                {
                    while(0==gpio_get (PTC5));
                    lptmr_delay_ms(5);
                    while(0==gpio_get (PTC5));
                    temp++;
                    if(temp==11)
                    {
                        temp=0;
                        LCD_PutChar8x16(186,2,temp+48, Black,Red);
                    }
                    else
                    {
                        LCD_PutChar8x16(186,2,temp + 47, Black,Red);
                    }   
                }
            }
            //
            
        
        }
        //
        lptmr_delay_ms(5);while(0==gpio_get (PTC4));
        if(temp!=0){temp-=1;} LCD_PutChar8x16(186,2,temp+48, Black,0X95BB); 
        sec+=temp;temp=0;
        
        
        
        ModifyTime(year,mon,day,hour,min,sec);   //设置时间
        
        
        
        time=0;
        
        
        
    }
    //

}
//


//设置基站号
uint8_t base=0;
void Set_Base(void)
{
    uint8_t i=0,x=56;
    if(0==gpio_get (PTC6))     
    {
        lptmr_delay_ms(5);
        if(0==gpio_get (PTC6))
        {
            while(0==gpio_get (PTC6));
            lptmr_delay_ms(5);
            while(0==gpio_get (PTC6));
            base=1;
            
        }
    }
    //
    while(base==1)
    {
        for(i=0;i<18;i++)
        {
        
            LCD_PutChar8x16(x,18,0 + 48, Black,Red);
            while(1==gpio_get (PTC6))     //设置年的十位
            {
                if(0==gpio_get (PTC7))     
                {
                    lptmr_delay_ms(5);
                    if(0==gpio_get (PTC7))
                    {
                        while(0==gpio_get (PTC7));
                        lptmr_delay_ms(5);
                        while(0==gpio_get (PTC7));
                        temp++;
                        if(temp==11)
                        {
                            temp=0;
                            LCD_PutChar8x16(x,18,temp+48, Black,Red);
                        }
                        else
                        {
                            LCD_PutChar8x16(x,18,temp + 47, Black,Red);
                        }   
                    }
                }
                //

            }
            //
            lptmr_delay_ms(5);while(0==gpio_get (PTC6));
            if(temp!=0){temp-=1;} LCD_PutChar8x16(x,18,temp+48, Black,0X95BB);
            Base_No[i]=temp;temp=0;x+=8;
        
        
        }
        //
        
        base=0;
    
    }
    //
    

}
//






