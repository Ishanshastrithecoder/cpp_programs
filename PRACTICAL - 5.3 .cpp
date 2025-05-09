#include <iostream>
#include <vector> // For STL vector
using namespace std;

// Define Point class
class Point {
private:
    int x, y;

public:
    // Constructor
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Overload unary - operator
    Point operator-() const {
        return Point(-x, -y);
    }

    // Overload binary + operator
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    // Overload == operator
    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }

    // Input point
    void input() {
        cout << "Enter x-coordinate : ";
        cin >> x;
        cout << "Enter y-coordinate : ";
        cin >> y;
    }

    // Display point
    void display() const {
        cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    int choice;
    cout << "Choose Approach :\n";
    cout << "1. STL Approach (using vector)\n";
    cout << "2. Non-STL Approach (using array)\n";
    cout << "Enter your choice : ";
    cin >> choice;

    switch (choice) {
    case 1: {
        cout << "\nSTL Approach :\n";

        vector<Point> points(2); // Size 2
        for (int i = 0; i < 2; ++i) {
            cout << "Input for Point " << i + 1 << " :\n";
            points[i].input();
        }

        // 1. Negate both points
        cout << "\nNegation of Point 1 : ";
        (-points[0]).display();

        cout << "\nNegation of Point 2 : ";
        (-points[1]).display();

        // 2. Add both points
        Point sum = points[0] + points[1];
        cout << "\n\nSum of Point 1 and Point 2 : ";
        sum.display();

        // 3. Check equality
        if (points[0] == points[1])
            cout << "\n\nPoints are EQUAL.\n";
        else
            cout << "\n\nPoints are NOT EQUAL.\n";

        break;
    }

    case 2: {
        cout << "\nNon-STL Approach :\n";

        Point points[2]; // Simple array
        for (int i = 0; i < 2; ++i) {
            cout << "Input for Point " << i + 1 << " :\n";
            points[i].input();
        }

        // 1. Negate both points
        cout << "\nNegation of Point 1 : ";
        (-points[0]).display();

        cout << "\nNegation of Point 2 : ";
        (-points[1]).display();

        // 2. Add both points
        Point sum = points[0] + points[1];
        cout << "\n\nSum of Point 1 and Point 2 : ";
        sum.display();

        // 3. Check equality
        if (points[0] == points[1])
            cout << "\n\nPoints are EQUAL.\n";
        else
            cout << "\n\nPoints are NOT EQUAL.\n";

        break;
    }
    default:
        cout << "Invalid choice. Please run the program again.\n";
    }

    cout << "\n24CE115_ishan" << endl ;
    return 0;
}
