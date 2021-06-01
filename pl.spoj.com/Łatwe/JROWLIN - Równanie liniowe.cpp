#include<iostream> // AC
#include<iomanip>
#include<cstdio>
using namespace std;
int main()
{
    double a,b,c;
    cin>>a>>b>>c;
    if(a==0)
    {
            if(b==c)
            {
                    cout<<"NWR"<<endl;
            }
            else
            {
                cout<<"BR"<<endl;
            }
    }
    else
    {
        cout<<fixed<<setprecision(2)<<(c-b)/a<<endl;
    }
    getchar();
    //system("pause");
    return 0;
}
     

