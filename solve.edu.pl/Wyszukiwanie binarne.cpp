#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,n) for(int i=0; i<n; ++i)


const int MAX_N = 1000000;


int q, n, t[MAX_N];


void wczytaj()
{
    scanf( "%d", &n );

    REP(i,n)
    {
        scanf( "%d", &t[i] );
    }
}


void query(int x)
{
    int pocz = 0, kon = n - 1, wyn = n, sr;

    while( pocz <= kon )
    {
        sr = ( pocz + kon ) / 2;

        if( t[ sr ] < x )
        {
            pocz = sr + 1;
        }
        else
        {
            wyn = sr;

            kon = sr - 1;
        }
    }

    printf( "%d ", n - wyn );
}


void zapytania()
{
    scanf( "%d", &q );

    int x;

    while( q )
    {
        scanf( "%d", &x );

        query( x );

        --q;
    }

    printf( "\n" );
}


int main()
{
    wczytaj();

    zapytania();

    return 0;
}
