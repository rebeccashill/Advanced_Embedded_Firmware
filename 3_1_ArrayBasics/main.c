#include "uart.h"
#include <stdint.h>



uint32_t x, *pt,data[5];

int main(){
	
	USART2_init();
	
	data[0] = 0xBABEFACE;
	data[1] = 0xBABADADA;
	data[2] = 0xDEADBEEF;
	data[3] = 0xBEEFCAFE;
	
	 /*set x equal to the 1st element*/
   	x  =  data[0];
	x  =  *data;
	
	/* set pt to address of the array*/
	pt = data;
   	pt = &data[0];	
	
	/* Set x equal to the 4th element*/
	x =  data[3];
	x =  *(data+3);
	
	/* :  Set pt to the address of the 4th element*/
	pt = data+3;
	pt = &data[3];
	


	pt  = data;
	 /*Set the 3rd element of the array to 0x12345678*/
  	data[2] = 0x12345678;
  	pt[2] = 0x12345678;
	*(pt+2) =  0x12345678;
	
	
	
	
	


}