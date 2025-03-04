#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<typename T>
void disp(const vector<T>v)
{
    for(auto& i:v)
    {
        cout<< i;
    }
}

template<typename T>
T max(const vector<T>v)
{
    return *max_element(v.begin(),v.end());
}

template<typename T>
void rev(vector<T>v)
{
    reverse(v.begin(),v.end());
    for(auto& i:v)
    {
        cout<<i;
    }
}

int main()
{
   /* vector<int>iv={1,2,3,4,5};
    disp(iv);
    cout<<endl<<max(iv)<<endl;
    rev(iv);
    cout<<endl;

    vector<char>ic={'a','b','c','d','e'};
    disp(ic);
    cout<<endl<<max(ic)<<endl;
    rev(ic);
    cout<<endl;

     vector<float>ifl={1.50,2.30,3.40,4.50,5.60};
    disp(ifl);
    cout<<endl<<max(ifl)<<endl;
    rev(ifl);*/


    int n;
    cout<<"enter the number of elements:";
    cin>>n;
    vector<int>iv(n);
    for(int j=0;j<n;j++)
    {
       cin>>iv[j];
    }
    disp(iv);
    cout<<endl<<max(iv)<<endl;
    rev(iv);
    cout<<endl;

    int k;
    cout<<"enter the number of elements for string:";
    cin>>k;
    vector<char>ic(k);
    for(int j=0;j<k;j++)
    {
       cin>>ic[j];
    }
    disp(ic);
    cout<<endl<<max(ic)<<endl;
    rev(ic);
    cout<<endl;

   /* double w;
    cout<<"enter the number of elements for double:";
    cin>>w;
    vector<double>id(w);
    for(int j=0;j<w;j++)
    {
       cin>>id[w];
    }
    disp(id);
    cout<<endl<<max(id)<<endl;
    rev(id);
    cout<<endl;*/
}
