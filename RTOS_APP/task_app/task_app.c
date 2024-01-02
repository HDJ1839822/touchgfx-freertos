#include "task_app.h"

#include "freertos.h"
#include "task.h"

#include "gpio.h"
#include "stdio.h"
#include "shell.h"





   void LedTask(void)
  {
	 while (1)
    {
      HAL_GPIO_TogglePin(LED_B_GPIO_Port,LED_B_Pin);
			HAL_GPIO_TogglePin(LED_R_GPIO_Port,LED_R_Pin);
      vTaskDelay(500);   /* 延时500个tick */
    }
  }	
	
	
	void ShellTask(void)
	{
	  while(1)
		{
		
	  	shell();
		  vTaskDelay(1);   /* 延时500个tick */
		}

	}
	
	
	
	void DisplayTask(void)
	{
	  while(1)
		{
		  
	    
		  vTaskDelay(1);   /* 延时500个tick */
		}

	}
	
	
			