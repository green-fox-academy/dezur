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

int main(void) {
	int counter = 0;
	int counter2 = 0;
	int delay_time = 2000;
	int flag = 0;

	HAL_Init();

	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

	BSP_LED_Init(LED1);

	while (1) {
		while (counter < 3) {
			BSP_LED_On(LED1);
			HAL_Delay(100);
			BSP_LED_Off(LED1);
			HAL_Delay(delay_time);
			counter++;
		}
		if (flag == 0) {
			delay_time = delay_time / 2;
			counter2++;
			if (counter2 == 3) {
				flag = 1;
				counter2 = 0;
			}
		} else {
			delay_time = delay_time * 2;
			counter2++;
			if (counter2 == 3) {
				flag = 0;
				counter2 = 0;
			}
		}
		counter = 0;
	}
}
