/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    ltdc.h
  * @brief   This file contains all the function prototypes for
  *          the ltdc.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LTDC_H__
#define __LTDC_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern LTDC_HandleTypeDef hltdc;

/* USER CODE BEGIN Private defines */

#define LTDC_reset(n) (n?HAL_GPIO_WritePin(GPIOH,GPIO_PIN_3,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOH,GPIO_PIN_3,GPIO_PIN_RESET))
//**************Attention lcd led c'est reset








typedef struct
{
    u32 pwidth;			//LCDé¢æ¿çš„å®½åº?,å›ºå®šå‚æ•°,ä¸éšæ˜¾ç¤ºæ–¹å‘æ”¹å˜,å¦‚æžœä¸?0,è¯´æ˜Žæ²¡æœ‰ä»»ä½•RGBå±æŽ¥å…?
    u32 pheight;		//LCDé¢æ¿çš„é«˜åº?,å›ºå®šå‚æ•°,ä¸éšæ˜¾ç¤ºæ–¹å‘æ”¹å˜
    u16 hsw;			//æ°´å¹³åŒæ­¥å®½åº¦
    u16 vsw;			//åž‚ç›´åŒæ­¥å®½åº¦
    u16 hbp;			//æ°´å¹³åŽå»Š
    u16 vbp;			//åž‚ç›´åŽå»Š
    u16 hfp;			//æ°´å¹³å‰å»Š
    u16 vfp;			//åž‚ç›´å‰å»Š
    u8 activelayer;		//å½“å‰å±‚ç¼–å?:0/1
    u8 dir;				//0,ç«–å±;1,æ¨ªå±;
    u16 width;			//LCDå®½åº¦
    u16 height;			//LCDé«˜åº¦
    u32 pixsize;		//æ¯ä¸ªåƒç´ æ‰?å å­—èŠ‚æ•°



}_ltdc_dev;


extern _ltdc_dev lcdltdc;		            //ç®¡ç†LCD LTDCå‚æ•°
extern LTDC_HandleTypeDef LTDC_Handler;	    //LTDCå¥æŸ„
extern DMA2D_HandleTypeDef DMA2D_Handler;   //DMA2Då¥æŸ„
extern u32 *ltdc_framebuf[2];

#define LCD_PIXEL_FORMAT_ARGB8888       0X00
#define LCD_PIXEL_FORMAT_RGB888         0X01
#define LCD_PIXEL_FORMAT_RGB565         0X02
#define LCD_PIXEL_FORMAT_ARGB1555       0X03
#define LCD_PIXEL_FORMAT_ARGB4444       0X04
#define LCD_PIXEL_FORMAT_L8             0X05
#define LCD_PIXEL_FORMAT_AL44           0X06
#define LCD_PIXEL_FORMAT_AL88           0X07

#define WHITE         	 0xFFFF
#define BLACK         	 0x0000
#define BLUE         	 0x001F
#define BRED             0XF81F
#define GRED 			 0XFFE0
#define GBLUE			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40 //æ£•è‰²
#define BRRED 			 0XFC07 //æ£•çº¢ï¿??
#define GRAY  			 0X8430 //ç°è‰²

#define LCD_PIXFORMAT				LCD_PIXEL_FORMAT_RGB565
//å®šä¹‰é»˜è®¤èƒŒæ™¯å±‚é¢œè‰?
#define LTDC_BACKLAYERCOLOR			0X00000000
//LCDå¸§ç¼“å†²åŒºé¦–åœ°å?,è¿™é‡Œå®šä¹‰åœ¨SDRAMé‡Œé¢.
#define LCD_FRAME_BUF_ADDR			0XC0000000


/* USER CODE END Private defines */

void MX_LTDC_Init(void);

/* USER CODE BEGIN Prototypes */
void LTDC_Init(void);
void LTDC_Fill(uint16_t sx,uint16_t sy,uint16_t ex,uint16_t ey,uint32_t color);
void LTDC_Clear(uint32_t color);

void LTDC_Color_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 *color);
void LTDC_Switch(u8 sw);
void LTDC_Select_Layer(u8 layerx);
void LTDC_Display_Dir(u8 dir);
void LTDC_Draw_Point(u16 x,u16 y,u32 color);
u32 LTDC_Read_Point(u16 x,u16 y);
void LTDC_Draw_bmp(u16 x,u16 y,u16 pic_width, u16 pic_height, const unsigned char *p);
void LTDC_ShowString(uint16_t x,uint16_t y,uint16_t width,uint16_t height,uint8_t size,uint8_t *p,uint32_t color);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __LTDC_H__ */

