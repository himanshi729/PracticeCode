#include<iostream>
using namespace std;

class Test{
    public: 
        int x;
     Test(int a){
        x=a;
     }

     int operator +(Test &obj){
        return this->x+obj.x;

     }
    
};
int main(){
    Test t = ;

}