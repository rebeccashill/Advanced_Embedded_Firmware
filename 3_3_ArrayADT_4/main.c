#include "uart.h"
#include <stdint.h>
#include <stdlib.h>


struct ARRAY
{
	int32_t data[50];
	int32_t capacity; /*Capacity of array capped at 50*/
	int32_t length;  /*Length of array user wants to initialize*/
};

typedef struct ARRAY arrayType;

void array_append(arrayType *arr, int32_t elem);
void array_insert(arrayType *arr, uint32_t idx, int32_t elem);
int32_t array_delete(arrayType *arr, uint32_t idx);
void array_reverse(arrayType *arr);
int8_t array_isAscending(arrayType *arr);
int8_t  array_isDescending(arrayType *arr);
void array_sort_ascend(arrayType *arr);
void array_sort_descend(arrayType *arr);
int32_t array_min(arrayType *arr);
int32_t array_max(arrayType *arr);
int32_t array_sum(arrayType *arr);
int32_t array_mean(arrayType *arr);

int main(){
	
	USART2_init();
//	arrayType  signal ={{7,6,5,4,3,2,1},50,7};
//	
//	printf(" Is the array ascending : %d \n\r ",array_isAscending(&signal));
//	printf(" Is the array descending : %d \n\r ",array_isDescending(&signal));

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
	
	array_delete(&signal,2);
	
	printf("The array after delete at idx 2 is : \n\r");
	for(int i=0;i<signal.length;i++){
	 printf(" %d ",signal.data[i]);
	}
	printf("\n\r\n\r");
	
	array_reverse(&signal);
	
		printf("The array after reverse is : \n\r");
	for(int i=0;i<signal.length;i++){
	 printf(" %d ",signal.data[i]);
	}
	printf("\n\r\n\r");
	
	array_sort_ascend(&signal);

		printf("The array after sort ascend is : \n\r");
	for(int i=0;i<signal.length;i++){
	 printf(" %d ",signal.data[i]);
	}
	printf("\n\r\n\r");	
	
		array_sort_descend(&signal);
		printf("The array after sort descend is : \n\r");
	for(int i=0;i<signal.length;i++){
	 printf(" %d ",signal.data[i]);
	}
	printf("\n\r\n\r");	
	
}


void array_append(arrayType *arr, int32_t elem){

	if(arr->length < arr->capacity){
	  arr->data[arr->length++] = elem;
	}
}

void array_insert(arrayType *arr, uint32_t idx, int32_t elem){
   if(idx <=arr->length){
	  
		 for(int i = arr->length;i>idx;i--){
			 
			 arr->data[i] =  arr->data[i-1];
		 }
		 
		 arr->data[idx] = elem;
		 arr->length++;
	   
	 }

}

int32_t array_delete(arrayType *arr, uint32_t idx){

	int32_t elem;
	if(idx < arr->length){
	  elem = arr->data[idx];
		
		for(int i =idx; i<arr->length -1;i++){
			arr->data[i] = arr->data[i+1];
	}
	arr->length--;
	return elem;
 }
	return 0;
}


void array_reverse(arrayType *arr){
  int i,j;
	int32_t *temp;
	
	temp  = (int32_t *)malloc(arr->length*sizeof(int32_t));
	
	for(i =arr->length-1,j=0;i>=0;i--,j++){
	
	   temp[j] =  arr->data[i];
	}
	for(i =0;i<arr->length;i++){
		
	 arr->data[i] = temp[i];
	}
	
	
}



int8_t array_isAscending(arrayType *arr){
   
	  for(int i=0;i<arr->length-1;i++){
			
		if(arr->data[i] > arr->data[i+1]){
		  return 0;
		}
		
	}
		
  return 1;
	
}

int8_t  array_isDescending(arrayType *arr){

	  for(int i =0;i<arr->length;i++){
		   
			 if(arr->data[i] < arr->data[i+1]){
			    return 0;
			 }
		}
		
		return 1;
		
}


void array_sort_ascend(arrayType *arr){
  int32_t i,j,n_temp;
	for(i =1;i<arr->length;i++){
	  n_temp  =  arr->data[i];
		j =i;
		while(j >0 && n_temp<arr->data[j-1]){
		  arr->data[j] = arr->data[j-1];
			--j;
		}
		arr->data[j] = n_temp;
	}
	
}


void array_sort_descend(arrayType *arr){
  int32_t i,j,n_temp;

	for(i =1;i<arr->length;i++){
	 n_temp = arr->data[i];
	 j=i;
		while(j>0 && n_temp > arr->data[j-1]){
		  arr->data[j] =  arr->data[j-1];
			--j;
		}
		arr->data[j] =  n_temp;
		
	}
	
}
int32_t array_max(arrayType *arr){

	int32_t mx =  arr->data[0];
	for(int i=0;i<arr->length;i++){
	   if(arr->data[i] > mx){
		   mx = arr->data[i];
		 }
	}
	return mx;
}


int32_t array_min(arrayType *arr){

	int32_t mn = arr->data[0];
	for(int i=0;i<arr->length;i++){
	  
		 if(arr->data[i] < mn){
		  mn  = arr->data[i];
		 }
		 
	}
	return mn;
}


int32_t array_sum(arrayType *arr){

  int32_t sm;
 for(int i =0;i<arr->length;i++){
   sm += arr->data[i];
 }	

  return sm;
}


double array_mean(arrayType *arr){
  double mn;
	int32_t sm;
	for(int i=0;i<arr->length;i++){
	 sm += arr->data[i];
	}
	return (sm/arr->length);
	
}