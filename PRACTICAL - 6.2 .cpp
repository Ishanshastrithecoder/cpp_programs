#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}
    Point* move(int dx, int dy) {
        x += dx;
        y += dy;
        return this;
    }

    void display() const {
        cout << "Point ( " << x << " , " << y << " )" << endl;
    }
};

int main() {
    int x, y;
    cout << "Enter the initial x and y: ";
    cin >> x >> y;

    Point* p = new Point(x, y);

    cout << "Initial Position: ";
    p->display();

    int movements;
    cout << "Enter number of movements: ";
    cin >> movements;

    for (int i = 0; i < movements; ++i) {
        int dx, dy;
        cout << "Enter shift in x and y: ";
        cin >> dx >> dy;
        p->move(dx, dy);
    }

    cout << "After Movements: ";
    p->display();

    delete p;

    cout << "24CE112_CHETAN" << endl ;
    return 0;
}