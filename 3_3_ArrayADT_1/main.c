#include "uart.h"
#include <stdint.h>


struct ARRAY
{
	int32_t data[50];
	int32_t capacity; /*Capacity of array capped at 50*/
	int32_t length;  /*Length of array user wants to initialize*/
};

typedef struct ARRAY arrayType;

void array_append(arrayType *arr, int32_t elem);
void array_insert(arrayType *arr, uint32_t idx, int32_t elem);


int main(){
	
	USART2_init();
	
	arrayType  signal ={{10,20,30,11,12,13,14},50,7};
	
	printf("The original array is : \n\r");
	for(int i=0;i<signal.length;i++){
		printf(" %d ",signal.data[i]);
	}
	printf("\n\r\n\r");
	
	array_append(&signal,3000);
	
	printf("The array after append is : \n\r");
	for(int i=0;i<signal.length;i++){
		printf(" %d ",signal.data[i]);
	}
	printf("\n\r\n\r");
	
	array_insert(&signal,2,4000);

	printf("The array after insert at idx 2 is : \n\r");
	for(int i=0;i<signal.length;i++){
		printf(" %d ",signal.data[i]);
	}
	printf("\n\r\n\r");
		
	
	
	
	
}


void array_append(arrayType *arr, int32_t elem){

	if (arr->length < arr->capacity){
	  arr->data[arr->length++] = elem;
	}
}

void array_insert(arrayType *arr, uint32_t idx, int32_t elem){
   if (idx <=arr->length){
	  
		for(int i = arr->length;i>idx;i--){
			arr->data[i] =  arr->data[i-1];
		}
		 
		 arr->data[idx] = elem;
		 arr->length++;
	   
	}

}

