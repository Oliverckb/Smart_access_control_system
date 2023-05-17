#include "TFT.h"    //显示屏头文件


//CS  -- PTE0   RST -- PTE1   A0  -- PTE2    SDI -- PTE3  SCK -- PTE4  LED -- PTE5

#include "8x16.h"     //8x16的字体
#include "GB1616.h"   //16x16的国标
#include "GB3232.h"   //32x32的国标


void  write_command(uint8_t c)
{
    uint8_t i;
    TFT_CS_L();
    TFT_A0_L();
    for(i=0;i<8;i++)
    {
        if( ( (c<<i)&0x80 ) == 0x80  )
        {
            TFT_SDI_H();
        }
        else
        {
            TFT_SDI_L();
        }
        TFT_SCK_L();
        TFT_SCK_H();
    
    } 
    TFT_CS_H();
    
}
//

void  write_data(uint8_t d)
{
    uint8_t i;
    TFT_CS_L();
    TFT_A0_H();
    for(i=0;i<8;i++)
    {
        if( ( (d<<i)&0x80 ) == 0x80  )
        {
            TFT_SDI_H();
        }
        else
        {
            TFT_SDI_L();
        }
        TFT_SCK_L();
        TFT_SCK_H();
    
    } 
    TFT_CS_H();
   
}
//

void wr_com16(uint16_t d)   
{     
    write_data( (uint8_t)( (d>>8)&0X00FF ) );  //高八位
    write_data( (uint8_t)( d&0X00FF ) );       //低八位
}
//

void addset(uint16_t x,uint16_t y)
{
      write_command(0x2a);
      wr_com16(x);
      write_command(0x2b);
      wr_com16(y);
      write_command(0x2c);
}
//


void LCD_SetPos(uint16_t x0,uint16_t x1,uint16_t y0,uint16_t y1)
{
    write_command(0x2A);
    write_data( (uint8_t)( (x0>>8)&0x00ff ) );
    write_data( (uint8_t)(   x0&0x00ff    ) );
    write_data( (uint8_t)( (x1>>8)&0x00ff ) );
    write_data( (uint8_t)(   x1&0x00ff    ) );
  
    write_command(0x2B);
    write_data( (uint8_t)( (y0>>8)&0x00ff ) );
    write_data( (uint8_t)(   y0&0x00ff    ) );
    write_data( (uint8_t)( (y1>>8)&0x00ff ) );
    write_data( (uint8_t)(   y1&0x00ff    ) );
    write_command(0x2c); 
}
//



