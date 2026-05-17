#include <iostream>
using namespace std;

class Item {
private:
    int id;
    string name;
    double price;

public:
    // Constructor 1
    Item(int i, string n, double p) {
        id = i;
        name = n;
        price = p;
    }

    // Overloaded Constructor
    Item(int i, string n) {
        id = i;
        name = n;
        price = 100;
    }

    // Copy Constructor
    Item(const Item &obj) {
        id = obj.id;
        name = obj.name;
        price = obj.price;
    }

    void display() {
        cout << "ID: " << id 
             << " Name: " << name 
             << " Price: " << price << endl;
    }
};

int main() {
    Item obj1(1, "Pizza", 200);
    Item obj2(2, "Burger");   // overloaded
    Item obj3(obj1);          // copy constructor

    obj1.display();
    obj2.display();
    obj3.display();

    return 0;
}