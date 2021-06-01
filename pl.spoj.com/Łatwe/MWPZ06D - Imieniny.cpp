#include<iostream> // AC
using namespace std;
void f(int n, int k)
{
     if(n==1)
     {
             cout<<"TAK\n";
     }
     else
     {
         if(k%(n-1)==0)
         {
                       cout<<"NIE\n";
         }
         else
         {
             cout<<"TAK\n";
         }
     }
}
int main()
{
    int t,n,k,i;
    cin>>t;
    for(i=0; i<t; i++)
    {
             cin>>n>>k;
             f(n,k);
    }
    //system("pause");
    return 0;
}

