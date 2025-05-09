

//IIC´ÓÉè±¸µØÖ·
#ifndef __FT5426_H
#define __FT5426_H
//#include "stm32h7xx_hal.h"
#include "main.h"


//  RESET PB0 zero
// INT
/* USER CODE BEGIN Private defines */

#define FT_RST(n)    			(n?HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET))	//FT5426¸´Î»Òý½Å
#define FT_INT    				  HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_4)		//FT5426ÖÐ¶ÏÒý½Å

//I2C¶ÁÐ´ÃüÁî
#define FT_CMD_WR 				0X70    	//Ð´ÃüÁî
#define FT_CMD_RD 				0X71		//¶ÁÃüÁî

//FT5426 ²¿·Ö¼Ä´æÆ÷¶¨Òå
#define FT_DEVIDE_MODE 			0x00   		//FT5426Ä£Ê½¿ØÖÆ¼Ä´æÆ÷
#define FT_REG_NUM_FINGER       0x02		  //´¥Ãþ×´Ì¬¼Ä´æÆ÷

#define FT_TP1_REG 				0X03	  	//µÚÒ»¸ö´¥ÃþµãÊý¾ÝµØÖ·
#define FT_TP2_REG 				0X09		  //µÚ¶þ¸ö´¥ÃþµãÊý¾ÝµØÖ·
#define FT_TP3_REG 				0X0F		  //µÚÈý¸ö´¥ÃþµãÊý¾ÝµØÖ·
#define FT_TP4_REG 				0X15		  //µÚËÄ¸ö´¥ÃþµãÊý¾ÝµØÖ·
#define FT_TP5_REG 				0X1B		  //µÚÎå¸ö´¥ÃþµãÊý¾ÝµØÖ·


#define	FT_ID_G_LIB_VERSION		0xA1		  //°æ±¾
#define FT_ID_G_MODE 			0xA4   		//FT5426ÖÐ¶ÏÄ£Ê½¿ØÖÆ¼Ä´æÆ÷
#define FT_ID_G_THGROUP			0x80   		//´¥ÃþÓÐÐ§ÖµÉèÖÃ¼Ä´æÆ÷
#define FT_ID_G_PERIODACTIVE	0x88   		//¼¤»î×´Ì¬ÖÜÆÚÉèÖÃ¼Ä´æÆ÷
/* USER CODE END Private defines */

u8 FT5426_WR_Reg(u16 reg,u8 *buf,u8 len);
void FT5426_RD_Reg(u16 reg,u8 *buf,u8 len);
u8 FT5426_Init(void);
u8 FT5426_Scan(void);

#endif

