#include "DS3231.h"        //时钟芯片头文件


//       SCL -- PTC10         SDA -- PTC11

 //BCD转换为Byte
static uint8_t BCD2HEX(uint8_t val)   
{
    return   ((val>>4)*10)+(val&0x0f);
}
//

//B码转换为BCD码
static uint8_t HEX2BCD(uint8_t val)    
{
    return   (((val%100)/10)<<4)|(val%10);
}
//

//iic延时微秒
static void iic_delay(uint8_t us)
{
    lptmr_delay_us(us);
}
//

//iic起始信号
static void Start_I2C(void)
{
    DS3231_SDA_H();            //发送起始条件的数据信号
    iic_delay(1);
    DS3231_SCL_H();
    iic_delay(5);              //起始条件建立时间大于4.7us,延时
   
    DS3231_SDA_L();            //发送起始信号
    iic_delay(5);              // 起始条件锁定时间大于4μs
       
    DS3231_SCL_L();                     //钳住I2C总线，准备发送或接收数据
    iic_delay(2);
}
//


//iic结束信号
static void Stop_I2C(void)
{
    DS3231_SDA_L();                  //发送结束条件的数据信号
    iic_delay(1);             //发送结束条件的时钟信号
    DS3231_SCL_H();                  //结束条件建立时间大于4us
    iic_delay(5);
   
    DS3231_SDA_H();                  //发送I2C总线结束信号
    iic_delay(4);
}
//


//发送一个字节   返回：1有应答  0：无应答
static uint8_t SendByte(uint8_t c)
{
    uint8_t BitCnt;
    uint8_t ack=0;
    
    for(BitCnt=0;BitCnt<8;BitCnt++)         //要传送的数据长度为8位
    {
        if( (c<<BitCnt)&0x80 )            //判断发送位
            DS3231_SDA_H();            
        else 
            DS3231_SDA_L(); 
        
        iic_delay(1);
        DS3231_SCL_H();       //置时钟线为高，通知被控器开始接收数据位
        iic_delay(5);         //保证时钟高电平周期大于4μs   
        DS3231_SCL_L();
    }
    //
    
   
    iic_delay(2);
    DS3231_SDA_H();                //8位发送完后释放数据线，准备接收应答位
    iic_delay(2);  
    DS3231_SCL_H();
    iic_delay(3);
    
    gpio_init(PTC11,GPI,1);
    
    if( gpio_get (PTC11) == 0 ) ack=1;   //判断是否接收到应答信号
          
    gpio_init(PTC11,GPO,1); 
    
    DS3231_SCL_L();
    iic_delay(2);
    
    return ack;
}
//


//接收一个字节   
static uint8_t RcvByte(void)
{
   uint8_t retc=0;
   uint8_t BitCnt;
 
   gpio_init(PTC11,GPI,1);             //置数据线为输入方式
   for(BitCnt=0;BitCnt<8;BitCnt++)
   {
        iic_delay(1);  
        DS3231_SCL_L();                //置时钟线为低，准备接收数据位
       
        iic_delay(5);                  //时钟低电平周期大于4.7μs
      
        DS3231_SCL_H();                //置时钟线为高使数据线上数据有效
        iic_delay(3);
        retc=retc<<1;
        if(gpio_get (PTC11) ==1 )
            retc=retc+1;               //读数据位,接收的数据位放入retc中
        iic_delay(2);
   }
   DS3231_SCL_L();
   iic_delay(2);
   
   gpio_init(PTC11,GPO,1);
   return(retc);
}
//

//发送应答信号  1：应答  0:不应答
static void Ack_I2C(uint8_t a)
{
    if(a==1)
        DS3231_SDA_H();              //在此发出应答或非应答信号
    else
        DS3231_SDA_L();
    iic_delay(3);     
    DS3231_SCL_H();
   
    iic_delay(5);                    //时钟低电平周期大于4μs
   
    DS3231_SCL_L();                  //清时钟线，钳住I2C总线以便继续接收
    iic_delay(2);   
}
// 

//写一个字节
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
 

//设置时间
void ModifyTime(uint8_t yea,uint8_t mon,uint8_t da,uint8_t hou,uint8_t min,uint8_t sec)
{
    uint8_t temp=0;
   
    temp=HEX2BCD(yea);
    write_byte(DS3231_YEAR,temp);   //修改年
   
    temp=HEX2BCD(mon);
    write_byte(DS3231_MONTH,temp);  //修改月
   
    temp=HEX2BCD(da);
    write_byte(DS3231_DAY,temp);    //修改日
   
    temp=HEX2BCD(hou);
    write_byte(DS3231_HOUR,temp);   //修改时
   
    temp=HEX2BCD(min);
    write_byte(DS3231_MINUTE,temp); //修改分
   
    temp=HEX2BCD(sec);
    write_byte(DS3231_SECOND,temp); //修改秒
}
//


//                 初始化DS3231
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




//获取DS3231的时间，温度数据
DS3231 get_DS3231_Data(void)
{
    DS3231 ds3231;
    uint16 T;     //温度高低八位
    
    ds3231.Year=BCD2HEX( read_random( DS3231_YEAR )  );     //年

    ds3231.Month=BCD2HEX( read_random( DS3231_MONTH ) );    //月
    
    ds3231.Day=BCD2HEX( read_random( DS3231_DAY )     );    //日
                         
    ds3231.Hour=BCD2HEX( read_random( DS3231_HOUR )   );    //时                     
                         
    ds3231.Minute=BCD2HEX( read_random( DS3231_MINUTE ) );  //分   
    
    ds3231.Second=BCD2HEX( read_random( DS3231_SECOND ) );  //分
    
    
    
    T=( ( ( (uint16_t)read_random(DS3231_TEMPERATUREH) ) <<8 )|( (uint16_t)read_random(DS3231_TEMPERATUREL) ) )>>6 ;
  
    if( (T&0X0200) ==0X0000)    //正温度
    {
        ds3231.Temperature=(int16_t)(T*0.25); 
    
    }
    else                    //负温度
    {
        T=T&0X01FF;
        ds3231.Temperature=-1*(int16_t)(T*0.25);
    }
    
    
   
        
        
        
    
    return ds3231;
}
//
















