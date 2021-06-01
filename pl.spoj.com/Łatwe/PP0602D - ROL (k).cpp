#include<cstdio> // AC


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 100;


int n, k, t[MAX_N];


void wczytaj()
{
    scanf( "%d %d", &n, &k );

    REP(i,0,n-1)
    {
        scanf( "%d", &t[i] );
    }
}


void odwroc(int pocz, int kon) // 0 <= pocz <= kon
{
    int tmp, dl = kon - pocz + 1, j;

    REP(i,0,(dl/2)-1)
    {
        j = dl - 1 - i;

        tmp = t[ i + pocz ];

        t[ i + pocz ] = t[ j + pocz ];

        t[ j + pocz ] = tmp;
    }
}


void przesun()
{
    odwroc( 0, k - 1 );

    odwroc( k, n - 1 );

    odwroc( 0, n - 1 );
}


void wypisz()
{
    REP(i,0,n-1)
    {
        printf( "%d ", t[i] );
    }

    printf( "\n" );
}


int main()
{
    wczytaj();

    przesun();

    wypisz();

    return 0;
}

