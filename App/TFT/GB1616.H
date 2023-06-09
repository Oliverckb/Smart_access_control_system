#ifndef GB1616_H
#define GB1616_H

// ------------------  汉字字模的数据结构定义 ------------------------ //
struct  typFNT_GB16                 // 汉字字模数据结构 
{
       unsigned char  Index[3];               // 汉字内码索引	
       unsigned char   Msk[32];                        // 点阵码数据 
};

/////////////////////////////////////////////////////////////////////////
// 汉字字模表                                                          //
// 汉字库: 宋体16.dot,横向取模左高位,数据排列:从左到右从上到下         //
/////////////////////////////////////////////////////////////////////////
const struct  typFNT_GB16 codeGB_16[] =          // 数据表 
{
    
     
/*--  文字:   系  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"系",
0x00,0xF8,0x3F,0x00,0x04,0x00,0x08,0x20,0x10,0x40,0x3F,0x80,0x01,0x00,0x06,0x10,
0x18,0x08,0x7F,0xFC,0x01,0x04,0x09,0x20,0x11,0x10,0x21,0x08,0x45,0x04,0x02,0x00,

/*--  文字:   统  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"统",
0x10,0x40,0x10,0x20,0x20,0x20,0x23,0xFE,0x48,0x40,0xF8,0x88,0x11,0x04,0x23,0xFE,
0x40,0x92,0xF8,0x90,0x40,0x90,0x00,0x90,0x19,0x12,0xE1,0x12,0x42,0x0E,0x04,0x00,

/*--  文字:   启  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"启",
0x01,0x00,0x00,0x80,0x1F,0xFC,0x10,0x04,0x10,0x04,0x10,0x04,0x1F,0xFC,0x10,0x00,
0x10,0x00,0x10,0x00,0x17,0xFC,0x24,0x04,0x24,0x04,0x44,0x04,0x87,0xFC,0x04,0x04,

/*--  文字:   动  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"动",
0x00,0x40,0x00,0x40,0x7C,0x40,0x00,0x40,0x01,0xFC,0x00,0x44,0xFE,0x44,0x20,0x44,
0x20,0x44,0x20,0x84,0x48,0x84,0x44,0x84,0xFD,0x04,0x45,0x04,0x02,0x28,0x04,0x10,

/*--  文字:   中  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"中",
0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x3F,0xF8,0x21,0x08,0x21,0x08,0x21,0x08,
0x21,0x08,0x21,0x08,0x3F,0xF8,0x21,0x08,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,


/*--  文字:   完  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"完",
0x02,0x00,0x01,0x00,0x7F,0xFE,0x40,0x02,0x80,0x04,0x1F,0xF0,0x00,0x00,0x00,0x00,
0x7F,0xFC,0x04,0x40,0x04,0x40,0x04,0x40,0x08,0x44,0x08,0x44,0x10,0x44,0x60,0x3C,

/*--  文字:   成  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"成",
0x00,0x50,0x00,0x48,0x00,0x40,0x3F,0xFE,0x20,0x40,0x20,0x40,0x20,0x44,0x3E,0x44,
0x22,0x44,0x22,0x28,0x22,0x28,0x22,0x12,0x2A,0x32,0x44,0x4A,0x40,0x86,0x81,0x02,

/*--  文字:   空格  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
" ",
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,


/*--  文字:   基  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"基",
0x08,0x20,0x08,0x20,0x7F,0xFC,0x08,0x20,0x0F,0xE0,0x08,0x20,0x0F,0xE0,0x08,0x20,
0xFF,0xFE,0x08,0x20,0x11,0x10,0x21,0x08,0xCF,0xE6,0x01,0x00,0x01,0x00,0x3F,0xF8,


/*--  文字:   站  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"站",
0x10,0x20,0x08,0x20,0x08,0x20,0x7E,0x20,0x00,0x3E,0x04,0x20,0x44,0x20,0x44,0x20,
0x25,0xFC,0x29,0x04,0x29,0x04,0x0F,0x04,0xF1,0x04,0x41,0x04,0x01,0xFC,0x01,0x04,

/*--  文字:   号  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"号",
0x00,0x00,0x1F,0xF0,0x10,0x10,0x10,0x10,0x10,0x10,0x1F,0xF0,0x00,0x00,0xFF,0xFE,
0x08,0x00,0x10,0x00,0x1F,0xF0,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0xA0,0x00,0x40,


/*--  文字:   密  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"密",
0x02,0x00,0x01,0x00,0x7F,0xFE,0x40,0x02,0x82,0x24,0x09,0x40,0x28,0x88,0x4B,0x14,
0x1C,0x10,0xE7,0xF0,0x01,0x00,0x21,0x08,0x21,0x08,0x21,0x08,0x3F,0xF8,0x00,0x08,

/*--  文字:   码  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"码",
0x00,0x00,0x01,0xF8,0xFC,0x08,0x10,0x08,0x10,0x88,0x20,0x88,0x3C,0x88,0x64,0xFE,
0x64,0x02,0xA4,0x02,0x24,0x02,0x25,0xFA,0x3C,0x02,0x24,0x02,0x20,0x14,0x00,0x08,


/*--  文字:   状  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"状",
0x08,0x40,0x08,0x48,0x08,0x44,0x48,0x44,0x28,0x40,0x2F,0xFE,0x08,0x40,0x08,0x40,
0x18,0x40,0x28,0xA0,0xC8,0xA0,0x08,0x90,0x09,0x10,0x09,0x08,0x0A,0x04,0x0C,0x02,


/*--  文字:   态  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"态",
0x01,0x00,0x01,0x00,0x7F,0xFC,0x01,0x00,0x02,0x80,0x04,0x40,0x0A,0x20,0x31,0x18,
0xC0,0x06,0x01,0x00,0x08,0x88,0x48,0x84,0x48,0x12,0x48,0x12,0x87,0xF0,0x00,0x00,


/*--  文字:   开  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"开",
0x00,0x00,0x7F,0xFC,0x08,0x20,0x08,0x20,0x08,0x20,0x08,0x20,0x08,0x20,0xFF,0xFE,
0x08,0x20,0x08,0x20,0x08,0x20,0x08,0x20,0x10,0x20,0x10,0x20,0x20,0x20,0x40,0x20,


/*--  文字:   关  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"关",
0x10,0x10,0x08,0x10,0x08,0x20,0x00,0x00,0x3F,0xF8,0x01,0x00,0x01,0x00,0x01,0x00,
0xFF,0xFE,0x01,0x00,0x02,0x80,0x02,0x80,0x04,0x40,0x08,0x20,0x30,0x18,0xC0,0x06,


/*--  文字:   时  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"时",
0x00,0x08,0x00,0x08,0x7C,0x08,0x44,0x08,0x45,0xFE,0x44,0x08,0x44,0x08,0x7C,0x08,
0x44,0x88,0x44,0x48,0x44,0x48,0x44,0x08,0x7C,0x08,0x44,0x08,0x00,0x28,0x00,0x10,



/*--  文字:   间  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"间",
0x20,0x00,0x13,0xFC,0x10,0x04,0x40,0x04,0x47,0xC4,0x44,0x44,0x44,0x44,0x44,0x44,
0x47,0xC4,0x44,0x44,0x44,0x44,0x44,0x44,0x47,0xC4,0x40,0x04,0x40,0x14,0x40,0x08,


/*--  文字:   正  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"正",
0x00,0x00,0x7F,0xFC,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x11,0x00,0x11,0xF8,
0x11,0x00,0x11,0x00,0x11,0x00,0x11,0x00,0x11,0x00,0x11,0x00,0xFF,0xFE,0x00,0x00,


/*--  文字:   确  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"确",
0x00,0x40,0x00,0x40,0xFC,0x7C,0x10,0x84,0x11,0x08,0x22,0xFE,0x3C,0x92,0x64,0x92,
0x64,0xFE,0xA4,0x92,0x24,0x92,0x24,0xFE,0x3C,0x92,0x25,0x12,0x21,0x0A,0x02,0x04,

/*--  文字:   错  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"错",
0x21,0x10,0x21,0x10,0x39,0x10,0x27,0xFC,0x41,0x10,0x79,0x10,0xAF,0xFE,0x20,0x00,
0xFB,0xF8,0x22,0x08,0x22,0x08,0x23,0xF8,0x2A,0x08,0x32,0x08,0x23,0xF8,0x02,0x08,


/*--  文字:   误  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"误",
0x00,0x00,0x43,0xF8,0x22,0x08,0x22,0x08,0x03,0xF8,0x00,0x00,0xE0,0x00,0x27,0xFC,
0x20,0x40,0x20,0x40,0x2F,0xFE,0x20,0x40,0x28,0xA0,0x31,0x10,0x22,0x08,0x0C,0x06,


/*--  文字:   温  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"温",
0x00,0x00,0x23,0xF8,0x12,0x08,0x12,0x08,0x83,0xF8,0x42,0x08,0x42,0x08,0x13,0xF8,
0x10,0x00,0x27,0xFC,0xE4,0xA4,0x24,0xA4,0x24,0xA4,0x24,0xA4,0x2F,0xFE,0x00,0x00,


/*--  文字:   度  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"度",
0x01,0x00,0x00,0x80,0x3F,0xFE,0x22,0x20,0x22,0x20,0x3F,0xFC,0x22,0x20,0x22,0x20,
0x23,0xE0,0x20,0x00,0x2F,0xF0,0x24,0x10,0x42,0x20,0x41,0xC0,0x86,0x30,0x38,0x0E,


/*--  文字:   门  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"门",
0x20,0x00,0x13,0xFC,0x10,0x04,0x40,0x04,0x40,0x04,0x40,0x04,0x40,0x04,0x40,0x04,
0x40,0x04,0x40,0x04,0x40,0x04,0x40,0x04,0x40,0x04,0x40,0x04,0x40,0x14,0x40,0x08,




};



#endif
