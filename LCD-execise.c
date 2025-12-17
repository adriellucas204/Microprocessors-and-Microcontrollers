/*
Digitando o meu nome em um display de cristal líquido usando uma biblioteca
externa feita pelo professor da disciplina.
*/
/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Utility.h"
#include "LCD_Blio.h"
/* USER CODE END Includes */
/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/* USER CODE END PTD */
/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */
/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/* USER CODE END PM */
/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
/* USER CODE END PV */
/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
/* USER CODE END PFP */
/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* USER CODE END 0 */
/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
 /* USER CODE BEGIN 1 */
 /* USER CODE END 1 */
 /* MCU Configuration--------------------------------------------------------*/
 /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
 HAL_Init();
 /* USER CODE BEGIN Init */
 /* USER CODE END Init */
 /* Configure the system clock */
 SystemClock_Config();
 /* USER CODE BEGIN SysInit */
 /* USER CODE END SysInit */
 /* Initialize all configured peripherals */
 MX_GPIO_Init();
 /* USER CODE BEGIN 2 */
 Utility_Init();
 LCD_Init(4, 20);
 GPIO_Clock_Enable(GPIOA);
 GPIO_Clock_Enable(GPIOD);
 //colocar os pinos como saida
//  GPIO_Pin_Mode(GPIOA, PIN_0, OUTPUT); //LED azul
//  GPIO_Pin_Mode(GPIOA, PIN_1, OUTPUT); //LED vermelho
//  GPIO_Pin_Mode(GPIOA, PIN_2, OUTPUT); //LED amarelo
//  GPIO_Pin_Mode(GPIOA, PIN_3, OUTPUT); //LED azul
 GPIO_Pin_Mode(GPIOD, PIN_0, OUTPUT); //LED azul
 GPIO_Pin_Mode(GPIOD, PIN_1, OUTPUT); //LED vermelho
 GPIO_Pin_Mode(GPIOD, PIN_2, OUTPUT); //LED amarelo
 GPIO_Pin_Mode(GPIOD, PIN_3, OUTPUT); //LED azul
//  GPIO_Pin_Mode(GPIOE, PIN_3, INPUT); //BOTAO K0
//  GPIO_Pin_Mode(GPIOE, PIN_4, INPUT); //BOTAO K1
//
//  GPIO_Write_Pin(GPIOD, PIN_0, LOW); //leds comecam desligados
//  GPIO_Write_Pin(GPIOA, PIN_1, LOW);
//  GPIO_Write_Pin(GPIOA, PIN_2, LOW);
//  GPIO_Write_Pin(GPIOA, PIN_3, LOW);
 const uint8_t mask[16]={ 0b00111111, //0
 0b00000110, //1
 0b01011011, //2
 0b01001111, //3
 0b01100110, //4
 0b01101101, //5
 0b01111101, //6
 0b00000111, //7
 0b01111111, //8
 0b01101111, //9
 0b01110111, //A
 0b01111100, //B
 0b00111001, //C
 0b01011110, //D
 0b01111001, //E
 0b01110001}; //F
//  EXTI_Config(EXTI3, GPIOE, FALLING_EDGE);
//  EXTI_Config(EXTI4, GPIOE, FALLING_EDGE);
//
//  NVIC_EnableIRQ(EXTI3_IRQn);
//  NVIC_EnableIRQ(EXTI4_IRQn);
 /* USER CODE END 2 */
 /* Infinite loop */
 /* USER CODE BEGIN WHILE */
 while (1){
	  LCD_Set_Cursor(1, 1);
	  LCD_Write_String(1, 1, "Adriel");
	  Delay_ms(500);
	  LCD_Write_String(2, 1, "Lucas");
	  Delay_ms(500);
	  LCD_Write_String(3, 1, "Pereira");
	  Delay_ms(500);
	  LCD_Set_Cursor(4, 1);
	  for (int i = 10; i >= 0; i--) {
		  if (i == 10){
			  LCD_Write_String(4, 1, "10");
			  LCD_Set_Cursor(4, 1);
		  } else {
			  LCD_Write_String(4, 1, "0");
			  LCD_Write_Char(i + 48);
		  }
		  Delay_ms(500);
	  }
	  LCD_Write_String(4, 1, "");
	  LCD_Write_String(4, 2, "");
	  LCD_Write_String(4, 3, "");
	  LCD_Write_String(4, 4, "");
   /* USER CODE END WHILE */
   /* USER CODE BEGIN 3 */
 }
 /* USER CODE END 3 */
}
/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
 RCC_OscInitTypeDef RCC_OscInitStruct = {0};
 RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
 /** Configure the main internal regulator output voltage
 */
 __HAL_RCC_PWR_CLK_ENABLE();
 __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
 /** Initializes the RCC Oscillators according to the specified parameters
 * in the RCC_OscInitTypeDef structure.
 */
 RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
 RCC_OscInitStruct.HSIState = RCC_HSI_ON;
 RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
 RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
 RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
 RCC_OscInitStruct.PLL.PLLM = 8;
 RCC_OscInitStruct.PLL.PLLN = 168;
 RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
 RCC_OscInitStruct.PLL.PLLQ = 4;
 if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
 {
   Error_Handler();
 }
 /** Initializes the CPU, AHB and APB buses clocks
 */
 RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                             |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
 RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
 RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
 RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
 RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
 if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
 {
   Error_Handler();
 }
}
/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void)
{
 /* USER CODE BEGIN MX_GPIO_Init_1 */
 /* USER CODE END MX_GPIO_Init_1 */
 /* GPIO Ports Clock Enable */
 __HAL_RCC_GPIOH_CLK_ENABLE();
 /* USER CODE BEGIN MX_GPIO_Init_2 */
 /* USER CODE END MX_GPIO_Init_2 */
}
/* USER CODE BEGIN 4 */
//void EXTI3_IRQHandler(){
//	GPIO_Toggle_Pin(GPIOA, PIN_7);
//	EXTI_Clear_Pending(EXTI3);
//}
//
//void EXTI4_IRQHandler(){
//	GPIO_Toggle_Pin(GPIOA, PIN_6);
//	EXTI_Clear_Pending(EXTI4);
//}
/* USER CODE END 4 */
/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
 /* USER CODE BEGIN Error_Handler_Debug */
 /* User can add his own implementation to report the HAL error return state */
 __disable_irq();
 while (1)
 {
 }
 /* USER CODE END Error_Handler_Debug */
}
#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
 /* USER CODE BEGIN 6 */
 /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
 /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
