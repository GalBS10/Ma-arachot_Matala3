#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define SIZE 50

int shift_element(int* arr,int i){

    int tmp = *(arr+i)+1;//in order to keep the value in that index. Moreover we do so in order to prevent duplicates of value that are allready exist 
    for(int* j=(arr+i+1);j>arr;j--){

        *(j)=*(j-1);

    }
    *(arr)=tmp;

    return 0;
}

int insertion_sort(int* arr, int len){
    int j,val=0;
    for (int i = 1; i < len; i++) {
    val = *(arr+i);
    j = i - 1;
        while ((j >= 0) && (*(arr+j) > val)) {
            *(arr+j+1) = *(arr+j);
            j--;
        }
        *(arr+j+1) = val;
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

   
    for(int i=0;i<SIZE-1;i++){

        printf("%d,",*(arr+i));

    }
    printf("%d",*(arr +SIZE-1));    
    printf("\n");
    
    shift_element(arr,5);

     for(int i=0;i<SIZE-1;i++){

        printf("%d,",*(arr+i));

    }
    printf("%d",*(arr +SIZE-1));    
    printf("\n");

    return 0;

}