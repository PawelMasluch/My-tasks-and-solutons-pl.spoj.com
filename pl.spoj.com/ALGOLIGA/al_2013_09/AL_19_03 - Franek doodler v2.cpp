#include<cstdio> // AC
 
using namespace std;
 
typedef long long LL;
 
LL f(LL n) // 0 <= n <= 10^12
{
        LL pocz = 0, kon = 1000000, sr, wyn;
        
        while( pocz <= kon )
        {
               sr = ( pocz+kon ) >> 1;
               
               if( sr * sr <= n )
               {
                        wyn = sr;
                        pocz = sr + 1;
               }
               else
               {
                   kon = sr - 1;
               }
        }
        
        return wyn;
}
 
LL ile(LL n)
{
          LL i, wyn = 0, pom1, pom2 = f(n);
          
          for(i=1; i*i<=n; ++i)
          {
                   pom1 = ( n / i );
                   
                   wyn += ( pom2 + ( ( pom1 - pom2 ) << 1 ) ); 
          }
          
          return wyn;
}
 
int main()
{
    LL t, n;
    
    scanf("%lld", &t);
    
    while( t > 0 )
    {
           scanf("%lld", &n);
           
           printf( "%lld\n", ile(n) );
           
           --t;
    }
    
    return 0;
} 
