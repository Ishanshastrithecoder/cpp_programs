#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    DynamicArray(int cap = 4) : size(0), capacity(cap) {
        data = new int[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void insert(int value) {
        if (size == capacity) {
            resize();
        }
        data[size++] = value;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index!\n";
            return;
        }
        cout << "Element which deleted: " << data[index] << endl;
        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }

    int get(int index) const {
        if (index < 0 || index >= size) {
            cout << "Invalid index!\n";
            return -1;
        }
        return data[index];
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray arr;
    arr.insert(10);
    arr.insert(20);
    arr.insert(30);
    arr.insert(40);

    cout << "Array contents: ";
    arr.display();

    arr.insert(10);
    arr.insert(20);
    arr.insert(30);

    cout << "Array contents: ";
    arr.display();

    arr.remove(1);

    cout << "After deletion: ";
    arr.display();

    cout << "24CE115_Ishan" << endl ;
    return 0;
}
