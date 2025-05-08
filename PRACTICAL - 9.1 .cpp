#include <iostream>
#include <limits> // For input validation

using namespace std;

double getValidatedInput(const string &prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) { // Check for non-numeric input
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input! Please enter a valid numeric value.\n";
        } else if (value < 0) { // Prevent negative values
            cout << "Value cannot be negative. Try again.\n";
        } else {
            return value;
        }
    }
}

int main() {
    cout << "Bank Loan-to-Income Ratio Calculator\n";

    double loanAmount = getValidatedInput("Enter the total loan amount : ");

    double annualIncome;
    while (true) {
        annualIncome = getValidatedInput("Enter your annual income : ");
        if (annualIncome == 0) {
            cout << "Income cannot be zero! Please enter a valid amount.\n";
        } else {
            break;
        }
    }

    // Calculate loan-to-income ratio
    double ratio = loanAmount / annualIncome;

    // Display result
    cout << "\nLoan-to-Income Ratio : " << ratio << endl;
    cout << "Note: A lower ratio typically indicates better loan eligibility.\n";

    cout << "24CE112_CHETAN" << endl ;
    return 0;
}
