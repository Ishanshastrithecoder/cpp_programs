#include <iostream>  
#include <vector>  
#include <cmath>  

using namespace std;  

class Complex {  
private:  
    double real;  
    double imag;  

public:  
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}  

    // Overloaded + operator  
    Complex operator+(const Complex& other) const {  
        return Complex(real + other.real, imag + other.imag);  
    }  

    // Overloaded - operator  
    Complex operator-(const Complex& other) const {  
        return Complex(real - other.real, imag - other.imag);  
    }  

    // Overloaded << operator for output  
    friend ostream& operator<<(ostream& os, const Complex& c) {  
        os << "(" << c.real;  
        if (c.imag >= 0)  
            os << "+" << c.imag << "i)";  
        else  
            os << c.imag << "i)";  
        return os;  
    }  

    // Overloaded >> operator for input  
    friend istream& operator>>(istream& is, Complex& c) {  
        is >> c.real >> c.imag;  
        return is;  
    }  

    // Method to calculate the magnitude  
    double magnitude() const {  
        return sqrt(real * real + imag * imag);  
    }  

    // Method to compare two complex numbers  
    bool isLargerThan(const Complex& other) const {  
        return this->magnitude() > other.magnitude();  
    }  
};  

// STL Approach  
void stlApproach() {  
    vector<Complex> complexVector(2);  
    cout << "Enter first complex number (real imag) : ";  
    cin >> complexVector[0];  
    cout << "Enter second complex number (real imag) : ";  
    cin >> complexVector[1];  

    cout << "\nComplex numbers in vector:" << endl;  
    cout << "First : " << complexVector[0] << endl;  
    cout << "Second : " << complexVector[1] << endl;  

    Complex sum = complexVector[0] + complexVector[1];  
    Complex difference = complexVector[0] - complexVector[1];  

    cout << "\nResults using STL vector :" << endl;  
    cout << "Sum : " << sum << endl;  
    cout << "Difference : " << difference << endl;  

    if (complexVector[0].isLargerThan(complexVector[1])) {  
        cout << "\nFirst complex number is larger." << endl;  
    } else if (complexVector[1].isLargerThan(complexVector[0])) {  
        cout << "Second complex number is larger." << endl;  
    } else {  
        cout << "Both complex numbers are equal in magnitude." << endl;  
    }  

    cout << "24CE112_CHETAN" << endl ;
}  

// Non-STL Approach  
void nonStlApproach() {  
    int size = 2;  
    Complex* complexArray = new Complex[size];  
    
    cout << "\nEnter first complex number (real imag) : ";  
    cin >> complexArray[0];  
    cout << "Enter second complex number (real imag) : ";  
    cin >> complexArray[1];  

    cout << "\nComplex numbers in array :" << endl;  
    cout << "First : " << complexArray[0] << endl;  
    cout << "Second : " << complexArray[1] << endl;  

    Complex sum = complexArray[0] + complexArray[1];  
    Complex difference = complexArray[0] - complexArray[1];  

    cout << "\nResults using array (non-STL):" << endl;  
    cout << "Sum : " << sum << endl;  
    cout << "Difference : " << difference << endl;  

    if (complexArray[0].isLargerThan(complexArray[1])) {  
        cout << "\nFirst complex number is larger." << endl;  
    } else if (complexArray[1].isLargerThan(complexArray[0])) {  
        cout << "Second complex number is larger." << endl;  
    } else {  
        cout << "Both complex numbers are equal in magnitude." << endl;  
    }  

    delete[] complexArray;  

    cout << "24CE115_Ishan" << endl ;
}  

int main() {  
    int choice;  
    do {  
        cout << "\nComplex Number Operations" << endl;  
        cout << "---------------------------" << endl;  
        cout << "1. Using STL Approach" << endl;  
        cout << "2. Using Non-STL Approach" << endl;  
        cout << "Enter your choice : ";  
        cin >> choice;  

        switch (choice) {  
            case 1:  
                stlApproach();  
                break;  
            case 2:  
                nonStlApproach();  
                break;   
            default:  
                cout << "Invalid choice. Please choose again." << endl;  
        }  
    } while (choice != 2);  

    return 0;  
}  
