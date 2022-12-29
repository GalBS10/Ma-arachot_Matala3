#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define SIZE 50

int shift_element(int* arr,int i){

    int tmp = *(arr+i);
    for(int* j=(arr+i+1);j>arr;j--){

        *(j)=*(j-1);

    }
    *(arr)=tmp;

    return 0;
}

int insertion_sort(int* arr, int len){

    int i, key, j;
    for (i = 1; i < len; i++) {
    key = *(arr+i);
    j = i - 1;

        while (j >= 0 && *(arr+j) > key) {
            *(arr+j+1) = *(arr+j);
            j = j - 1;
        }
        *(arr+j+1) = key;
    }

    return 0;
}

int main(){
    int arr [SIZE]={0};
    int tmp;
    for(int i=0;i<SIZE;i++){
        
        scanf("%d",&tmp);
        *(arr+i)=tmp;

    }    
    
    insertion_sort(arr,SIZE);

    printf("%d",*(arr));    
    for(int i=1;i<SIZE;i++){

        printf(",%d",*(arr+i));

    }   
   // printf("\n");

    return 0;

}