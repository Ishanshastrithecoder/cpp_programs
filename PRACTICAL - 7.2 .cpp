#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstring>
#include <cctype>
using namespace std;

// STL Approach
void stlApproach(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error: File could not be opened.\n";
        return;
    }

    vector<string> lines;
    string line;
    int totalChars = 0, totalWords = 0, totalLines = 0;

    while (getline(file, line))
    {
        lines.push_back(line);
        totalChars += line.length(); // doesn't include newline
        totalLines++;

        istringstream iss(line);
        string word;
        while (iss >> word)
        {
            totalWords++;
        }
    }

    file.close();

    cout << "\nSTL Approach\n";
    cout << "Total Lines : " << totalLines << endl;
    cout << "Total Words : " << totalWords << endl;
    cout << "Total Characters : " << totalChars << endl;
}

//  Non-STL Approach
void nonStlApproach(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        cerr << "Error : File could not be opened.\n";
        return;
    }

    const int MAX_LINE = 1024;
    char line[MAX_LINE];
    int totalChars = 0, totalWords = 0, totalLines = 0;

    while (fgets(line, MAX_LINE, file))
    {
        totalLines++;
        totalChars += strlen(line); // includes newline

        bool inWord = false;
        for (int i = 0; line[i]; i++)
        {
            if (isspace(line[i]))
            {
                inWord = false;
            }
            else if (!inWord)
            {
                inWord = true;
                totalWords++;
            }
        }
    }

    fclose(file);

    cout << "\nNon-STL Approach\n";
    cout << "Total Lines : " << totalLines << endl;
    cout << "Total Words : " << totalWords << endl;
    cout << "Total Characters : " << totalChars << endl;
}

int main()
{
    string filename;
    cout << "Enter the filename : ";
    cin >> filename;

    int choice;
    cout << "\nChoose approach :\n";
    cout << "1. STL Approach\n";
    cout << "2. Non-STL Approach\n";
    cout << "Enter your choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        stlApproach(filename);
        break;
    case 2:
        nonStlApproach(filename.c_str());
        break;
    default:
        cout << "Invalid choice.\n";
    }

    cout << "24CE115_Ishan" << endl ;
    return 0;
}
