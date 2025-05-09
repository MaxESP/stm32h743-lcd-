#include "exti.h"

//ÖÐ¶Ï´¥·¢±êÖ¾Î»
u8 touch_flag=0;   //0-Ã»ÓÐ´¥·¢ÖÐ¶Ï£¬1-´¥·¢ÖÐ¶Ï

/*****************************************************************************
 * @name       :void Touch_EXTI_Init(void)
 * @date       :2020-05-13
 * @function   :DInitialization  PC1 exti
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void Touch_EXTI_Init(void)
{
	GPIO_InitTypeDef GPIO_Initure;
	__HAL_RCC_GPIOH_CLK_ENABLE();               //¿ªÆôGPIOHÊ±ÖÓ

	GPIO_Initure.Pin=GPIO_PIN_4;               //PC13
  GPIO_Initure.Mode=GPIO_MODE_IT_FALLING;     //ÏÂ½µÑØ´¥·¢
  GPIO_Initure.Pull=GPIO_PULLUP;				//ÉÏÀ­
  HAL_GPIO_Init(GPIOA,&GPIO_Initure);

	HAL_NVIC_SetPriority(EXTI9_5_IRQn,2,2);   //ÇÀÕ¼ÓÅÏÈ¼¶Îª2£¬×ÓÓÅÏÈ¼¶Îª2
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);         //Ê¹ÄÜÖÐ¶ÏÏß13
	touch_flag=0;
}

/*****************************************************************************
 * @name       :void EXTI1_IRQHandler(void)
 * @date       :2020-05-13
 * @function   :PC1 Interrupt Processing Function
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void EXTI9_5_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);  //µ÷ÓÃÖÐ¶Ï´¦Àí¹«ÓÃº¯Êý
}

/*****************************************************************************
 * @name       :void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
 * @date       :2020-05-13
 * @function   :EXTI line detection callback
 * @parameters :GPIO_Pin:Specifies the port pin connected to corresponding EXTI line
 * @retvalue   :None
******************************************************************************/
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin==GPIO_PIN_4)
	{
		touch_flag=1;
	}
}
