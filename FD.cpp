#include <iostream>
#include <iomanip>
#include <vector>
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
            throw p;

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

    virtual void display() {
        cout << "ID: " << id << " | " << name
             << " | Price: ₹" << fixed << setprecision(2) << price << endl;
    }

    double getPrice() { return price; }
    int getId() { return id; }
    string getName() { return name; }

    static void showCount() {
        cout << "Total items: " << count << endl;
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

// Discount function
void applyDiscount(Item &obj) {
    if(obj.price == 0)
        throw "Cannot apply discount!";
    obj.price *= 0.9;
}

// Cart structure
struct CartItem {
    Item* item;
    int qty;
};

int main() {
    vector<Item*> menu;
    vector<CartItem> cart;

    try {
        // Create Menu
        menu.push_back(new FoodItem(1, "Pizza", 200, VEG));
        menu.push_back(new FoodItem(2, "Burger", 150, NONVEG));
        menu.push_back(new FoodItem(3, "Pasta", 180, VEG));
        menu.push_back(new DrinkItem(4, "Coke", 60));
        menu.push_back(new DrinkItem(5, "Juice", 80));

        int choice;

        do {
            cout << "\n===== FOOD DELIVERY APP =====\n";
            cout << "1. Show Menu\n";
            cout << "2. Order Item\n";
            cout << "3. View Cart\n";
            cout << "4. Checkout\n";
            cout << "5. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch(choice) {

                case 1:
                    cout << "\n--- MENU ---\n";
                    for(auto item : menu)
                        item->display();
                    break;

                case 2: {
                    int id, qty, found = 0;
                    cout << "Enter Item ID: ";
                    cin >> id;
                    cout << "Enter Quantity: ";
                    cin >> qty;

                    for(auto item : menu) {
                        if(item->getId() == id) {
                            cart.push_back({item, qty});
                            cout << "Item added to cart!\n";
                            found = 1;
                            break;
                        }
                    }

                    if(!found)
                        cout << "Invalid Item ID!\n";
                    break;
                }

                case 3:
                    cout << "\n--- CART ---\n";
                    for(auto c : cart) {
                        cout << c.item->getName()
                             << " x " << c.qty
                             << " = ₹" << c.item->getPrice() * c.qty << endl;
                    }
                    break;

                case 4: {
                    double total = 0;

                    cout << "\n--- BILL ---\n";
                    for(auto c : cart) {
                        double cost = c.item->getPrice() * c.qty;
                        cout << c.item->getName()
                             << " x " << c.qty
                             << " = ₹" << cost << endl;
                        total += cost;
                    }

                    // Discount
                    if(total > 500) {
                        cout << "Applying 10% discount...\n";
                        total *= 0.9;
                    }

                    // Delivery charge
                    if(total < 200) {
                        cout << "Adding ₹30 delivery charge\n";
                        total += 30;
                    }

                    cout << "Final Amount: ₹" << total << endl;

                    int pay;
                    cout << "Select Payment Method (1-Cash, 2-UPI): ";
                    cin >> pay;

                    cout << "Order Placed Successfully!\n";
                    cart.clear();
                    break;
                }

                case 5:
                    cout << "Thank you for using app!\n";
                    break;

                default:
                    cout << "Invalid choice!\n";
            }

        } while(choice != 5);

        // Cleanup 
        for(auto item : menu)
            delete item;
    }

    catch(const char* msg) {
        cout << "Exception: " << msg << endl;
    }

    catch(double p) {
        cout << "Invalid price: " << p << endl;
    }

    catch(...) {
        cout << "Unknown error!\n";
    }

    return 0;
}