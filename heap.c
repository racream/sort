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

void heapify(ElemType* arr,int len,int k);

void build_heap(ElemType* arr,int len){
	for(int i = len/2-1; i >= 0; i--){
		heapify(arr,len,i);
	}
}

void heapify(ElemType* arr,int len,int k){
	int top = arr[k];
	for(int i = 2*k+1; i < len; i = 2*i+1){
		if(i < len-1 && arr[i] < arr[i+1]){
			i++;
		}
		if(top > arr[i]) break;
		else{
			arr[k] = arr[i];
			k = i;
		}
	}
	arr[k] = top;
}

void heap_sort(ElemType* arr,int len){
	build_heap(arr,len);
	for(int i = len-1; i > 0; i--){
		swap(&arr[i],&arr[0]);
		heapify(arr,i,0);
	}
}

int main(void){
        ElemType arr[] = {56,23,18,-9,0,36,2,67,45,88,17,};
        int len = sizeof(arr)/sizeof(arr[0]);

        printf("before sorting!\n");
        print_arr(arr,len);

        //sorting......
        printf("after sorting!\n");
        heap_sort(arr,len);
        print_arr(arr,len);
}
