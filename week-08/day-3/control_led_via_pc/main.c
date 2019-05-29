#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define UART_PUTCHAR int __io_putchar(int ch)

UART_HandleTypeDef uart_handle;

volatile uint8_t buffer = 0;
volatile uint8_t *string;

void init_uart()
{
	__HAL_RCC_USART1_CLK_ENABLE();

	uart_handle.Instance = USART1;
    uart_handle.Init.BaudRate = 115200;
    uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
    uart_handle.Init.StopBits = UART_STOPBITS_1;
    uart_handle.Init.Parity = UART_PARITY_NONE;
    uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);

	HAL_NVIC_EnableIRQ(USART1_IRQn);
	HAL_NVIC_SetPriority(USART1_IRQn, 8, 0);
}

int main(void)
{
	HAL_Init();
	init_uart();
    BSP_LED_Init(LED1);

	string = calloc(1, 1);

	HAL_UART_Receive_IT(&uart_handle, &buffer, 1);

	while (1) {
		
	}

	free(string);
}

void USART1_IRQHandler()
{
	HAL_UART_IRQHandler(&uart_handle);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	uint32_t length = strlen(string);
	string = realloc(string, length + 2);
	string[length] = buffer;
	string[length + 1] = '\0';

	if (buffer == 13) {
        if(strncmp((char *)string,"\nled on",7) == 0 )
            BSP_LED_On(LED1);
        else if(strncmp((char *)string,"\nled off",8) == 0 )
            BSP_LED_Off(LED1);
        
		strcpy(string, "");
	}

	HAL_UART_Receive_IT(&uart_handle, &buffer, 1);
}

UART_PUTCHAR
{
    HAL_UART_Transmit(&uart_handle, (uint8_t*)&ch, 1, 0xFFFF);
    return ch;
}

///////////////////////////// You shouldn't write any code beyond this point //////////////////////////////

static void Error_Handler(void)
{
}

static void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /**Configure the main internal regulator output voltage */
    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
    __HAL_RCC_RNG_CLK_ENABLE();

    /**Initializes the CPU, AHB and APB busses clocks */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
    RCC_OscInitStruct.PLL.PLLM = 8;
    RCC_OscInitStruct.PLL.PLLN = 216;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ = 2;

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }

    /**Activate the Over-Drive mode */
    if (HAL_PWREx_EnableOverDrive() != HAL_OK)
    {
        Error_Handler();
    }

    /**Initializes the CPU, AHB and APB busses clocks */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
    {
        Error_Handler();
    }
}

void SysTick_Handler(void)
{
    HAL_IncTick();
    HAL_SYSTICK_IRQHandler();
}

void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
    while (1)
    {
    }
}

void MemManage_Handler(void)
{
    while (1)
    {
    }
}

void BusFault_Handler(void)
{
    while (1)
    {
    }
}

void UsageFault_Handler(void)
{
    while (1)
    {
    }
}

void SVC_Handler(void)
{
}

void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}