#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Base class
class Shape {
public:
    virtual double Area() const = 0; // pure virtual function
    virtual void display() const = 0; // display info
    virtual ~Shape() {} // Virtual destructor
};

// Derived class: Rectangle
class Rectangle : public Shape {
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double Area() const override {
        return length * width;
    }

    void display() const override {
        cout << "Rectangle | Length : " << length << " | Width : " << width;
    }
};

// Derived class: Circle
class Circle : public Shape {
    double radius;

public:
    Circle(double r) : radius(r) {}

    double Area() const override {
        return M_PI * radius * radius;
    }

    void display() const override {
        cout << "Circle | Radius : " << radius;
    }
};

int main() {
    int storageChoice;
    cout << "Choose storage approach:\n";
    cout << "1. STL Vector\n";
    cout << "2. Non-STL Array\n";
    cout << "Enter your choice : ";
    cin >> storageChoice;

    int n;
    cout << "Enter the number of shapes : ";
    cin >> n;

    switch (storageChoice) {
    case 1: { // STL Vector approach
        vector<Shape*> shapes;

        for (int i = 0; i < n; ++i) {
            int type;
            cout << "\nShape " << i + 1 << ":\n";
            cout << "1. Rectangle\n2. Circle\nEnter shape type : ";
            cin >> type;

            if (type == 1) {
                double l, w;
                cout << "Enter length and width : ";
                cin >> l >> w;
                shapes.push_back(new Rectangle(l, w));
            } else if (type == 2) {
                double r;
                cout << "Enter radius : ";
                cin >> r;
                shapes.push_back(new Circle(r));
            } else {
                cout << "Invalid type!\n";
                --i; // Retry this shape
            }
        }

        cout << "\n--- Areas of Shapes (STL Vector) ---\n";
        for (auto shape : shapes) {
            shape->display();
            cout << " | Area: " << shape->Area() << endl;
        }

        // Free memory
        for (auto shape : shapes) {
            delete shape;
        }
        shapes.clear();
        break;
    }

    case 2: { // Non-STL Array approach
        Shape** shapes = new Shape*[n];

        for (int i = 0; i < n; ++i) {
            int type;
            cout << "\nShape " << i + 1 << ":\n";
            cout << "1. Rectangle\n2. Circle\nEnter shape type : ";
            cin >> type;

            if (type == 1) {
                double l, w;
                cout << "Enter length and width : ";
                cin >> l >> w;
                shapes[i] = new Rectangle(l, w);
            } else if (type == 2) {
                double r;
                cout << "Enter radius : ";
                cin >> r;
                shapes[i] = new Circle(r);
            } else {
                cout << "Invalid type!\n";
                --i; // Retry this shape
            }
        }

        cout << "\n--- Areas of Shapes (Non-STL Array) ---\n";
        for (int i = 0; i < n; ++i) {
            shapes[i]->display();
            cout << " | Area: " << shapes[i]->Area() << endl;
        }

        // Free memory
        for (int i = 0; i < n; ++i) {
            delete shapes[i];
        }
        delete[] shapes;
        break;
    }

    default:
        cout << "Invalid choice!\n";
    }

    cout << "24CE115_Ishan" << endl;
    return 0;
}
