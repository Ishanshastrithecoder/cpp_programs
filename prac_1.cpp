#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    string accountNumber;
    double balance;

public:
    BankAccount(string name, string accNumber, double initialBalance) {
        accountHolderName = name;
        accountNumber = accNumber;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " successfully." << endl;
        } else {
            cout << "Invalid deposit amount. Please enter a positive value." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn $" << amount << " successfully." << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance. Cannot withdraw $ " << amount << "." << endl;
        } else {
            cout << "Invalid withdrawal amount. Please enter a positive value." << endl;
        }
    }

    void display_balance() const {
        cout << "Account Holder : " << accountHolderName << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Current Balance : $" << balance << endl;
    }
};

int main() {
    string name, accNumber;
    double initialBalance;

    cout << "Enter Account Holder's Name : ";
    getline(cin, name);
    cout << "Enter Account Number : ";
    getline(cin, accNumber);
    cout << "Enter Initial Balance : $ ";
    cin >> initialBalance;

    BankAccount userAccount(name, accNumber, initialBalance);

    int choice;
    double amount;

    do {
        cout << endl << "Choose an operation : " << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Display Balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit : $ ";
                cin >> amount;
                userAccount.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw : $ ";
                cin >> amount;
                userAccount.withdraw(amount);
                break;
            case 3:
                userAccount.display_balance();
                break;
            case 4:
                cout << "Exiting the program. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    cout << "24CE112_CHETAN" ;
    return 0;
}
