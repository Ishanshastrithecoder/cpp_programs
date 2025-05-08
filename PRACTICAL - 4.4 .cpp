#include <iostream>
#include <string>
#include <stack>
using namespace std;

// Base Class for Bank Account
class BankAccount {
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNum, double initialBalance)
        : accountNumber(accNum), balance(initialBalance) {}

    virtual ~BankAccount() {
        cout << "BankAccount Destructor called!" << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << "\nNew balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    virtual bool withdraw(double amount) = 0;

    double getBalance() const {
        return balance;
    }

    string getAccountNumber() const {
        return accountNumber;
    }
};

// Derived Class for Savings Account
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(string accNum, double initialBalance, double rate)
        : BankAccount(accNum, initialBalance), interestRate(rate) {}

    ~SavingsAccount() {
        cout << "SavingsAccount Destructor called!" << endl;
    }

    bool withdraw(double amount) override {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
            return false;
        }
        balance -= amount;
        cout << "Withdrew: $" << amount << "\nNew balance: $" << balance << endl;
        return true;
    }

    void applyInterest() {
        balance += balance * (interestRate / 100);
        cout << "Interest applied. New balance: $" << balance << endl;
    }
};

// Derived Class for Current Account
class CurrentAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CurrentAccount(string accNum, double initialBalance, double limit)
        : BankAccount(accNum, initialBalance), overdraftLimit(limit) {}

    ~CurrentAccount() {
        cout << "CurrentAccount Destructor called!" << endl;
    }

    bool withdraw(double amount) override {
        if (amount > balance + overdraftLimit) {
            cout << "Overdraft limit exceeded!" << endl;
            return false;
        }
        balance -= amount;
        cout << "Withdrew: $" << amount << "\nNew balance: $" << balance << endl;
        return true;
    }
};

// Transaction History Using STL (std::stack)
class TransactionHistorySTL {
private:
    stack<string> transactionHistory;

public:
    void addTransaction(const string& transaction) {
        transactionHistory.push(transaction);
    }

    void undoLastTransaction() {
        if (!transactionHistory.empty()) {
            cout << "Undoing transaction: " << transactionHistory.top() << endl;
            transactionHistory.pop();
        } else {
            cout << "No transactions to undo." << endl;
        }
    }
};

// Transaction History Using Non-STL (Manual Stack with Linked List)
class TransactionNode {
public:
    string transaction;
    TransactionNode* next;

    TransactionNode(const string& trans) : transaction(trans), next(nullptr) {}
};

class TransactionHistoryNonSTL {
private:
    TransactionNode* top;

public:
    TransactionHistoryNonSTL() : top(nullptr) {}

