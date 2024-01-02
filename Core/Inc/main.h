/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LCD_BL_Pin GPIO_PIN_4
#define LCD_BL_GPIO_Port GPIOD
#define LED_R_Pin GPIO_PIN_15
#define LED_R_GPIO_Port GPIOC
#define UART4_RX_Pin GPIO_PIN_9
#define UART4_RX_GPIO_Port GPIOI
#define LED_B_Pin GPIO_PIN_8
#define LED_B_GPIO_Port GPIOI
#define TIM3_CH1_PWM_Pin GPIO_PIN_6
#define TIM3_CH1_PWM_GPIO_Port GPIOC
#define IRDA_Pin GPIO_PIN_2
#define IRDA_GPIO_Port GPIOA
#define UART4_TX_Pin GPIO_PIN_0
#define UART4_TX_GPIO_Port GPIOA
#define USER_KEY_Pin GPIO_PIN_4
#define USER_KEY_GPIO_Port GPIOH
#define USER_KEY_EXTI_IRQn EXTI4_IRQn
#define PAJ7620_SCL_Pin GPIO_PIN_11
#define PAJ7620_SCL_GPIO_Port GPIOH
#define TEST_GPIO_Pin GPIO_PIN_2
#define TEST_GPIO_GPIO_Port GPIOB
#define PAJ7620_SDA_Pin GPIO_PIN_12
#define PAJ7620_SDA_GPIO_Port GPIOH
#define DHT11_Pin GPIO_PIN_1
#define DHT11_GPIO_Port GPIOB
#define SD_CAP_Pin GPIO_PIN_12
#define SD_CAP_GPIO_Port GPIOB
#define SPI1_FLASH_NSS__Pin GPIO_PIN_4
#define SPI1_FLASH_NSS__GPIO_Port GPIOA
#define DS18B20_Pin GPIO_PIN_0
#define DS18B20_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
