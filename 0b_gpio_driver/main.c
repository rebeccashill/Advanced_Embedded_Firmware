#include "uart.h"
#include "gpio_driver.h"


bool btn_state;

int main(){
  
	USART2_Init();
	// Initialize button
	p1_button_init();

	while(1){
	  btn_state = get_p13_button_state();
	}

}
