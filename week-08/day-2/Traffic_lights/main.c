#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

static void SystemClock_Config(void);

TIM_HandleTypeDef timer_handle;
GPIO_InitTypeDef gpio_config;

void init_timer()
{
    __HAL_RCC_TIM2_CLK_ENABLE();

    timer_handle.Instance = TIM2;
    timer_handle.Init.Prescaler = 54000 - 1; 
    timer_handle.Init.Period = 24000 - 1;
    timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

    /* configuring the timer in PWM mode instead of calling HAL_TIM_Base_Init(&timer_handle) */
    HAL_TIM_Base_Init(&timer_handle);
}

void init_led_pins()
{
    __HAL_RCC_GPIOF_CLK_ENABLE();

    GPIO_InitTypeDef gpio_config;

    gpio_config.Pin = GPIO_PIN_10 | GPIO_PIN_9 | GPIO_PIN_8;
    gpio_config.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_config.Pull = GPIO_NOPULL;
    gpio_config.Speed = GPIO_SPEED_FAST;

    HAL_GPIO_Init(GPIOF, &gpio_config);
}


int main(void)
{
    HAL_Init();

    /* this function call sets the timers input clock to 108 Mhz (=108000000 Hz) */	
    SystemClock_Config();

    init_led_pins();
    init_timer();

    /* starting the timer */
    HAL_TIM_Base_Start_IT(&timer_handle);
    uint16_t timer_value = 0;
    while (1) {
        timer_value = __HAL_TIM_GET_COUNTER(&timer_handle);
	    if (timer_value == 0) {
            HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, 0);
            HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, 0);
            HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, 1);
        }
        if (timer_value == 10000) {
            HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, 0);
            HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, 1);
            HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, 0);
        }
        if (timer_value == 14000) {
            HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, 1);
            HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, 0);
            HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, 0);
        }
        if (timer_value == 22000) {
            HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, 1);
            HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, 1);
            HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, 0);
        }
    }       
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