#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


template<typename T>
T findmax(const vector<T>& vec) {
    T maxvalue = vec[0];
    for (const auto& elem : vec) {
        if (elem > maxvalue) {
            maxvalue = elem;
        }
    }
    return maxvalue;
}

template <typename T>
void reversevector(vector<T>& vec) {
    reverse(vec.begin(), vec.end());
}


template <typename T>
void printvector(const vector<T>& vec) {
    for (const auto& elem : vec) {
        cout << elem << " ";
    }
    cout << endl;
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5}; // vector declaration
    cout << "The vector elements are: ";
    printvector(vec);
    cout << "Max value of the array is: " << findmax(vec) << endl;
    reversevector(vec);
    cout << "Reverse of array is: ";
    printvector(vec);

    vector<float> fvec = {1.8, 2.6, 3.9, 4.5, 5.6};
    cout << "\nThe vector elements are: ";
    printvector(fvec);
    cout << "Max value of the array is: " << findmax(fvec) << endl;
    reversevector(fvec);
    cout << "Reverse of array is: ";
    printvector(fvec);

    vector<char> cvec = {'a', 'b', 'c'};
    cout << "\nThe vector elements are: ";
    printvector(cvec);
    cout << "Max value of the array is: " << findmax(cvec) << endl;
    reversevector(cvec);
    cout << "Reverse of array is: ";
    printvector(cvec);

    return 0;
}
