#include <stdio.h>

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

/*
int partition(ElemType* arr,int low,int high){
	int pivot = arr[high];
	int i = low-1;
	for(int j = low; j < high; j++){
		if(arr[j] <= pivot){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	
	return i+1;
}
*/

int partition(ElemType* arr,int low,int high){
	int pivot = arr[low];
	while(low < high){
		while(low < high && arr[high] >= pivot){
			high--;
		}
		arr[low] = arr[high];
		while(low < high && arr[low] <= pivot){
			low++;
		}
		arr[high] = arr[low];
	}
	arr[low] = pivot;
	return low;
}

void quick_sort(ElemType* arr,int low,int high){
	if(low < high){
		int pi = partition(arr,low,high);

		quick_sort(arr,low,pi-1);
		quick_sort(arr,pi+1,high);
	}
}

int main(void){
        ElemType arr[] = {56,23,18,-9,0,36,2,67,45,88,17,};
        int len = sizeof(arr)/sizeof(arr[0]);

        printf("before sorting!\n");
        print_arr(arr,len);

        //sorting......
        printf("after sorting!\n");
        quick_sort(arr,0,len-1);
        print_arr(arr,len);
}