    ~TransactionHistoryNonSTL() {
        while (top != nullptr) {
            TransactionNode* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void addTransaction(const string& transaction) {
        TransactionNode* newTransaction = new TransactionNode(transaction);
        newTransaction->next = top;
        top = newTransaction;
    }

    void undoLastTransaction() {
        if (top != nullptr) {
            cout << "Undoing transaction: " << top->transaction << endl;
            TransactionNode* temp = top;
            top = top->next;
            delete temp;
        } else {
            cout << "No transactions to undo." << endl;
        }
    }
};

// Main Function
int main() {
    string accountType;
    string accountNumber;
    double initialBalance, interestRate, overdraftLimit;
    int transactionChoice, approachChoice;
    bool running = true;

    // Ask user for account type and details
    cout << "Enter account type (Savings/Current): ";
    cin >> accountType;

    cout << "Enter account number: ";
    cin >> accountNumber;

    cout << "Enter initial balance: $";
    cin >> initialBalance;

    if (accountType == "Savings" || accountType == "savings") {
        cout << "Enter interest rate (%): ";
        cin >> interestRate;

        // Create Savings Account object
        SavingsAccount savingsAcc(accountNumber, initialBalance, interestRate);

        // Ask user for approach choice (STL or Non-STL)
        cout << "\nChoose Approach for Transaction History:\n";
        cout << "1. STL Approach (Using std::stack)\n";
        cout << "2. Non-STL Approach (Using manual stack)\n";
        cout << "Enter your choice (1 or 2): ";
        cin >> approachChoice;

        // Transaction History Management
        if (approachChoice == 1) {
            // Using STL Stack
            TransactionHistorySTL historySTL;

            while (running) {
                cout << "\nChoose an operation:\n";
                cout << "1. Deposit\n2. Withdraw\n3. Apply Interest\n4. Undo Last Transaction\n5. Exit\n";
                cout << "Enter your choice: ";
                cin >> transactionChoice;

                switch (transactionChoice) {
                    case 1: {
                        double depositAmount;
                        cout << "Enter deposit amount: $";
                        cin >> depositAmount;
                        savingsAcc.deposit(depositAmount);
                        historySTL.addTransaction("Deposited $" + to_string(depositAmount) + " to Savings Account");
                        break;
                    }
                    case 2: {
                        double withdrawAmount;
                        cout << "Enter withdrawal amount: $";
                        cin >> withdrawAmount;
                        savingsAcc.withdraw(withdrawAmount);
                        historySTL.addTransaction("Withdrew $" + to_string(withdrawAmount) + " from Savings Account");
                        break;
                    }
                    case 3:
                        savingsAcc.applyInterest();
                        historySTL.addTransaction("Applied interest to Savings Account");
                        break;
                    case 4:
                        historySTL.undoLastTransaction();
                        break;
                    case 5:
                        running = false;
                        break;
                    default:
                        cout << "Invalid choice! Try again." << endl;
                        break;
                }
            }
        } else if (approachChoice == 2) {
            // Using Non-STL Stack
            TransactionHistoryNonSTL historyNonSTL;

            while (running) {
                cout << "\nChoose an operation:\n";
                cout << "1. Deposit\n2. Withdraw\n3. Apply Interest\n4. Undo Last Transaction\n5. Exit\n";
                cout << "Enter your choice: ";
                cin >> transactionChoice;

                switch (transactionChoice) {
                    case 1: {
                        double depositAmount;
                        cout << "Enter deposit amount: $";
                        cin >> depositAmount;
                        savingsAcc.deposit(depositAmount);
                        historyNonSTL.addTransaction("Deposited $" + to_string(depositAmount) + " to Savings Account");
                        break;
                    }
                    case 2: {
                        double withdrawAmount;
                        cout << "Enter withdrawal amount: $";
                        cin >> withdrawAmount;
                        savingsAcc.withdraw(withdrawAmount);
                        historyNonSTL.addTransaction("Withdrew $" + to_string(withdrawAmount) + " from Savings Account");
                        break;
                    }
                    case 3:
                        savingsAcc.applyInterest();
                        historyNonSTL.addTransaction("Applied interest to Savings Account");
                        break;
                    case 4:
                        historyNonSTL.undoLastTransaction();
                        break;
                    case 5:
                        running = false;
                        break;
                    default:
                        cout << "Invalid choice! Try again." << endl;
                        break;
                }
            }
        } else {
            cout << "Invalid choice for approach!" << endl;
        }

    } else if (accountType == "Current" || accountType == "current") {
        cout << "Enter overdraft limit: $";
        cin >> overdraftLimit;

        // Create Current Account object
        CurrentAccount currentAcc(accountNumber, initialBalance, overdraftLimit);

        // Ask user for approach choice (STL or Non-STL)
        cout << "\nChoose Approach for Transaction History:\n";
        cout << "1. STL Approach (Using std::stack)\n";
        cout << "2. Non-STL Approach (Using manual stack)\n";
        cout << "Enter your choice (1 or 2): ";
        cin >> approachChoice;

        // Transaction History Management
        if (approachChoice == 1) {
            // Using STL Stack
            TransactionHistorySTL historySTL;

            while (running) {
                cout << "\nChoose an operation:\n";
                cout << "1. Deposit\n2. Withdraw\n3. Undo Last Transaction\n4. Exit\n";
                cout << "Enter your choice: ";
                cin >> transactionChoice;

                switch (transactionChoice) {
                    case 1: {
                        double depositAmount;
                        cout << "Enter deposit amount: $";
                        cin >> depositAmount;
                        currentAcc.deposit(depositAmount);
                        historySTL.addTransaction("Deposited $" + to_string(depositAmount) + " to Current Account");
                        break;
                    }
                    case 2: {
                        double withdrawAmount;
                        cout << "Enter withdrawal amount: $";
                        cin >> withdrawAmount;
                        currentAcc.withdraw(withdrawAmount);
                        historySTL.addTransaction("Withdrew $" + to_string(withdrawAmount) + " from Current Account");
                        break;
                    }
                    case 3:
                        historySTL.undoLastTransaction();
                        break;
                    case 4:
                        running = false;
                        break;
                    default:
                        cout << "Invalid choice! Try again." << endl;
                        break;
                }
            }
        } else if (approachChoice == 2) {
            // Using Non-STL Stack
            TransactionHistoryNonSTL historyNonSTL;

            while (running) {
                cout << "\nChoose an operation:\n";
                cout << "1. Deposit\n2. Withdraw\n3. Undo Last Transaction\n4. Exit\n";
                cout << "Enter your choice: ";
                cin >> transactionChoice;

                switch (transactionChoice) {
                    case 1: {
                        double depositAmount;
                        cout << "Enter deposit amount: $";
                        cin >> depositAmount;
                        currentAcc.deposit(depositAmount);
                        historyNonSTL.addTransaction("Deposited $" + to_string(depositAmount) + " to Current Account");
                        break;
                    }
                    case 2: {
                        double withdrawAmount;
                        cout << "Enter withdrawal amount: $";
                        cin >> withdrawAmount;
                        currentAcc.withdraw(withdrawAmount);
                        historyNonSTL.addTransaction("Withdrew $" + to_string(withdrawAmount) + " from Current Account");
                        break;
                    }
                    case 3:
                        historyNonSTL.undoLastTransaction();
                        break;
                    case 4:
                        running = false;
                        break;
                    default:
                        cout << "Invalid choice! Try again." << endl;
                        break;
                }
            }
        } else {
            cout << "Invalid choice for approach!" << endl;
        }

    } else {
        cout << "Invalid account type!" << endl;
    }

    cout << "24CE115_Ishan" << endl ;
    return 0;
}
