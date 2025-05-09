#include <iostream>
#include <queue>
using namespace std;

// Forward declaration
class Fahrenheit;

class Celsius {
    float temp;

public:
    Celsius(float t = 0.0f) : temp(t) {}

    float getTemp() const { return temp; }

    // Conversion operator: Celsius to Fahrenheit
    operator Fahrenheit();

    // Overload == to compare Celsius with Fahrenheit
    bool operator==(const Fahrenheit& f) const;
};

class Fahrenheit {
    float temp;

public:
    Fahrenheit(float t = 32.0f) : temp(t) {}

    float getTemp() const { return temp; }

    // Conversion operator: Fahrenheit to Celsius
    operator Celsius() {
        return Celsius((temp - 32) * 5.0f / 9.0f);
    }

    // Overload == to compare Fahrenheit with Celsius
    bool operator==(const Celsius& c) const {
        return Celsius((temp - 32) * 5.0f / 9.0f).getTemp() == c.getTemp();
    }
};

// Define Celsius to Fahrenheit conversion
Celsius::operator Fahrenheit() {
    return Fahrenheit(temp * 9.0f / 5.0f + 32);
}

// Define Celsius == Fahrenheit
bool Celsius::operator==(const Fahrenheit& f) const {
    return temp == ((f.getTemp() - 32) * 5.0f / 9.0f);
}

// Display helper
void displayCelsius(const Celsius& c) {
    cout << c.getTemp() << "°C";
}

void displayFahrenheit(const Fahrenheit& f) {
    cout << f.getTemp() << "°F";
}

int main() {
    int choice;
    cout << "Welcome to the Temperature Converter!\n";
    cout << "Choose conversion type :\n";
    cout << "1. Celsius to Fahrenheit\n";
    cout << "2. Fahrenheit to Celsius\n";
    cout << "Enter your choice (1 or 2) : ";
    cin >> choice;

    if (choice == 1) {
        int n;
        cout << "Enter number of temperatures to convert : ";
        cin >> n;

        Celsius* cArr = new Celsius[n];
        Fahrenheit* fArr = new Fahrenheit[n];
        queue<Fahrenheit> fQueue; // STL queue for Fahrenheit

        for (int i = 0; i < n; ++i) {
            float cVal;
            cout << "Enter temperature " << i + 1 << " in Celsius : ";
            cin >> cVal;
            cArr[i] = Celsius(cVal);
            fArr[i] = cArr[i];   // convert
            fQueue.push(fArr[i]);
        }

        int storageChoice;
        cout << "\nChoose storage approach :\n";
        cout << "1. STL Queue\n";
        cout << "2. Non-STL Array\n";
        cout << "Enter your choice: ";
        cin >> storageChoice;

        if (storageChoice == 1) {
            cout << "\nTemperatures in Fahrenheit (STL Queue order) :\n";
            while (!fQueue.empty()) {
                displayFahrenheit(fQueue.front());
                cout << endl;
                fQueue.pop();
            }
        } else if (storageChoice == 2) {
            cout << "\nTemperatures in Fahrenheit (Array order) :\n";
            for (int i = 0; i < n; ++i) {
                displayFahrenheit(fArr[i]);
                cout << endl;
            }
        } else {
            cout << "Invalid storage choice.\n";
        }

        if (n >= 2) {
            if (fArr[0] == fArr[1])
                cout << "First two temperatures are equal.\n";
            else
                cout << "First two temperatures are NOT equal.\n";
        }

        delete[] cArr;
        delete[] fArr;

    } else if (choice == 2) {
        int n;
        cout << "Enter number of temperatures to convert : ";
        cin >> n;

        Fahrenheit* fArr = new Fahrenheit[n];
        Celsius* cArr = new Celsius[n];
        queue<Celsius> cQueue; // STL queue for Celsius

        for (int i = 0; i < n; ++i) {
            float fVal;
            cout << "Enter temperature " << i + 1 << " in Fahrenheit : ";
            cin >> fVal;
            fArr[i] = Fahrenheit(fVal);
            cArr[i] = fArr[i];   // convert
            cQueue.push(cArr[i]);
        }

        int storageChoice;
        cout << "\nChoose storage approach:\n";
        cout << "1. STL Queue\n";
        cout << "2. Non-STL Array\n";
        cout << "Enter your choice: ";
        cin >> storageChoice;

        if (storageChoice == 1) {
            cout << "\nTemperatures in Celsius (STL Queue order) :\n";
            while (!cQueue.empty()) {
                displayCelsius(cQueue.front());
                cout << endl;
                cQueue.pop();
            }
        } else if (storageChoice == 2) {
            cout << "\nTemperatures in Celsius (Array order) :\n";
            for (int i = 0; i < n; ++i) {
                displayCelsius(cArr[i]);
                cout << endl;
            }
        } else {
            cout << "Invalid storage choice.\n";
        }

        if (n >= 2) {
            if (cArr[0] == fArr[1])
                cout << "First two temperatures are equal.\n";
            else
                cout << "First two temperatures are NOT equal.\n";
        }

        delete[] fArr;
        delete[] cArr;

    } else {
        cout << "Invalid choice! Please enter 1 or 2.\n";
    }

    cout << "24CE115_Ishan" << endl;
    return 0;
}
