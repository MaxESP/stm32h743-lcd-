

#include <ctpiic.h>
#include <ft5426.h>
#include "string.h"
#include <stdio.h>
#include  <stdlib.h>
#include  <touch.h>
#include "ltdc.h"
//#include "exti.h"
//typedef uint32_t  u32;
//typedef uint16_t u16;
//typedef uint8_t  u8;


 //u8 touch_flag;

extern u8 touch_flag;

/*****************************************************************************
 * @name       :u8 FT5426_WR_Reg(u16 reg,u8 *buf,u8 len)
 * @date       :2020-05-13
 * @function   :Write data to ft5426 once
 * @parameters :reg:Start register address for written
								buf:the buffer of data written
								len:Length of data written
 * @retvalue   :0-Write succeeded
								1-Write failed
******************************************************************************/
u8 FT5426_WR_Reg(u16 reg,u8 *buf,u8 len)
{
	u8 i;
	u8 ret=0;
	CTP_IIC_Start();
	CTP_IIC_Send_Byte(FT_CMD_WR);	//·¢ËÍÐ´ÃüÁî
	CTP_IIC_Wait_Ack();
	CTP_IIC_Send_Byte(reg&0XFF);   	//·¢ËÍµÍ8Î»µØÖ·
	CTP_IIC_Wait_Ack();
	for(i=0;i<len;i++)
	{
		CTP_IIC_Send_Byte(buf[i]);  	//·¢Êý¾Ý
		ret=CTP_IIC_Wait_Ack();
		if(ret)
		{
			break;
		}
	}
  CTP_IIC_Stop();					//²úÉúÒ»¸öÍ£Ö¹Ìõ¼þ
	return ret;
}

/*****************************************************************************
 * @name       :void FT5426_RD_Reg(u16 reg,u8 *buf,u8 len)
 * @date       :2020-05-13
 * @function   :Read data to ft5426 once
 * @parameters :reg:Start register address for read
								buf:the buffer of data read
								len:Length of data read
 * @retvalue   :none
******************************************************************************/
void FT5426_RD_Reg(u16 reg,u8 *buf,u8 len)
{
	u8 i;
 	CTP_IIC_Start();
 	CTP_IIC_Send_Byte(FT_CMD_WR);   	//·¢ËÍÐ´ÃüÁî
	CTP_IIC_Wait_Ack();
 	CTP_IIC_Send_Byte(reg&0XFF);   	//·¢ËÍµÍ8Î»µØÖ·
	CTP_IIC_Wait_Ack();
 	CTP_IIC_Start();
	CTP_IIC_Send_Byte(FT_CMD_RD);   	//·¢ËÍ¶ÁÃüÁî
	CTP_IIC_Wait_Ack();
	for(i=0;i<len;i++)
	{
    	buf[i]=CTP_IIC_Read_Byte(i==(len-1)?0:1); //·¢Êý¾Ý
	}
  CTP_IIC_Stop();//²úÉúÒ»¸öÍ£Ö¹Ìõ¼þ
}

/*****************************************************************************
 * @name       :u8 FT5426_Init(void)
 * @date       :2020-05-13
 * @function   :Initialize the ft5426 touch screen
 * @parameters :none
 * @retvalue   :0-Initialization successful
								1-initialization failed
******************************************************************************/
u8 FT5426_Init(void)
{
	u8 temp[2];
	GPIO_InitTypeDef GPIO_Initure;

  __HAL_RCC_GPIOH_CLK_ENABLE();			//¿ªÆôGPIOHÊ±ÖÓ
  __HAL_RCC_GPIOI_CLK_ENABLE();			//¿ªÆôGPIOIÊ±ÖÓ

  //PH7
  GPIO_Initure.Pin=GPIO_PIN_4;            //PH7// Attention int Pin PA4
  GPIO_Initure.Mode=GPIO_MODE_INPUT;      //ÊäÈë
  GPIO_Initure.Pull=GPIO_PULLUP;          //ÉÏÀ­
  GPIO_Initure.Speed=GPIO_SPEED_HIGH;     //¸ßËÙ
  HAL_GPIO_Init(GPIOA,&GPIO_Initure);     //³õÊ¼»¯

  //PI8//Avoir reset ou int
  GPIO_Initure.Pin=GPIO_PIN_0;            //reset PB0  interupt PA4
  GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  //ÍÆÍìÊä³ö
  HAL_GPIO_Init(GPIOB,&GPIO_Initure);     //³õÊ¼»¯
#if SCAN_TYPE
	Touch_EXTI_Init();// Attention
#endif


	CTP_IIC_Init();      	//³õÊ¼»¯µçÈÝÆÁµÄI2C×ÜÏß
	FT_RST(0);				//0
	HAL_Delay(20);
 	FT_RST(1);				//1
 	HAL_Delay(50);
	temp[0]=0;
	FT5426_WR_Reg(FT_DEVIDE_MODE,temp,1);	//½øÈëÕý³£²Ù×÷Ä£Ê½
#if SCAN_TYPE
	temp[0]=1;
#endif
	FT5426_WR_Reg(FT_ID_G_MODE,temp,1);		//²éÑ¯Ä£Ê½
	temp[0]=22;								//´¥ÃþÓÐÐ§Öµ£¬22£¬Ô½Ð¡Ô½ÁéÃô
	FT5426_WR_Reg(FT_ID_G_THGROUP,temp,1);	//ÉèÖÃ´¥ÃþÓÐÐ§Öµ
	temp[0]=12;								//¼¤»îÖÜÆÚ£¬²»ÄÜÐ¡ÓÚ12£¬×î´ó14
	FT5426_WR_Reg(FT_ID_G_PERIODACTIVE,temp,1);
	//¶ÁÈ¡°æ±¾ºÅ£¬²Î¿¼Öµ£º0x3003
	FT5426_RD_Reg(FT_ID_G_LIB_VERSION,&temp[0],2);
	if((temp[0]==0X30&&temp[1]==0X03)||temp[1]==0X01||temp[1]==0X02)//°æ±¾:0X3003
	{
		printf("CTP ID:%x\r\n",((u16)temp[0]<<8)+temp[1]);
		return 0;
	}
	return 1;
}

