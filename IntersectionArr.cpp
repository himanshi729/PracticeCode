#include<iostream>
using namespace std;

int main(){
    int n1, n2;
     int k=0 ;
    
    cout<<"Enter length of array1 and Array2: ";
    cin>>n1>>n2;

    int n3 = n1+n2;

    int arr1[n1], arr2[n2], arr3[n3];

    cout<<"Enter  elements of Array1: \n";
    for(int i=0; i<n1; i++)
    {
        cin>> arr1[i];
    }
    cout<<endl;

    cout<<"Enter elements of Array2: \n";
    for(int j=0;j<n2;j++){
        cin>>arr2[j];
    }

   

   for(int i=0 ; i<n1; i++){
    for(int j=0; j<n2; j++){
        if(arr1[i] == arr2[j]){
            arr3[k] = arr1[i];
            k++;
            break;
        }
    }
   }
   cout<<"Intersection of Two arrays:\n";
   for(int i=0; i<k; i++){
    cout<<arr3[i]<<" ";
   }
   return 0;
}