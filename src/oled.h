#ifndef OLED_H_
#define OLED_H_
#include "i2c_bb.h"
#include <stdint.h>

#define DEVICEADDR_OLED (0x3c << 1)
#define OLED_WIDTH 96
#define OLED_HEIGHT 16
#define FRAMEBUFFER_START 17

void oled_init(void);

void Oled_DisplayOn(void);
void Oled_DisplayOff(void);
void OLED_Sync(void);
void Oled_DrawArea(uint8_t x0, uint8_t y0, uint8_t wide, uint8_t height,
                   const uint8_t *ptr);
void Set_ShowPos(uint8_t x, uint8_t y);
void GPIO_Init_OLED(void);
void Init_Oled(uint8_t leftHanded);
void Data_Command(uint8_t len, const uint8_t *ptr);
void Clear_Screen(void); // Clear the screen
/*Functions for writing to the screen*/
void OLED_DrawString(const char *string, const uint8_t length);
void OLED_DrawChar(char c, uint8_t x);
void OLED_DrawTwoNumber(uint8_t in, uint8_t x);

#endif