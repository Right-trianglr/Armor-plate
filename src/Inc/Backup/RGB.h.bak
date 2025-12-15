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
extern const RGB_Color_TypeDef RED;
extern const RGB_Color_TypeDef BLUE;
extern const RGB_Color_TypeDef GREEN;
extern const RGB_Color_TypeDef BLACK;
extern const RGB_Color_TypeDef WHITE;


#define Pixel_NUM 8

void RGB_SetSingleColor(uint32_t Pixel_Buf[][24], uint16_t LedId, RGB_Color_TypeDef Color);

void Reset_Load(uint32_t Pixel_Buf[][24]);

void RGB_SendArray(uint32_t Pixel_Buf[][24], TIM_HandleTypeDef *htimx, const uint32_t channel);

void RGB_SetColors(uint32_t (*Pixel_Buf)[24], uint16_t Pixel_Len, RGB_Color_TypeDef Color);

#endif