#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

GPIO_InitTypeDef gpio_adc_pin;
ADC_HandleTypeDef adc_handle;
ADC_ChannelConfTypeDef adc_channel_config;
UART_HandleTypeDef uart_handle;
TIM_OC_InitTypeDef pwm_config;
GPIO_InitTypeDef PA15_LED_config;
TIM_HandleTypeDef timer_handle;
TIM_HandleTypeDef timer2_handle;
GPIO_InitTypeDef button_handle;

void SystemClock_Config(void);

int config_mode = 0;
int led_status = 0;
int brightness = 50;
int delay_time = 1000;

void init_adc()
{
    gpio_adc_pin.Mode = GPIO_MODE_ANALOG;
    gpio_adc_pin.Pin = GPIO_PIN_0;
    gpio_adc_pin.Speed = GPIO_SPEED_FAST;
    gpio_adc_pin.Pull = GPIO_NOPULL;

    HAL_GPIO_Init(GPIOA, &gpio_adc_pin);

    adc_handle.Instance = ADC3;
    adc_handle.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
    adc_handle.Init.Resolution = ADC_RESOLUTION12b;

    adc_handle.Init.ScanConvMode = DISABLE;
    adc_handle.Init.ContinuousConvMode = DISABLE;
    adc_handle.Init.DiscontinuousConvMode = DISABLE;
    adc_handle.Init.EOCSelection = ADC_EOC_SEQ_CONV;
    adc_handle.Init.NbrOfDiscConversion = 1;

    HAL_ADC_Init(&adc_handle);

    adc_channel_config.Channel = ADC_CHANNEL_0;
    adc_channel_config.SamplingTime = ADC_SAMPLETIME_56CYCLES;

    HAL_ADC_ConfigChannel(&adc_handle, &adc_channel_config);
}

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

void init_led_pins()
{
    PA15_LED_config.Pin = GPIO_PIN_15;
    PA15_LED_config.Mode = GPIO_MODE_AF_PP; /* configure as output, in PUSH-PULL mode */
    PA15_LED_config.Pull = GPIO_NOPULL;
    PA15_LED_config.Speed = GPIO_SPEED_HIGH;
    PA15_LED_config.Alternate = GPIO_AF1_TIM2;  /* we need this alternate function to use TIM2 in OC mode */

    HAL_GPIO_Init(GPIOA, &PA15_LED_config);
}

void init_PWM()
{
    /*
     * 50% * 0.01 s = 0.005 s: 0.005 low, then 0.005 s high;
     * our eyes are not able to notice that it is a vibrating light
    */
    pwm_config.Pulse = 50;
    pwm_config.OCMode = TIM_OCMODE_PWM1;
    pwm_config.OCPolarity = TIM_OCPOLARITY_HIGH;
    pwm_config.OCFastMode = TIM_OCFAST_ENABLE;

    HAL_TIM_PWM_ConfigChannel(&timer_handle, &pwm_config, TIM_CHANNEL_1);
}

void init_timer()
{
    timer_handle.Instance = TIM2;
    timer_handle.Init.Prescaler = 108 - 1; // 108000000/108=1000000 -> speed of 1 count-up: 1/1000000 s = 0.001 ms
    timer_handle.Init.Period = 100 - 1; // 100 x 0.001 ms = 10 ms = 0.01 s period
    timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

    /* configuring the timer in PWM mode instead of calling HAL_TIM_Base_Init(&timer_handle) */
    HAL_TIM_PWM_Init(&timer_handle);
}


void init_timer2()
{
    timer2_handle.Instance = TIM3;
    timer2_handle.Init.Prescaler = 54000 - 1; 
    timer2_handle.Init.Period = 1000 - 1;
    timer2_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    timer2_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_Base_Init(&timer2_handle);

    HAL_NVIC_SetPriority(TIM3_IRQn, 1, 0);

    HAL_NVIC_EnableIRQ(TIM3_IRQn);
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


int main(void)
{
    HAL_Init();
    SystemClock_Config();

    init_uart();
    init_adc();
    init_timer();
    init_timer2();
    init_PWM();
    init_led_pins();
    init_button();

    HAL_TIM_PWM_Start(&timer_handle, TIM_CHANNEL_1);
    HAL_TIM_Base_Start_IT(&timer2_handle);

    int adc_val;

    while (1) {
        HAL_ADC_Start(&adc_handle);
        if (HAL_ADC_PollForConversion(&adc_handle, 10) == HAL_OK) {
            adc_val = HAL_ADC_GetValue(&adc_handle);
            if (config_mode == 0){
                brightness = ((float)adc_val / 4095) * 100;
            } else if (config_mode == 1) {
                delay_time = adc_val * 0.464 + 100;
            }

            printf("ADC value: %d.\n", adc_val);
            printf("Brightness: %d%%\n", brightness);
            printf("Delay time: %dms\n", delay_time);
        }
        HAL_Delay(500);
    }
}

void EXTI15_10_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (config_mode == 0){
        config_mode = 1;
        printf("Config mode: frequency\n");
    } else {
        config_mode = 0;
        printf("Config mode: brightness\n");
    }
}

void TIM3_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&timer2_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    __HAL_TIM_SET_AUTORELOAD(&timer2_handle, delay_time);
    if (htim->Instance == TIM3) {
        /* toggling the LED once in every second */
        if (led_status == 0){
            __HAL_TIM_SET_COMPARE(&timer_handle, TIM_CHANNEL_1, brightness);
            led_status = 1;
        } else if (led_status == 1) {
            __HAL_TIM_SET_COMPARE(&timer_handle, TIM_CHANNEL_1, 0);
            led_status = 0;
        }
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
    __HAL_RCC_RNG_CLK_ENABLE();
    __HAL_RCC_I2C1_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_ADC3_CLK_ENABLE();
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