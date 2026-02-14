#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Item {
public:
    int id;
    string name;
    float price;
    int quantity;

    float totalPrice() const {
        return price * quantity;
    }
};

vector<Item> cart;

// Add item to cart
void addItem() {
    Item item;
    cout << "Enter Item ID: ";
    cin >> item.id;
    cout << "Enter Item Name: ";
    cin >> item.name;
    cout << "Enter Price: ";
    cin >> item.price;
    cout << "Enter Quantity: ";
    cin >> item.quantity;

    cart.push_back(item);
    cout << "Item added to cart successfully!\n";
}

// Remove item from cart
void removeItem() {
    int id;
    cout << "Enter Item ID to remove: ";
    cin >> id;

    for (auto it = cart.begin(); it != cart.end(); ++it) {
        if (it->id == id) {
            cart.erase(it);
            cout << "Item removed successfully!\n";
            return;
        }
    }

    cout << "Item not found in cart.\n";
}

// View cart
void viewCart() {
    if (cart.empty()) {
        cout << "Cart is empty.\n";
        return;
    }

    float grandTotal = 0;

    cout << left << setw(10) << "ID"
         << setw(15) << "Name"
         << setw(10) << "Price"
         << setw(10) << "Qty"
         << setw(10) << "Total" << endl;

    for (const auto &item : cart) {
        cout << left << setw(10) << item.id
             << setw(15) << item.name
             << setw(10) << item.price
             << setw(10) << item.quantity
             << setw(10) << item.totalPrice() << endl;

        grandTotal += item.totalPrice();
    }

    cout << "-------------------------------------------\n";
    cout << "Grand Total: " << grandTotal << endl;
}

// Generate bill
void generateBill() {
    if (cart.empty()) {
        cout << "Cart is empty. Nothing to bill.\n";
        return;
    }

    float grandTotal = 0;

    cout << "\n===== Final Bill =====\n";

    for (const auto &item : cart) {
        cout << item.name << " x " << item.quantity
             << " = " << item.totalPrice() << endl;
        grandTotal += item.totalPrice();
    }

    cout << "----------------------\n";
    cout << "Total Amount: " << grandTotal << endl;
    cout << "Thank you for shopping!\n";

    cart.clear();
}

// Main menu
int main() {
    int choice;

    do {
        cout << "\n===== Shopping Cart System =====\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. View Cart\n";
        cout << "4. Generate Bill\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addItem(); break;
            case 2: removeItem(); break;
            case 3: viewCart(); break;
            case 4: generateBill(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
