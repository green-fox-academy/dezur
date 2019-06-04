#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

UART_HandleTypeDef uart_handle;
GPIO_InitTypeDef button_handle;
TIM_HandleTypeDef timer_handle;
TIM_HandleTypeDef timer2_handle;


void SystemClock_Config(void);

typedef enum {
    OPEN, SECURING, SECURED, OPENING
} state_t;

state_t state = OPEN;

void init_uart()
{
    uart_handle.Instance = USART1;
    uart_handle.Init.BaudRate = 115200;
    uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
    uart_handle.Init.StopBits = UART_STOPBITS_1;
    uart_handle.Init.Parity = UART_PARITY_NONE;
    uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    uart_handle.Init.Mode = UART_MODE_TX_RX;

    BSP_COM_Init(COM1, &uart_handle);

    HAL_UART_Init(&uart_handle);
}

void init_button()
{
    button_handle.Pin = GPIO_PIN_11;
    button_handle.Mode = GPIO_MODE_IT_RISING;
    button_handle.Pull = GPIO_NOPULL;
    button_handle.Speed = GPIO_SPEED_FAST;

    HAL_GPIO_Init(GPIOI, &button_handle);

    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void init_timer()
{
    timer_handle.Instance = TIM2;
    timer_handle.Init.Prescaler = 54000 - 1; 
    timer_handle.Init.Period = 22000 - 1;
    timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_Base_Init(&timer_handle);
}

void init_timer2()
{
    timer2_handle.Instance = TIM3;
    timer2_handle.Init.Prescaler = 54000 - 1; 
    timer2_handle.Init.Period = 2000 - 1;
    timer2_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    timer2_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_Base_Init(&timer2_handle);

    HAL_NVIC_SetPriority(TIM3_IRQn, 3, 0);

    HAL_NVIC_EnableIRQ(TIM3_IRQn);
}

int main(void)
{
    HAL_Init();
    SystemClock_Config();

    init_uart();
    init_timer();
    init_timer2();
    init_button();
    BSP_LED_Init(LED1);

    HAL_TIM_Base_Start_IT(&timer2_handle);

    uint16_t timer_value = 0;

    while (1) {
        timer_value = __HAL_TIM_GET_COUNTER(&timer_handle);
        if (state == SECURING) {
            if (timer_value == 10000) {
                state = SECURED;
                printf("ENTERED in SECURED state\n");
                HAL_TIM_Base_Stop_IT(&timer2_handle);
                HAL_TIM_Base_Stop(&timer_handle);
                BSP_LED_Off(LED1);
            }
        } else if (state == OPENING) {   
            if (timer_value == 21999) {
                state = OPEN;
                printf("ENTERED in OPEN state\n");
                HAL_TIM_Base_Stop(&timer_handle);
                __HAL_TIM_SET_AUTORELOAD(&timer2_handle, 2000);
            }
        }

    }
}

void EXTI15_10_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (state == OPEN) {
        state = SECURING;
        __HAL_TIM_SET_AUTORELOAD(&timer2_handle, 1000);
        __HAL_TIM_SET_COUNTER(&timer2_handle, 1);
        HAL_TIM_Base_Start(&timer_handle);
        printf("ENTERED in SECURING state\n");
    } else if (state == SECURED){
        state = OPENING;
        HAL_TIM_Base_Start_IT(&timer2_handle);
        HAL_TIM_Base_Start(&timer_handle);
        printf("ENTERED in OPENING state\n");
    }
}

void TIM3_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&timer2_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM3) {
        BSP_LED_Toggle(LED1);    
    }
}


int _write(int file, char *ptr, int len)
{
	int DataIdx;

	for (DataIdx = 0; DataIdx < len; DataIdx++) {
		HAL_UART_Transmit(&uart_handle, &ptr[DataIdx], 1, HAL_MAX_DELAY);
	}
	return len;
}

///////////////////////////// You shouldn't write any code beyond this point //////////////////////////////

static void Error_Handler(void)
{
}

void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /**Configure the main internal regulator output voltage */
    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
    __HAL_RCC_GPIOI_CLK_ENABLE();
    __HAL_RCC_TIM2_CLK_ENABLE();
    __HAL_RCC_TIM3_CLK_ENABLE();
    

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