/**
  ******************************************************************************
  * @file    main.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    02-October-2013
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup STM32F0308-Discovery_Demo
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static __IO uint32_t TimingDelay;
uint8_t BlinkSpeed = 0;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
void Demonstration(void)
{
  RCC_ClocksTypeDef RCC_Clocks;
  
  /* Configure LED3 and LED4 on STM32F0308-Discovery */
  STM_EVAL_LEDInit(LED3);
  STM_EVAL_LEDInit(LED4);
  
  /* Initialize User_Button on STM32F0308-Discovery */
  STM_EVAL_PBInit(BUTTON_USER, BUTTON_MODE_GPIO);
  
  /* SysTick end of count event each 1ms */
  RCC_GetClocksFreq(&RCC_Clocks);
  SysTick_Config(RCC_Clocks.HCLK_Frequency / 1000);
   
  /* Initiate Blink Speed variable */ 
  BlinkSpeed = 1;
  
  while(1)
  {  
    /* Check if the user button is pressed */
    if(STM_EVAL_PBGetState(BUTTON_USER)== SET)
    {
      /* BlinkSpeed: 1 -> 2 -> 0, then re-cycle */
      /* Turn on LD4 Blue LED during 1s each time User button is pressed */
      STM_EVAL_LEDOn(LED4);
      
      /* wait for 1s */
      Delay(1000);
      
      /* Turn off LD4 Blue LED after 1s each time User button is pressed */
      STM_EVAL_LEDOff(LED4);
      
      /* Increment the blink speed counter */
      BlinkSpeed++;
      
      /* Default value for blink speed counter */
      if(BlinkSpeed == 3)
      {  
        BlinkSpeed = 0;
      }
    }
    
    /* Test on blink speed */
    if(BlinkSpeed == 2)
    {
      /* LED3 toggles each 100 ms */
      STM_EVAL_LEDToggle(LED3);
      
      /* maintain LED3 status for 100ms */
      Delay(100);
    }
    else if(BlinkSpeed == 1)
    {
      /* LED3 toggles each 200 ms */
      STM_EVAL_LEDToggle(LED3);
      
      /* maintain LED3 status for 200ms */
      Delay(200);
    }
    else
    {  
      /* LED3 Off */
      STM_EVAL_LEDOff(LED3);
    }
  }
}

/**
  * @brief  Inserts a delay time.
  * @param  nTime: specifies the delay time length, in 1 ms.
  * @retval None
  */
void Delay(__IO uint32_t nTime)
{
  TimingDelay = nTime;

  while(TimingDelay != 0);
}

/**
  * @brief  Decrements the TimingDelay variable.
  * @param  None
  * @retval None
  */
void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {}
}
#endif

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
