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

void append(struct Array *arr, int x){
    if(arr-> length < arr -> size)
    arr->a[arr->length ++]=x;
}

void insert(struct Array *arr, int index, int x){
    if(index >= 0 && index <=arr->length){
        for(int i=arr->length; i>index; i--)
        arr->a[i]=arr->a[i-1];
        arr->a[index]=x;
        arr->length ++;
    }

}

int main(){
    struct Array arr = {{2, 3, 4, 5, 6}, 20, 10};
  
    insert(&arr, 7, 20);
    append(&arr, 10);
      display(arr);
    return 0;
}