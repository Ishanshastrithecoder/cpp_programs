#include<iostream>
using namespace std;

class Student
{
    int r_num;
    string name;
    int marks[3];

    public:

    Student()
    {
        r_num = 0;
        name = "N/A";
       marks[1]=0;
       marks[2]=0;
       marks[3]=0;

    }

    Student(int a,string b)
    {
        r_num = a;
        name = b;

    }
    void input()
    {
        cout<<"enter marks:";
        for(int i=0;i<=2;i++)
        {
            cin>>marks[i];
        }
    }
    void displayDetails()
    {
        cout<<"roll number = "<<r_num<<endl;
        cout<<"name = "<<name<<endl;
      /*  for(int i=0;i<=2;i++)
        {
            cout<<"marks of "<<i+1<<"= "<<marks[i]<<endl;
        }*/
    }
    float avg()
    {
        int sum = 0;
        for(int i=0;i<=2;i++)
        {
            sum = sum + marks[i];
        }
        int avg = sum/3;
        cout<<"avg marks= "<<avg;
    }

};

    int main()
    {
        Student s1;
        s1.displayDetails();
        Student s2(101,"ishan");
        s2.input();
        s2.avg();
    cout<<"24ce115_Ishan";
    }

