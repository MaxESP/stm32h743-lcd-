//if (CSP_QUADSPI_Init()!= HAL_OK) Error_Handler();

// if (CSP_QSPI_ResetChip()!= HAL_OK) Error_Handler();

    //  if (CSP_QSPI_Erase_Chip()!= HAL_OK) Error_Handler();

    //  if (CSP_QSPI_EraseBlock(0)!= HAL_OK) Error_Handler();


     //if (CSP_QSPI_WriteMemory(writebuf,0, sizeof(writebuf)) != HAL_OK)Error_Handler();

     // if (CSP_QSPI_Read(Readbuf,0,30)!= HAL_OK) Error_Handler();

    //  if (CSP_QSPI_EnableMemoryMappedMode() != HAL_OK)Error_Handler();
   // memcpy(Readbuf,(uint8_t *) 0x90000000, 30);

  /*HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
  		  		  		  	 	 		  HAL_Delay(250);
  		  		  		  	 	  		  //HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0,GPIO_PIN_RESET);
  		  		  		  	 	  		  HAL_Delay(250);*/


  /*HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_4);

      __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4, P);
*/

 //HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
  //		  		  		  	 	 		  HAL_Delay(250);
 // CTP_IIC_Init();

 // memcpy((uint32_t *) SDRAM_ADD, wdata, 11);
 //     memcpy(rdata, (uint32_t *) SDRAM_ADD, 11);



 /* HAL_StatusTypeDef result;
	   	uint8_t i;
	   	for (i=1; i<128; i++)
	   	{

	   	   * the HAL wants a left aligned i2c address
	   	   * &hi2c1 is the handle
	   	   * (uint16_t)(i<<1) is the i2c address left aligned
	   	   * retries 2
	   	   * timeout 2

	   	  result = HAL_I2C_IsDeviceReady(&hi2c2, (uint16_t)(i<<1), 2, 2);
	   	  if (result != HAL_OK) // HAL_ERROR or HAL_BUSY or HAL_TIMEOUT
	   	  {
	   		  printf("."); // No ACK received at that address
	   	  }
	   	  if (result == HAL_OK)
	   	  {
	   		  printf("0x%X", i); // Received an ACK at that address
	   	  }
	   	}
	   	printf("\r\n");*/

		  	 	   	  	     /// HAL_Delay(5000);

	/*  LTDC_Fill(0,0,1020,600,RED);
	  	  HAL_Delay(1000);
	  	  LTDC_Clear(BLACK);

	  	  HAL_Delay(1000);
	  	  LTDC_Clear(BLACK);
	  	  HAL_Delay(500);
	  	  LTDC_Fill(0,0,1020,600,YELLOW);
	  	  HAL_Delay(1000);
	  	  LTDC_Clear(BLACK);
	  	  HAL_Delay(500);
	  	  LTDC_Fill(0,0,1020,600,GREEN);
	  	  HAL_Delay(1000);
	  	 LTDC_Clear(BLACK);
	  	//LCD_DrawImage(585,558, 100, 100,gImage_qq);
	  	 HAL_Delay(4000);*/

		/*HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
		  		  		  	 	 		  HAL_Delay(250);
		  		  		  	 	  		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0,GPIO_PIN_RESET);
		  		  		  	 	  		  HAL_Delay(250);*/






	 //FT5426_Scan();
	// FT5426_RD_Reg(u16 reg,u8 *buf,u8 len);



//TP_Init();
//int DATA=10;
//    int DATAX=ID;
//    printf("%d\r\n",DATA);
//    printf("%d\r\n",DATA);
   // printf("%d\r\n",DATAX);
//FT5426_Init();

 // Ctp_Test();


	 // HAL_Delay(1000);















