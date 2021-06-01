#include<cstdio> // AC
#include<vector>

using namespace std;

typedef long long LL;

bool czy_palindrom(LL &n)
{
     vector < LL > v;
     
     LL temp = n, x = 1, r = 0, i;
     
     while( temp > 0 )
     {
            v.push_back( temp % 10 );
            ++r;
            temp /= 10;
     }
     
     for(i=r-1; i>=0; --i)
     {
          temp += ( v[i] * x );
          x *= 10;
     }
     
     v.clear();
     
     if( temp == n )
     {
         return true;
     }
     
     return false;
}

LL g(LL n)
{
        vector < LL > v;
     
        LL x = 1, r = 0, i, wyn = 0;
     
        while( n > 0 )
        {
               v.push_back( n % 10 );
               ++r;
               n /= 10;
        }
     
        for(i=r-1; i>=0; --i)
        {
                   wyn += ( v[i] * x );
                   x *= 10;
        }
     
        v.clear();
        
        return wyn;
}

LL f(LL &n)
{
        LL wyn = 0;
        
        while( czy_palindrom( n ) == false )
        {
               n += g( n );
               ++wyn;
        }
        
        return wyn;
}

int main()
{
    LL t, n;
    
    scanf("%lld", &t);
    
    while( t )
    {       
           scanf("%lld", &n);
           
           printf("%lld %lld\n", n, f( n ) );
                 
           --t;
    }
    
    return 0;
}
