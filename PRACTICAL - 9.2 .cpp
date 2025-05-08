#include <iostream>
#include <vector>
#include <ctime>
#include <string.h>


using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;
    vector<string> transactionHistory; // Stores transaction logs

    // Function to log transactions
    void logTransaction(const string &transaction) {
        time_t now = time(0);
        char* dt = ctime(&now);
        dt[strlen(dt) - 1] = '\0';
        transactionHistory.push_back(dt + string(" - ") + transaction);
    }

public:
    // Constructor
    BankAccount(string name, double initialBalance) : accountHolder(name), balance(initialBalance) {
        logTransaction("Account created with initial balance : ₹" + to_string(balance));
    }

    // Deposit function
    void deposit(double amount) {
        if (amount <= 0) {
            logTransaction("Failed deposit attempt of ₹" + to_string(amount) + " (Invalid amount)");
            cout << "Error: Deposit amount must be positive.\n";
            return;
        }
        balance += amount;
        logTransaction("Deposited ₹" + to_string(amount) + ", New balance: ₹" + to_string(balance));
        cout << "Deposit successful! New balance : ₹" << balance << endl;
    }

    // Withdraw function with error handling
    void withdraw(double amount) {
        if (amount <= 0) {
            logTransaction("Failed withdrawal attempt of ₹" + to_string(amount) + " (Invalid amount)");
            cout << "Error: Withdrawal amount must be positive.\n";
            return;
        }
        if (amount > balance) {
            logTransaction("Failed withdrawal of ₹" + to_string(amount) + " (Insufficient balance)");
            cout << "Error: Insufficient funds! Current balance : ₹" << balance << endl;
            return;
        }
        balance -= amount;
        logTransaction("Withdrew ₹" + to_string(amount) + ", New balance : ₹" + to_string(balance));
        cout << "Withdrawal successful! New balance : ₹" << balance << endl;
    }

    // Display transaction history
    void displayTransactionHistory() const {
        cout << "\nTransaction History for " << accountHolder << ":\n";
        if (transactionHistory.empty()) {
            cout << "No transactions recorded.\n";
        } else {
            for (const auto &entry : transactionHistory) {
                cout << entry << endl;
            }
        }
    }
};

int main() {
    string name;
    double initialBalance;

    cout << "Enter account holder name : ";
    cin >> name;
    cout << "Enter initial deposit amount : ₹";
    cin >> initialBalance;

    BankAccount account(name, initialBalance);

    int choice;
    double amount;
    do {
        cout << "\nBanking System Menu :\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. View Transaction History\n";
        cout << "4. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter deposit amount : ₹";
                cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter withdrawal amount : ₹";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.displayTransactionHistory();
                break;
            case 4:
                cout << "Thank you for using our banking system!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    cout << "24CE115_Ishan" << endl ;
    return 0;
}
