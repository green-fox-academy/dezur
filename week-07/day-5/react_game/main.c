#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

/* necessary include files */
#include "stm32746g_discovery_lcd.h" // Feel free to look inside and explore!
#include "stm32746g_discovery_ts.h"  // Feel free to look inside and explore!
#include "ft5366.h"

static void Error_Handler(void);
static void SystemClock_Config(void);
static void LCD_Init();
static void home_screen(RNG_HandleTypeDef, TS_StateTypeDef);
static void create_box(RNG_HandleTypeDef);
static int box_touched(TS_StateTypeDef);
static void game_over(void);

uint32_t randx, randy, time;
char buffer[100];
uint32_t now, react_time, counter = 0, sum = 0, avg = 0;
int status = 0;
int results[10];
int offset = 20;

int main(void)
{
    SystemClock_Config();
    HAL_Init();
    LCD_Init();
    BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());
    TS_StateTypeDef ts_state;
    RNG_HandleTypeDef rng_handle;
    rng_handle.Instance = RNG;
    HAL_RNG_Init(&rng_handle);

    while (1)
    {
        BSP_TS_GetState(&ts_state);

        switch (status){
            case 0: home_screen(rng_handle, ts_state);
                    break;
            case 1: if (box_touched(ts_state))
                        create_box(rng_handle);
                    break;
            case 2: game_over();
                    break;
        }
    }
}

static void home_screen(RNG_HandleTypeDef rng_handle, TS_StateTypeDef ts_state)
{
    sum = 0;
    counter = 0;
    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    BSP_LCD_DisplayStringAt(0, 120, "Touch to start!", CENTER_MODE);
    if (ts_state.touchDetected)
    {
        status = 1;
        create_box(rng_handle);
    }
}

static void create_box(RNG_HandleTypeDef rng_handle)
{
    randx = HAL_RNG_GetRandomNumber(&rng_handle) % 430;
    randy = HAL_RNG_GetRandomNumber(&rng_handle) % 200 + 20;
    time = HAL_RNG_GetRandomNumber(&rng_handle) % 2500 + 500;
    if (counter < 10)
    {
        BSP_LCD_Clear(LCD_COLOR_WHITE);
        if (counter > 0)
        {
            react_time = HAL_GetTick() - now - 4;
            sprintf(buffer, "%d ms", react_time);
            BSP_LCD_DisplayStringAtLine(0, buffer);
            results[counter - 1] = react_time;
        }
        HAL_Delay(time);
        BSP_LCD_FillRect(randx, randy, 50, 50);
        now = HAL_GetTick();
    }
    else
    {
        status = 2;
    }
    counter++;
}

static int box_touched(TS_StateTypeDef ts_state)
{
    BSP_TS_GetState(&ts_state);
    if (ts_state.touchDetected && ts_state.touchX[0] > randx  - offset && ts_state.touchX[0] < randx + 50 + offset  && 
    ts_state.touchX[0] < randx + 50 + offset && ts_state.touchY[0] > randy - offset && ts_state.touchY[0] < randy + 50 + offset)
        return 1;
    else
        return 0;
}

static void game_over()
{
    while (status == 2)
    {
        BSP_LCD_Clear(LCD_COLOR_WHITE);
        BSP_LCD_DisplayStringAt(0, 120, "GAME OVER", CENTER_MODE);
        for (int i = 0; i < 10; i++)
        {
            sum += results[i];
        }
        avg = sum / 10;
        sprintf(buffer, "Average: %d ms", avg);
        BSP_LCD_DisplayStringAt(0, 150, buffer, CENTER_MODE);
        counter++;
        HAL_Delay(5000);
        status = 0;
    }
}


///////////////////////////// You shouldn't write any code beyond this point //////////////////////////////
static void LCD_Init()
{
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(1);
    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
    BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
    BSP_LCD_Clear(LCD_COLOR_WHITE);
}

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