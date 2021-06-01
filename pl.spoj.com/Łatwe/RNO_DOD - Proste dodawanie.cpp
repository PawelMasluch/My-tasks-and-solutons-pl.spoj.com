#include<iostream> // AC
using namespace std;
int main()
{
    int t,n,x=0,a;
    cin>>t;
    for(int i=0; i<t; i++)
    {
            cin>>n;
            for(int k=0; k<n; k++)
            {
                    cin>>a;
                    x=x+a;
            }
                    cout<<x<<endl;
                    x=0;
    }
    getchar();
    //system("pause");
    return 0;
}
                    

