#include<stdio.h>
#include<stdlib.h>

int main(){
    int n; 
    scanf("%d ", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d ", &arr[i]);
    }
    int l , h; 
    l = arr[0];
    h=arr[n];
    int diff = arr[0] - 0;
    for(int i =0; i<n; i++){
        if(arr[i] - i != diff){
            while(diff<arr[i]-i){
                printf("%d\n", i+diff);
                diff++;
            }
        }
        
    }
    return 0;

}