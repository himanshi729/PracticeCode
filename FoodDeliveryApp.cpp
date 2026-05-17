#include <iostream>
#include <iomanip>
using namespace std;

enum Category { VEG, NONVEG, DRINK };

class Item {
protected:
    int id;
    string name;
    double price;
    static int count;

public:
    Item(int i = 0, string n = "None", double p = 0.0) {
        if(i <= 0)
            throw "Invalid Item ID!";

        if(p < 0)
            throw p;   // throwing exception

        id = i;
        name = n;
        price = p;
        count++;
    }

    double operator+(Item &obj) {
        return this->price + obj.price;
    }

    bool operator==(Item &obj) {
        return this->price == obj.price;
    }

    friend ostream& operator<<(ostream &out, Item &obj);

    inline double getPrice() { return price; }

    virtual void display() {
        cout << "ID: " << id << " Name: " << name
             << " Price: ₹" << fixed << setprecision(2) << price << endl;
    }

    static void showCount() {
        cout << "Total items created: " << count << endl;
    }

    friend void applyDiscount(Item &obj);

    virtual ~Item() {}
};

int Item::count = 0;

class FoodItem : public Item {
    Category type;

public:
    FoodItem(int i, string n, double p, Category t)
        : Item(i, n, p), type(t) {}

    void display() override {
        cout << "[FOOD] ";
        Item::display();
    }
};

class DrinkItem : public Item {
public:
    DrinkItem(int i, string n, double p) : Item(i, n, p) {}

    void display() override {
        cout << "[DRINK] ";
        Item::display();
    }
};

// Friend function with exception
void applyDiscount(Item &obj) {

    if(obj.price == 0)
        throw "Cannot apply discount on zero price!";

    obj.price = obj.price * 0.9;
}

// Exception propagation example
void processDiscount(Item &obj) {
    applyDiscount(obj); // exception propagates to caller
}

ostream& operator<<(ostream &o, Item &obj) {
    o << "ID: " << obj.id
      << " Name: " << obj.name
      << " Price: ₹" << fixed << setprecision(2) << obj.price;
    return o;
}

int main() {

    try {  // MAIN TRY BLOCK

        Item *ptr1 = new FoodItem(-1, "Pizza", 200, VEG);
        Item *ptr2 = new FoodItem(2, "Burger", 180, NONVEG);
        Item *ptr3 = new DrinkItem(3, "Coke", 60);

        cout << "\n--- Menu ---\n";
        ptr1->display();
        ptr2->display();
        ptr3->display();

        double total = *ptr1 + *ptr2;
        cout << "\nTotal Bill using Operator + : ₹" << total << endl;

        if (*ptr1 == *ptr2)
            cout << "Both items have same price\n";
        else
            cout << "Items have different prices\n";

        cout << "\nPrinting Item using << operator:\n";
        cout << *ptr1 << endl;

        // Nested try catch
        try {
            processDiscount(*ptr1);  // exception propagation
            cout << "\nAfter Discount:\n";
            ptr1->display();
        }
        catch(const char* msg) { // catching exception
            cout << "Nested Catch: " << msg << endl;
        }

        Item::showCount();

        delete ptr1;
        delete ptr2;
        delete ptr3;
    }

    // Catch block for string exception
    catch(const char* msg) {
        cout << "Exception caught: " << msg << endl;
    }

    // Catch block for double exception
    catch(double price) {
        cout << "Exception caught: Invalid price entered: " << price << endl;
    }

    catch(...) {
        cout << "Unknown exception occurred!" << endl;
    }

    return 0;
}