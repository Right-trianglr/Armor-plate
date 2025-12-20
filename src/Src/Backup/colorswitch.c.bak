#include "colorSwitch.h"
#include "beeper.h"
#include "RGB.h"
#include "main.h"

extern TIM_HandleTypeDef htim2;
enum Color_enum ledcolor = red;
uint32_t black_array[Pixel_NUM+1][24];
uint32_t red_array[Pixel_NUM+1][24];
uint32_t blue_array[Pixel_NUM+1][24];

void colorSwitchInit() {
    RGB_SetColors(black_array,8,BLACK);
    RGB_SetColors(red_array,8,RED);
    RGB_SetColors(blue_array,8,BLUE);
}

void handleColorSwitch() {
    HAL_Delay(10);
    GPIO_PinState state = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0);
    switch (state) {
        case GPIO_PIN_RESET:
            ledcolor = blue;
            break;
        case GPIO_PIN_SET:
            ledcolor = red;
            break;
    }
    flashColor();
}

void flashColor() {
    beeperOn();
    if (ledcolor == red) {
        RGB_SendArray(black_array, &htim2, TIM_CHANNEL_1);
        RGB_SendArray(black_array, &htim2, TIM_CHANNEL_2);
        HAL_Delay(20);
        RGB_SendArray(red_array, &htim2, TIM_CHANNEL_1);
        RGB_SendArray(red_array, &htim2, TIM_CHANNEL_2);
    }
    if (ledcolor == blue) {
        RGB_SendArray(black_array, &htim2, TIM_CHANNEL_1);
        RGB_SendArray(black_array, &htim2, TIM_CHANNEL_2);
        HAL_Delay(20);
        RGB_SendArray(blue_array, &htim2, TIM_CHANNEL_1);
        RGB_SendArray(blue_array, &htim2, TIM_CHANNEL_2);
    }
    beeperOff();
}