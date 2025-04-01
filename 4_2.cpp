#include <iostream>
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

    managers m("John Doe", 30, 1234, "Engineering");

    cout << "Name: " << m.name << endl;
    cout << "Age: " << m.age << endl;
    cout << "ID: " << m.ID << endl;
    cout << "Department: " << m.department << endl;

    return 0;
}
