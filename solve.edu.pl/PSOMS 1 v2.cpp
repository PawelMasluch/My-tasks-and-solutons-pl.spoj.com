#include<cstdio> // 100 pkt
using namespace std;
typedef long long ll;
ll max(ll a, ll b)
{
          return (a>b) ? a : b ;
}
ll f(int n)
{
         ll w=0,wyn=0,i,a;
         for(i=0; i<n; i++)
         {
                  scanf("%lld", &a);
                  if(w>0)
                  {
                         w+=a;
                  }
                  else
                  {
                      w=a;
                  }
                  wyn=max(wyn,w);
         }
         return wyn;
}
int main()
{
    ll n;
    scanf("%lld", &n);
    printf("%lld\n", f(n));
    //system("pause");
    return 0;
}
