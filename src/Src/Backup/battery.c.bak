//
// Created by Right on 2025/10/30.
//
#include "beeper.h"
#include "main.h"

extern TIM_HandleTypeDef htim3;
extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;

void startBatteryMonitor(void) {
    HAL_ADCEx_Calibration_Start(&hadc1);
    HAL_TIM_Base_Start_IT(&htim3);
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim == &htim3) {

        uint16_t ADC_value_battery = 0;
        uint16_t ADC_value_vref = 0;
        float Battery_voltage = 0;
        float Vref = 0;

        // Read ref voltage
        HAL_ADC_Start(&hadc1);
        HAL_ADC_PollForConversion(&hadc1, 1);
        ADC_value_vref = HAL_ADC_GetValue(&hadc1);
        Vref = 1.2 * 4095 / ADC_value_vref;
        HAL_ADC_Stop(&hadc1);

        // Read battery voltage
        HAL_ADC_Start(&hadc2);
        HAL_ADC_PollForConversion(&hadc2, 1);
        ADC_value_battery = HAL_ADC_GetValue(&hadc2);
        Battery_voltage = ADC_value_battery * 2 * Vref / 4095.0f;
        HAL_ADC_Stop(&hadc2);


        // battery voltage compare
        // there is no battery when vbat <= 1v
        if ( (Battery_voltage > 1) && (Battery_voltage < 3.5f || Battery_voltage > 4.3f) ) {
            beeperOn();
        }
        else {
            beeperOff();
        }
    }
}
