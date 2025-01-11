#ifndef	_ADC_DRIVER_H
#define _ADC_DRIVER_H
#include <stdint.h>

void pa1_analog_init(void);
uint32_t pa1_analog_read(void);

void temp_sensor_init(void);
double read_chip_temperature(void);

#endif