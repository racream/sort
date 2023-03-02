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

void shell_sort(ElemType* arr,int len){
	for(int gap = len/2; gap > 0; gap /= 2){
		for(int i = gap; i < len; i++){
			int temp = arr[i];
			int j;
			for(j = i-gap; j >= 0 && arr[j] >= temp; j -= gap){
				arr[j+gap] = arr[j];
			}
			arr[j+gap] = temp;
		}
	}
}

int main(void){
        ElemType arr[] = {56,23,18,-9,0,36,2,67,45,88,17,};
        int len = sizeof(arr)/sizeof(arr[0]);

        printf("before sorting!\n");
        print_arr(arr,len);

        //sorting......
        printf("after sorting!\n");
        shell_sort(arr,len);
        print_arr(arr,len);
}
