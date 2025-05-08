#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    string paragraph;
    cout << "Enter a paragraph:" << endl;
    getline(cin, paragraph);

    int capacity = 10;
    int size = 0;
    string* words = new string[capacity];
    int* frequencies = new int[capacity];



    stringstream ss(paragraph);
    string word;

    while (ss >> word) {

        word.erase(remove_if(word.begin(), word.end(), [](char c) {
            return !isalpha(c);
        }), word.end());

        if (!word.empty()) {

            transform(word.begin(), word.end(), word.begin(), ::tolower);


            bool found = false;
            for (int i = 0; i < size; ++i) {
                if (words[i] == word) {

                    frequencies[i]++;
                    found = true;
                    break;
                }
            }

            if (!found) {

                if (size == capacity) {

                    capacity *= 2;
                    string* newWords = new string[capacity];
                    int* newFrequencies = new int[capacity];

                    for (int i = 0; i < size; ++i) {
                        newWords[i] = words[i];
                        newFrequencies[i] = frequencies[i];
                    }

                    delete[] words;
                    delete[] frequencies;

                    words = newWords;
                    frequencies = newFrequencies;
                }

                words[size] = word;
                frequencies[size] = 1;
                size++;
            }
        }
    }


    cout << "Word frequencies:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << words[i] << ": " << frequencies[i] << endl;
    }


    delete[] words;
    delete[] frequencies;
cout<<"24ce115_Ishan";
    return 0;
}
