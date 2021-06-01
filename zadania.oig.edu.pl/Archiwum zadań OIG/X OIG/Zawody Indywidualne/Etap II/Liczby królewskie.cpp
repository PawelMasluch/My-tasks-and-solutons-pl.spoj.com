#include<cstdio> // 100 pkt


using namespace std;


#define FORD(i,b,a) for(int i=b; i>=a; --i)


int f(int n)
{
    int wyn = 0, tmp = ( 1 << 30 ), ile = 0;

    FORD(i,30,1)
    {
        if( n > ( tmp >> 1 ) )
        {
            wyn += tmp;

            n -= ( tmp >> 1 );

            ++ile;
        }

        tmp >>= 1;
    }

    if( ile & 1 )
    {
        ++wyn;
    }

    return wyn;
}


void zapytania()
{
    int q, n;

    scanf( "%d", &q );

    while( q )
    {
        scanf( "%d", &n );

        printf( "%d\n", f( n ) );

        --q;
    }
}


int main()
{
    zapytania();

    return 0;
}
