#include "Password.h"

//  ��Ƶ����PTA12
//  �ӿ�  �̽�PTD4 PTD6

uint8_t  START_FLAG=0;   //��ʼ��Ƶ�ʱ�־

uint32_t Frequence;      //Ƶ��

uint8_t Password[28];   //���յ�����������   ��ͬ  ��#��28λ
uint8_t KEY[27];        //��������������
uint8_t Base_No[18]=    //��վ��
{
    '5','1','0','1','2','1','5','0','0','0','0','0','0','0','0','0','3','8'
};


uint8_t FLAG=0;   //�������ݽ������
uint8_t PULSE=0;  //������

//����Ƶ��ʶ��
void _Password(void)
{
    uint32 flag = PORTA_ISFR;
    PORTA_ISFR  = ~0;          //���жϱ�־λ
                                         
    if(flag & (1 << 12))                                
    {
        if(PULSE!=100)
        {
            PULSE++;
        
        }
        else
        {
            START_FLAG++;

            if( START_FLAG == 1 )      //��2�������ؿ�ʼ��Ƶ��
            {
                pit_time_start(PIT0);
            }
            

            if( START_FLAG == 2 )      //��3�����������ز�Ƶ��
            {
                Frequence = (uint32_t)( 1000000.0/(pit_time_get(PIT0)*1000/bus_clk_khz) );
                
                if( Frequence>=11500 && Frequence<=12500 )   // 1        12KHz
                {
                    gpio_set (PTD4, 1); 
                }
                if( Frequence>=9500 && Frequence<=10500  )   // 0        10KHz
                {
                    gpio_set (PTD4, 0); 
                }  
               
                START_FLAG=0; 
                
            }
            //
            
        }
        //
        
        
        
    }
    //
    
}
//


//������պ���  27������
uint8_t i=0; 
void Password_R(void)
{
    char ch;
    UARTn_e uartn=UART0;
    
    if( UART_S1_REG( UARTN[uartn]) & UART_S1_RDRF_MASK )
    {
        uart_getchar (UART0,&ch);
        if( ch=='#'&& FLAG==0 )   //���ݿ�ʼλ
        {
            i=0;
            FLAG=2; 
            Password[0]='0';
        }
        
        if(FLAG==2)
        {
            Password[i]=ch;
            i++;
            if(i==28)
            { 
                DisableInterrupts;    //��ֹ�ж�
                i=0;                  
                FLAG=1; 
                PULSE=0;
            }       
        }
               
    }
    //    
}
//



//��ʼ������ɼ�
void Password_Config(void)
{
    gpio_init (PTD4, GPO,1);port_init (PTD4, PF | ALT1 | PULLUP );
    
    port_init (PTA12, IRQ_FALLING | PF | ALT1 | PULLUP );
    set_vector_handler(PORTA_VECTORn , _Password);
    PORTA_ISFR  = ~0;          //���жϱ�־λ
    enable_irq(PORTA_IRQn);
    
    uart_init (UART0, 870);
    set_vector_handler( UART0_RX_TX_VECTORn ,Password_R );
    uart_rx_irq_en(UART0);
    Password_Reset();
    
}
//



//����
static int translate(int buffer)
{
    if (buffer >= 0 & buffer < 10)
    {
        buffer += 48;
    }
    else if (buffer >= 10 & buffer < 36)
    {
        buffer += 55;
    }
    else if (buffer >= 36 & buffer < 62)
    {
        buffer += 61;
    }
    else
    {
        buffer = buffer %9+48;
    }
    return buffer;
}
//


//���㵱ǰ����
static void Password_Cal(void)
{
    DS3231 ds3231;    
    
   
    uint32_t buffer;
    uint8_t A,B,C,D,E,F;
    
    
    ds3231=get_DS3231_Data();

    buffer=  (ds3231.Year/10)*100000 +  (ds3231.Year%10)*10000
           + (ds3231.Month/10)*1000  +  (ds3231.Month%10)*100
           + (ds3231.Day/10)*10      +  (ds3231.Day%10);
    
    
    A = translate( (int)(buffer+Password[1])%67 ); 
    B = translate( (int)(buffer % 100000+A)%67  );
    
    C = translate( (int)(buffer % 10000+B+Password[2]) % 67 );                 
    D = translate( (int)(buffer % 1000+C) % 67 );
    
    E = translate( (int)(buffer % 100+D+Password[3]) % 67 );                   
    F = translate( (int)( (buffer % 100)* (buffer % 10+E) ) % 69 );
    
    
    KEY[0] = Password[1];
    KEY[1] = Password[2];
    KEY[2] = Password[3];
    
    KEY[3]  = A; 
    KEY[4]  = B; 
    KEY[5]  = C; 
    KEY[6]  = D; 
    KEY[7]  = E; 
    KEY[8]  = F;
    
    
    
    KEY[9]  = Base_No[0];
    KEY[10] = Base_No[1];
    KEY[11] = Base_No[2];
    KEY[12] = Base_No[3];
    KEY[13] = Base_No[4];
    KEY[14] = Base_No[5];
    KEY[15] = Base_No[6];
    KEY[16] = Base_No[7];
    KEY[17] = Base_No[8];
    KEY[18] = Base_No[9];
    KEY[19] = Base_No[10];
    KEY[20] = Base_No[11];
    KEY[21] = Base_No[12];
    KEY[22] = Base_No[13];
    KEY[23] = Base_No[14];
    KEY[24] = Base_No[15];
    KEY[25] = Base_No[16];
    KEY[26] = Base_No[17];
    
    
}
//




//����У��    0:��������  1����ȷ����   2��δ�ɼ�������
uint8_t Password_Check(void)
{
    uint8_t flag=0;
    uint8_t i=0;
    uint8_t count=0;
    if(FLAG==1)
    {
        FLAG=0;
        Password_Cal();   //���㵱ʱ����
        
        while(i<27)      //�Ƚϵ�ǰ����
        {
            if( Password[i+1]==KEY[i] )
            {
                count++;
            }
            i++;
        }
        if(count==27)
        {
            flag=1;
        }  
        else
        {
             flag=0;
        }
        
    }
    else
    {
        flag=2;
    }
    
    
    return flag;


}
//


//��λ���뼰���־λ
void Password_Reset(void)
{
    uint8_t t=0;
    START_FLAG=0;
    PULSE=0;
    FLAG=0; 
    i=0;
    for(t=0;t<27;t++)
    {
        Password[t]='#';
    }
}
//













