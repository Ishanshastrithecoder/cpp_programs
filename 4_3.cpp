#include <iostream>
#include <vector>
using namespace std;

class Fuel {
protected:
    string fuelType;

public:
    Fuel(string fuel) {
        fuelType = fuel;
    }
};

class Brand {
protected:
    string brandName;

public:
    Brand(string brand) {
        brandName = brand;
    }
};

class Car : public Fuel, public Brand {
public:
    Car(string brand, string fuel) : Brand(brand), Fuel(fuel) {}

    void display(int index) {
        cout << "\nCar " << index + 1 << " Details:\n";
        cout << "Brand: " << brandName << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of cars to process: ";
    cin >> n;

    vector<Car> serviceQueue;

    for (int i = 0; i < n; i++) {
        string brand, fuel;
        cout << "\nEnter details for car " << i + 1 << ":\n";
        cout << "Brand: ";
        cin >> ws;
        getline(cin, brand);

        cout << "Fuel Type: ";
        getline(cin, fuel);

        serviceQueue.push_back(Car(brand, fuel));
    }

    cout << "\n--- Service Queue ---\n";
    for (int i = 0; i < serviceQueue.size(); i++) {
        serviceQueue[i].display(i);
    }

    return 0;
}
