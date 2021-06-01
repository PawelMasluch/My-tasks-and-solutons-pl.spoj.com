#include<cstdio> // AC

using namespace std;

typedef long long LL;

LL NWD(LL a, LL b)
{
          LL temp;
          
          while(b)
          {
                  temp = a % b;
                  a = b;
                  b = temp;
          }
          
          return a;
}

int main()
{
    LL t, a, b, d, pom;
    
    scanf("%lld", &t);
    
    while( t > 0 )
    {
           scanf("%lld%lld%lld", &a, &b, &d);
           
           pom = NWD( a, a + b );
           
           printf( "%lld/%lld\n",  a / pom,  ( a + b ) / pom );
           
           --t;
    }
    
    return 0;
}
