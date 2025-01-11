#include "adc_driver.h"
#include "stm32f4xx.h"                  // Device header


void pa1_analog_init(void){
 
	  RCC->AHB1ENR |=(1U<<0); //Enable clock to GPIOA
	 
	  //Set PA1 as analog
	 GPIOA->MODER  |=(1U<<2);
	 GPIOA->MODER  |=(1U<<3);
	
	  //Setup ADC1
	 RCC->APB2ENR |=(1U<<8); //Enable clock access to ADC1
	 ADC1->CR2 = 0; //SW trigger, Disable ADC
	 ADC1->SQR3  =1;  // Conversion sequence starts at CH1
	 ADC1->SQR1 = 0;  // Conversion sequence length is 1
	 ADC1 ->CR2 = (1U<<0); //Enable ADC	 

}

uint32_t pa1_analog_read(void){

  ADC1->CR2 |=(1U<<30); // Start a conversion
	
	 while(!(ADC1->SR &(1U<<1))){} // Wait for conversion completion
		 
	return ADC1->DR; 
	 
}