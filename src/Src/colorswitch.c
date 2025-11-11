//
// Created by Right on 2025/11/3.
//

#include "colorswitch.h"
#include "main.h"

extern enum Color_enum ledcolor = red;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if (GPIO_Pin == GPIO_PIN_0) {
        GPIO_PinState state = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0);
        switch (state) {
            case GPIO_PIN_RESET:
                ledcolor = blue;
                break;
            case GPIO_PIN_SET:
                ledcolor = red;
                break;
        }
    }
}

