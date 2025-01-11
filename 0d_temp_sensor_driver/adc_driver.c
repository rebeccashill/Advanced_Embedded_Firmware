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


//Configure TIM2 to generate 1hz output
//to trigger on_chip temperature_sensor adc_conversion
//Sysclock = TIM2 clock source  = 16MHz  = 16 000 000 cycls/second
//16 000 000  / 16 00 = 10 000
//10000 /10000 =1
void temp_sensor_init(void){
	
	 //Setup TIM2
		RCC->APB1ENR |= (1U<<0);  //Enable clock to TIM2
		TIM2->PSC =  1600 -1 ; //clock divided by 1600
		TIM2->ARR  =  10000-1;  // divide by 10000 , sample at 1hz
	  TIM2->CNT = 0;
	  TIM2->CCMR1=  0x00006800; // pwm1 mode, preload enable
		TIM2->CCER  = 0x10;    //Enable CH2 
		TIM2->CCR2  = 50 -1;   // High campture/compare 2
		TIM2->CR1 =  1;       // Enable TIM2
	
	
	//Setup ADC1
	RCC->APB2ENR |=(1U<<8); //Enable clock access to ADC1
	//turn on the temp sensor
	ADC->CCR |=0x800000;
	ADC->CCR &= ~0x400000;  
	ADC1->SMPR1  =  0x4000000;  //Sampliny time minimum to 10us
	ADC1->SQR3 = 18;
	ADC1->CR2  = 0x13000000 ; //trigger :  External, rising edge, extsel3  = tim2.2
	ADC1->CR2  |=1; 
	
}

double read_chip_temperature(void){

  uint32_t data;
	double volt, temp;
	
	while(!(ADC1->SR &(1U<<1))){} // Wait for conversion completion
  
	 data =  ADC1->DR;
	volt  = (double)data/4095*3.3; //Convert the adc output to voltage
  temp = (volt - 0.76)/0.0025 + 25; 	//convert voltage to temperature in Celsius	
  
	return temp;
}














