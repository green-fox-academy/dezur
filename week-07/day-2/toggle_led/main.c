/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
			

int main(void)
{
	int status = 0;

    HAL_Init();

    BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

    BSP_LED_Init(LED1);

    while (1) {
        /* If button is pressed do something */
        if (BSP_PB_GetState(BUTTON_KEY) == 1) {
        	BSP_LED_Toggle(LED1);
        	HAL_Delay(250);
        }
    }
}