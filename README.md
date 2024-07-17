# Code for 6Sens Project : test of Internal STM32 ADC

## Overview
This code allows us to test the internal battery level and the internal voltage reference of the STM32WLE5xx ADC.

## Building and Running
The following commands clean build folder, build and flash the sample:

**Command to use**

west build -t pristine

west build -p always -b stm32wl_dw1000_iot_board applications/stm32wle5_rtos_sensor

west flash --runner stm32cubeprogrammer