#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

// Structure to store student data
struct Student {
    string name;
    int marks;
    char grade;
};

// User-defined manipulator for formatting table columns
ostream& format(ostream& os) {
    os << left << setw(15);
    return os;
}

// Function to add a new student to the file
void addStudent(const string& name, int marks, char grade) {
    ofstream file("students", ios::app);
    if (file) {
        file << name << "," << marks << "," << grade << endl;
        cout << "Student added successfully!" << endl;
    } else {
        cerr << "Error: Unable to write to file!" << endl;
    }
    file.close();
}

// STL Approach: Load student data into a vector
vector<Student> loadStudents() {
    vector<Student> students;
    ifstream file("students");
    string line;

    if (!file) {
        cerr << "Error: Unable to open file!" << endl;
        return students;
    }

    while (getline(file, line)) {
        stringstream ss(line);
        Student s;
        getline(ss, s.name, ',');
        ss >> s.marks;
        ss.ignore();
        ss >> s.grade;
        students.push_back(s);
    }

    file.close();
    return students;
}

// STL Approach: Display formatted student report
void viewStudentsSTL() {
    vector<Student> students = loadStudents();

    cout << format << "Name" << format << "Marks" << format << "Grade" << endl;
    cout << "-------------------------------------" << endl;

    for (const auto& student : students) {
        cout << format << student.name << format << student.marks << format << student.grade << endl;
    }
}

// Non-STL Approach: Read and format data directly from the file
void viewStudentsNonSTL() {
    ifstream file("students");
    string line;

    if (!file) {
        cerr << "Error: Unable to open file!" << endl;
        return;
    }

    cout << format << "Name" << format << "Marks" << format << "Grade" << endl;
    cout << "-------------------------------------" << endl;

    while (getline(file, line)) {
        stringstream ss(line);
        Student s;
        getline(ss, s.name, ',');
        ss >> s.marks;
        ss.ignore();
        ss >> s.grade;

        cout << format << s.name << format << s.marks << format << s.grade << endl;
    }

    file.close();
}

// STL Approach: Search for a student
void searchStudentSTL() {
    vector<Student> students = loadStudents();
    string searchName;
    cout << "Enter student name to search : ";
    cin >> searchName;

    bool found = false;
    for (const auto& student : students) {
        if (student.name == searchName) {
            cout << "Found : " << student.name << ", Marks : " << student.marks << ", Grade : " << student.grade << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found!" << endl;
    }
}

// Non-STL Approach: Search for a student directly from the file
void searchStudentNonSTL() {
    ifstream file("students");
    string line;
    string searchName;
    bool found = false;

    cout << "Enter student name to search : ";
    cin >> searchName;

    while (getline(file, line)) {
        stringstream ss(line);
        Student s;
        getline(ss, s.name, ',');
        ss >> s.marks;
        ss.ignore();
        ss >> s.grade;

        if (s.name == searchName) {
            cout << "Found : " << s.name << ", Marks : " << s.marks << ", Grade : " << s.grade << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found!" << endl;
    }

    file.close();
}

// Main function with STL/Non-STL choice & menu-driven system
int main() {
    int approachChoice;
    cout << "Choose an approach:\n";
    cout << "1. Non-STL Approach\n";
    cout << "2. STL Approach\n";
    cout << "Enter your choice : ";
    cin >> approachChoice;

    int operationChoice;
    do {
        cout << "\nStudent Management System Menu:\n";
        cout << "1. Add Student\n";
        cout << "2. View Student Report\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice : ";
        cin >> operationChoice;

        switch (operationChoice) {
            case 1: {
                string name;
                int marks;
                char grade;
                cout << "Enter name, marks, grade: ";
                cin >> name >> marks >> grade;
                addStudent(name, marks, grade);
                break;
            }
            case 2:
                (approachChoice == 1) ? viewStudentsNonSTL() : viewStudentsSTL();
                break;
            case 3:
                (approachChoice == 1) ? searchStudentNonSTL() : searchStudentSTL();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (operationChoice != 4);

    cout << "24CE112_CHETAN" << endl ;
    return 0;
}
