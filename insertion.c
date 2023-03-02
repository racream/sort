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

void insertion_sort(ElemType* arr,int len){
	for(int step = 1; step < len;step++){
		int key = arr[step];
		int j = step-1;
		while(j >= 0 && key < arr[j]){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

int main(void){
        ElemType arr[] = {56,23,18,-9,0,36,2,67,45,88,17,};
        int len = sizeof(arr)/sizeof(arr[0]);

        printf("before sorting!\n");
        print_arr(arr,len);

        //sorting......
        printf("after sorting!\n");
        insertion_sort(arr,len);
        print_arr(arr,len);
}
