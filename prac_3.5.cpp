
 #include <iostream>
#include <string>

using namespace std;


int superDigit(long long n) {
    if (n < 10) return n;

    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return superDigit(sum);
}


int computeSuperDigit(string n, int k) {
    long long digitSum = 0;

  
    for (char c : n) {
        digitSum += c - '0';
    }

    long long total = digitSum * k;

    
    return superDigit(total);
}

int main() {
    string n = "9875";
    int k = 4;

    cout << computeSuperDigit(n, k) << endl;  // Output: 8

    return 0;
}
