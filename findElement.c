#include<stdio.h>
int main(){
    int n1;
 
    scanf("%d ", &n1);
    int A[n1];

    for(int i=0; i<n1; i++){
        scanf("%d ", &A[i]);
    }
    int l , h; 
    l = A[0]; h=A[n1];

    int H[h]; 

    for(int i=0; i<n1; i++){
        H[A[i]]++;
    }
    for(int i = l; i<=h; i++){
        if(H[i] == 0)
            printf("%d\n", i);
    }
    return 0;
}