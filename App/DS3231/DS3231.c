#include "DS3231.h"        //ʱ��оƬͷ�ļ�


//       SCL -- PTC10         SDA -- PTC11

 //BCDת��ΪByte
static uint8_t BCD2HEX(uint8_t val)   
{
    return   ((val>>4)*10)+(val&0x0f);
}
//

//B��ת��ΪBCD��
static uint8_t HEX2BCD(uint8_t val)    
{
    return   (((val%100)/10)<<4)|(val%10);
}
//

//iic��ʱ΢��
static void iic_delay(uint8_t us)
{
    lptmr_delay_us(us);
}
//

//iic��ʼ�ź�
static void Start_I2C(void)
{
    DS3231_SDA_H();            //������ʼ�����������ź�
    iic_delay(1);
    DS3231_SCL_H();
    iic_delay(5);              //��ʼ��������ʱ�����4.7us,��ʱ
   
    DS3231_SDA_L();            //������ʼ�ź�
    iic_delay(5);              // ��ʼ��������ʱ�����4��s
       
    DS3231_SCL_L();                     //ǯסI2C���ߣ�׼�����ͻ��������
    iic_delay(2);
}
//


//iic�����ź�
static void Stop_I2C(void)
{
    DS3231_SDA_L();                  //���ͽ��������������ź�
    iic_delay(1);             //���ͽ���������ʱ���ź�
    DS3231_SCL_H();                  //������������ʱ�����4us
    iic_delay(5);
   
    DS3231_SDA_H();                  //����I2C���߽����ź�
    iic_delay(4);
}
//


//����һ���ֽ�   ���أ�1��Ӧ��  0����Ӧ��
static uint8_t SendByte(uint8_t c)
{
    uint8_t BitCnt;
    uint8_t ack=0;
    
    for(BitCnt=0;BitCnt<8;BitCnt++)         //Ҫ���͵����ݳ���Ϊ8λ
    {
        if( (c<<BitCnt)&0x80 )            //�жϷ���λ
            DS3231_SDA_H();            
        else 
            DS3231_SDA_L(); 
        
        iic_delay(1);
        DS3231_SCL_H();       //��ʱ����Ϊ�ߣ�֪ͨ��������ʼ��������λ
        iic_delay(5);         //��֤ʱ�Ӹߵ�ƽ���ڴ���4��s   
        DS3231_SCL_L();
    }
    //
    
   
    iic_delay(2);
    DS3231_SDA_H();                //8λ��������ͷ������ߣ�׼������Ӧ��λ
    iic_delay(2);  
    DS3231_SCL_H();
    iic_delay(3);
    
    gpio_init(PTC11,GPI,1);
    
    if( gpio_get (PTC11) == 0 ) ack=1;   //�ж��Ƿ���յ�Ӧ���ź�
          
    gpio_init(PTC11,GPO,1); 
    
    DS3231_SCL_L();
    iic_delay(2);
    
    return ack;
}
//


//����һ���ֽ�   
static uint8_t RcvByte(void)
{
   uint8_t retc=0;
   uint8_t BitCnt;
 
   gpio_init(PTC11,GPI,1);             //��������Ϊ���뷽ʽ
   for(BitCnt=0;BitCnt<8;BitCnt++)
   {
        iic_delay(1);  
        DS3231_SCL_L();                //��ʱ����Ϊ�ͣ�׼����������λ
       
        iic_delay(5);                  //ʱ�ӵ͵�ƽ���ڴ���4.7��s
      
        DS3231_SCL_H();                //��ʱ����Ϊ��ʹ��������������Ч
        iic_delay(3);
        retc=retc<<1;
        if(gpio_get (PTC11) ==1 )
            retc=retc+1;               //������λ,���յ�����λ����retc��
        iic_delay(2);
   }
   DS3231_SCL_L();
   iic_delay(2);
   
   gpio_init(PTC11,GPO,1);
   return(retc);
}
//

