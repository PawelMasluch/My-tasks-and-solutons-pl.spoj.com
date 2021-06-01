#include<iostream> // AC
using namespace std;
int main()
{
    int t;
    cin>>t;
    unsigned long long int x=0;
    long int a;
    int n;
    unsigned long long int m;
    for(int r=0; r<t; r++)
    {
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
            cin>>a;
            x=x+(86400/a);
    }
    if(x%m==0)
    {
              cout<<x/m<<endl;
    }
    else
    {
        cout<<((x-(x%m))/m)+1<<endl;
    }
    x=0;
    }
    /*getchar();
    system("pause");*/
    return 0;
}
              

