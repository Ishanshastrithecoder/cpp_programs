#include <iostream>  
#include <vector>  

using namespace std;  

class Calculator {  
public:  
    int add(int a, int b) {  
        return a + b;  
    }  

    double add(double a, double b) {  
        return a + b;  
    }  

    double add(int a, double b) {  
        return a + b;  
    }  
};  

int main() {  
    Calculator calc;  

    // Ask for two integers for add(int, int)  
    int intVal1, intVal2;  
    cout << "Enter two integer numbers : ";  
    cin >> intVal1 >> intVal2;  

    // Ask for two doubles for add(double, double)  
    double doubleVal1, doubleVal2;  
    cout << "Enter two double numbers : ";  
    cin >> doubleVal1 >> doubleVal2;  

    // Ask for one integer and one double for add(int, double)  
    int intVal3;  
    double doubleVal3;  
    cout << "Enter one integer and one double number : ";  
    cin >> intVal3 >> doubleVal3;  

    cout << "Choose storage approach :\n";  
    cout << "1. STL vector\n";  
    cout << "2. Basic array\n";  
    cout << "Enter choice (1 or 2) : ";  

    int choice;  
    cin >> choice;  

    switch (choice) {  
        case 1: {  
            vector<double> resultsVector;  
            resultsVector.push_back(calc.add(intVal1, intVal2));          // int + int  
            resultsVector.push_back(calc.add(doubleVal1, doubleVal2));    // double + double  
            resultsVector.push_back(calc.add(intVal3, doubleVal3));       // int + double  

            cout << "\nResults using STL vector :" << endl;  
            for (double res : resultsVector) {  
                cout << res << endl;  
            }  
            break;  
        }  
        case 2: {  
            double resultsArray[3];  
            resultsArray[0] = calc.add(intVal1, intVal2);  
            resultsArray[1] = calc.add(doubleVal1, doubleVal2);  
            resultsArray[2] = calc.add(intVal3, doubleVal3);  

            cout << "\nResults using basic array :" << endl;  
            for (int i = 0; i < 3; ++i) {  
                cout << resultsArray[i] << endl;  
            }  
            break;  
        }  
        default:  
            cout << "Invalid choice!" << endl;  
    }  

    cout << "24CE115_Ishan" << endl ;
    return 0;  
}  
