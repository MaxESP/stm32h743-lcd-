



#include <ft5426.h>
#include <touch.h>
#include "main.h"
#include "ctpiic.h"


_m_tp_dev tp_dev=
{
 	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
};

/*****************************************************************************
 * @name       :u8 TP_Init(void)
 * @date       :2020-05-13
 * @function   :DInitialization  touch screen
 * @parameters :None
 * @retvalue   :0-Initialization successful
								1-initialization failed
******************************************************************************/
u8 TP_Init(void)
{
	u8 ret=0;
#if TP_TYPE
	ret=FT5426_Init();
	tp_dev.touchtype|=0x80;			//µçÈÝÆÁ
#else
	ret=RTP_Init();
	tp_dev.touchtype|=0x00;			//µç×èÆÁ
#endif
	return ret;
}
