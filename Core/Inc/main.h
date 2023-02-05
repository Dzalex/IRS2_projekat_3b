/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ssd1306_conf.h"
#include "stdint.h"

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
enum generator_waveform {SIN=0, TRIANGE=1, SQUARE=2};
struct generator_params;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
extern struct generator_params g_Generator_parameters;
extern const uint16_t FREQ_TO_COUNT_RATIO;
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void Init_Generator();
void Set_Generator_Amplitude(uint16_t amplitude);
void Set_Generator_Frequency(uint16_t frequency);
void Set_Generator_Mode(enum generator_waveform waveform);

void Generator_Next_Mode();
void Set_Previous_Mode();

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define OLED_I2C hi2c2
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define ADC1_POT0_Pin GPIO_PIN_0
#define ADC1_POT0_GPIO_Port GPIOA
#define ADC1_POT1_Pin GPIO_PIN_1
#define ADC1_POT1_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define SW2_Pin GPIO_PIN_8
#define SW2_GPIO_Port GPIOC
#define SW2_EXTI_IRQn EXTI9_5_IRQn
#define SW1_Pin GPIO_PIN_9
#define SW1_GPIO_Port GPIOC
#define SW1_EXTI_IRQn EXTI9_5_IRQn
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
