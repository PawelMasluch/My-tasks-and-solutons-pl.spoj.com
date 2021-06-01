#include<cstdio> /* 100 pkt */


using namespace std;


typedef long long LL;


#define REP(i,a,b,skok) for(LL i=a; i<=b; i+=skok)


const LL MAX_N = 20000099, MAX_ZAKRES = 32000;


bool czy[MAX_N], pom[MAX_ZAKRES+1];

LL a, b, ZAKRES;


LL bin1(LL x) /* 1 <= x <= 10^18 ; wyn = min k: k^2 >= x */
{
    LL pocz = 1, kon = 1000000000, wyn, sr;

    while( pocz <= kon )
    {
        sr = ( pocz + kon ) / 2;

        if( sr * sr >= x )
        {
            wyn = sr;

            kon = sr - 1;
        }
        else
        {
            pocz = sr + 1;
        }
    }

    return wyn;
}


LL bin2(LL x) /* 1 <= x <= 10^18 ; wyn = max k: k^2 <= x */
{
    LL pocz = 1, kon = 1000000000, wyn, sr;

    while( pocz <= kon )
    {
        sr = ( pocz + kon ) / 2;

        if( sr * sr <= x )
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


LL max(LL x, LL y)
{
    return ( x > y ) ? x : y ;
}


LL f(LL k, LL x) /* min (alfa >= 2) : alfa * k >= x oraz k - liczba pierwsa */
{
    return max(  ( x + k - 1 ) / k  ,  2  );
}


void wczytaj()
{
    scanf( "%lld %lld", &a, &b ); /* 4 <= a <= b <= 10^18 */

    a = bin1( a );

    b = bin2( b );
}


void Eratostenes()
{
    REP(i,2,MAX_ZAKRES,1)
    {
        pom[i] = true;
    }

    ZAKRES = bin2( MAX_ZAKRES );

    REP(i,2,ZAKRES,1)
    {
        if( pom[i] == true )
        {
            REP(j,i*i,MAX_ZAKRES,i)
            {
                pom[j] = false;
            }
        }
    }
}


void oblicz()
{
    Eratostenes();

    REP(i,a,b,1)
    {
        czy[ i - a ] = true;
    }

    ZAKRES = bin2( b );

    REP(i,2,ZAKRES,1)
    {
        if( pom[i] == true )
        {
            REP(j,f(i,a)*i,b,i)
            {
                czy[ j - a ] = false;
            }
        }
    }

    LL wyn = 0;

    REP(i,a,b,1)
    {
        if( czy[ i - a ] == true )
        {
            ++wyn;
        }
    }

    printf( "%lld\n", wyn );
}


int main()
{
    wczytaj();

    oblicz();

    return 0;
}
