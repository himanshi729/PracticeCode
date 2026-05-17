#include<stdio.h>
#include<stdlib.h>

struct Array {
    int a[20];
    int size;
    int length;
};
void display(struct Array arr){
    int i;
    printf(" elements of array:");
    for(i=0; i<arr.length; i++)
    printf("%d ", arr.a[i]);
}


void Reverse(struct Array *arr){
    int *B;

    B = (int *)malloc(arr->length*sizeof(int));

    for(int i=arr->length-1, j=0; j>0, i>=0; i--, j++)
        B[j] = arr-> a[i];
    
    for(int i=0; i<arr->length; i++)
        arr->a[i] = B[i];
}

void Reverse2(struct Array *arr){
    int i, j;

    for(i=0, j = arr->length-1; i<j; i++, j--){
        int temp = arr->a[i];
        arr-> a[i] = arr->a[j];
        arr->a[j] = temp;
    }
}


int main(){
    struct Array arr = {{2, 3, 4, 5, 6 }, 20, 5};
    
    Reverse2(&arr);
    display(arr);
    return 0;
}