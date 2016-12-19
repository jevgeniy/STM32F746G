#ifndef LCD
#define LCD

#include "stm32f7xx_hal.h"
/* ----------------------------------*/
#include "stm32746g_discovery.h"
#include "stm32746g_discovery_lcd.h"
#include <stdlib.h>

#define LCD_FRAME_BUFFER	SDRAM_DEVICE_ADDR

void LCD_Ini(void);
void LCD_Test_ColorText(void);

#endif
