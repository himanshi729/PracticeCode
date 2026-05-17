#include<iostream>
using namespace std;
class Complex{
    public:
    int real, imaginary;

    Complex(int real=0, int imaginary=0){
        this->real=real;
        this->imaginary=imaginary;
    }

    Complex add(Complex &obj){
        Complex temp;
        temp.real=real+obj.real;
        temp.imaginary=imaginary+obj.imaginary;
        return temp;
    }

};
int main(){
    Complex C1(2, 3), C2(3, 5);
    Complex C = C1.add(C2);

    
    return 0;
}