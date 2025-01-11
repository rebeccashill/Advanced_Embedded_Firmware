#ifndef _GPIO_DRIVER_H
#define _GPIO_DRIVER_H

// Include the function that allows the usage of booleans on the microcontroller.
#include <stdbool.h>

// Create void functions
void p1_button_init(void);
bool get_p13_button_state(void);

	
#endif
