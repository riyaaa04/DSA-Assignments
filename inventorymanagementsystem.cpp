#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_PRODUCTS = 100; 
const int LOW_STOCK_THRESHOLD = 10; 

// Structure to represent a product
struct Product {
    string name;
    int quantity;
};

class InventoryManagementSystem {
private:
    Product products[MAX_PRODUCTS];
    int numProducts;

public:
    // Constructor
    InventoryManagementSystem() {
        numProducts = 0;
    }

    // Function to add a product to the inventory
    void addProduct(string name, int quantity) {
        if (numProducts < MAX_PRODUCTS) {
            products[numProducts].name = name;
            products[numProducts].quantity = quantity;
            numProducts++;
            cout << "Product added: " << name << endl;
        } else {
            cout << "Inventory is full. Cannot add more products." << endl;
        }
    }

    // Function to update the quantity of a product
    void updateQuantity(string name, int quantity) {
        for (int i = 0; i < numProducts; i++) {
            if (products[i].name == name) {
                products[i].quantity = quantity;
                cout << "Quantity updated for product: " << name << endl;
                return;
            }
        }
        cout << "Product not found." << endl;
    }

    // Function to remove a product from the inventory
    void removeProduct(string name) {
        for (int i = 0; i < numProducts; i++) {
            if (products[i].name == name) {
                products[i] = products[numProducts - 1]; // Replace with the last product
                numProducts--;
                cout << "Product removed: " << name << endl;
                return;
            }
        }
        cout << "Product not found." << endl;
    }

    // Function to display the current inventory
    void displayInventory() {
        cout << "\nCurrent Inventory:" << endl;
        cout << "-------------------" << endl;
        for (int i = 0; i < numProducts; i++) {
            cout << "Product: " << products[i].name << "\tQuantity: " << products[i].quantity << endl;
        }
    }

    // Function to alert when a product is running low on stock
    void checkLowStock() {
        cout << "\nLow Stock Alert:" << endl;
        cout << "-------------------" << endl;
        for (int i = 0; i < numProducts; i++) {
            if (products[i].quantity < LOW_STOCK_THRESHOLD) {
                cout << "Low stock for product: " << products[i].name << "\tQuantity: " << products[i].quantity << endl;
            }
        }
    }
};

int main() {
    InventoryManagementSystem ims;
    int choice;

    while (true) {
        cout << "\n\tInventory Management System";
        cout << "\n1. Add Product";
        cout << "\n2. Update Product Quantity";
        cout << "\n3. Remove Product";
        cout << "\n4. Display Inventory";
        cout << "\n5. Check Low Stock";
        cout << "\n6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int quantity;
            cout << "Enter product name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter product quantity: ";
            cin >> quantity;
            ims.addProduct(name, quantity);
            break;
        }
        case 2: {
            string name;
            int quantity;
            cout << "Enter product name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter new quantity: ";
            cin >> quantity;
            ims.updateQuantity(name, quantity);
            break;
        }
        case 3: {
            string name;
            cout << "Enter product name to remove: ";
            cin.ignore();
            getline(cin, name);
            ims.removeProduct(name);
            break;
        }
        case 4:
            ims.displayInventory();
            break;
        case 5:
            ims.checkLowStock();
            break;
        case 6:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 6." << endl;
        }
    }

    return 0;
}
