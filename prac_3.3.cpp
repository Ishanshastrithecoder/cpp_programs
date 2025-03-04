#include<iostream>
#include<map>
using namespace std;

class bank
{
    //AN = account number  AHN=account holder name
    int AN;
    string AHN;
    double balance;
    static int account;

public:

    bank()
    {
        AN = 0;
        AHN = "NA";
        balance = 0;
        account =0;
    }

    bank(int a,string b,double c)
    {
        AN = a;
        AHN = b;
        balance = c;
        //account = d;
    }
    void get()
    {
        cin>>AN>>AHN>>balance>>account;
    }
    void disp()
    {
        cout<<"Account number: "<<AN<<endl;
        cout<<"Account holder's name : "<<AHN<<endl;
        cout<<"current balance : "<<balance<<endl;
    }
    void withdraw()
    {
        double w_amount;
        cout<<"Enter the withdrawal amount :";
        cin>>w_amount;
        balance = balance - w_amount;
        cout<<endl<<"current balance :"<<balance;
    }

    void deposite()
    {
        double dep_amount;
        cout<<"Enter the deposite amount :";
        cin>>dep_amount;
        balance = balance + dep_amount;
        cout<<endl<<"current balance :"<<balance;
    }
    static void total_account()
    {
        account++;
    }
    friend void transfer(bank &from,bank &to,double bal);
};
    int bank::account = 0;

    void transfer(bank &from,bank &to,double bal)
    {
        if(from.withdraw())
        {
            to.deposite();
        }
        else
        {
            cout<<"there is some error in money-transfer";
        }
    }

    int main()
    {
        map<int,bank>M;
        int a,ta;
        string b;
        double c;

        cout<<"enter the number of total account:";
        cin>>ta;

        for(int j=0;j<ta;j++)
        {
            cout << "Enter account number: ";
            cin >> a;
            cout << "Enter account holder's name: ";
            cin >> b;
            cout << "Enter the current balance: ";
            cin >> c;

            M[a]=bank(a,b,c);
        }

        for(auto& i:M)
        {
            i.second.disp();
        }

        int from,to;
        double amt;
        cout<<"Enter the transfer's account num :"<<endl;
        cin>>from;
        cout<<"Enter the recipient's account num :"<<endl;
        cin>>to;
        cout<<"Enter the amount :"<<endl;
        cin>>amt;

        for(auto& i:M)
        {
            i.second.disp();
        }
    }
