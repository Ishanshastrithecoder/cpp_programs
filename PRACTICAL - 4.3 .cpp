#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Fuel {
protected:
    string fuelType;
public:
    Fuel(const string& fuel) : fuelType(fuel) {}

    string getFuelType() const {
        return fuelType;
    }
};

class Brand {
protected:
    string brandName;
public:
    Brand(const string& brand) : brandName(brand) {}

    string getBrandName() const {
        return brandName;
    }
};

class Car : public Fuel, public Brand {
private:
    string carModel;

public:
    Car() : Fuel("Unknown"), Brand("Unknown"), carModel("Unknown") {}

    Car(const string& model, const string& brand, const string& fuel)
        : Brand(brand), Fuel(fuel), carModel(model) {}

    void displayDetails() const {
        cout << "Car Model : " << carModel << endl;
        cout << "Brand : " << getBrandName() << endl;
        cout << "Fuel Type : " << getFuelType() << endl;
    }
};

// STL Approach: Use a queue to store multiple Car objects (e.g., service queue)
void serviceCarsUsingQueue() {
    int numCars;

    cout << "Enter the number of cars in the service queue : ";
    cin >> numCars;

    queue<Car> carQueue;

    for (int i = 0; i < numCars; ++i) {
        string model, brand, fuel;
        cout << "\nEnter details for car " << i + 1 << " :\n";
        cout << "Car Model : ";
        cin >> model;
        cout << "Brand : ";
        cin >> brand;
        cout << "Fuel Type : ";
        cin >> fuel;

        Car newCar(model, brand, fuel);
        carQueue.push(newCar);
    }

    cout << "\nCars in the service queue : \n\n";
    while (!carQueue.empty()) {
        carQueue.front().displayDetails();
        carQueue.pop();
        cout << "--------------------\n";
    }
}

// Non-STL Approach: Use an array to manage Car objects
void serviceCarsUsingArray() {
    int numCars;

    cout << "Enter the number of cars in the service queue : ";
    cin >> numCars;

    Car* carArray = new Car[numCars];

    for (int i = 0; i < numCars; ++i) {
        string model, brand, fuel;
        cout << "\nEnter details for car " << i + 1 << ":\n";
        cout << "Car Model: ";
        cin >> model;
        cout << "Brand: ";
        cin >> brand;
        cout << "Fuel Type: ";
        cin >> fuel;

        carArray[i] = Car(model, brand, fuel);
    }

    cout << "\nCars in the service queue : \n\n";
    for (int i = 0; i < numCars; ++i) {
        carArray[i].displayDetails();
        cout << "--------------------\n";
    }

    delete[] carArray;
}

int main() {
    int choice;

    cout << "Choose an approach for managing cars in the service queue :\n";
    cout << "1. STL Approach (using std::queue)\n";
    cout << "2. Non-STL Approach (using array)\n";
    cout << "Enter your choice (1 or 2) : ";
    cin >> choice;

    if (choice == 1) {
        serviceCarsUsingQueue();  // STL Approach
    } else if (choice == 2) {
        serviceCarsUsingArray();  // Non-STL Approach
    } else {
        cout << "Invalid choice. Exiting program.\n";
    }

    cout << "24CE115_Ishan" << endl ;
    return 0;
}
