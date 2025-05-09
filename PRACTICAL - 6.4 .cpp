
using namespace std;

class Base {
public:
    Base() { cout << "Base constructor\n"; }

    virtual ~Base() { cout << "Base destructor\n"; }
};

class Derived : public Base {
private:
    int* data;
public:
    Derived() {
        cout << "Derived constructor\n";
        data = new int[100];
    }

    ~Derived() {
        cout << "Derived destructor\n";
        delete[] data;
    }
};

int main() {
    Base* obj = new Derived();
    delete obj;

    cout << "24CE115_Ishan" << endl ;
    return 0;
}
