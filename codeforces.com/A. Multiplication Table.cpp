#include<cstdio> // AC
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int main()
{
    int n, x, wyn = 0;
    
    scanf( "%d %d", &n, &x );
    
    REP(i,1,n)
    {
        if( x % i == 0 )
        {
            if( ( x / i ) <= n )
            {
                ++wyn;
            }
        }
    }
    
    printf( "%d\n", wyn );
    
    return 0;
}