const u16 FT5426_TPX_TBL[5]={FT_TP1_REG,FT_TP2_REG,FT_TP3_REG,FT_TP4_REG,FT_TP5_REG};

/*****************************************************************************
 * @name       :u8 FT5426_Scan(void)
 * @date       :2020-05-13
 * @function   :Scan touch screen (query mode)
 * @parameters :none
 * @retvalue   :Current touch screen status
								0-No touch
								1-With touch
******************************************************************************/
u8 FT5426_Scan(void)
{
	u8 buf[4];
	u8 i=0;
	u8 res=0;
	u8 temp;
	u8 mode;
#if SCAN_TYPE
	if(touch_flag)
#else
	static u8 t=0;//¿ØÖÆ²éÑ¯¼ä¸ô,´Ó¶ø½µµÍCPUÕ¼ÓÃÂÊ
	t++;
	if((t%10)==0||t<10)//¿ÕÏÐÊ±,Ã¿½øÈë10´ÎCTP_Scanº¯Êý²Å¼ì²â1´Î,´Ó¶ø½ÚÊ¡CPUÊ¹ÓÃÂÊ
#endif
	{
		FT5426_RD_Reg(FT_REG_NUM_FINGER,&mode,1);//¶ÁÈ¡´¥ÃþµãµÄ×´Ì¬
		if((mode&0XF)&&((mode&0XF)<6))
		{
			temp=0XFF<<(mode&0XF);//½«µãµÄ¸öÊý×ª»»Îª1µÄÎ»Êý,Æ¥Åätp_dev.sta¶¨Òå
			tp_dev.sta=(~temp)|TP_PRES_DOWN|TP_CATH_PRES;
			for(i=0;i<CTP_MAX_TOUCH;i++)
			{
				if(tp_dev.sta&(1<<i))	//´¥ÃþÓÐÐ§?
				{
					FT5426_RD_Reg(FT5426_TPX_TBL[i],buf,4);	//¶ÁÈ¡XY×ø±êÖµ//*************lcdltdc.dir=dir;
					switch(lcdltdc.dir)
					{
						case 0:
							tp_dev.x[i]=lcdltdc.width-(((u16)(buf[0]&0X0F)<<8)+buf[1]);
							tp_dev.y[i]=((u16)(buf[2]&0X0F)<<8)+buf[3];
							break;
						case 1:
							tp_dev.y[i]=((u16)(buf[0]&0X0F)<<8)+buf[1];
							tp_dev.x[i]=((u16)(buf[2]&0X0F)<<8)+buf[3];
							break;
						case 2:
							tp_dev.x[i]=((u16)(buf[0]&0X0F)<<8)+buf[1];
							tp_dev.y[i]=lcdltdc.height-(((u16)(buf[2]&0X0F)<<8)+buf[3]);
							break;
						case 3:
							tp_dev.y[i]=lcdltdc.height-(((u16)(buf[0]&0X0F)<<8)+buf[1]);
							tp_dev.x[i]=lcdltdc.width-(((u16)(buf[2]&0X0F)<<8)+buf[3]);///important avant lcd_dev
							break;
					}
					if((buf[0]&0XF0)!=0X80)tp_dev.x[i]=tp_dev.y[i]=0;//±ØÐëÊÇcontactÊÂ¼þ£¬²ÅÈÏÎªÓÐÐ§
					printf("x[%d]:%d,y[%d]:%d\r\n",i,tp_dev.x[i],i,tp_dev.y[i]);
				}
			}
			res=1;
			if(tp_dev.x[0]==0 && tp_dev.y[0]==0)mode=0;	//¶Áµ½µÄÊý¾Ý¶¼ÊÇ0,ÔòºöÂÔ´Ë´ÎÊý¾Ý
#if !SCAN_TYPE
			t=0;		//´¥·¢Ò»´Î,Ôò»á×îÉÙÁ¬Ðø¼à²â10´Î,´Ó¶øÌá¸ßÃüÖÐÂÊ
#endif
		}
	}
	if((mode&0X1F)==0)//ÎÞ´¥Ãþµã°´ÏÂ
	{
#if SCAN_TYPE
		touch_flag=0;
#endif
		if(tp_dev.sta&TP_PRES_DOWN)	//Ö®Ç°ÊÇ±»°´ÏÂµÄ
		{
			tp_dev.sta&=~(1<<7);	//±ê¼Ç°´¼üËÉ¿ª
		}else						//Ö®Ç°¾ÍÃ»ÓÐ±»°´ÏÂ
		{
			tp_dev.x[0]=0xffff;
			tp_dev.y[0]=0xffff;
			tp_dev.sta&=0XE0;	//Çå³ýµãÓÐÐ§±ê¼Ç
		}
	}
#if !SCAN_TYPE
	if(t>240)t=10;//ÖØÐÂ´Ó10¿ªÊ¼¼ÆÊý
#endif
	return res;
}
