#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

UART_HandleTypeDef uart_handle;
GPIO_InitTypeDef gpio_adc_pin;
ADC_HandleTypeDef adc_handle;
ADC_ChannelConfTypeDef adc_channel_config;
TIM_HandleTypeDef timer_handle;
TIM_HandleTypeDef ic_timer_handle;
TIM_OC_InitTypeDef pwm_config;
GPIO_InitTypeDef FAN;
GPIO_InitTypeDef ic_gpio;

void SystemClock_Config(void);
static void Error_Handler(void);
int get_rpm(int);

volatile uint8_t pwm_val = 0;
volatile uint8_t uart_flag = 0;
volatile uint8_t buffer = 0;
volatile uint8_t *text;
volatile uint8_t blade_counter = 0;
volatile uint16_t period_counter = 0;
volatile uint16_t fan_rpm;
volatile uint32_t fan_round_counter = 0;

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

    HAL_NVIC_EnableIRQ(USART1_IRQn);
	HAL_NVIC_SetPriority(USART1_IRQn, 8, 0);
}

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

void init_PWM()
{
    pwm_config.Pulse = 50;
    pwm_config.OCMode = TIM_OCMODE_PWM1;
    pwm_config.OCPolarity = TIM_OCPOLARITY_HIGH;
    pwm_config.OCFastMode = TIM_OCFAST_ENABLE;

    HAL_TIM_PWM_ConfigChannel(&timer_handle, &pwm_config, TIM_CHANNEL_1);
}

void init_fan_pin()
{
    FAN.Pin = GPIO_PIN_4;
    FAN.Mode = GPIO_MODE_AF_PP;
    FAN.Pull = GPIO_NOPULL;
    FAN.Speed = GPIO_SPEED_HIGH;
    FAN.Alternate = GPIO_AF2_TIM3; 

    HAL_GPIO_Init(GPIOB, &FAN);
}

void init_timer()
{
    timer_handle.Instance = TIM3;
    timer_handle.Init.Prescaler = 108 - 1;
    timer_handle.Init.Period = 100 - 1;
    timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_PWM_Init(&timer_handle);
}

void init_ic_timer()
{
    TIM_MasterConfigTypeDef sMasterConfig = { 0 };
	TIM_IC_InitTypeDef sConfigIC = { 0 };

    ic_timer_handle.Instance = TIM2;
    ic_timer_handle.Init.Prescaler = 0;
    ic_timer_handle.Init.Period = 65535 - 1;
    ic_timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    ic_timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
    ic_timer_handle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

    if (HAL_TIM_IC_Init(&ic_timer_handle) != HAL_OK) {
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&ic_timer_handle, &sMasterConfig)
			!= HAL_OK) {
		Error_Handler();
	}
	sConfigIC.ICPolarity = TIM_INPUTCHANNELPOLARITY_RISING;
	sConfigIC.ICSelection = TIM_ICSELECTION_DIRECTTI;
	sConfigIC.ICPrescaler = TIM_ICPSC_DIV1;
	sConfigIC.ICFilter = 0;
	if (HAL_TIM_IC_ConfigChannel(&ic_timer_handle, &sConfigIC, TIM_CHANNEL_1) != HAL_OK) {
		Error_Handler();
	}

    HAL_NVIC_SetPriority(TIM2_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

void init_ic_input()
{
    ic_gpio.Pin = GPIO_PIN_15;
    ic_gpio.Mode = GPIO_MODE_AF_PP;
    ic_gpio.Pull = GPIO_NOPULL;
    ic_gpio.Speed = GPIO_SPEED_FREQ_LOW;
    ic_gpio.Alternate = GPIO_AF1_TIM2;

    HAL_GPIO_Init(GPIOA, &ic_gpio);
}

int main(void)
{
    HAL_Init();
    SystemClock_Config();

    init_ic_input();
    init_uart();
    init_adc();
    init_timer();
    init_ic_timer();
    init_PWM();
    init_fan_pin();

    HAL_TIM_PWM_Start(&timer_handle, TIM_CHANNEL_1);
    HAL_TIM_IC_Start_IT(&ic_timer_handle, TIM_CHANNEL_1);
	HAL_TIM_Base_Start_IT(&ic_timer_handle);
    HAL_UART_Receive_IT(&uart_handle, &buffer, 1);

    int adc_val, adc_val_pwm;

    printf("---------------------------\n");
    printf("Closed loop control project\n");
    printf("     WORK IN PROGRESS\n");
    printf("---------------------------\n");


    while (1) {
        if (uart_flag == 1){
            pwm_val = atoi(text);
            free(text);
		    text = calloc(1, 1);
            uart_flag = 0;
        }
        HAL_ADC_Start(&adc_handle);
        adc_val = HAL_ADC_GetValue(&adc_handle);
        adc_val_pwm = ((float)adc_val / 4095) * 100;
        printf("PWM: %d | RPM: %d | CNT: %d\n", pwm_val, fan_rpm, fan_round_counter);
        __HAL_TIM_SET_COMPARE(&timer_handle, TIM_CHANNEL_1, pwm_val);
        HAL_Delay(500);
    }
}

void USART1_IRQHandler()
{
	HAL_UART_IRQHandler(&uart_handle);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	uint32_t length = strlen(text);
	text = realloc(text, length + 2);
	text[length] = buffer;
	text[length + 1] = '\0';

    uart_flag = 1;

	HAL_UART_Receive_IT(&uart_handle, &buffer, 1);
}

void TIM2_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&ic_timer_handle);
}

void HAL_TIM_IC_CaptureCallback (TIM_HandleTypeDef * htim)
{
    blade_counter++;
    if (blade_counter == 8){
	    if(htim->Instance == TIM2) {
		    fan_rpm = get_rpm(HAL_TIM_ReadCapturedValue(&ic_timer_handle, TIM_CHANNEL_1) + (period_counter * (65535 - 1)));
            fan_round_counter++;
	    }
        blade_counter = 0;
        period_counter = 0;
    }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM2) {
        period_counter++;  
    }
}

int get_rpm(int time)
{
    float round_time = time / 108000000.0;
    int rpm = 60 / round_time;

    return rpm;
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

    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_RCC_SYSCFG_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_ADC3_CLK_ENABLE();
    __HAL_RCC_TIM3_CLK_ENABLE();
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