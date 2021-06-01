#include<cstdio> // AC
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
    scanf("%d", &t); 
    for(i=0; i<t; i++)
    {
             scanf("%d", &n);
             printf("%lld\n", f(n));
    } 
    //system("pause");
    return 0;
}

