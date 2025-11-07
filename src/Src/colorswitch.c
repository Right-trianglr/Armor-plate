//
// Created by Right on 2025/11/3.
//

#include "colorswitch.h"
#include "main.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if (GPIO_Pin == GPIO_PIN_0) {
        enum Color_enum color;
        GPIO_PinState state = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0);
        switch (state) {
            case GPIO_PIN_RESET:
                color = blue;
            case GPIO_PIN_SET:
                color = red;
        }
    }
}

