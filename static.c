#include<stdio.h>

int fun(int n){
    static int x = 0;
    if(n>0){
        x++;
        return fun(n-1)+x;
    }
    return 0;
}

int main(){
    int num;
    num = fun(5);
    printf("%d", num);
    return 0;
}