#include <stdio.h>
#include <stdbool.h>

typedef int ElemType;

void swap(ElemType* a,ElemType* b) {
        ElemType temp = *a;
        *a = *b;
        *b = temp;
}

void print_arr(ElemType* arr,int len){
        for(int i = 0; i < len; i++){
                printf("%d ->",arr[i]);
        }
        printf("\n");
}

void bubble_sort(ElemType* arr,int len){
        bool Swapped = false;
        for(int step = 0; step < len-1; step++){
                for(int i = 0; i < len-step-1; i++){
                        if(arr[i] > arr[i+1]){
                                swap(&arr[i],&arr[i+1]);
                                Swapped = true;
                        }
                }
                if(!Swapped) break;
        }
}

int main(void){
        ElemType arr[] = {56,23,18,-9,0,36,2,67,45,88,17,};
        int len = sizeof(arr)/sizeof(arr[0]);

        printf("before sorting!\n");
        print_arr(arr,len);

        //sorting......
        printf("after sorting!\n");
        bubble_sort(arr,len);
        print_arr(arr,len);
}
