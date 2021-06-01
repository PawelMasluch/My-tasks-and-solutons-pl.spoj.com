#include<iostream> // AC
using namespace std;
typedef long long ll;
typedef long double ld;
ld modul(ld m)
{
       return (m>0.00) ? m : -m ;
}
ll f(ll a, ll b, ld m)
{
         a+=1000000000;
         b+=1000000000;
         if(modul(m)>1.00)
         {
                        return 0;
         }
         if(m==0.00)
         {
                  return b-a+1;
         }
         if(m==1.00)
         {
                  if(a%2==0 && b%2==1)
                  {
                            return (b-a+1)/2;
                  }
                  return (b-a)/2;
         }
         if(m==-1.00)
         {
                   if(a%2==1 && b%2==0)
                   {
                             return (b-a+1)/2;
                   }
                   return (b-a)/2;
         }
         if(m>0.00 && m<1.00)
         {
                 if(a%2==0 && b%2==1)
                 {
                           return b-a+1;
                 }
                 if(a%2==1 && b%2==0)
                 {
                     return b-a-1;
                 }
                 return b-a;
         }
         if(m>-1.00 && m<0.00)
         {
                  if(a%2==0 && b%2==1)
                  {
                            return b-a-1;
                  }
                  if(a%2==1 && b%2==0)
                  {
                      return b-a+1;
                  }
                  return b-a;
         }
} 
int main()
{
    ll t,i,a,b;
    ld m;
    cin>>t;
    for(i=0; i<t; i++)
    {
             cin>>a>>b>>m;
             cout<<f(a,b,m)<<endl;
    }
    //system("pause");
    return 0;
}

