#include "creat_task.h"

#include "task_app.h"

#include "stdio.h"
#include "api_information.h"
#include "api_sdram.h"
#include "api_led.h"



	static void hardware_init(void);

/********************************************************************************************************/
		/* 任务句柄 */
		static TaskHandle_t StartTask_Handle = NULL;    /* 启动任务任务句柄*/
		static TaskHandle_t LedTask_Handle = NULL;      /* LED     任务句柄     */
		static TaskHandle_t ShellTask_Handle = NULL;    /* Shell   任务句柄     */
    static TaskHandle_t DisplayTask_Handle = NULL;  /* display 任务句柄     */
/********************************************************************************************************/

/********************************************************************************************************/
		/* 任务函数声明 */
	  static void StartTask(void);/* 用于创建任务的 任务 */
/********************************************************************************************************/


  


  /*启动任务用于启动其他任务，启动之后就将自己删除或者挂起*/
   int FreeRTOS_Start(void)
   {
		 BaseType_t xReturn = pdPASS;/* 定义一个创建信息返回值，默认为pdPASS */

     
  
     /* 创建AppTaskCreate任务 */
     xReturn = xTaskCreate((TaskFunction_t )StartTask,  /* 任务入口函数 */
                        (const char*    )"AppTaskCreate",/* 任务名字 */
                        (uint16_t       )512,  /* 任务栈大小 */
                        (void*          )NULL,/* 任务入口函数参数 */
                        (UBaseType_t    )1, /* 任务的优先级 */
                        (TaskHandle_t*  )&StartTask_Handle);/* 任务控制块指针 */ 
     /* 启动任务调度 */           
     if(pdPASS == xReturn)
       vTaskStartScheduler();   /* 启动任务，开启调度 */
    else
    return -1;  
  
    while(1);   /* 正常不会执行到这里 */  
	}




   void StartTask(void)
	{
	  BaseType_t xReturn = pdPASS;/* 定义一个创建信息返回值，默认为pdPASS */
  
    taskENTER_CRITICAL();           //进入临界区
		
//		hardware_init();
  
    /* 创建LedTask任务 */
    xReturn = xTaskCreate((TaskFunction_t )LedTask, /* 任务入口函数 */
                        (const char*    )"LED_Task",/* 任务名字 */
                        (uint16_t       )128,   /* 任务栈大小 */
                        (void*          )NULL,	/* 任务入口函数参数 */
                        (UBaseType_t    )2,	    /* 任务的优先级 */
                        (TaskHandle_t*  )&LedTask_Handle);/* 任务控制块指针 */
    if(pdPASS != xReturn){
		
		  printf(" create LedTask err  \r\n");
		}
		
	 
		/* 创建ShellTask任务 */
    xReturn = xTaskCreate((TaskFunction_t )ShellTask, /* 任务入口函数 */
                        (const char*    )"Shell_Task",/* 任务名字 */
                        (uint16_t       )256,   /* 任务栈大小 */
                        (void*          )NULL,	/* 任务入口函数参数 */
                        (UBaseType_t    )2,	    /* 任务的优先级 */
                        (TaskHandle_t*  )&ShellTask_Handle);/* 任务控制块指针 */
    if(pdPASS != xReturn){
		 printf(" create ShellTask err  \r\n");
		}
		
		
		
		/* 创建display任务 */
    xReturn = xTaskCreate((TaskFunction_t )DisplayTask, /* 任务入口函数 */
                        (const char*    )"Display_Task",/* 任务名字 */
                        (uint16_t       )256,   /* 任务栈大小 */
                        (void*          )NULL,	/* 任务入口函数参数 */
                        (UBaseType_t    )2,	    /* 任务的优先级 */
                        (TaskHandle_t*  )&DisplayTask_Handle);/* 任务控制块指针 */
    if(pdPASS != xReturn){
		 printf(" create DisplayTask err  \r\n");
		}
		
	  /* Other Task  …… */
		
		
		
		
		
		
		vTaskDelete(StartTask_Handle);  //删除AppTaskCreate任务
		
    taskEXIT_CRITICAL();            //退出临界区
		
		
		
	}
		

  






	void display_app_logo(void)
	{
	
  printf("               AAA               PPPPPPPPPPPPPPPPP   PPPPPPPPPPPPPPPPP     1111111   \r\n");
  printf("              A:::A              P::::::::::::::::P  P::::::::::::::::P   1::::::1    \r\n");
  printf("             A:::::A             P::::::PPPPPP:::::P P::::::PPPPPP:::::P 1:::::::1    \r\n");
  printf("            A:::::::A            PP:::::P     P:::::PPP:::::P     P:::::P111:::::1     \r\n");
  printf("           A:::::::::A             P::::P     P:::::P  P::::P     P:::::P   1::::1    \r\n");
  printf("          A:::::A:::::A            P::::P     P:::::P  P::::P     P:::::P   1::::1    \r\n");
  printf("         A:::::A A:::::A           P::::PPPPPP:::::P   P::::PPPPPP:::::P    1::::1    \r\n");
  printf("        A:::::A   A:::::A          P:::::::::::::PP    P:::::::::::::PP     1::::l    \r\n");
  printf("       A:::::A     A:::::A         P::::PPPPPPPPP      P::::PPPPPPPPP       1::::l    \r\n");
  printf("      A:::::AAAAAAAAA:::::A        P::::P              P::::P               1::::l     \r\n");
  printf("     A:::::::::::::::::::::A       P::::P              P::::P               1::::l    \r\n");
  printf("    A:::::AAAAAAAAAAAAA:::::A      P::::P              P::::P               1::::l     \r\n");
  printf("   A:::::A             A:::::A    PP::::::PP          PP::::::PP          111::::::111 \r\n");
  printf("  A:::::A               A:::::A  P::::::::P          P::::::::P          1::::::::::1 \r\n");
  printf(" A:::::A                 A:::::A P::::::::P          P::::::::P          1::::::::::1 \r\n");
  printf("AAAAAAA                   AAAAAAAPPPPPPPPPP          PPPPPPPPPP          111111111111 \r\n\r\n\r\n");
  printf(" jump to app1 success\r\n");                                                                           

	}
	
	
	void hardware_init(void)
	{
		
		//打印logo
		display_app_logo();
		
		//获取设备信息
		uint32_t SysClock,HCLKFreq,PCLK1Freq,PCLK2Freq;
		api_clock_info * papi_clock_info =&sapi_clock_info;
		SysClock = papi_clock_info->get_SysClockFreq();
	  HCLKFreq = papi_clock_info->get_HCLKFreq();
		PCLK1Freq = papi_clock_info->get_PCLK1Freq();
	  PCLK2Freq = papi_clock_info->get_PCLK2Freq();
		printf("SysClock:%d \r\n ",SysClock);
		printf("HCLKFreq:%d \r\n ",HCLKFreq);
		printf("PCLK1Freq:%d \r\n ",PCLK1Freq);
		printf("PCLK2Freq:%d \r\n ",PCLK2Freq);
	}





