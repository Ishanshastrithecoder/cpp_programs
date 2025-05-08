#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    vector<int> numbers;
    int n, value;

    cout << "Enter the number of elements : ";
    cin >> n;

    cout << "Enter " << n << " integers : ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        numbers.push_back(value);
    }

    set<int> uniqueNumbers(numbers.begin(), numbers.end());

    vector<int> uniqueVector(uniqueNumbers.begin(), uniqueNumbers.end());

    cout << "\nUnique elements (using set iterator) : ";
    for (auto it = uniqueNumbers.begin(); it != uniqueNumbers.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Unique elements (converted back to vector) : ";
    for (int num : uniqueVector) {
        cout << num << " ";
    }
    cout << endl;

    cout << "24CE112_CHETAN" << endl ;
    return 0;
}
