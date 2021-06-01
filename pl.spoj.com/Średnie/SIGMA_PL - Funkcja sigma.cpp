#include<iostream> // AC
using namespace std;
long long int f(int n)
{
     int i;
     long long int suma=0;
     for(i=1; i*i<=n; i++)
     {
              if(i*i==n)
              {
                       suma+=i;
              }
              else
              {
                  if(n%i==0)
                  {
                            suma+=i+(n/i);
                  }
              }
     }
     return suma;
}
int main()
{
    int t,n,i;
    cin>>t;  
    for(i=0; i<t; i++)
    {
             cin>>n;
             cout<<f(n)<<endl;
    } 
    //system("pause");
    return 0;
}
