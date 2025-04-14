#include <iostream>
#define PI 3.14159
using namespace std;

class Shape {
protected:
    float radius;
public:
    void setRadius(float r) {
        radius = r;
    }

    float getRadius() const {
        return radius;
    }
};

class Circle : public Shape {
public:
    float area() const {
        return PI * radius * radius;
    }

    void display(int index) const {
        cout << "Circle " << index + 1 << ":\n";
        cout << "Radius: " << radius << endl;
        cout << "Area: " << area() << endl << endl;
    }
};

int main() {
    int n;

    cout << "Enter the number of circles: ";
    cin >> n;

    cout << "\n--- Static Array Approach ---\n";
    Circle staticCircles[100]; // assuming max 100 for simplicity

    for (int i = 0; i < n; i++) {
        float r;
        cout << "Enter radius for circle " << i + 1 << ": ";
        cin >> r;
        staticCircles[i].setRadius(r);
    }

    for (int i = 0; i < n; i++) {
        staticCircles[i].display(i);
    }

    cout << "\n--- Dynamic Array Approach ---\n";
    Circle* dynamicCircles = new Circle[n];

    for (int i = 0; i < n; i++) {
        float r;
        cout << "Enter radius for circle " << i + 1 << ": ";
        cin >> r;
        dynamicCircles[i].setRadius(r);
    }

    for (int i = 0; i < n; i++) {
        dynamicCircles[i].display(i);
    }

    delete[] dynamicCircles;
    return 0;
}
