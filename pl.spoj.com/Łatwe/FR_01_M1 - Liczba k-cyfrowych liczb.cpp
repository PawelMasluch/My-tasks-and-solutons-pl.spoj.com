#include<iostream> // AC
using namespace std;
int main()
{
    int t,i,k,n,j;
    unsigned long long int x=1;
    cin>>t;
    for(i=0; i<t; i++)
    {
             cin>>k>>n;
             if(k==1)
             {
                     cout<<n<<endl;
             }
             else
             {
                 for(j=1; j<=k-1; j++)
                 {
                          x*=n;
                 }
                 cout<<x*(n-1)<<endl;
                 x=1;
             }
    }
    //system("pause");
    return 0;
}
