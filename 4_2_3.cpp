#include <iostream>
#include <vector>
#include <string>
using namespace std;

class basic {
public:
    string name;
    int age;

    basic(string names, int AGE) {
        name = names;
        age = AGE;
    }
};

class employee : public basic {
public:
    int ID;

    employee(string names, int AGE, int id) : basic(names, AGE) {
        ID = id;
    }
};

class managers : public employee {
public:
    string department;

    managers(string names, int AGE, int id, string depart)
        : employee(names, AGE, id) {
        department = depart;
    }
};

int main() {
    vector<managers> managerList;
    int numberOfManagers;


    cout << "Enter the number of managers: ";
    cin >> numberOfManagers;
    cin.ignore();

    for (int i = 0; i < numberOfManagers; ++i) {
        string name, department;
        int age, ID;


        cout << "\nEnter details for manager " << (i + 1) << ":\n";

        cout << "Name: ";
        getline(cin, name);
        cout << "Age: ";
        cin >> age;

        cout << "ID: ";
        cin >> ID;

        cin.ignore();

        cout << "Department: ";
        getline(cin, department);


        managerList.push_back(managers(name, age, ID, department));
    }


    cout << "\nDetails of all managers:\n";
    for (const auto& m : managerList) {
        cout << "\nName: " << m.name << endl;
        cout << "Age: " << m.age << endl;
        cout << "ID: " << m.ID << endl;
        cout << "Department: " << m.department << endl;
        cout << "-----------------------" << endl;
    }

    return 0;
}

