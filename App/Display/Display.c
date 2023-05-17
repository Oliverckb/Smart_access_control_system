#include "Display.h"



#include "Image.h"        //����ͼƬ

extern uint8_t Base_No[];    //��վ��
//��ʾ������ȷ
void Password_Right(void)
{
    uint8_t i=40,t=38;
    LCD_PutChar16x16(i,t,"��",Red,0X95DB);i+=16;
    LCD_PutChar16x16(i,t,"ȷ",Red,0X95DB);i+=16;
    LCD_PutChar8x16 (i,t,'!',Red,0X95DB) ;
}
//


//��ʾ�������
void Password_Wrong(void)
{
    uint8_t i=40,t=38;
    LCD_PutChar16x16(i,t,"��",Red,0X95DB);i+=16;
    LCD_PutChar16x16(i,t,"��",Red,0X95DB);i+=16;
    LCD_PutChar8x16 (i,t,'!',Red,0X95DB) ;
}
//

//��ʾ����״̬
void Show_Open(void)
{
    LCD_PutChar16x16(130,38,"��",Red,0X95DB);
}
//

//��ʾ����״̬
void Show_Close(void)
{
    LCD_PutChar16x16(130,38,"��",Red,0X95DB);
}
//



/*****************************************************
��������Wait_Start
��������
���ܣ��ȴ��������
******************************************************/
void Wait_Start(void)
{
    uint8_t x1=80,y1=2;
    uint8_t x2=0,y2=20;
    
    uint8_t percent=1;
    uint8_t ge,shi,bai;
    
    LCD_PutChar16x16(x1,y1,"ϵ",Black,0X95BB);x1+=16;   
    LCD_PutChar16x16(x1,y1,"ͳ",Black,0X95BB);x1+=16; 
    LCD_PutChar16x16(x1,y1,"��",Black,0X95BB);x1+=16;   
    LCD_PutChar16x16(x1,y1,"��",Black,0X95BB);x1+=16; 
    LCD_PutChar16x16(x1,y1,"��",Black,0X95BB);x1+=25; 
   
   
    
    for(x2=0;x2<240;x2+=8)
    {
        percent++;x1=169;
        
        bai=( (percent*100)/31 ) /100;            //��λ
        shi=( ( (percent*100)/31 ) %100 )/10;     //ʮλ
        ge =( (percent*100)/31 ) %10;             //��λ
        
        LCD_PutChar8x16(x2,y2,' ', Black,Black);DelayMs(200);
        
        LCD_PutChar8x16(x1,y1,'(', Black,0X95BB);x1+=8;
        LCD_PutChar8x16(x1,y1,' ', Black,0X95BB);x1+=8;
        
        LCD_PutChar8x16(x1,y1,bai+48, Black,0X95BB);x1+=8;
        LCD_PutChar8x16(x1,y1,shi+48, Black,0X95BB);x1+=8;
        LCD_PutChar8x16(x1,y1,ge +48, Black,0X95BB);x1+=8;
        
        LCD_PutChar8x16(x1,y1,'%', Black,0X95BB);x1+=8;
        LCD_PutChar8x16(x1,y1,' ', Black,0X95BB);x1+=8;
        LCD_PutChar8x16(x1,y1,')', Black,0X95BB);x1+=8;
    }
    
    DelayMs(500);
    
    x1=80;y1=2;
    LCD_PutChar16x16(x1,y1," ",0X95BB,0X95BB);x1+=16;   
    LCD_PutChar16x16(x1,y1," ",0X95BB,0X95BB);x1+=16; 
    LCD_PutChar16x16(x1,y1," ",0X95BB,0X95BB);x1+=16;   
    LCD_PutChar16x16(x1,y1," ",0X95BB,0X95BB);x1+=16; 
    LCD_PutChar16x16(x1,y1," ",0X95BB,0X95BB);x1+=16;
    
    
    x1=169;
    LCD_PutChar8x16(x1,y1,' ', 0X95BB,0X95BB);x1+=8;
    LCD_PutChar8x16(x1,y1,' ', 0X95BB,0X95BB);x1+=8;
    LCD_PutChar8x16(x1,y1,' ', 0X95BB,0X95BB);x1+=8;
    LCD_PutChar8x16(x1,y1,' ', 0X95BB,0X95BB);x1+=8;
    LCD_PutChar8x16(x1,y1,' ', 0X95BB,0X95BB);x1+=8;  
    LCD_PutChar8x16(x1,y1,' ', 0X95BB,0X95BB);x1+=8;
    LCD_PutChar8x16(x1,y1,' ', 0X95BB,0X95BB);x1+=8;
    LCD_PutChar8x16(x1,y1,' ', 0X95BB,0X95BB);x1+=8;
    
    
    
    x1=88;y1=2;
    
    LCD_PutChar16x16(x1,y1,"��",Black,0X95BB);x1+=16;   
    LCD_PutChar16x16(x1,y1,"��",Black,0X95BB);x1+=16; 
    LCD_PutChar16x16(x1,y1,"��",Black,0X95BB);x1+=16;
    LCD_PutChar16x16(x1,y1,"��",Black,0X95BB);x1+=16;
    x1=88;y1=2;DelayMs(1000);
    
    
    
    LCD_PutChar16x16(x1,y1," ",0X95BB,0X95BB);x1+=16;   
    LCD_PutChar16x16(x1,y1," ",0X95BB,0X95BB);x1+=16; 
    LCD_PutChar16x16(x1,y1," ",0X95BB,0X95BB);x1+=16;
    LCD_PutChar16x16(x1,y1," ",0X95BB,0X95BB);x1+=16;
    
    for(x2=0;x2<240;x2+=8)
    {
        LCD_PutChar8x16(x2,y2,' ', 0X95DB,0X95DB);
    }
    
    
   
}