//初始化屏幕
//CS  -- PTE0   RST -- PTE1   A0  -- PTE2    SDI -- PTE3  SCK -- PTE4  LED -- PTE5
void TFT_Init(void)
{
    gpio_init(PTE0,GPO,1);port_init (PTE0, PF | ALT1 | PULLUP );
    gpio_init(PTE1,GPO,1);port_init (PTE1, PF | ALT1 | PULLUP );
    gpio_init(PTE2,GPO,1);port_init (PTE2, PF | ALT1 | PULLUP );
    gpio_init(PTE3,GPO,1);port_init (PTE3, PF | ALT1 | PULLUP );
    gpio_init(PTE4,GPO,1);port_init (PTE4, PF | ALT1 | PULLUP );
    gpio_init(PTE5,GPO,1);port_init (PTE5, PF | ALT1 | PULLUP );
    gpio_init(PTE6,GPO,1);port_init (PTE6, PF | ALT1 | PULLUP );
   
    TFT_RST_L();
    DelayMs(100);
    TFT_RST_H();
    DelayMs(100);;
     

    write_command(0xCB);  
    write_data(0x39); 
    write_data(0x2C); 
    write_data(0x00); 
    write_data(0x34); 
    write_data(0x02); 

    write_command(0xCF);  
    write_data(0x00); 
    write_data(0XC1); 
    write_data(0X30); 
 
    write_command(0xE8);  
    write_data(0x85); 
    write_data(0x00); 
    write_data(0x78); 
 
    write_command(0xEA);  
    write_data(0x00); 
    write_data(0x00); 
 
    write_command(0xED);  
    write_data(0x64); 
    write_data(0x03); 
    write_data(0X12); 
    write_data(0X81); 

    write_command(0xF7);  
    write_data(0x20); 
  
    write_command(0xC0);    //Power control 
    write_data(0x23);   //VRH[5:0] 
 
    write_command(0xC1);    //Power control 
    write_data(0x10);   //SAP[2:0];BT[3:0] 
 
    write_command(0xC5);    //VCM control 
    write_data(0x3e); //对比度调节
    write_data(0x28); 
 
    write_command(0xC7);    //VCM control2 
    write_data(0x86);  //--
 
    write_command(0x36);    // Memory Access Control 
    write_data(0x48); //C8       //48 68竖屏//28 E8 横屏

    write_command(0x3A);    
    write_data(0x55); 

    write_command(0xB1);    
    write_data(0x00);  
    write_data(0x18); 
 
    write_command(0xB6);    // Display Function Control 
    write_data(0x08); 
    write_data(0x82);
    write_data(0x27);  
 
    write_command(0xF2);    // 3Gamma Function Disable 
    write_data(0x00); 
 
    write_command(0x26);    //Gamma curve selected 
    write_data(0x01); 
 
    write_command(0xE0);    //Set Gamma 
    write_data(0x0F); 
    write_data(0x31); 
    write_data(0x2B); 
    write_data(0x0C); 
    write_data(0x0E); 
    write_data(0x08); 
    write_data(0x4E); 
    write_data(0xF1); 
    write_data(0x37); 
    write_data(0x07); 
    write_data(0x10); 
    write_data(0x03); 
    write_data(0x0E); 
    write_data(0x09); 
    write_data(0x00); 

    write_command(0XE1);    //Set Gamma 
    write_data(0x00); 
    write_data(0x0E); 
    write_data(0x14); 
    write_data(0x03); 
    write_data(0x11); 
    write_data(0x07); 
    write_data(0x31); 
    write_data(0xC1); 
    write_data(0x48); 
    write_data(0x08); 
    write_data(0x0F); 
    write_data(0x0C); 
    write_data(0x31); 
    write_data(0x36); 
    write_data(0x0F); 
 
    write_command(0x11);    //Exit Sleep 
    DelayMs(100); 
                
    write_command(0x29);    //Display on 
    write_command(0x2c); 
   
    
  

}
//

//显示单色
void dsp_single_colour(uint16_t color)
{
    uint16_t i,j;
    addset(0,0);
    for (i=0;i<320;i++)
    for (j=0;j<240;j++)
    wr_com16(color);    

}
//


/************************************************************
函数名：LCD_PutChar8x16
  参数：x,y：显示字符的坐标  c:待显示字符   fColor，bColor：前景，背景颜色
  功能：在屏幕指定位置显示8X16的字符
*************************************************************/
void LCD_PutChar8x16(uint16_t x, uint16_t y, uint8_t c, uint16_t fColor, uint16_t bColor)
{
    uint16_t i,j;
    LCD_SetPos(x,x+8-1,y,y+16-1);
    for(i=0; i<16;i++) 
    {
        uint8_t m=Font8x16[c*16+i];
        for(j=0;j<8;j++) 
        {
            if((m&0x80)==0x80) 
            {
                wr_com16(fColor);
            }
            else 
            {
                wr_com16(bColor);
            }
            m<<=1;
        }
    }
}
//


/************************************************************
函数名：LCD_PutChar16x16
  参数：x,y：显示字符的坐标  c:待显示字符   fColor，bColor：前景，背景颜色    
  功能：在屏幕指定位置显示16X16的汉字字符
*************************************************************/
void LCD_PutChar16x16(uint16_t x, uint16_t  y, uint8_t c[2], uint16_t fColor,uint16_t bColor)
{

    uint16_t i,j,k;

    LCD_SetPos(x,  x+16-1,y, y+16-1);

    for (k=0;k<64;k++) 
    { //64标示自建汉字库中的个数，循环查询内码
        if ((codeGB_16[k].Index[0]==c[0])&&(codeGB_16[k].Index[1]==c[1]))
        { 
            for(i=0;i<32;i++) 
            {
                uint16_t m=codeGB_16[k].Msk[i];
                for(j=0;j<8;j++) 
                {
                    if((m&0x80)==0x80) 
                    {
                        wr_com16(fColor);
                    }
                    else 
                    {
                        wr_com16(bColor);
                    }
                    m<<=1;
                } 
            }
        }  
    }	
}
//