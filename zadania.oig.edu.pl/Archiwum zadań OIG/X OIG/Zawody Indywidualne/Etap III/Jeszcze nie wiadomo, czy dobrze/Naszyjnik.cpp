#include<cstdio>
#include<algorithm>


using namespace std;


typedef long long LL;

typedef pair < int, int > PII;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define MP make_pair

#define wartosc first

#define indeks second


const int MAX_N = 100000;


int q, n, t[MAX_N], ile[MAX_N];


void wczytaj()
{
    scanf( "%d %d", &n, &q );

    REP(i,0,n-1)
    {
        scanf( "%d", &t[i] );
    }
}


void przeskaluj()
{
    PII pom[n];

    REP(i,0,n-1)
    {
        pom[i] = MP( t[i], i );
    }

    sort( pom, pom + n );

    int tmp = 0;

    t[ pom[0].indeks ] = tmp;

    REP(i,1,n-1)
    {
        if( pom[i].wartosc > pom[ i - 1 ].wartosc )
        {
            ++tmp;
        }

        t[ pom[i].indeks ] = tmp;
    }
}


LL oblicz(int k)
{
    LL wyn = 0;

    int i = 0, j = 0, ile_kolorow = 0;

    while( i < n )
    {
        while( j < n )
        {
            ++ile[ t[j] ];

            if( ile[ t[j] ] == 1 )
            {
                ++ile_kolorow;
            }

            if( ile_kolorow > k )
            {
                --ile_kolorow;

                --ile[ t[j] ];

                break;
            }

            ++j;
        }

        wyn += ( j - i );

        --ile[ t[i] ];

        if( ile[ t[i] ] == 0 )
        {
            --ile_kolorow;
        }

        ++i;
    }

    REP(i,0,n-1)
    {
        ile[i] = 0;
    }

    return wyn;
}


void zapytania()
{
    int k;

    while( q )
    {
        scanf( "%d", &k );

        printf( "%lld\n", oblicz( k ) );

        --q;
    }
}


int main()
{
    wczytaj();

    przeskaluj();

    zapytania();

    return 0;
}
