#include "beeper.h"

/**
 * @brief 通过GPIO驱动有源蜂鸣器
*/
void beeperOn(void) {
    HAL_GPIO_WritePin(GPIOx, GPIO_PIN, GPIO_PIN_SET);
}

/**
 * @brief 通过GPIO驱动有源蜂鸣器
*/
void beeperOff(void) {
    HAL_GPIO_WritePin(GPIOx, GPIO_PIN, GPIO_PIN_RESET);
}