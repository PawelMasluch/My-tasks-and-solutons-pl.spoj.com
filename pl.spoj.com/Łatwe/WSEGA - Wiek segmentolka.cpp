#include<iostream> // AC
using namespace std;
int main()
{
    int t;
    cin>>t;
    unsigned long long int x=0;
    int n,a;
    for(int r=0; r<t; r++)
    {
    cin>>n;
    for(int i=0; i<n; i++)
    {
            cin>>a;
            x=x+a;
    }
    cout<<(x+n)-1<<endl;
    x=0;
    }
    /*getchar();
    system("pause");*/
    return 0;
}

