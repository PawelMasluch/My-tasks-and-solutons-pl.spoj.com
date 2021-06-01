#include<cstdio> // AC
#include<vector>


using namespace std;


typedef vector < int > VI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)

#define PB push_back

#define S size


const int MAX_N = 1000000;


VI G[MAX_N];

int n, ile_wierszy = 0;


int Gauss(int x)
{
    return ( x * ( x + 1 ) ) / 2;
}


void wczytaj()
{
    scanf( "%d", &n );
}


void wypelnij()
{
    int akt, skok;

    while( Gauss( ile_wierszy ) + 1 <= n )
    {
        akt = Gauss( ile_wierszy ) + 1;

        skok = ile_wierszy + 2;

        do
        {
            G[ ile_wierszy ].PB( akt );

            akt += skok;

            ++skok;
        }
        while( akt <= n );

        ++ile_wierszy;
    }
}


void wypisz()
{
    int r;

    FORD(i,ile_wierszy-1,0)
    {
        r = G[i].S();

        REP(j,0,r-1)
        {
            printf( "%d ", G[i][j] );
        }

        printf( "\n" );
    }
}


void rozwiaz()
{
    wczytaj();

    wypelnij();

    wypisz();
}


int main()
{
    rozwiaz();

    return 0;
}

