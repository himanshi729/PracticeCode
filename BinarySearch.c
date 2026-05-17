#include<stdio.h>
#include<stdlib.h>

struct Array{
    int A[50];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for(int i =0; i<arr.length; i++){
        printf("%d ", arr.A[i]);
    }
}
void swap(int *x, int *y){
    int temp=*x;
    *x = *y;
    *y = temp;
}

int BinarySearch(struct Array arr, int key){
int l, mid, h;
l=0;
h=arr.length-1;
while(l<=h){
    mid = (l+h)/2;
    if(key == arr.A[mid])
    return mid;
    else if(key<arr.A[mid])
        h = mid-1;
        else
        l = mid+1;
}
return -1;
}
// Recursively Binary Search 
/* 
int RBinSearch(int a[], int l, int h, int key){
    int mid = 0;
    if(l<=h){
        mid = (l+h)/2;
        if(key == a[mid])
        return mid;
        else if(key<a[mid])
        return RBinSearch(a, l, mid-1, key);
    }
    else
    return RBinSearch(a, mid+1, h, key);
    return -1;
}
    */

int main(){
struct Array arr = {{2,3,5,7,9,10,24,56,70}, 50, 9};   //  struct Array a = {2, 3, 5, 7, 9, 10, 24, 56, 70};

    printf("%d ", BinarySearch(arr,56 ));
   // printf("%d", RBinSearch(a, 56));
    Display(arr);
    return 0;
}