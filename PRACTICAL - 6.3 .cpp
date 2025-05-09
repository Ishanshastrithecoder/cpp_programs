#include <iostream>

using namespace std;

void merge_sorted_arrays(int* arr1, int m, int* arr2, int n, int*& merged_arr, int& merged_size) {
    merged_size = m + n;
    merged_arr = new int[merged_size];
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            merged_arr[k++] = arr1[i++];
        } else {
            merged_arr[k++] = arr2[j++];
        }
    }

    while (i < m) {
        merged_arr[k++] = arr1[i++];
    }

    while (j < n) {
        merged_arr[k++] = arr2[j++];
    }
}

int main() {
    int m, n;

    cout << "Enter size of first sorted array : ";
    cin >> m;
    int* arr1 = new int[m];

    cout << "Enter " << m << " elements (sorted) : ";
    for (int i = 0; i < m; ++i) {
        cin >> arr1[i];
    }

    cout << "Enter size of second sorted array : ";
    cin >> n;
    int* arr2 = new int[n];

    cout << "Enter " << n << " elements (sorted): ";
    for (int i = 0; i < n; ++i) {
        cin >> arr2[i];
    }

    int* merged_arr;
    int merged_size;

    merge_sorted_arrays(arr1, m, arr2, n, merged_arr, merged_size);

    cout << "Merged Sorted Array: ";
    for (int i = 0; i < merged_size; ++i) {
        cout << merged_arr[i] << " ";
    }
    cout << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] merged_arr;

    cout << "24CE115_Ishan" << endl ;
    return 0;
}
