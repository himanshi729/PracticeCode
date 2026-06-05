// #include<stdio.h>
// int main(){
    // char a[] = "wElCome";
    // for(int i=0; a[i]!='\0'; i++){
        // if(a[i]>=65 && a[i]<=90)
            // a[i]+=32;
        // else if(a[i]>='a'&& a[i]<=122) 
            // a[i] -=32;
    // }
    // printf("result is: ");
    // for(int i=0; a[i]!='\0'; i++){
        // printf("%c", a[i]);
    // }
    // return 0;
// }


#include<iostream>
using namespace std; 

int main(){
    char a[] = "welcome";
    for (int i=0; a[i]!=0; i++){
        if(a[i]>=65 && a[i]<=90)
            a[i]+=32;
        else if(a[i]>='a'&& a[i]<=122) 
            a[i] -=32;
    }
    cout<<"Result is :"<<endl;
    for(int i =0; a[i]!=0; i++){
        cout<<a[i];
    }
    return 0;
}

