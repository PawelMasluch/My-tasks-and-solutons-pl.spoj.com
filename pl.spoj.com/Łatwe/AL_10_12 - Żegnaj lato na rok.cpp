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

LL NWW(LL a, LL b)
{
        return ( a/NWD(a,b) ) * b ;
}

LL NWW3(LL a, LL b, LL c)
{
           return NWW(NWW(a,b),c);
}

LL f(LL a, LL b, LL c, LL n)
{
      return (n/a) + (n/b) + (n/c) - ( n / NWW(a,b) ) - ( n / NWW(b,c) ) - ( n / NWW(c,a) ) + ( n / NWW3(a,b,c) ) ;
}

int main()
{
    LL a,b,c,sp,sk;
    
    scanf("%lld%lld%lld", &a, &b, &c);
    
    while(scanf("%lld%lld", &sp, &sk) != EOF)
    {
                            printf("%lld\n", f(a,b,c,sk) - f(a,b,c,sp-1));
    }
    
    return 0;
}

