#include <iostream>
using namespace std;

int recursiveSum(int arr[], int size) {
    if (size == 0)
        return 0;
    return arr[size - 1] + recursiveSum(arr, size - 1);
}

int iterativeSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int sumRecursive = recursiveSum(arr, size);
    int sumIterative = iterativeSum(arr, size);

    cout << "\nSum using recursion: " << sumRecursive << endl;
    cout << "Sum using iteration: " << sumIterative << endl;

    delete[] arr;

    return 0;
}
