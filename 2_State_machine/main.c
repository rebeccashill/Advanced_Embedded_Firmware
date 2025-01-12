#include "uart.h"
#include "stm32f4xx_hal.h"              // Keil::Device:STM32Cube HAL:Common



enum states{
  	STATE_A = 0,
	STATE_B,
	STATE_C
};

typedef enum states State_Type;

void state_a_function(void);
void state_b_function(void);
void state_c_function(void);
void state_machine_init(void);


static void (*state_table[])(void) ={									state_a_function,
																		state_b_function,
																		state_c_function

};
static State_Type current_state;
static int Clock;

int main(){
	
	HAL_Init();
	
	USART2_Init();
	state_machine_init();

	while(1){
	state_table[current_state]();
		
	HAL_Delay(1000);	
	Clock++;
	
	}
		
}


void state_machine_init(void){
	
 current_state  = STATE_A;
 Clock =0;
}

uint32_t  sa_prev_time =0;
uint32_t sa_now;
float sa_delta;

void state_a_function(void){
	
	 if(Clock  == 2){
		current_state =  STATE_B;

		sa_now  = HAL_GetTick();
		sa_delta =  sa_now - sa_prev_time;
		 /*To seconds*/
		sa_delta /=1000;
		sa_prev_time = sa_now;
		printf("This is the output of STATE A : %f seconds ago \n\r",sa_delta);
		// printf("This is the execution of STATE A \n\r");
	 }
}



uint32_t  sb_prev_time =0;
uint32_t sb_now;
float sb_delta;


void state_b_function(void){
	 if(Clock == 5){
	  current_state  = STATE_C;
		 
		sb_now  = HAL_GetTick();
		sb_delta =  sb_now -  sb_prev_time;
		sb_delta /= 1000;
		sb_prev_time = sb_now;
		printf("This is the output of STATE B : %f seconds ago\n\r",sb_delta);
		// printf("This is the execution of STATE B \n\r");
	 }
}

uint32_t  sc_prev_time =0;
uint32_t sc_now;
float sc_delta;

void state_c_function(void){
	if(Clock  == 9){
		Clock =0;
		current_state = STATE_A;
		sc_now =  HAL_GetTick();
		sc_delta = sc_now - sc_prev_time;
		sc_delta /=1000;
    	sc_prev_time =  sc_now;
		printf("This is the output of STATE C : %f seconds ago\n\r",sc_delta);
		
		//printf("This is the execution of STATE C \n\r");
	}
}

void SysTick_Handler(void){
	HAL_IncTick();
}