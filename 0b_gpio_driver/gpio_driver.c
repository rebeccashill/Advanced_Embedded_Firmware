#include "gpio_driver.h"
#include "stm32f4xx.h"                  // Device header

void p1_button_init(void){

   RCC->AHB1ENR |=(1U<<2); // Enable clock to PORTC
	
	// Set P13 as input. Protocol P13 handles input and output signals.
	GPIOC->MODER  &= ~(0U<<26);
	GPIOC->MODER  &= ~(0U<<27);

}

bool get_p13_button_state(void){
	
	return (GPIOC->IDR & (1U<<13));


}
