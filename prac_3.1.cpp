#include <iostream>
#include <vector>
using namespace std;

class employee {
    string name;
    float basic;
    float bonus;
    int id;

public:
    employee() {
        name = "abc";
        basic = 15000;
        bonus = 500;
        id = 1;
    }

    employee(string a, float b, float c, int ID) {
        name = a;
        basic = b;
        bonus = c;
        id = ID;
    }

    inline void t_salary() {
        float total_s = basic + bonus;
        cout << "Total salary: " << total_s << endl;
    }

    void display() {
        cout << "\nName of employee: " << name << endl;
        cout << "Employee ID number: " << id << endl;
        cout << "Basic salary of the employee: " << basic << endl;
        cout << "Bonus for the employee: " << bonus << endl;
        t_salary();
    }
};

int main() {
    vector<employee> a;
    int n;

    cout << "Enter the number of employees: ";
    cin >> n;

    string name;
    int EMP_id;
    float salary;
    float bonus;

    for (int j = 0; j < n; j++) {
        cout << "\nFor employee " << j + 1 << ":" << endl;
        cout << "Enter name: ";
        cin >> ws;            
        getline(cin, name);  
        cout << "Enter employee ID: ";
        cin >> EMP_id;

        cout << "Enter basic salary: ";
        cin >> salary;

        cout << "Enter bonus: ";
        cin >> bonus;

        a.push_back(employee(name, salary, bonus, EMP_id));
    }

    for (auto& i : a) {
        i.display();
    }

    return 0;
}
