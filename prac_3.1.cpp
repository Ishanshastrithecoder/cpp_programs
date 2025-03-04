
#include<iostream>
#include<vector>
using namespace std;

class employee
{
    string name;
    float basic;
    float bonus;

public:
    employee()
    {
        name = "abc";
        basic = 15000;
        bonus = 500;
    }
    employee(string a,float b,float c=500)
    {
        name = a;
        basic = b;
        bonus = c;
    }
    void get()
    {

    }
    inline void t_salary()
    {
        float total_s = basic + bonus;
        cout<<"total salary :"<<total_s<<endl;
    }
    void display()
    {
        cout<<"Name of employee :"<<name<<endl;
        cout<<"Basic salary of the employee :"<<basic<<endl;
        cout<<"Bonus for the employee :"<<bonus<<endl;
        t_salary();
    }
};

    int main()
    {
        /*employee A[4] = {employee(),
                            employee("kunj",15000,500),
                            employee("milan",20000,1000),
                            employee("kunj",15000,1500)};

        for(int i=0;i<=3;i++)
        {
            A[i].display();
            A[i].t_salary();
        }*/

        vector<employee> a;
       /* a.push_back(employee("kunj",15000,500));
        a.push_back(employee("milan",15000,500));
        a.push_back(employee("brij",15000,1500));

        for(auto& i:a)
        {
            i.display();
        }*/


        int n;
        cin>>n;
        string e;
        float b;
        float c;

        for(int j=0;j<n;j++)
        {
            cin>>e>>b>>c;
            a.push_back(employee(e,b,c));

        }

        for(auto& i:a)
        {
            i.display();
        }
    }
