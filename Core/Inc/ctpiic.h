/*
 * ctpiic.h
 *
 *  Created on: Apr 23, 2025
 *      Author: domoledlight
 */

#ifndef INC_CTPIIC_H_
#define INC_CTPIIC_H_

//#ifdef __cplusplus
//extern "C" {
//#endif



//#include <ctpiic.h>
#include <main.h>//ok
//#include "ctpiic.h"//ok
//CTP_IIC_SDA

//IO**************CTP_IIC_SDA
//#define CTP_SDA_IN()  {GPIOH->MODER&=~(3<<(3*2));GPIOH->MODER|=0<<3*2;}	//PI3ÊäÈëÄ£Ê½
//#define CTP_SDA_OUT() {GPIOH->MODER&=~(3<<(3*2));GPIOH->MODER|=1<<3*2;} //PI3Êä³öÄ£Ê½

#define CTP_SDA_IN() {GPIOH->MODER&=~(3<<(5*2));GPIOH->MODER|=0<<5*2;}	//PH5输入模式
#define  CTP_SDA_OUT() {GPIOH->MODER&=~(3<<(5*2));GPIOH->MODER|=1<<5*2;} //PH5输出模式



//#define LCD_LED(n) (n?HAL_GPIO_WritePin(GPIOH,GPIO_PIN_3,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOH,GPIO_PIN_3,GPIO_PIN_RESET))

#define CTP_IIC_SCL(n)    (n?HAL_GPIO_WritePin(GPIOH,GPIO_PIN_4,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOH,GPIO_PIN_4,GPIO_PIN_RESET))//SCL
#define CTP_IIC_SDA(n)    (n?HAL_GPIO_WritePin(GPIOH,GPIO_PIN_5,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOH,GPIO_PIN_5,GPIO_PIN_RESET))//SDA
#define CTP_READ_SDA       HAL_GPIO_ReadPin(GPIOH,GPIO_PIN_5)//ÊäÈëSDA

//#define IIC_SCL(n)  (n?HAL_GPIO_WritePin(GPIOH,GPIO_PIN_4,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOH,GPIO_PIN_4,GPIO_PIN_RESET)) //SCL
//#define IIC_SDA(n)  (n?HAL_GPIO_WritePin(GPIOH,GPIO_PIN_5,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOH,GPIO_PIN_5,GPIO_PIN_RESET)) //SDA
//#define READ_SDA    HAL_GPIO_ReadPin(GPIOH,GPIO_PIN_5)  //输入SDA


//IICËùÓÐ²Ù×÷º¯Êý
void CTP_IIC_Init(void);                	//³õÊ¼»¯IICµÄIO¿Ú
void CTP_IIC_Start(void);				//·¢ËÍIIC¿ªÊ¼ÐÅºÅ
void CTP_IIC_Stop(void);	  				//·¢ËÍIICÍ£Ö¹ÐÅºÅ
void CTP_IIC_Send_Byte(u8 txd);			//IIC·¢ËÍÒ»¸ö×Ö½Ú
u8 CTP_IIC_Read_Byte(unsigned char ack);	//IIC¶ÁÈ¡Ò»¸ö×Ö½Ú
u8 CTP_IIC_Wait_Ack(void); 				//IICµÈ´ýACKÐÅºÅ
void CTP_IIC_Ack(void);					//IIC·¢ËÍACKÐÅºÅ
void CTP_IIC_NAck(void);
void delay_us(uint32_t nus);
//void IIC_Write_One_Byte(uint8_t daddr,uint8_t addr,uint8_t data);
//uint8_t IIC_Read_One_Byte(uint8_t daddr,uint8_t addr);


//#ifdef __cplusplus
//}
#endif
//
//#endif /*/* INC_CTPIIC_H_ */
