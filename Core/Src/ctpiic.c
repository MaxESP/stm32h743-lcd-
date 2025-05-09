/*
 * ctpiic.c
 *
 *  Created on: Apr 23, 2025
 *      Author: domoledlight
 */


#include <ctpiic.h>
//#include "delay.h"

uint16_t fac_us=400;						    //不论是否使用OS,fac_us都需要使用
void delay_us(u32 nus)
{
    u32 ticks;
    u32 told,tnow,tcnt=0;
    u32 reload=SysTick->LOAD;				//LOAD的值
    ticks=nus*fac_us; 						//需要的节拍数
    told=SysTick->VAL;        				//刚进入时的计数器值
    while(1)
    {
        tnow=SysTick->VAL;
        if(tnow!=told)
        {
            if(tnow<told)tcnt+=told-tnow;	//这里注意一下SYSTICK是一个递减的计数器就可以了.
            else tcnt+=reload-tnow+told;
            told=tnow;
            if(tcnt>=ticks)break;			//时间超过/等于要延迟的时间,则退出.
        }
    };
}


void CTP_Delay(void)
{
    delay_us(150);
//    HAL_Delay(1);
}




//void CTP_Delay(uint32_t Delay)
//{
//	HAL_Delay(Delay);
//}

/*****************************************************************************
 * @name       :void CTP_IIC_Init(void)
 * @date       :2020-05-13
 * @function   :Initialize IIC
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void CTP_IIC_Init(void)
{
	 GPIO_InitTypeDef GPIO_Initure;



    __HAL_RCC_GPIOH_CLK_ENABLE();			//¿ªÆôGPIOHÊ±ÖÓ
	__HAL_RCC_GPIOI_CLK_ENABLE();			//¿ªÆôGPIOIÊ±ÖÓ

	GPIO_Initure.Pin=GPIO_PIN_4;            //PH6
	GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  //ÍÆÍìÊä³ö
	GPIO_Initure.Pull=GPIO_PULLUP;          //ÉÏÀ­
	GPIO_Initure.Speed=GPIO_SPEED_HIGH;    //¸ßËÙ
    HAL_GPIO_Init(GPIOH,&GPIO_Initure);     //³õÊ¼»¯

    GPIO_Initure.Pin=GPIO_PIN_5;            //SDA
    HAL_GPIO_Init(GPIOH,&GPIO_Initure);     //³õÊ¼»¯



}

/*****************************************************************************
 * @name       :void CTP_IIC_Start(void)
 * @date       :2020-05-13
 * @function   :Generating IIC starting signal
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void CTP_IIC_Start(void)
{



	CTP_SDA_OUT();     //sdaÏßÊä³ö
	CTP_IIC_SDA(1); //1
	CTP_IIC_SCL(1);//1
	HAL_Delay(30);
 	CTP_IIC_SDA(0);//START:when CLK is high,DATA change form high to low
	CTP_Delay();
	CTP_IIC_SCL(0);//Ç¯×¡I2C×ÜÏß£¬×¼±¸·¢ËÍ»ò½ÓÊÕÊý¾Ý
}

/*****************************************************************************
 * @name       :void CTP_IIC_Stop(void)
 * @date       :2020-05-13
 * @function   :Generating IIC stop signal
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void CTP_IIC_Stop(void)
{
	CTP_SDA_OUT();//sdaÏßÊä³ö
	CTP_IIC_SCL(0);//0
	CTP_IIC_SDA(0);  //STOP:when CLK is high DATA change form low to high  0
	HAL_Delay(30);
	CTP_IIC_SCL(1);
	CTP_Delay();
	CTP_IIC_SDA(1); //·¢ËÍI2C×ÜÏß½áÊøÐÅºÅ
}

/*****************************************************************************
 * @name       :u8 CTP_IIC_Wait_Ack(void)
 * @date       :2020-05-13
 * @function   :Wait for the response signal
 * @parameters :None
 * @retvalue   :0-receive response signal successfully
								1-receive response signal unsuccessfully
******************************************************************************/
u8 CTP_IIC_Wait_Ack(void)
{
	u8 ucErrTime=0;
	CTP_SDA_IN();      //SDAÉèÖÃÎªÊäÈë
	CTP_IIC_SDA(1);//1
	CTP_IIC_SCL(1);//1
	CTP_Delay();
	while(CTP_READ_SDA)
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			CTP_IIC_Stop();
			return 1;
		}
		CTP_Delay();
	}
	CTP_IIC_SCL(0);//Ê±ÖÓÊä³ö0
	return 0;
}

/*****************************************************************************
 * @name       :void CTP_IIC_Ack(void)
 * @date       :2020-05-13
 * @function   :Generate ACK response signal
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void CTP_IIC_Ack(void)
{
	CTP_IIC_SCL(0);//0
	CTP_SDA_OUT();
	CTP_IIC_SDA(0);//0
	CTP_Delay();
	CTP_IIC_SCL(1);//1
	CTP_Delay();
	CTP_IIC_SCL(0);//0
}

/*****************************************************************************
 * @name       :void CTP_IIC_NAck(void)
 * @date       :2020-05-13
 * @function   :Don't generate ACK response signal
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void CTP_IIC_NAck(void)
{
	CTP_IIC_SCL(0);//0
	CTP_SDA_OUT();
	CTP_IIC_SDA(1);//1
	CTP_Delay();
	CTP_IIC_SCL(1);//1
	CTP_Delay();
	CTP_IIC_SCL(0);//0
}

/*****************************************************************************
 * @name       :void CTP_IIC_Send_Byte(u8 txd)
 * @date       :2020-05-13
 * @function   :send a byte data by IIC bus
 * @parameters :txd:Data to be sent
 * @retvalue   :None
******************************************************************************/
void CTP_IIC_Send_Byte(u8 txd)
{
  u8 t;
	CTP_SDA_OUT();
  CTP_IIC_SCL(0);//0
  for(t=0;t<8;t++)
  {
    CTP_IIC_SDA((txd & 0x80)>>7);
    txd<<=1;
		CTP_Delay();
		CTP_IIC_SCL(1);//1
		CTP_Delay();
		CTP_IIC_SCL(0);//0
		CTP_Delay();
  }
}

/*****************************************************************************
 * @name       :u8 CTP_IIC_Read_Byte(unsigned char ack)
 * @date       :2020-05-13
 * @function   :read a byte data by IIC bus
 * @parameters :ack:0-send nACK
									  1-send ACK
 * @retvalue   :Data to be read
******************************************************************************/
u8 CTP_IIC_Read_Byte(unsigned char ack)
{
	u8 i,receive=0;
 	CTP_SDA_IN();//SDAÉèÖÃÎªÊäÈë
 	HAL_Delay(30);
  for(i=0;i<8;i++ )
	{
    CTP_IIC_SCL(0);//0
		CTP_Delay();
		CTP_IIC_SCL(1);//1
		receive<<=1;
		if(CTP_READ_SDA)receive++;
		CTP_Delay();
	}
	if (!ack)CTP_IIC_NAck();//·¢ËÍnACK
	else CTP_IIC_Ack(); //·¢ËÍACK
 	return receive;
}

