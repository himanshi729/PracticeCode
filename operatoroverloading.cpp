#include<iostream>
using namespace std;
class Complex{
    private:
        int real, imaginary;
    public:
        Complex(int real=0, int imaginary=0){
            this->real = real;
            this->imaginary = imaginary;
        
        }
    Complex operator +(Complex &obj){
        Complex temp;
        temp.real = real + obj.real;
        temp.real = imaginary + obj.imaginary;
        return temp;
    }
//   insertion operator overload
friend ostream& operator <<(ostream& out,Complex& c );

   
};
ostream& operator <<(ostream& out,Complex& c ){
        out<<c.real<<"+ i"<<c.imaginary<<endl;
}

int main(){
    Complex c,c1(3, 4), c2(1, 3);
    c = (c1 + c2);
    cout<<c;
    return 0;
}