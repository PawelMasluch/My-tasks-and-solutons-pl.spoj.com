#include<cstdio> // do sprawdzenia

using namespace std;

typedef long long LL;

LL NWD(LL a, LL b)
{
          LL temp;
          while(b)
          {
                  temp = a % b;
                  a=b;
                  b=temp;
          }
          return a;
}

int main()
{
    LL z,n,d,i;
    scanf("%lld", &z);
    for(i=1; i<=z; i++)
    {
             scanf("%lld%lld", &n, &d);
             printf("%lld\n", n/NWD(n,d));
    }
    
    return 0;
}
