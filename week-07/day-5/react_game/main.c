#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

/* necessary include files */
#include "stm32746g_discovery_lcd.h" // Feel free to look inside and explore!
#include "stm32746g_discovery_ts.h"  // Feel free to look inside and explore!
#include "ft5366.h"

static void Error_Handler(void);
static void SystemClock_Config(void);

void LCD_Init()
{
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(1);
    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
    BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
    BSP_LCD_Clear(LCD_COLOR_WHITE);
}

int main(void)
{
    char buffer[100];
    uint32_t now, react_time, randx, randy, time, avg;
    int status = 0;

    SystemClock_Config();
    HAL_Init();
    LCD_Init();
    BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());
    TS_StateTypeDef ts_state;
    RNG_HandleTypeDef rng_handle;
    rng_handle.Instance = RNG;
    HAL_RNG_Init(&rng_handle);

    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);

    BSP_LCD_DisplayStringAt(0, 120, "Touch to start!", CENTER_MODE);

    while (1)
    {
        BSP_TS_GetState(&ts_state);
        if (ts_state.touchDetected && status == 0)
        {
            status = 1;
            BSP_LCD_Clear(LCD_COLOR_WHITE);
            randx = HAL_RNG_GetRandomNumber(&rng_handle) % 430;
            randy = HAL_RNG_GetRandomNumber(&rng_handle) % 220;
            time = HAL_RNG_GetRandomNumber(&rng_handle) % 2500 + 500;
            HAL_Delay(time);
            BSP_LCD_FillRect(randx, randy, 50, 50);
            now = HAL_GetTick();
        }
        BSP_TS_GetState(&ts_state);
        if (status == 1 && ts_state.touchDetected && ts_state.touchX[0] > randx && ts_state.touchX[0] < randx + 50 && ts_state.touchY[0] > randy && ts_state.touchY[0] < randy + 50)
        {
            BSP_LCD_Clear(LCD_COLOR_WHITE);
            randx = HAL_RNG_GetRandomNumber(&rng_handle) % 430;
            randy = HAL_RNG_GetRandomNumber(&rng_handle) % 220;
            time = HAL_RNG_GetRandomNumber(&rng_handle) % 2500 + 500;
            react_time = HAL_GetTick() - now;
            sprintf(buffer, "%d ms", react_time);
            BSP_LCD_DisplayStringAtLine(0, buffer);
            HAL_Delay(time);
            BSP_LCD_FillRect(randx, randy, 50, 50);
            now = HAL_GetTick();
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