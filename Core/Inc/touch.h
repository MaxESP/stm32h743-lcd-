



#ifndef __TOUCH_H__
#define __TOUCH_H__
//#include "sys.h"
#include "main.h"
#include <ft5426.h>



//µçÈÝ´¥ÃþÆÁºÍµç×è´¥ÃþÆÁÑ¡Ôñ¶¨Òå
#define TP_TYPE 1    //0-µç×è´¥ÃþÆÁ£¬1-µçÈÝ´¥ÃþÆÁ

//´¥ÃþÆÁ¹¤×÷Ä£Ê½Ñ¡Ôñ¶¨Òå
#define SCAN_TYPE 0  //0-ÂÖÑ¯Ä£Ê½£¬1-ÖÐ¶ÏÄ£Ê½

//µçÈÝ´¥ÃþÆÁ×î´óÖ§³ÖµÄ´¥ÃþµãÊý
#define CTP_MAX_TOUCH     5

#define TP_PRES_DOWN 0x80  //´¥ÆÁ±»°´ÏÂ
#define TP_CATH_PRES 0x40  //ÓÐ°´¼ü°´ÏÂÁË

//´¥ÃþÆÁ¿ØÖÆÆ÷
typedef struct
{
	u16 x[CTP_MAX_TOUCH]; 		  //µ±Ç°×ø±ê(´Ë´ÎÉ¨ÃèÊ±,´¥ÆÁµÄ×ø±ê)
	u16 y[CTP_MAX_TOUCH];
	u8  sta;					          //±ÊµÄ×´Ì¬
								              //b7:°´ÏÂ1/ËÉ¿ª0;
	                            //b6:0,Ã»ÓÐ°´¼ü°´ÏÂ;1,ÓÐ°´¼ü°´ÏÂ.
															//b5:±£Áô
															//b4~b0:µçÈÝ´¥ÃþÆÁ°´ÏÂµÄµãÊý(0,±íÊ¾Î´°´ÏÂ,1±íÊ¾°´ÏÂ)
////////////////////////µç×èÆÁ´¥ÃþÆÁÐ£×¼²ÎÊý/////////////////////////
	float xfac;
	float yfac;
	short xoff;
	short yoff;
//b0~6:±£Áô.
//b7:0,µç×èÆÁ
//   1,µçÈÝÆÁ
	u8 touchtype;
}_m_tp_dev;

extern _m_tp_dev tp_dev;	 	//´¥ÆÁ¿ØÖÆÆ÷ÔÚtouch.cÀïÃæ¶¨Òå

u8 TP_Init(void);								//³õÊ¼»¯



#ifdef __cplusplus
}
#endif

#endif /* __I2C_H__ */


