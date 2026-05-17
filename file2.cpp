// Access Specifier , Default Constructor ,  Parameterized Constructor

#include <iostream>
using namespace std;

class Item {             // Access Specifier: Public, Private, Protected
private:
    int id;
    string name;

public:
    // Default Constructor
    Item() {
        id = 0;
        name = "None";
    }

    // Parameterized Constructor
    Item(int i, string n) {
        id = i;
        name = n;
    }

    void display() {
        cout << "ID: " << id << " Name: " << name << endl;
    }
};

int main() {
    Item obj1;                 // Default constructor
    Item obj2(2, "Burger");   // Parameterized constructor

    obj1.display();
    obj2.display();

    return 0;
}