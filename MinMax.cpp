#include<iostream>
using namespace std;

int main ()
{
    int v[8]= {-1, 8, -3, -1, 2, 1, -3, 4,};

    int d= max(v[0], v[1]);
    int e= max(v[2], v[3]);
    int f= max(v[4], v[5]);
    int g= max(v[6], v[7]);

    int b= min(d,e);
    int c= min(f, g);

    int a=max(b,c);

    cout<<"Utility = " <<a<<endl;

    if (a==b)
        cout <<"Path: A-> B-> ";
    else
        cout<< "Path: A-> C-> ";

    if (a==b)
    {
        if (b==d)
            cout<<"D-> " <<d <<endl;
        else
            cout<<"E-> " <<e <<endl;
    }
    else
    {
        if(c==f)
            cout<<"F-> " << f<<endl;
        else
            cout<<"G-> " <<g<<endl;
    }

    return 0;

}
