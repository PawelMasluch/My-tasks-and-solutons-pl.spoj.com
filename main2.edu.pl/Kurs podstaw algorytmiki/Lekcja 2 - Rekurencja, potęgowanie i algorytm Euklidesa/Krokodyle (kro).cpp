#include<cstdio> // do sprawdzenia

using namespace std;

typedef long long LL;

LL fpm(LL a, LL b, LL p)
{
          LL wyn = 1;
          while(b)
          {
                 if(b&1)
                 {
                        wyn = (wyn*a)%p;
                 }
                 a = (a*a)%p;
                 b >>= 1;
          }
          return wyn;
}

int main()
{
    LL P,i,a,b;
    scanf("%lld", &P);
    for(i=1; i<=P; i++)
    {
             scanf("%lld%lld", &a, &b);
             printf("%lld\n", fpm(a+1,b,10000));
    }
    return 0;
}
