#include<cstdio> // AC


using namespace std;


typedef long long LL;


LL q, p, a;


LL fpm(LL a, LL b, LL p)
{
    LL wyn = 1;

    while( b )
    {
        if( b & 1 )
        {
            wyn = ( wyn * a ) % p;
        }

        a = ( a * a ) % p;

        b >>= 1;
    }

    return wyn;
}


void zapytania()
{
    scanf( "%lld", &q );

    while( q )
    {
        scanf( "%lld %lld", &p, &a );

        printf( "%lld\n", fpm( a, p - 2, p ) );

        --q;
    }
}


int main()
{
    zapytania();

    return 0;
}
