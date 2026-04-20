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
#include "dma.h"
#include "eth.h"
#include "fatfs.h"
#include "quadspi.h"
#include "sdmmc.h"
#include "spi.h"
#include "usart.h"
#include "usb_device.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
#include <stdio.h>
#include "usbd_cdc_if.h"
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
volatile uint8_t readFlag = 0;

uint8_t frameBuffer[288000];

char TxBuffer[250];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
static void USB_CDC_Print(char* TxStr)
{
//    while(CDC_Transmit_FS((uint8_t*)TxStr, strlen(TxStr)) == USBD_BUSY);
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
//	  FRESULT res; /* FatFs function common result code */
//	  uint32_t byteswritten, bytesread; /* File write/read counts */
//	  uint8_t wtext[] = "STM32 FATFS works great!"; /* File write buffer */
//	  uint8_t rtext[_MAX_SS];/* File read buffer */

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
  MX_DMA_Init();	MX_SPI3_Init();
	WriteBitStream();

  MX_ETH_Init();
  MX_USART3_UART_Init();
  MX_QUADSPI_Init();
  MX_SDMMC1_SD_Init();
  MX_FATFS_Init();
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 2 */

    uint32_t bytesRead = 0;

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

    FATFS FatFs;
      FIL Fil;
      FRESULT FR_Status;
      FATFS *FS_Ptr;
      UINT RWC, WWC; // Read/Write Word Counter
      DWORD FreeClusters;
      uint32_t TotalSize, FreeSpace;
      char RW_Buffer[200];

        //------------------[ Mount The SD Card ]--------------------
        FR_Status = f_mount(&FatFs, SDPath, 1);
        while (FR_Status != FR_OK)
        {
          sprintf(TxBuffer, "Error! While Mounting SD Card, Error Code: (%i)\r\n", FR_Status);
//          USB_CDC_Print(TxBuffer);
//          break;
        }
        sprintf(TxBuffer, "SD Card Mounted Successfully! \r\n\n");
        USB_CDC_Print(TxBuffer);

        //------------------[ Get & Print The SD Card Size & Free Space ]--------------------
        f_getfree("", &FreeClusters, &FS_Ptr);
        TotalSize = (uint32_t)((FS_Ptr->n_fatent - 2) * FS_Ptr->csize * 0.5);
        FreeSpace = (uint32_t)(FreeClusters * FS_Ptr->csize * 0.5);
        sprintf(TxBuffer, "Total SD Card Size: %lu Bytes\r\n", TotalSize);
        USB_CDC_Print(TxBuffer);
        sprintf(TxBuffer, "Free SD Card Space: %lu Bytes\r\n\n", FreeSpace);
        USB_CDC_Print(TxBuffer);
        //------------------[ Open A Text File For Write & Write Data ]--------------------
        //Open the file
        FR_Status = f_open(&Fil, "file.raw", FA_WRITE | FA_READ | FA_CREATE_ALWAYS);
        while(FR_Status != FR_OK)
        {
          sprintf(TxBuffer, "Error! While Creating/Opening A New Text File, Error Code: (%i)\r\n", FR_Status);
//          USB_CDC_Print(TxBuffer);

        }

        // Enable fifo half full interrupts
        HAL_NVIC_SetPriority(EXTI2_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(EXTI2_IRQn);
        /*
        sprintf(TxBuffer, "Text File Created & Opened! Writing Data To The Text File..\r\n\n");
        USB_CDC_Print(TxBuffer);
        // (1) Write Data To The Text File [ Using f_puts() Function ]
        f_puts("Hello! From STM32 To SD Card Over SDMMC, Using f_puts()\n", &Fil);
        // (2) Write Data To The Text File [ Using f_write() Function ]
        strcpy(RW_Buffer, "Hello! From STM32 To SD Card Over SDMMC, Using f_write()\r\n");
        f_write(&Fil, RW_Buffer, strlen(RW_Buffer), &WWC);
        // Close The File
        f_close(&Fil);
        //------------------[ Open A Text File For Read & Read Its Data ]--------------------
        // Open The File
        FR_Status = f_open(&Fil, "MyTextFile.txt", FA_READ);
        while(FR_Status != FR_OK)
        {
          sprintf(TxBuffer, "Error! While Opening (MyTextFile.txt) File For Read.. \r\n");
          USB_CDC_Print(TxBuffer);

        }
        // (1) Read The Text File's Data [ Using f_gets() Function ]
        f_gets(RW_Buffer, sizeof(RW_Buffer), &Fil);
        sprintf(TxBuffer, "Data Read From (MyTextFile.txt) Using f_gets():%s", RW_Buffer);
        USB_CDC_Print(TxBuffer);
        // (2) Read The Text File's Data [ Using f_read() Function ]
        f_read(&Fil, RW_Buffer, f_size(&Fil), &RWC);
        sprintf(TxBuffer, "Data Read From (MyTextFile.txt) Using f_read():%s", RW_Buffer);
        USB_CDC_Print(TxBuffer);
        // Close The File
        f_close(&Fil);
        sprintf(TxBuffer, "File Closed! \r\n\n");
        USB_CDC_Print(TxBuffer);
        //------------------[ Open An Existing Text File, Update Its Content, Read It Back ]--------------------
        // (1) Open The Existing File For Write (Update)
        FR_Status = f_open(&Fil, "MyTextFile.txt", FA_OPEN_EXISTING | FA_WRITE);
        FR_Status = f_lseek(&Fil, f_size(&Fil)); // Move The File Pointer To The EOF (End-Of-File)
        while(FR_Status != FR_OK)
        {
          sprintf(TxBuffer, "Error! While Opening (MyTextFile.txt) File For Update.. \r\n");
//          USB_CDC_Print(TxBuffer);
//          break;
        }
        // (2) Write New Line of Text Data To The File
        FR_Status = f_puts("This New Line Was Added During File Update!\r\n", &Fil);
        f_close(&Fil);
        memset(RW_Buffer,'\0',sizeof(RW_Buffer)); // Clear The Buffer
        // (3) Read The Contents of The Text File After The Update
        FR_Status = f_open(&Fil, "MyTextFile.txt", FA_READ); // Open The File For Read
        f_read(&Fil, RW_Buffer, f_size(&Fil), &RWC);
        sprintf(TxBuffer, "Data Read From (MyTextFile.txt) After Update:\r\n%s", RW_Buffer);
        USB_CDC_Print(TxBuffer);
        f_close(&Fil);
        //------------------[ Delete The Text File ]--------------------
            // Delete The File
            /*
            FR_Status = f_unlink(MyTextFile.txt);
            if (FR_Status != FR_OK){
                sprintf(TxBuffer, "Error! While Deleting The (MyTextFile.txt) File.. \r\n");
                USC_CDC_Print(TxBuffer);
            }


      //------------------[ Test Complete! Unmount The SD Card ]--------------------
      FR_Status = f_mount(NULL, "", 0);
      while (FR_Status != FR_OK)
      {
          sprintf(TxBuffer, "\r\nError! While Un-mounting SD Card, Error Code: (%i)\r\n", FR_Status);
          USB_CDC_Print(TxBuffer);
      }

          sprintf(TxBuffer, "\r\nSD Card Un-mounted Successfully! \r\n");
          USB_CDC_Print(TxBuffer);
          */

	uint32_t readCounter = 0;

	while (1)
	{
	  // Wait until fpga signals that data is ready
	  if (readFlag == 1)
	  {
		  __disable_irq();

		  // Quad SPI is memory mapped, can use memcpy or DMA directly from the FPGA memory
		  // Number of bytes read must be equal to fpga fifo size (currently 512 bytes can be increased up to 4KB) (bigger better for SDCard writes?)
		  memcpy(&frameBuffer[bytesRead], ((uint8_t *)QSPI_MEMORY_START_ADDRESS + bytesRead), 512);

		  // Reads must be made to sequential addresses due to stm pre-fetching, even though the FPGA doesn't care what the address is.
		  // Maximum of 256MB can be memory mapped so wrap address
		  // Not sure what happens with pre-fetch at end of memory
		  bytesRead = (bytesRead + 512) & 0xfffffff;

		  readFlag = 0;
		  readCounter++;
		  __enable_irq();
	  }
	  UINT bytesWritten = 0;
	  // After data is collected send over serial
	  if (readCounter >= 562)
	  {
//		  for (int i = 0; i < 562 / 2; i++){
//			  HAL_UART_Transmit(&huart3, &frameBuffer[512*i], 512, 1000);
		  f_write(&Fil, &frameBuffer[0], 562*512, &bytesWritten);
//
		  f_close(&Fil);
		  __BKPT(1);
		  while(1)
		  {
			  __BKPT(1);
		  }
	  }

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

  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 8;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
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

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_6) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if(GPIO_Pin == GPIO_PIN_2)
    {
		readFlag = 1;
    }
}

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
#ifdef USE_FULL_ASSERT
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
