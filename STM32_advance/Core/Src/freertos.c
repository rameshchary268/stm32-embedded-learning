/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include <stdio.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
static void LedTask(void *argument);
static void UartTask(void *argument);

/* USER CODE END FunctionPrototypes */

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
static const osThreadAttr_t ledTaskAttributes = {
  .name = "LedTask",
  .stack_size = 256,
  .priority = (osPriority_t) osPriorityNormal,
};

static const osThreadAttr_t uartTaskAttributes = {
  .name = "UartTask",
  .stack_size = 512,
  .priority = (osPriority_t) osPriorityBelowNormal,
};

void AppTasks_Init(void)
{
  if (osThreadNew(LedTask, NULL, &ledTaskAttributes) == NULL)
  {
    Error_Handler();
  }

  if (osThreadNew(UartTask, NULL, &uartTaskAttributes) == NULL)
  {
    Error_Handler();
  }
}

static void LedTask(void *argument)
{
  (void)argument;

  for (;;)
  {
    HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
    osDelay(200);
  }
}

static void UartTask(void *argument)
{
  (void)argument;

  for (;;)
  {
    printf("UART task is running\r\n");
    osDelay(1000);
  }
}

/* USER CODE END Application */

