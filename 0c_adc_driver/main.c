#include "uart.h"
#include "gpio_driver.h"
#include "adc_driver.h"

bool btn_state;
uint32_t sensorValue;

int main(){
  
	USART2_Init();
	p1_button_init();
	pa1_analog_init();

	while(1){
	  btn_state = get_p13_button_state();
		sensorValue =  pa1_analog_read();
	} 

}