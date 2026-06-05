
#include <iostream>
using namespace std;

class Array{
    private:
        int *a;
        int size;
        int length;
        void swap(int *x, int *y);
    public:
    //Constructor
        Array(){
            size = 50;
            length = 0;
            a = new int[size];
        }
        Array(int sz){
            size = sz;
            length = 0; 
            a = new int[size];
        }
        //Destructor
        ~Array(){
            delete []a;
        }

        void Display();
        void Append(int x);
        void Insert(int index,int x);
        int Delete(int index);
        int LinearSearch(int key);
        int BinarySearch(int key);
        int RBinSearch(int l, int h, int key);
        int Get(int index);
        void Set(int index,int x);
        int Max();
        int Min();
        int Sum();
        float Avg();
        void Reverse();
        void Reverse2();
        void InsertSort(int x);
        int isSorted();
        void Rearrange();
        Array* Merge(Array arr2);
        Array* Union(Array arr2);
        Array* Intersection(Array arr2);
        Array* Difference(Array arr2);


    };
//Display
void Array :: Display()
{
    int i;
    cout<<"\nElements are\n";
    for(i=0;i<length;i++){
        cout<<a[i]<<" ";}
    }
//Append
void Array :: Append(int x)
{
    if(length<size)
        a[length++]=x;
}

//Insertion
void Array :: Insert(int index,int x)
{
    int i;
    if(index>=0 && index <=length){
        for(i=length;i>index;i--)
            a[i]=a[i-1];
            a[index]=x;
            length++;
    }
}
//deletion
int Array::Delete(int index){
    int x=0;
    int i;
    if(index>=0 && index<length){
        x=a[index];
    for(i=index;i<length-1;i++)
        a[i]=a[i+1];
        length--;
        return x;
    }
    return 0;
}

//Swap
void Array::swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

