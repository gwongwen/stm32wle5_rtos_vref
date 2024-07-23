/*
 * Copyright (c) 2023
 * Regis Rousseau
 * Univ Lyon, INSA Lyon, Inria, CITI, EA3720
 * SPDX-License-Identifier: Apache-2.0
 */

#include "app_vref.h"
#include "app_vbat.h"

//  ======== main ===============================================
int main(void)
{
	const struct device *vref_dev = NULL;
	const struct device *vbat_dev = NULL;

	// setup all devices
	vref_dev = DEVICE_DT_GET_ONE(st_stm32_vref);
	vbat_dev = DEVICE_DT_GET_ONE(st_stm32_vbat);
	app_stm32_vref_init(vref_dev);
	app_stm32_vbat_init(vbat_dev);
	
	printk("Internal Voltage Reference and Battery Example\nBoard: %s\n", CONFIG_BOARD);

	while (1) {
		uint16_t vref = app_stm32_get_vref(vref_dev);
		uint16_t vbat = app_stm32_get_vbat(vbat_dev, vref);
		k_sleep(K_MSEC(2000));
	}
	return 0;
}