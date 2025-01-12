#include "uart.h"
#include <stdint.h>




uint32_t sig[] = {23,567,0,12,144,134,13,4};
void arr_2_max(uint32_t *src_array, uint32_t *dest_array, uint32_t src_len);

uint32_t output[4];
int main(){
	
	USART2_init();
	arr_2_max(sig,output,8);
}


void arr_2_max(uint32_t *src_array, uint32_t *dest_array, uint32_t srcLength){

	uint32_t max1, max2, max1Index, max2Index;
	
	max1 =  src_array[0];
	for(int i = 1; i < srcLength; i++){
		
	    if(src_array[i]> max1){
		    max1 =  src_array[i];
			max1Index = i;
		}
	
	}
	
	max2  = src_array[0];
	for(int i = 0; i < srcLength; i++){
	
	  	/*Skip largest value */
		if(src_array[i] != max1){
		  	if(src_array[i] > max2){
				max2 = src_array[i];
				max2Index = i;
			}
		}
	}
	
	dest_array[0] = max1;
	dest_array[1] = max1Index;
	dest_array[2] = max2;
	dest_array[3] = max2Index; 

}