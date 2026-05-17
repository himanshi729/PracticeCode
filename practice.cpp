#include<iostream>
using namespace std;
// call by refer
void incX(int &x){
    x++;
    return ;
}
int main()
{
    int a=1;
    incX(a);
    incX(a);
    cout<<a<<endl;

}