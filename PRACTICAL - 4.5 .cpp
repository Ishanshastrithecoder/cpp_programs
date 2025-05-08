#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Abstract Base Class
class GradingCriteria {
protected:
    float marks;

public:
    GradingCriteria() : marks(0) {}
    GradingCriteria(float m) : marks(m) {}

    void setMarks(float m) {
        marks = m;
    }

    float getMarks() const {
        return marks;
    }

    virtual char computeGrade() const = 0; // Pure virtual
    virtual void display() const = 0;       // For info
};

// UndergraduateStudent Class
class UndergraduateStudent : public GradingCriteria {
public:
    UndergraduateStudent() {}
    UndergraduateStudent(float m) : GradingCriteria(m) {}

    char computeGrade() const override {
        if (marks >= 90) return 'A';
        else if (marks >= 75) return 'B';
        else if (marks >= 60) return 'C';
        else return 'F';
    }

    void display() const override {
        cout << "Undergraduate - Marks : " << marks << " -> Grade : " << computeGrade() << endl;
    }
};

// PostgraduateStudent Class
class PostgraduateStudent : public GradingCriteria {
public:
    PostgraduateStudent() {}
    PostgraduateStudent(float m) : GradingCriteria(m) {}

    char computeGrade() const override {
        if (marks >= 85) return 'A';
        else if (marks >= 70) return 'B';
        else if (marks >= 60) return 'C';
        else return 'F';
    }

    void display() const override {
        cout << "Postgraduate - Marks : " << marks << " -> Grade : " << computeGrade() << endl;
    }
};

int main() {
    int choice, n;

    cout << "Choose Grading System Approach :\n";
    cout << "1. STL (std::vector)\n";
    cout << "2. Non-STL (basic array)\n";
    cout << "Enter your choice : ";
    cin >> choice;

    switch (choice) {
        case 1: {
            // STL Approach
            cout << "Enter number of students : ";
            cin >> n;

            vector<GradingCriteria*> studentVector;

            for (int i = 0; i < n; ++i) {
                int type;
                float marks;
                cout << "Student " << i + 1 << " type (1=Undergraduate, 2=Postgraduate) : ";
                cin >> type;
                cout << "Enter marks : ";
                cin >> marks;

                if (type == 1)
                    studentVector.push_back(new UndergraduateStudent(marks));
                else
                    studentVector.push_back(new PostgraduateStudent(marks));
            }

            cout << "\nGrades (STL Approach) :\n";
            for (auto s : studentVector) {
                s->display();
                delete s;
            }
            break;
        }

        case 2: {
            // Non-STL Approach
            cout << "Enter number of students : ";
            cin >> n;

            GradingCriteria** studentArray = new GradingCriteria*[n];

            for (int i = 0; i < n; ++i) {
                int type;
                float marks;
                cout << "Student " << i + 1 << " type (1=Undergraduate, 2=Postgraduate) : ";
                cin >> type;
                cout << "Enter marks : ";
                cin >> marks;

                if (type == 1)
                    studentArray[i] = new UndergraduateStudent(marks);
                else
                    studentArray[i] = new PostgraduateStudent(marks);
            }

            cout << "\nGrades (Non-STL Approach):\n";
            for (int i = 0; i < n; ++i) {
                studentArray[i]->display();
                delete studentArray[i];
            }

            delete[] studentArray;
            break;
        }

        default:
            cout << "Invalid choice. Please select 1 or 2.\n";
    }

    cout << endl << "24CE115_Ishan" << endl ;
    return 0;
}