/*****************************************************
��������Back_image
��������
���ܣ���ʾ����ͼƬ
******************************************************/
void Back_image(void) 
{
    uint16_t x,y; 
    uint32_t i=0;
    addset(0,0);
    for(x=0;x<240;x++)
    {
        for(y=0;y<320;y++)
        {					 
            wr_com16( ( (Back_IMG[i+1]<<8)&0xff00 ) | ( Back_IMG[i]&0x00ff ) );
            i+=2; 
        }	
    }
    	
}
//


//��ʾ����ʾ��̬����
void Show_StaticText(void)
{
    uint8_t i=0,t=18;
    uint8_t p=0;
    LCD_PutChar16x16(i,t,"��",Black,0X95DB);i+=16;
    LCD_PutChar16x16(i,t,"վ",Black,0X95DB);i+=16;
    LCD_PutChar16x16(i,t,"��",Black,0X95DB);i+=16;
    LCD_PutChar8x16 (i,t,':',Black,0X95DB) ;i+=8;
    
    for(p=0;p<18;p++)
    {
       LCD_PutChar8x16(i,t,Base_No[p],Red,0X95DB);i+=8;
    }
    
     i=0;t=38;
     LCD_PutChar16x16(i,t,"��",Black,0X95DB);i+=16;
     LCD_PutChar16x16(i,t,"��",Black,0X95DB);i+=16;
     LCD_PutChar8x16 (i,t,':',Black,0X95DB) ;
     Password_Wrong();
     
     i=90;t=38;
     LCD_PutChar16x16(i,t,"״",Black,0X95DB);i+=16;
     LCD_PutChar16x16(i,t,"̬",Black,0X95DB);i+=16;
     LCD_PutChar8x16 (i,t,':',Black,0X95DB) ;
     Show_Close();
     
     i=155;t=38;
     LCD_PutChar16x16(i,t,"��",Black,0X95DB);i+=16;
     LCD_PutChar16x16(i,t,"��",Black,0X95DB);i+=16;
     LCD_PutChar8x16 (i,t,':',Red,0X95DB) ;i+=8;
     LCD_PutChar8x16 (i,t,' ',Red,0X95DB) ;i+=8;
     LCD_PutChar8x16 (i,t,' ',Red,0X95DB) ;i+=8;
     LCD_PutChar8x16 (i,t,' ',Red,0X95DB) ;i+=8;
     LCD_PutChar16x16(i,t,"��",Red,0X95DB);i+=16;
     
     
     i=0;t=58;
     LCD_PutChar16x16(i,t,"��",Black,0X95DB);i+=16;
     LCD_PutChar16x16(i,t,"��",Black,0X95DB);i+=16;
     LCD_PutChar16x16(i,t,"ʱ",Black,0X95DB);i+=16;
     LCD_PutChar16x16(i,t,"��",Black,0X95DB);i+=16;
     LCD_PutChar8x16 (i,t,':' ,Black,0X95DB);i+=6;
     
     LCD_PutChar8x16 (i,t,'0',Red,0X95DB) ;i+=6;
     LCD_PutChar8x16 (i,t,'0',Red,0X95DB) ;i+=6;
     LCD_PutChar8x16 (i,t,':' ,Red,0X95DB);i+=6;
     LCD_PutChar8x16 (i,t,'0',Red,0X95DB) ;i+=6;
     LCD_PutChar8x16 (i,t,'0',Red,0X95DB) ;i+=6;
     LCD_PutChar8x16 (i,t,':' ,Red,0X95DB);i+=6;
     LCD_PutChar8x16 (i,t,'0',Red,0X95DB) ;i+=6;
     LCD_PutChar8x16 (i,t,'0',Red,0X95DB) ;i+=8;
     
     LCD_PutChar16x16(i,t,"��",Black,0X95DB);i+=16;
     LCD_PutChar16x16(i,t,"��",Black,0X95DB);i+=16;
     LCD_PutChar16x16(i,t,"ʱ",Black,0X95DB);i+=16;
     LCD_PutChar16x16(i,t,"��",Black,0X95DB);i+=16;
     LCD_PutChar8x16 (i,t,':' ,Black,0X95DB);i+=6;
     
     LCD_PutChar8x16 (i,t,'0',Red,0X95DB) ;i+=6;
     LCD_PutChar8x16 (i,t,'0',Red,0X95DB) ;i+=6;
     LCD_PutChar8x16 (i,t,':' ,Red,0X95DB) ;i+=6;
     LCD_PutChar8x16 (i,t,'0',Red,0X95DB) ;i+=6;
     LCD_PutChar8x16 (i,t,'0',Red,0X95DB) ;i+=6;
     LCD_PutChar8x16 (i,t,':' ,Red,0X95DB) ;i+=6;
     LCD_PutChar8x16 (i,t,'0',Red,0X95DB) ;i+=6;
     LCD_PutChar8x16 (i,t,'0',Red,0X95DB) ;i+=6;
     
     
     

}
//


