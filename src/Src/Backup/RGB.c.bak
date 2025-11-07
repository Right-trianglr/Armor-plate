#include "RGB.h"
#include "main.h"


/*Some Static Colors------------------------------*/
const RGB_Color_TypeDef RED = {220, 0, 0}; // 显示红色RGB数据
const RGB_Color_TypeDef BLUE = {0, 0, 255};
const RGB_Color_TypeDef BLACK = {0, 0, 0};

// 测试数据
RGB_Color_TypeDef COLOR1 = {200, 0, 0};

/*二维数组存放最终PWM输出数组，每一行24个
数据代表一个LED，最后一行24个0代表RESET码*/
uint32_t Pixel_Buf[Pixel_NUM + 1][24];

/**
 * @brief 设置单个RGB LED的颜色
 *
 * 将颜色结构体中的RGB三色数据（各8位）转换为24位PWM码，存入Pixel_Buf数组，
 * 用于WS2812灯珠的驱动。每个LED对应Pixel_Buf的一行，依次存放G、R、B三色的8位数据。
 *
 * @param LedId LED序号（从0开始，最大为Pixel_NUM）
 * @param Color RGB颜色结构体（包含R、G、B分量）
 */
void RGB_SetColor(uint16_t LedId, RGB_Color_TypeDef Color)
{
	uint16_t i;
	if (LedId > Pixel_NUM)
		return; // avoid overflow 防止写入ID大于LED总数

	for (i = 0; i < 8; i++)
		Pixel_Buf[LedId][i] = ((Color.G & (1 << (7 - i))) ? (CODE_1) : CODE_0); // 数组某一行0~7转化存放G
	for (i = 8; i < 16; i++)
		Pixel_Buf[LedId][i] = ((Color.R & (1 << (15 - i))) ? (CODE_1) : CODE_0); // 数组某一行8~15转化存放R
	for (i = 16; i < 24; i++)
		Pixel_Buf[LedId][i] = ((Color.B & (1 << (23 - i))) ? (CODE_1) : CODE_0); // 数组某一行16~23转化存放B
}

/**
 * @brief WS2812灯珠复位码加载函数
 * 
 * 将最后一行的部分数据（当前为前2个）置为0，输出低电平PWM波
 * 
 * 用于WS2812灯珠的复位延时。实际复位时长为 24*1.2us = 28.8us，满足大于24us的要求。
 * 注意：如需完整复位，建议将全部24位都置为0。
 */
void Reset_Load(void)
{
	uint16_t i;
	for (i = 0; i < 2; i++)
	{
		Pixel_Buf[Pixel_NUM][i] = 0;
	}
} // 注释掉后点灯代码便可以在while循环中使用了


TIM_HandleTypeDef htim2;
/**
 * @brief 通过TIM2通道1发送WS2812灯珠数据
 *
 * PA0 靶环 （当前测试用）
 * TIM2-通道1
 *
 * 使用DMA方式，将Pixel_Buf数组中的数据输出
 * 用于驱动WS2812灯珠显示靶环效果。
 */
void RGB_SendArray_PA0(void)
{
	HAL_TIM_PWM_Start_DMA(&htim2, TIM_CHANNEL_1, (uint32_t *)Pixel_Buf, (Pixel_NUM + 1) * 24);
}

// PA1
void RGB_SendArray(void)
{
	HAL_TIM_PWM_Start_DMA(&htim2, TIM_CHANNEL_2, (uint32_t *)Pixel_Buf, (Pixel_NUM + 1) * 24);
}


/**
 * @brief 红色灯珠显示函数2（TIM2通道1，PA0，靶环专用）
 *
 * 用TIM2通道1发送数据 (PA0)
 * @param Pixel_Len 需要点亮的LED数量
 * 
 */
void RGB_RED2(uint16_t Pixel_Len)
{
	uint16_t i;

	for (i = 0; i < Pixel_Len; i++) // 给对应个数LED写入红色
	{
		RGB_SetColor(i, RED);
	}

	Reset_Load();
	//DWT_Delay(5);
	RGB_SendArray_PA0();
}



/**
 * @brief 全灭灯珠显示函数2（TIM2通道1，PA0，靶环专用）
 *
 * 用TIM2通道1发送数据 (PA0)
 *
 * @param Pixel_Len 需要熄灭的LED数量
 */
void RGB_Black2(uint16_t Pixel_Len)
{
	uint16_t i;

	for (i = 0; i < Pixel_Len; i++) // 给对应个数LED写入黑色（熄灭）
	{
		RGB_SetColor(i, BLACK);
	}

	Reset_Load();
	RGB_SendArray_PA0();
}

// 全灭函数
void RGB_all_black(void)
{
	uint16_t i;
	for (i = 0; i < 8; i++) // 全灭
	{
		RGB_SetColor(i, BLACK);
	}
	Reset_Load();
	RGB_SendArray_PA0();
}