//Linear Search
int Array ::LinearSearch(int key)
{
int i;
for(i=0;i<length;i++)
{
if(key==a[i])
{
swap(&a[i],&a[0]);
return i;
}
}
return -1;
}
//Binary search
int Array::BinarySearch(int key){
    int l,mid,h;
    l=0;
    h=length-1;
    while(l<=h){
        mid=(l+h)/2;
        if(key==a[mid])
            return mid;
        else if(key<a[mid])
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;
}

//recursive Binary search
int Array::RBinSearch(int l, int h, int key){
    int mid;
if(l<=h){
    mid=(l+h)/2;
    if(key==a[mid])
        return mid;
    else if(key<a[mid])
        return RBinSearch(l,mid-1,key);
    else
        return RBinSearch(mid+1,h,key);
}
return -1;
}

//Get function
int Array::Get(int index)
{
if(index>=0 && index<length)
return a[index];
return -1;
}

//Set function
void Array::Set(int index,int x)
{
if(index>=0 && index<length)
a[index]=x;
}

//Maximum element of array
int Array::Max()
{
int max= a[0];
int i;
for(i=1;i<length;i++){
    if(a[i]>max)
        max=a[i];
}
return max;
}

//Minimum element of array

int Array::Min()
{
int min=a[0];
int i;
for(i=1;i<length;i++){
    if(a[i]<min)
        min=a[i];
}
return min;
}

//Sum of the array
int Array::Sum()
{
int s=0;
int i;
for(i=0;i<length;i++)
s+=a[i];
return s;
}

// Average of the sum of array
float Array::Avg()
{
return (float)Sum()/length;
}

//Reverse of array
void Array::Reverse()
{
int *B;
int i,j;
B=new int;
for(i=length-1,j=0;i>=0;i--,j++)
B[j]=a[i];
for(i=0;i<length;i++)
a[i]=B[i];
}

//Reversse of array using swap
void Array::Reverse2()
{
int i,j;
for(i=0,j=length-1;i<j;i++,j--)
{
swap(&a[i],&a[j]);
}
}

// Insertion in sorted array
void Array:: InsertSort(int x){
int i=length-1;
if(length==size)
return;
while(i>=0 && a[i]>x)
{
a[i+1]=a[i];
i--;
}
a[i+1]=x;
length++;
}

// Check for sorted array
int Array::isSorted()
{
int i;
for(i=0;i<length-1;i++)
{
if( a[i]>a[i+1])
return 0;
}
return 1;
}

//Rearrange Array
void Array::Rearrange()
{
int i,j;
i=0;
j=length-1;
while(i<j){
    while(a[i]<0)i++;
    while(a[j]>=0)j--;
    if(i<j)
     swap(&a[i],&a[j]);
    }
}

//Merge array
 Array* Array::Merge(Array arr2){
int i,j,k;
i=j=k=0;
Array *arr3=new Array(length+arr2.length);

while(i<length && j<arr2.length){
if(a[i]<arr2.a[j])
    arr3->a[k++]=a[i++];
else
    arr3->a[k++]=arr2.a[j++];
}
for(;i<length;i++)
    arr3->a[k++]=a[i];

for(;j<arr2.length;j++)
    arr3->a[k++]=arr2.a[j];
    arr3->length=length+arr2.length;
    arr3->size=10;
return arr3;
}

// Union of two array
Array* Array:: Union( Array arr2)
{
int i,j,k;
i=j=k=0;
Array *arr3=new Array (length+arr2.length);

while(i<length && j<arr2.length)
{
if(a[i]<arr2.a[j])
arr3->a[k++]=a[i++];
else if(arr2.a[j]<a[i])
arr3->a[k++]=arr2.a[j++];
else
{
arr3->a[k++]=a[i++];
j++;
}
}
for(;i<length;i++)
arr3->a[k++]=a[i];
for(;j<arr2.length;j++)
arr3->a[k++]=arr2.a[j];
arr3->length=k;
arr3->size=10;
return arr3;
}

//Intersection of two array
Array* Array::Intersection(Array arr2){
int i,j,k;
i=j=k=0;
Array *arr3=new Array (length+arr2.length);
while(i<length && j<arr2.length)
{
    if(a[i]<arr2.a[j])
        i++;
    else if(arr2.a[j]<a[i])
        j++;
    else if(a[i]==arr2.a[j]){
        arr3->a[k++]=a[i++];
        j++;
    }   
}
arr3->length=k;
arr3->size=10;
return arr3;
}

// Difference between two array
Array* Array::Difference(Array arr2){
int i,j,k;
i=j=k=0;
Array *arr3=new Array (length+arr2.length);

while(i<length && j<arr2.length){
    if(a[i]<arr2.a[j])
        arr3->a[k++]=a[i++];
    else if(arr2.a[j]<a[i])
        j++;
    else{
        i++;
        j++;
    }
}
for(;i<length;i++)
    arr3->a[k++]=a[i];
    arr3->length=k;
    arr3->size=10;
return arr3;
}


int main(){
    Array *arr1;
    int ch, sz;
    int x,index;

    cout<<"Enter Size of Array";
    cin>>sz;

    arr1 = new Array(sz);
    
    do
    {
    cout<<"\n\nMenu\n";
    cout<<"1. Insert\n";
    cout<<"2. Delete\n";
    cout<<"3. Search\n";
    cout<<"4. Sum\n";
    cout<<"5. Display\n";
    cout<<"6.Exit\n";
    cout<<"enter you choice ";
    scanf("%d",&ch);

    switch(ch){
    case 1: cout<<"Enter an element and index";
            cin>>x>>index;
            arr1->Insert(index, x);
            break;
    case 2: cout<<"Enter index ";
            cin>>index;
            x=arr1->Delete(index);
            cout<<"Deleted Element is %d\n",x;
            break;
    case 3:cout<<"Enter element to search ";
            scanf("%d",&x);
            index=arr1->LinearSearch(x);
            cout<<"Element index %d",index;
            break;
    case 4:cout<<"Sum is "<<arr1->Sum();
            break;
    case 5:arr1->Display();
        }

}while(ch<6);

    return 0;

}