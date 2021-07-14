#include<cstdio> // AC
//#include<iostream>
 
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
    LL d, n, g, m, s, czas, wyn;
    
    scanf("%lld", &d);
    
    while( d > 0 )
    {
           scanf("%lld%lld:%lld:%lld", &n, &g, &m, &s);
           
           czas = ( ( 3600 * g ) + ( 60 * m ) + s ) * 1000;
           
           wyn = czas / n;
           
           if( 2 * ( czas % n ) >= n )
           {
               ++wyn;
           }
           
           printf("%lld:", wyn / 60);
           
           if( wyn % 60 < 10 )
           {
               printf("0");
           }
           
           printf("%lld\n", wyn % 60);
           
           --d;
    }
    
    //system("pause");
    return 0;
}
 
