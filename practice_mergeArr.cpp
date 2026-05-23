#include<iostream>
using namespace std;

int main(){
    int n1, n2;
    cout<<"Enter length of array1 and Array2: ";
    cin>>n1>>n2;

    int arr1[n1], arr2[n2];

    cout<<"Enter  elements of Array1: \n";
    for(int i=0; i<n1; i++)
    {
        cin>> arr1[i];
    }
    cout<<endl;

    int n3 = n1+n2;
    int arr3[n3];

    cout<<"Enter elements of Array2: \n";
    for(int j=0;j<n2;j++){
        //cout<<"Enter elements of Array2: \n";
        cin>>arr2[j];
    }

    int i, j, k;
    i=j=k=0;

    while(i<n1 && j<n2){
        if(arr1[i] < arr2[j]){
            arr3[k] = arr1[i];
            i++, k++;
        }

        else{
            arr3[k] = arr2[j];
            k++, j++ ;
        }
}
while(i<n1){
    arr3[k] = arr1[i];
    i++, k++;
}
while(j<n2){
    arr3[k] = arr2[j];
    j++, k++;
}

cout<<"Merged Array \n";
for(int i=0; i<n3; i++){
    cout<<arr3[i]<<" ";
}

return 0;
}