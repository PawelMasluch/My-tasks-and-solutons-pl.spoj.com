#include<cstdio> // AC


using namespace std;


typedef long long LL;


#define REP(i,n) for(LL i=0; i<n; ++i)


LL max(LL a, LL b)
{
    return ( a > b ) ? a : b ;
}


LL znajdz(LL n) // dla n >= 1 znajduje max L,ze 2^L - 1 <= n
{
    LL exp = 1, tmp = 2;

    while( tmp - 1 <= n )
    {
        ++exp;

        tmp <<= 1;
    }

    return exp - 1;
}


LL f(LL n)
{
    if( n == 0 )
    {
        return 1;
    }

    LL wyn = 1, L = znajdz( n ), tmp = 1;

    REP(i,L)
    {
        wyn += tmp * ( i + 1 );

        tmp <<= 1;
    }

    wyn += max( 0, n - tmp + 1 ) * ( L + 1 );

    return wyn;
}


void zapytania()
{
    LL q, n;

    scanf( "%lld", &q );

    while( q )
    {
        scanf( "%lld", &n );

        printf( "%lld\n", f( n ) );

        --q;
    }
}


int main()
{
    zapytania();

    return 0;
}
