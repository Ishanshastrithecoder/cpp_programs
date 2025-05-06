#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

int  main()
{

    ifstream file("data.txt");
    if(!file)
    {

        cerr<<"error :file not found !"<< endl;
        return 1;
    }
    string line;
    int linecount=0,wordcount=0,charcount=0;
    while(getline(file,line)){
        linecount++;
        charcount+=line.length();
        stringstream ss(line);
        string word;
        while(ss>>word)

        {

            wordcount++;
        }
    }
   file.close();
   cout<<"total lines :"<<linecount<<endl;
   cout<<"total character :"<<charcount<<endl;
   cout<<"total words :"<<wordcount<<endl;
   return 0;
}
