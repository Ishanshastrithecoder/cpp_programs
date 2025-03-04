#include<iostream>
#include<string>
using namespace std;
int st(string n,int k)
{
    if(n.length()==1)
    {
        return n[0]-'0';
    }

    string mer="";
    for(int i=0;i<k;i++)
    {
       mer=mer+n;
    }
    cout<<mer;

 long long p;
    while(mer.length()!=1)
    {
        for(char i:mer)
        {

            p=p+i-'0';
        }
    }
    return p;

}




int main()
{
    string n;
    int k;
    cout<<"enter the string:";
    cin>>n;
    cout<<endl;
    cout<<"enter the multiplying number:";
    cin>>k;
    cout<<endl<<st(n,k);
}
