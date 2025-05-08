#include <iostream>
#include <vector>
#include <algorithm> // For std::reverse

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

    // Using std::reverse()
    vector<int> reversedNumbers = numbers;
    reverse(reversedNumbers.begin(), reversedNumbers.end());

    cout << "\nReversed using std::reverse() : ";
    for (int num : reversedNumbers) {
        cout << num << " ";
    }
    cout << endl << endl ;

    // Manual reversal using iterators
    cout << "Reversed manually using iterators : ";
    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl << endl ;

    cout << "24CE112_CHETAN" << endl ;
    return 0;
}
