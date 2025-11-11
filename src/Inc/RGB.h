#ifndef __RGB_H__
#define __RGB_H__

#include "main.h"

#define CODE_1 (58)
#define CODE_0 (25)

typedef struct
{
	uint8_t R;
	uint8_t G;
	uint8_t B;
} RGB_Color_TypeDef;

#define Pixel_NUM 8

void RGB_SetColor(uint16_t LedId, RGB_Color_TypeDef Color);

void Reset_Load(void);

void RGB_SetRED(uint16_t Pixel_Len);

#endif
