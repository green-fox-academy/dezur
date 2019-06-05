#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

UART_HandleTypeDef uart_handle;
GPIO_InitTypeDef button_handle;
TIM_HandleTypeDef timer_handle;

void SystemClock_Config(void);
void button_short_press(void);
void button_long_press(void);

typedef enum button_state {
    PUSHED, RELEASED, LONG_PRESSED
} button_state_t;

// Here you can define long press time in millisec
int long_press_time = 2000;

button_state = RELEASED;

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

void init_timer()
{
    timer_handle.Instance = TIM2;
    timer_handle.Init.Prescaler = 54000 - 1; 
    timer_handle.Init.Period = long_press_time * 2 - 1;
    timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_Base_Init(&timer_handle);

    HAL_NVIC_SetPriority(TIM2_IRQn, 3, 0);

    HAL_NVIC_EnableIRQ(TIM2_IRQn);

    // DONT FORGET TO USE CLEAR FLAG MACRO!!!
    // If you dont use the clear flag macro, the long press function runs immediately after you press the user button!!!
    __HAL_TIM_CLEAR_FLAG(&timer_handle, TIM_FLAG_UPDATE);
}

void init_button()
{
    button_handle.Pin = GPIO_PIN_11;
    button_handle.Mode = GPIO_MODE_IT_RISING_FALLING;
    button_handle.Pull = GPIO_NOPULL;
    button_handle.Speed = GPIO_SPEED_FAST;

    HAL_GPIO_Init(GPIOI, &button_handle);

    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

int main(void)
{
    HAL_Init();
    SystemClock_Config();

    init_uart();
    init_timer();
    init_button();
    BSP_LED_Init(LED1);

    while (1) {

    }
}

void TIM2_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&timer_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM2) {
        button_long_press();
        HAL_TIM_Base_Stop_IT(&timer_handle);
        button_state = LONG_PRESSED;
    }
}

void EXTI15_10_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    ///////// You can choose between 'if else if' or 'switch case' solution ////////////


    /*
    if (button_state == RELEASED) {
        __HAL_TIM_SET_COUNTER(&timer_handle, 1);
        HAL_TIM_Base_Start_IT(&timer_handle);
        button_state = PUSHED;
    } else if(button_state == PUSHED) {
        HAL_TIM_Base_Stop_IT(&timer_handle);
        button_short_press();
        button_state = RELEASED;
    } else if (button_state == LONG_PRESSED) {
        button_state = RELEASED;
    }
    */

    switch (button_state) {
        case RELEASED : 
            __HAL_TIM_SET_COUNTER(&timer_handle, 1);
            HAL_TIM_Base_Start_IT(&timer_handle);
            button_state = PUSHED;
            break;
        case PUSHED :
            HAL_TIM_Base_Stop_IT(&timer_handle);
            button_short_press();
            button_state = RELEASED;
            break;
        case LONG_PRESSED :
            button_state = RELEASED;
            break;
    }
}

////// Pretty cool functions, huh? //////

void button_short_press(void)
{
    printf("Short press\n");
}

void button_long_press(void)
{
    printf("Long press\n");
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