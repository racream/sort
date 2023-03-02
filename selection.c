#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

void swap(ElemType* a,ElemType* b){
	ElemType temp = *a;
	*a = *b;
	*b = temp;
}

void print_arr(ElemType* arr,int len){
	for(int i = 0; i < len; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void selection_sort(ElemType* arr,int len){
	for(int step = 0; step < len-1; step++){
		int min_index = step;
		for(int i = step+1; i < len; i++){
			if(arr[i] < arr[min_index]){
				min_index = i;
			}
		}
		swap(&arr[min_index],&arr[step]);
	}
}

int main(void){
        ElemType arr[] = {56,23,18,-9,0,36,2,67,45,88,17,};
        int len = sizeof(arr)/sizeof(arr[0]);

        printf("before sorting!\n");
        print_arr(arr,len);

        //sorting......
        printf("after sorting!\n");
        selection_sort(arr,len);
        print_arr(arr,len);
}