/*****************************************************
��������Show_Time
��������
���ܣ���ʾʵʱʱ��
******************************************************/
void Show_Time(void)
{
    uint8_t i=44,t=2;
    
    DS3231 ds3231;    
    ds3231=get_DS3231_Data();
    
    
    LCD_PutChar8x16(i,t,'2', Black,0X95BB);i+=8;
    LCD_PutChar8x16(i,t,'0', Black,0X95BB);i+=8;
    LCD_PutChar8x16(i,t,ds3231.Year/10 + 48, Black,0X95BB);i+=8;
    LCD_PutChar8x16(i,t,ds3231.Year%10 + 48, Black,0X95BB);i+=8;
    
    
    LCD_PutChar8x16(i,t,'-', Black,0X95BB);i+=8;
    
    
    LCD_PutChar8x16(i,t,ds3231.Month/10 + 48, Black,0X95BB);i+=8;
    LCD_PutChar8x16(i,t,ds3231.Month%10 + 48, Black,0X95BB);i+=8;
    
    LCD_PutChar8x16(i,t,'-', Black,0X95BB);i+=8;
    
    LCD_PutChar8x16(i,t,ds3231.Day/10 + 48, Black,0X95BB);i+=8;
    LCD_PutChar8x16(i,t,ds3231.Day%10 + 48, Black,0X95BB);i+=8;
    
    LCD_PutChar8x16(i,t,'-', Black,0X95BB);i+=8;
    
    LCD_PutChar8x16(i,t,ds3231.Hour/10 + 48, Black,0X95BB);i+=8;
    LCD_PutChar8x16(i,t,ds3231.Hour%10 + 48, Black,0X95BB);i+=8;
    
    LCD_PutChar8x16(i,t,'-', Black,0X95BB);i+=8;
    
    LCD_PutChar8x16(i,t,ds3231.Minute/10 + 48, Black,0X95BB);i+=8;
    LCD_PutChar8x16(i,t,ds3231.Minute%10 + 48, Black,0X95BB);i+=8;
    
    LCD_PutChar8x16(i,t,'-', Black,0X95BB);i+=8;
    
    LCD_PutChar8x16(i,t,ds3231.Second/10 + 48, Black,0X95BB);i+=8;
    LCD_PutChar8x16(i,t,ds3231.Second%10 + 48, Black,0X95BB);i+=8;


}
//


