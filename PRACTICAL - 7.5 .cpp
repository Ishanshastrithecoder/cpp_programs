#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

ostream& currency(ostream& os) {
    return os << "₹"; 
}

int main() {
    ifstream inputFile("student"); 
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return 1; 
    }

    string line, name;
    int score;
    double fee;

    cout << left << setw(14) << "Name" << setw(13) << "Score" << setw(12) << "Fees" << endl;
    cout << setfill('-') << setw(37) << "-" << setfill(' ') << endl;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        getline(ss, name, ','); 
        ss >> score;
        ss.ignore(); 
        ss >> fee; 

        cout << left << setw(15) << name 
             << setw(10) << score 
             << currency << setw(10) << fixed << setprecision(2) << fee 
             << endl;
    }

    inputFile.close(); 
    
    cout << "24CE115_Ishan" << endl ;
    return 0;
}
