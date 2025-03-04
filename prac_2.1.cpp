#include<iostream>
using namespace std;

class Rectangle
{
    int length;
    int width;

    public:

    void setDimentions(int l,int w)
    {
        length = l;
        width = w;
    }

    int area()
    {

        int A = length*width;
        return A;
    }
    int perimeter()
    {
        int P = 2*(length+width);
        return P;
    }
};

    int main()
        {
            Rectangle o1,o2;
            o1.setDimentions(12,10);
            int A1 = o1.area();
            cout <<"Area for = "<< A1<<" squre meter"<<endl;
            int P1 = o1.perimeter();
            cout <<"perimeter = "<< P1<<" meter"<<endl;

            o2.setDimentions(12,20);
            int A2 = o2.area();
            cout <<"Area = "<< A2<<" squre meter"<<endl;
            int P2 =o2.perimeter();
            cout <<"Perimeter = "<< P2<<" meter"<<endl;
        }
