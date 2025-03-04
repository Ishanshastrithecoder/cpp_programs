#include<iostream>
#include<cmath>
using namespace std;

class Loan {
    int id;
    string name;
    double tla;        // Total Loan Amount
    float air;         // Annual Interest Rate
    float l_tenure;    // Loan Tenure in Months

public:
    Loan() {
        id = 0;
        name = "abc";
        tla = 0;
        air = 0;
        l_tenure = 0;
    }

    Loan(int a, string b, double c, float d, float e) {
        id = a;
        name = b;
        tla = c;
        air = d;
        l_tenure = e;
    }

    void loan_calc() {
        // Convert annual interest rate to monthly
        float monthlyInterestRate = (air / 100) / 12;

        // EMI Calculation
        double emi = (tla * monthlyInterestRate * pow(1 + monthlyInterestRate, l_tenure)) / (pow(1 + monthlyInterestRate, l_tenure) - 1);

        cout << "Your monthly EMI: $" << emi << endl;
    }
};

int main() {
    int a, f;
    string b;
    double c;
    float d, e;

    do {
        cout << "Enter loan id: ";
        cin >> a;
        cout << "Enter applicant's name: ";
        cin >> b;
        cout << "Enter total loan amount: $";
        cin >> c;
        cout << "Enter annual interest rate (%): ";
        cin >> d;
        cout << "Enter loan tenure in months: ";
        cin >> e;

        Loan l1(a, b, c, d, e);
        l1.loan_calc();

        cout << "\nIf you want to calculate another loan, enter 1; otherwise, enter 0 to exit: ";
        cin >> f;

    } while (f != 0);

    return 0;
}