//����Ӧ���ź�  1��Ӧ��  0:��Ӧ��
static void Ack_I2C(uint8_t a)
{
    if(a==1)
        DS3231_SDA_H();              //�ڴ˷���Ӧ����Ӧ���ź�
    else
        DS3231_SDA_L();
    iic_delay(3);     
    DS3231_SCL_H();
   
    iic_delay(5);                    //ʱ�ӵ͵�ƽ���ڴ���4��s
   
    DS3231_SCL_L();                  //��ʱ���ߣ�ǯסI2C�����Ա��������
    iic_delay(2);   
}
// 

//дһ���ֽ�
static void write_byte(uint8_t addr, uint8_t write_data)
{
    Start_I2C();
    while( !SendByte(DS3231_WriteAddress) );
    while( !SendByte(addr) );
    while( !SendByte(write_data) );
    Stop_I2C();
    iic_delay(10);      
}
//


static uint8_t read_current(void)
{
    uint8_t read_data;
    Start_I2C();
    while( !SendByte(DS3231_ReadAddress) );
    
   
    read_data = RcvByte();
    Ack_I2C(1);
    Stop_I2C();
    return read_data;
}
//

static uint8_t read_random(uint8_t random_addr)
{
    Start_I2C();
    while( !SendByte(DS3231_WriteAddress) );
   
    while( !SendByte(random_addr) );
   
    return(read_current());
}
 

//����ʱ��
void ModifyTime(uint8_t yea,uint8_t mon,uint8_t da,uint8_t hou,uint8_t min,uint8_t sec)
{
    uint8_t temp=0;
   
    temp=HEX2BCD(yea);
    write_byte(DS3231_YEAR,temp);   //�޸���
   
    temp=HEX2BCD(mon);
    write_byte(DS3231_MONTH,temp);  //�޸���
   
    temp=HEX2BCD(da);
    write_byte(DS3231_DAY,temp);    //�޸���
   
    temp=HEX2BCD(hou);
    write_byte(DS3231_HOUR,temp);   //�޸�ʱ
   
    temp=HEX2BCD(min);
    write_byte(DS3231_MINUTE,temp); //�޸ķ�
   
    temp=HEX2BCD(sec);
    write_byte(DS3231_SECOND,temp); //�޸���
}
//


//                 ��ʼ��DS3231
//       SCL -- PTC10         SDA -- PTC11
void DS3231_Config(void)
{  
    gpio_init(PTC10,GPO,1);port_init (PTC10, PF | ALT1 | PULLUP );   
    gpio_init(PTC11,GPO,1);port_init (PTC11, PF | ALT1 | PULLUP );
    lptmr_delay_ms(50);
    write_byte(DS3231_CONTROL, 0x1C);
    write_byte( DS3231_STATUS, 0x00);
    
 
}
//




//��ȡDS3231��ʱ�䣬�¶�����
DS3231 get_DS3231_Data(void)
{
    DS3231 ds3231;
    uint16 T;     //�¶ȸߵͰ�λ
    
    ds3231.Year=BCD2HEX( read_random( DS3231_YEAR )  );     //��

    ds3231.Month=BCD2HEX( read_random( DS3231_MONTH ) );    //��
    
    ds3231.Day=BCD2HEX( read_random( DS3231_DAY )     );    //��
                         
    ds3231.Hour=BCD2HEX( read_random( DS3231_HOUR )   );    //ʱ                     
                         
    ds3231.Minute=BCD2HEX( read_random( DS3231_MINUTE ) );  //��   
    
    ds3231.Second=BCD2HEX( read_random( DS3231_SECOND ) );  //��
    
    
    
    T=( ( ( (uint16_t)read_random(DS3231_TEMPERATUREH) ) <<8 )|( (uint16_t)read_random(DS3231_TEMPERATUREL) ) )>>6 ;
  
    if( (T&0X0200) ==0X0000)    //���¶�
    {
        ds3231.Temperature=(int16_t)(T*0.25); 
    
    }
    else                    //���¶�
    {
        T=T&0X01FF;
        ds3231.Temperature=-1*(int16_t)(T*0.25);
    }
    
    
   
        
        
        
    
    return ds3231;
}
//
















