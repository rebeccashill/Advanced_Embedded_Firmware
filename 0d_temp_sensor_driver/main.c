#include "uart.h"
#include "gpio_driver.h"
#include "adc_driver.h"

bool btn_state;
double chip_temperature;

int main(){
  
	USART2_Init();
	p1_button_init();
	temp_sensor_init();

	while(1){
	  btn_state = get_p13_button_state();
		chip_temperature =  read_chip_temperature();
	} 

}