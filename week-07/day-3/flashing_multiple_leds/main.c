#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

int main(void) {
	HAL_Init();

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;

	GPIOF->MODER |= (GPIO_MODER_MODER10_0);
	GPIOF->MODER |= (GPIO_MODER_MODER9_0);
	GPIOF->MODER |= (GPIO_MODER_MODER8_0);
	GPIOF->MODER |= (GPIO_MODER_MODER7_0);

	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_10);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_9);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_8);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_7);

	int pin = 7;
	uint32_t on, off;

	while (1) {
		for (pin = 7; pin < 11; pin++) {
			on = 1 << pin;
			GPIOF->BSRR = on;
		}

		HAL_Delay(50);

		for (pin = 7; pin < 11; pin++) {
			on = 1 << pin;
			off = on << 16;
			GPIOF->BSRR = off;
		}

		HAL_Delay(950);
	}
}