/*****************************************************
��������Show_Temperature
��������
���ܣ���ʾʵʱ�¶�
******************************************************/
void Show_Temperature(void)
{
    uint8_t i=195,t=38;

    DS3231 ds3231;    
    
    ds3231=get_DS3231_Data();
    LCD_PutChar8x16 (i,t,' ' ,0X95DB,0X95DB) ;i+=8;
    LCD_PutChar8x16 (i,t,(ds3231.Temperature/10)+48,Red,0X95DB) ;i+=8;
    LCD_PutChar8x16 (i,t,(ds3231.Temperature%10)+48,Red,0X95DB) ;i+=8;
    

}
//



//����ʱ�䡢�¶�����
DS3231 T={1,1,1,1,1,1,1};     //�ϴε�����
void Update_Data(void)
{
    uint8_t i=60,t=2;
    
    DS3231 ds3231;    
    ds3231=get_DS3231_Data();
   
    
    
    if(T.Year!=ds3231.Year)   //���ϴ���ʱ�䲻���
    {
        LCD_PutChar8x16(i,t,ds3231.Year/10 + 48, Black,0X95BB);i+=8;
        LCD_PutChar8x16(i,t,ds3231.Year%10 + 48, Black,0X95BB);i+=16;
        T.Year=ds3231.Year;
    }
    else
    {
        i+=24;
    }
    
    
    
    if(T.Month!=ds3231.Month)   //���ϴ���ʱ�䲻���
    {
        LCD_PutChar8x16(i,t,ds3231.Month/10 + 48, Black,0X95BB);i+=8;
        LCD_PutChar8x16(i,t,ds3231.Month%10 + 48, Black,0X95BB);i+=16;
        T.Month=ds3231.Month;
    }
    else
    {
        i+=24;
    }
    
    
    
    
    if(T.Day!=ds3231.Day)   //���ϴ���ʱ�䲻���
    {
       LCD_PutChar8x16(i,t,ds3231.Day/10 + 48, Black,0X95BB);i+=8;
       LCD_PutChar8x16(i,t,ds3231.Day%10 + 48, Black,0X95BB);i+=16;
       T.Day=ds3231.Day;
    }
    else
    {
        i+=24;
    }
    
    
    
    
    if(T.Hour!=ds3231.Hour)   //���ϴ���ʱ�䲻���
    {
        LCD_PutChar8x16(i,t,ds3231.Hour/10 + 48, Black,0X95BB);i+=8;
        LCD_PutChar8x16(i,t,ds3231.Hour%10 + 48, Black,0X95BB);i+=16;
        T.Hour=ds3231.Hour;
    }
    else
    {
        i+=24;
    }
    
    
    
    if(T.Minute!=ds3231.Minute)   //���ϴ���ʱ�䲻���
    {
        LCD_PutChar8x16(i,t,ds3231.Minute/10 + 48, Black,0X95BB);i+=8;
        LCD_PutChar8x16(i,t,ds3231.Minute%10 + 48, Black,0X95BB);i+=16;
        T.Minute=ds3231.Minute;
    }
    else
    {
        i+=24;
    }
    
   
    
    if(T.Second!=ds3231.Second)   //���ϴ���ʱ�䲻���
    {
        LCD_PutChar8x16(i,t,ds3231.Second/10 + 48, Black,0X95BB);i+=8;
        LCD_PutChar8x16(i,t,ds3231.Second%10 + 48, Black,0X95BB);
        T.Second=ds3231.Second;
    }
    
    if(T.Temperature!=ds3231.Temperature)
    {
        i=195,t=38;
        T.Temperature=ds3231.Temperature;
            
        if(ds3231.Temperature>=0)
        {
            LCD_PutChar8x16 (i,t,' ' ,0X95DB,0X95DB) ;i+=8;
            LCD_PutChar8x16 (i,t,(ds3231.Temperature/10)+48,Red,0X95DB) ;i+=8;
            LCD_PutChar8x16 (i,t,(ds3231.Temperature%10)+48,Red,0X95DB) ;i+=8;
        }
        else
        {
            ds3231.Temperature=-1*ds3231.Temperature;
            LCD_PutChar8x16 (i,t,'-' ,Red,0X95DB) ;i+=8;
            LCD_PutChar8x16 (i,t,(ds3231.Temperature/10)+48,Red,0X95DB) ;i+=8;
            LCD_PutChar8x16 (i,t,(ds3231.Temperature%10)+48,Red,0X95DB) ;i+=8;
        
        }
        
    }
    
   
    

}
//




