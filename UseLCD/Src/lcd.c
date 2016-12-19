#include "lcd.h"

uint8_t lcd_status = LCD_OK;
static uint8_t buf[20]={0};
static uint32_t i, color;

/* ----------------------------------------------------------*/
void LCD_Ini(void)
{
	lcd_status = BSP_LCD_Init();
	BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER,LCD_FRAME_BUFFER);
	BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
	BSP_LCD_DisplayOn();
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_SetTextColor(LCD_COLOR_RED);
	BSP_LCD_SetFont(&Font24);
}
/* ----------------------------------------------------------*/
void LCD_Test_ColorText(void)
{	
	sprintf((char*)buf, "%s", "Hello, World!");
	BSP_LCD_Clear(LCD_COLOR_BLACK);
		for(i=0; i<8; i++)
		{
			color = (uint32_t)(LCD_COLOR_TRANSPARENT |
													((rand() %256) <<16) | 
													((rand() %256) << 8) | 
													 (rand() %256)			 );
			BSP_LCD_SetTextColor(color);
			BSP_LCD_DisplayStringAt(10, 10+(i*30), buf, LEFT_MODE);
			HAL_Delay(400);
		}
}

