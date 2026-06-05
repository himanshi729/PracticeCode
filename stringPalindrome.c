#include<stdio.h>
int main(){
    char a[] = "painter";
    char b[] = "painting";

    int i, j;
    for(i=0, j=0; a[i]!=0 && b[j]!='\0'; i++, j++){
        if(a[i]!=b[j])
        break;
    }
    if(a[i]==b[j])
    printf("Equal");
    else if(a[i]<b[j])
    printf("smaller");
    else
    printf("greater");

    return 0;
}