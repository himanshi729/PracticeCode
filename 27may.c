#include<stdio.h>
#include<stdlib.h>

struct Array{
    int a[30];
    int size;
    int length;
};

void Display(struct Array arr){
    for(int i=0; i<arr.length; i++){
        printf("%d ", arr.a[i]);
    }
}

void Insert(struct Array *arr, int indx, int x){
    if(indx<=arr->length && indx>=0){
        for(int i=arr->length; i>indx; i--){
            arr->a[i] = arr->a[i-1];
        }
        arr->a[indx] = x;
        arr->length++;
    }
}

void Delete(struct Array *arr, int indx){
    if(indx<=arr->length && indx>=0){
        for(int i = indx; i<arr->length; i++){
            arr->a[i] = arr->a[i+1];
        }
        arr->length--;
    }
}

void Append(struct Array *arr, int x){
    if(arr->length < arr->size){
        arr->a[arr->length] = x;
        arr->length++;
    }
}

void LinearSearch(struct Array *arr, int key){
        for(int i=0; i<arr->length; i++){
            if(key == arr->a[i]){
                printf("%d\n", i);
                return ;
            }
        }
    printf("Element NOT Found!\n");
}

int BinarySearch(struct Array *arr, int key){
    int l, h, mid;
    l=0; 
    h=arr->length-1; 

    while(l<=h){
        mid = (l+h)/2;

        if(key == arr->a[mid]){
            return mid;
        }
        else if(key > arr->a[mid]){
            l = mid+1;
        }
        else{
             h = mid-1;
        }
    }
    printf("\nElement Not found");
    return -1;
}

int RBinarySearch(int a[], int l, int h, int key){
    int mid; 
    while(l<=h){
        mid=(l+h)/2;
        if(a[mid] == key)
            return mid;
        else if(key<a[mid])
            return RBinarySearch(a, l, mid-1, key);
        else
            return RBinarySearch(a, mid+1, h, key);
    }
    return -1;
}

int Max(struct Array arr){
    int max = arr.a[0];
    for(int i=0; i<arr.length; i++){
        if(arr.a[i] > max)
        return max;
    }
}

int Min(struct Array arr){
    int min = arr.a[0];
    for(int i=0; i<arr.length; i++){
        if(arr.a[i]<min)
        return min;
    }
}

int ReverseArray(struct Array *arr){
    int *B ; 
    B = (int*)malloc(arr->length * sizeof(int));
    for(int i = arr->length, j=0; i>=0; i--, j++){
        B[j] = arr->a[i];
    }
    for(int i=0; i<arr->length; i++){
        arr->a[i] = B[i];
    }
    
}
int main(){
    struct Array arr = {{2,4,6,8,10}, 30, 10};

    // Insert(&arr, 3, 15);
    // Display(arr);
    // printf("Size of array after Insertion: \n%d\n", arr.length);
// 
    // Delete(&arr, 1);
    // Display(arr);
    // printf("Size of array after Deletion: \n%d\n", arr.length);
// 
    // Append(&arr, 33);
    // Display(arr);
    // printf("Size of array after Append a value: \n%d\n", arr.length);

   // LinearSearch(&arr, 6);
   // Display(arr);
   // printf("Size of array after Append a value: \n%d\n", arr.length);

   printf("\n%d\n", BinarySearch(&arr, 5));
   Display(arr);
    

    return 0;
}