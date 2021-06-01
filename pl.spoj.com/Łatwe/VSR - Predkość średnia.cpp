#include<iostream> // AC
#include<cstdio>
using namespace std;
int main()
{
    int t;
    int a,b;
    cin>>t;
    for(int r=0; r<t; r++)
    {
            cin>>a>>b;
            cout<<(2*a*b)/(a+b)<<endl;
    }
    getchar();
    //system("pause");
    return 0;
}

