#include<stdio.h>

int main(){
    int a[] = {2,4,1,7,5};
    int b[] = {1, 3, 4, 7, 8, 2};
    int n1 = 5, n2 = 6;
    int unionArr[20] ;

    int i, j, k;
    i=j=k=0;

    int found, x;

    while(i<n1){
        unionArr[k++] = a[i];
        i++;
    }
    while(j<n2){
        found = 0;

        for(x= 0; x<k; x++){
            if(b[j] == unionArr[x]){
                found = 1;
                break;
            }
        }
        if(found == 0){
            unionArr[k++] = b[j];
        }
         j++;
    }
    printf("Union of two arrays:\n");
    for(int i=0; i<k; i++){
        printf("%d ", unionArr[i]);
    }
    return 0;
}