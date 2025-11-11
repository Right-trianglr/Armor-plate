#ifndef __RGB_H__
#define __RGB_H__

#include "main.h"

/*?????????CCR????*/
#define CODE_1 (58) // 1????????58
#define CODE_0 (25) // 0????????25

typedef struct
{
	uint8_t R;
	uint8_t G;
	uint8_t B;
} RGB_Color_TypeDef;

#define Pixel_NUM 8

extern int target_time_flag;
extern int Arrow_flag;

void RGB_SetColor(uint16_t LedId, RGB_Color_TypeDef Color);
void Reset_Load(void);
void RGB_SendArray_PA0(void);

void RGB_RED2(uint16_t Pixel_Len);

void RGB_Black2(uint16_t Pixel_Len);

extern RGB_Color_TypeDef COLOR1;

#endif
