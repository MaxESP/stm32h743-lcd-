


/*#include <stdio.h>
#include <string.h>
#include "ltdc.h"
//#include "delay.h"
//#include "gui.h"
#include "test.h"
#include "touch.h"
//#include "key.h"
//#include "led.h"
//#include "pic.h"
#include "ft5426.h"
//#include "rtp.h"
//#include "exti.h"


#define OTT_MAX_TOUCH  5
#define LED0(n)		(n?HAL_GPIO_WritePin(GPIOC,GPIO_PIN_10,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOC,GPIO_PIN_10,GPIO_PIN_RESET))
#define LED0_Toggle (HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_10))

u16 ColorTab[5]={RED,GREEN,BLUE,YELLOW,BRED};//¶¨ÒåÑÕÉ«Êý×é
const u16 POINT_COLOR_TBL[OTT_MAX_TOUCH]={RED,GREEN,BLUE,BROWN,GRED}; //µçÈÝ´¥Ãþ5µãÑÕÉ«¶¨Òå
u16 ColornTab[8]={RED,MAGENTA,GREEN,BLUE,BLACK};
// POINT_COLOR=RED;

void Ctp_Test(void)
{
	u8 t=0;
	u8 i=0,j=0;
 	u16 lastpos[5][2];		//×îºóÒ»´ÎµÄÊý¾Ý
	//LED_Init();
	//DrawTestPage("²âÊÔ10:µçÈÝTouch²âÊÔ(Ö§³Ö5µã´¥Ãþ)  ");
	//LCD_ShowString(lcdltdc.width-24,0,16,"RST",1);//ÏÔÊ¾ÇåÆÁÇøÓò
//POINT_COLOR=RED;//ÉèÖÃ»­±ÊÀ¶É« //Çå³ý
	while(1)
	{
		j++;
		FT5426_Scan();
		for(t=0;t<OTT_MAX_TOUCH;t++)//×î¶à5µã´¥Ãþ
		{
			if((tp_dev.sta)&(1<<t))//ÅÐ¶ÏÊÇ·ñÓÐµã´¥Ãþ£¿
			{
				if(tp_dev.x[t]<lcdltdc.width&&tp_dev.y[t]<lcdltdc.height)//ÔÚLCD·¶Î§ÄÚ
				{
					if(lastpos[t][0]==0XFFFF)
					{
						lastpos[t][0] = tp_dev.x[t];
						lastpos[t][1] = tp_dev.y[t];
					}
					if(tp_dev.x[t]>(lcdltdc.width-24)&&tp_dev.y[t]<16)
					{
							if(j>1) //·ÀÖ¹µã»÷Ò»´Î£¬¶à´ÎÇåÆÁ
							{
								continue;
							}
							//DrawTestPage("²âÊÔ10:µçÈÝTouch²âÊÔ(Ö§³Ö5µã´¥Ãþ)  ");
							//LCD_ShowString(lcdltdc.width-24,0,16,"RST",1);//ÏÔÊ¾ÇåÆÁÇøÓò
							//POINT_COLOR=RED;//ÉèÖÃ»­±ÊÀ¶É« //Çå³ý
							printf("CTP ID:%x\r\n",t);
					}
					else
					{
						//LTDC_DrawLine(lastpos[t][0],lastpos[t][1],tp_dev.x[t],tp_dev.y[t],2,POINT_COLOR_TBL[t]);//»­Ïß
					}
					lastpos[t][0]=tp_dev.x[t];
					lastpos[t][1]=tp_dev.y[t];
				}
			}else lastpos[t][0]=0XFFFF;
		}
		HAL_Delay(5);;i++;
		if(i%30==0)LED0_Toggle;
		if(j>4)
		{
			j=0;
		}
	}
}*/