//��ʾ����ʱ��
void ShowOpenTime(void)
{
    uint8_t i=70,t=58;
    DS3231 ds3231;    
    ds3231=get_DS3231_Data();
    LCD_PutChar8x16 (i,t,ds3231.Hour/10 + 48,Red,0X95DB) ;i+=6;
    LCD_PutChar8x16 (i,t,ds3231.Hour%10 + 48,Red,0X95DB) ;i+=6;
    
    LCD_PutChar8x16 (i,t,':' ,Red,0X95DB) ;i+=6;
    
    LCD_PutChar8x16 (i,t,ds3231.Minute/10 + 48,Red,0X95DB) ;i+=6;
    LCD_PutChar8x16 (i,t,ds3231.Minute%10 + 48,Red,0X95DB) ;i+=6;
    
    LCD_PutChar8x16 (i,t,':' ,Red,0X95DB) ;i+=6;
    
    LCD_PutChar8x16 (i,t,ds3231.Second/10 + 48,Red,0X95DB) ;i+=6;
    LCD_PutChar8x16 (i,t,ds3231.Second%10 + 48,Red,0X95DB) ;i+=8;
    
}
//



//��ʾ����ʱ��
void ShowCloseTime(void)
{
    uint8_t i=190,t=58;
    DS3231 ds3231;    
    ds3231=get_DS3231_Data();
    LCD_PutChar8x16 (i,t,ds3231.Hour/10 + 48,Red,0X95DB) ;i+=6;
    LCD_PutChar8x16 (i,t,ds3231.Hour%10 + 48,Red,0X95DB) ;i+=6;
    
    LCD_PutChar8x16 (i,t,':' ,Red,0X95DB) ;i+=6;
    
    LCD_PutChar8x16 (i,t,ds3231.Minute/10 + 48,Red,0X95DB) ;i+=6;
    LCD_PutChar8x16 (i,t,ds3231.Minute%10 + 48,Red,0X95DB) ;i+=6;
    
    LCD_PutChar8x16 (i,t,':' ,Red,0X95DB) ;i+=6;
    
    LCD_PutChar8x16 (i,t,ds3231.Second/10 + 48,Red,0X95DB) ;i+=6;
    LCD_PutChar8x16 (i,t,ds3231.Second%10 + 48,Red,0X95DB) ;i+=8;
    

}
//















