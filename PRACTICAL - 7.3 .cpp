#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Structure to represent an inventory item
struct Item {
    string name;
    int quantity;
    double price;
};

// Function to add an item to inventory (Same for both approaches)
void addItem() {
    ofstream file("inventory", ios::app); // Append mode
    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    Item item;
    cout << "Enter item name : ";
    cin.ignore();
    getline(cin, item.name);
    cout << "Enter quantity : ";
    cin >> item.quantity;
    cout << "Enter price : ";
    cin >> item.price;

    file << item.name << "," << item.quantity << "," << item.price << "\n";
    file.close();

    cout << "Item added successfully!\n";
}

// **Approach 1: File Processing Directly (Non-STL)**
void viewItemsNonSTL() {
    ifstream file("inventory");
    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    cout << "\nInventory List (Non-STL Approach):\n";
    string name;
    int quantity;
    double price;

    while (file >> ws, getline(file, name, ',') && file >> quantity && file.ignore() && file >> price) {
        cout << "Name : " << name << " , Quantity : " << quantity << " , Price : $" << price << "\n";
    }
    file.close();
}

// **Search using File Processing Directly**
void searchItemNonSTL() {
    ifstream file("inventory");
    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    string searchName, name;
    int quantity;
    double price;
    bool found = false;

    cout << "Enter item name to search : ";
    cin.ignore();
    getline(cin, searchName);

    while (file >> ws, getline(file, name, ',') && file >> quantity && file.ignore() && file >> price) {
        if (name == searchName) {
            cout << "Item found: Name : " << name << " , Quantity : " << quantity << " , Price : $" << price << "\n";
            found = true;
            break;
        }
    }
    file.close();

    if (!found) {
        cout << "Item not found.\n";
    }
}

// **Approach 2: Using STL (Vector-Based)**
vector<Item> loadInventory() {
    vector<Item> inventory;
    ifstream file("inventory");

    if (!file) {
        cout << "Error opening file!\n";
        return inventory;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Item item;
        getline(ss, item.name, ',');
        ss >> item.quantity;
        ss.ignore();
        ss >> item.price;
        inventory.push_back(item);
    }
    file.close();
    return inventory;
}

// **View all items using STL**
void viewItemsSTL() {
    vector<Item> inventory = loadInventory();

    if (inventory.empty()) {
        cout << "Inventory is empty!\n";
        return;
    }

    cout << "\nInventory List (STL Approach):\n";
    for (const Item& item : inventory) {
        cout << "Name : " << item.name << " , Quantity : " << item.quantity << " , Price : $" << item.price << "\n";
    }
}

// **Search for an item using STL**
void searchItemSTL() {
    vector<Item> inventory = loadInventory();
    if (inventory.empty()) {
        cout << "Inventory is empty!\n";
        return;
    }

    string searchName;
    cout << "Enter item name to search: ";
    cin.ignore();
    getline(cin, searchName);

    bool found = false;
    for (const Item& item : inventory) {
        if (item.name == searchName) {
            cout << "Item found: Name : " << item.name << " , Quantity : " << item.quantity << " , Price : $" << item.price << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Item not found.\n";
    }
}

// **Main Menu**
int main() {
    int approachChoice;
    cout << "Choose an approach :\n";
    cout << "1. Non-STL Approch \n";
    cout << "2. STL Approach \n";
    cout << "Enter your choice : ";
    cin >> approachChoice;

    int operationChoice;
    do {
        cout << "\nInventory System Menu :\n";
        cout << "1. Add Item\n";
        cout << "2. View Items\n";
        cout << "3. Search Item\n";
        cout << "4. Exit\n";
        cout << "Enter your choice : ";
        cin >> operationChoice;

        switch (operationChoice) {
            case 1:
                addItem();
                break;
            case 2:
                (approachChoice == 1) ? viewItemsNonSTL() : viewItemsSTL();
                break;
            case 3:
                (approachChoice == 1) ? searchItemNonSTL() : searchItemSTL();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (operationChoice != 4);

    cout << "24CE112_CHETAN" << endl ;
    return 0;
}
