#include<stdio.h>
#include<stdlib.h>

/*
int main(){
    int A[5];
    int B[5] = {1,2 ,3,4,5};
    int C[10]= {2,4,6};
    int D[5]={0};
    int E[]={3,6,9,12,15};
    printf("%d\n", A[2]);
    for(int i =0; i<5; i++){
        printf("%d\n", B[i]);
    }
    for(int i =0; i<5; i++){
        printf("%d\n", C[i]);
    }
    printf("%d\n", D[0]);
    return 0;
}
    */

int main(){
    int A[5]={2, 4, 6, 8, 7};
    int *p;
    p = (int *)malloc(5*sizeof(int));
    p[0]=4; p[1]=2; p[2]= 8; p[3]= 3; p[4]=9; p[5]=6;
    for(int i =0; i<5; i++)
        printf("%d\t", A[i]);
        printf("\n");
    
for(int i =0; i<5; i++)
    printf("%d\t", p[i]);
    return 0;

}    