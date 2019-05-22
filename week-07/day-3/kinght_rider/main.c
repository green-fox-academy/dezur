#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

void PIN_Init();

int main(void) {
	HAL_Init();
	PIN_Init();

	int pin = 7;
	int direction = 0;
	uint32_t on, off;

	while (1) {
		if (direction == 0) {
			for (pin = 7; pin < 11; pin++) {
				if (GPIOB->IDR & (1 << 4))
					direction = 1;
				on = 1 << pin;
				off = on << 16;
				GPIOF->BSRR = on;
				HAL_Delay(100);
				GPIOF->BSRR = off;
			}
		} else {
			for (pin = 10; pin > 6; pin--) {
				if (GPIOB->IDR & (1 << 4))
					direction = 0;
				on = 1 << pin;
				off = on << 16;
				GPIOF->BSRR = on;
				HAL_Delay(100);
				GPIOF->BSRR = off;
			}
		}
	}
}

void PIN_Init() {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

	GPIOF->MODER |= (GPIO_MODER_MODER10_0);
	GPIOF->MODER |= (GPIO_MODER_MODER9_0);
	GPIOF->MODER |= (GPIO_MODER_MODER8_0);
	GPIOF->MODER |= (GPIO_MODER_MODER7_0);

	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_10);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_9);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_8);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_7);

	GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPDR4);
	GPIOB->MODER |= (1 << 4);
}
