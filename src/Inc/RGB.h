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

/*一些常见颜色*/
const RGB_Color_TypeDef RED = {255, 0, 0};
const RGB_Color_TypeDef BLUE = {0, 0, 255};
const RGB_Color_TypeDef GREEN = {0, 255, 0};
const RGB_Color_TypeDef BLACK = {0, 0, 0};
const RGB_Color_TypeDef WHITE = {255, 255, 255};


#define Pixel_NUM 8

void RGB_SetColor(uint16_t LedId, RGB_Color_TypeDef Color);

void Reset_Load(void);

void RGB_SetColors(uint16_t Pixel_Len, RGB_Color_TypeDef Color);

void RGB_SendArray(TIM_HandleTypeDef *htimx, const uint32_t channel);

#endif
