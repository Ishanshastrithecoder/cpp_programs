#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void addFolder(map<string, vector<string>> &directory) {
    string folderName;
    cout << "Enter folder name : ";
    cin >> folderName;
    
    if (directory.find(folderName) == directory.end()) {
        directory[folderName] = {}; // Create empty folder
        cout << "Folder '" << folderName << "' added successfully!\n";
    } else {
        cout << "Folder '" << folderName << "' already exists!\n";
    }
}

void addFile(map<string, vector<string>> &directory) {
    string folderName, fileName;
    cout << "Enter folder name : ";
    cin >> folderName;

    if (directory.find(folderName) == directory.end()) {
        cout << "Folder '" << folderName << "' does not exist. Please add the folder first.\n";
        return;
    }

    cout << "Enter file name : ";
    cin >> fileName;
    directory[folderName].push_back(fileName);
    cout << "File '" << fileName << "' added to folder '" << folderName << "' successfully!\n";
}

void displayDirectory(const map<string, vector<string>> &directory) {
    if (directory.empty()) {
        cout << "No folders available.\n";
        return;
    }

    cout << "\n--- Directory Structure ---\n";
    for (const auto &folder : directory) {
        cout << "Folder : " << folder.first << "\n";
        if (folder.second.empty()) {
            cout << "  [No files]\n";
        } else {
            cout << " Files : ";
            for (const auto &file : folder.second) {
                cout << file << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    map<string, vector<string>> directory;
    int choice;

    do {
        cout << "\nDirectory Management System\n";
        cout << "1. Add Folder\n";
        cout << "2. Add File to Folder\n";
        cout << "3. Display Directory\n";
        cout << "4. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1: addFolder(directory); break;
            case 2: addFile(directory); break;
            case 3: displayDirectory(directory); break;
            case 4: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    cout << "24CE112_CHETAN" << endl ;
    return 0;
}
