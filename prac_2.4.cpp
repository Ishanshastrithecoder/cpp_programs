#include<iostream>
using namespace std;

    class inventory_item
    {
        int i_id;
        string name;
        float price;
        int quantity;

    public:

        inventory_item()
        {
            i_id=0;
            name = "abc";
            price = 0;
            quantity =0;
        }
        inventory_item(int a,string b,float c,int d)
        {
            i_id=a;
            name = b;
            price = c;
            quantity = d;
        }
        void increase()
        {

            int a;
            cout<<"Enter the arrived new stock : "<<endl;
            cin>>a;
            quantity+=a;
            cout<<"Available stock now : "<<quantity<<endl;
        }
        void decrease()
        {
            int b;
            cout<<"Enter the sold stock : "<<endl;
            cin>>b;
            if(quantity<b)
            {
                cout<<"Not enough stock!";
            }
            else
            {
                 quantity-=b;
            cout<<"Available stock now: "<<quantity<<endl;
            }

        }

         void displayDetails()
         {
             cout<<"item id is: "<<i_id<<endl<<"item name: "<<name<<endl<<"item price: "<<price<<endl<<"item quantity: "<<quantity<<endl;
         }
    };


         int main()
    {
        inventory_item a1[4];
        a1[0] = inventory_item(46456,"book",135.55,140);
         a1[1] = inventory_item(4456,"send",185.55,10);
          a1[2] = inventory_item(4646,"light",195.55,150);
           a1[3] = inventory_item(6456,"paper",165.55,100);
       for(int i=0;i<=3;i++)
       {
        a1[i].increase();
        a1[i].decrease();
        a1[i].displayDetails();
       }

    }
