#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolder;
    double balance;

public:

    BankAccount() {
        accountNumber = 0;
        accountHolder = "Unnamed";
        balance = 0.0;
    }


    BankAccount(int accNo, string name, double initialBalance) {
        accountNumber = accNo;
        accountHolder = name;
        balance = initialBalance;
    }

    void createAccount(int accNo, string name) {
        accountNumber = accNo;
        accountHolder = name;
        balance = 0.0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        } else {
            cout << "Insufficient funds or invalid amount.\n";
        }
    }

    void display() {
        cout << "\nAccount Summary:\n";
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
    }
};

int main() {
    BankAccount acc1;
    acc1.createAccount(1001, "Alice");

    BankAccount acc2(1002, "Bob", 5000.00);

    acc1.deposit(1000);
    acc1.withdraw(300);
    acc1.withdraw(800);
    acc1.display();

    acc2.deposit(2000);
    acc2.withdraw(1500);
    acc2.display();

    return 0;
}

