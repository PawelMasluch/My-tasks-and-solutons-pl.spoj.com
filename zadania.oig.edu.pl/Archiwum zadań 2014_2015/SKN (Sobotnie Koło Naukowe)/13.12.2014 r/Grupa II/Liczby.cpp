#include<cstdio> /* 100 pkt */
#include<vector>


using namespace std;


typedef long long LL;

typedef pair < LL, LL > PLL;

typedef vector < LL > VLL;

typedef vector < PLL > VPLL;


#define FOR(i,a,b,skok) for(LL i=a; i<=b; i+=skok)

#define REP(i,a,b) for(LL i=a; i<=b; ++i)

#define PB push_back

#define C clear

#define MP make_pair

#define ST first

#define ND second


const LL MAX_N = 100000, p = 1000000033, ZAKRES = 320;


VPLL rozklad;

VLL cykl;

bool czy[MAX_N];

PLL pierwsza[MAX_N+1];

LL n, t[MAX_N], IleCykli = 0, exp[MAX_N+1], r = 0;


void wczytaj()
{
    scanf( "%lld", &n );

    REP(i,0,n-1)
    {
        scanf( "%lld", &t[i] );

        --t[i];
    }
}


bool CzyPermutacja()
{
    REP(i,0,n-1)
    {
        if( czy[ t[i] ] == true )
        {
            return false;
        }

        czy[ t[i] ] = true;
    }

    return true;
}


void DFS(LL x)
{
    LL DlugoscCyklu = 0;

    while( czy[x] == false )
    {
        czy[x] = true;

        ++DlugoscCyklu;

        x = t[x];
    }

    cykl.PB( DlugoscCyklu );

    ++IleCykli;
}


void DlugosciCykli()
{
    REP(i,0,n-1)
    {
        czy[i] = false;
    }

    REP(i,0,n-1)
    {
        if( czy[i] == false )
        {
            DFS( i );
        }
    }
}


void Eratostenes()
{
    REP(i,2,MAX_N)
    {
        pierwsza[i] = MP( i, 1 );
    }

    LL wykladnik;

    REP(i,2,ZAKRES)
    {
        if( pierwsza[i].ST == i )
        {
            /*FOR(j,2*i,MAX_N,i)
            {
                wykladnik  =  ( pierwsza[ j / i ].ST == i )  ?  pierwsza[ j / i ].ND + 1  :  1  ;

                pierwsza[j] = MP( i, wykladnik );
            }*/

            FOR(j,i*i,MAX_N,i)
            {
                if( pierwsza[j].ST == j )
                {
                    wykladnik  =  ( pierwsza[ j / i ].ST == i )  ?  pierwsza[ j / i ].ND + 1  :  1  ;

                    pierwsza[j] = MP( i, wykladnik );
                }
            }
        }
    }


}


LL fpm(LL a, LL b)
{
    LL wyn = 1;

    while( b )
    {
        if( b & 1 )
        {
            wyn *= a;
        }

        b >>= 1;

        a *= a;
    }

    return wyn;
}


LL max(LL a, LL b)
{
    return ( a > b ) ? a : b ;
}


void rozloz(LL x)
{
    LL p, alfa;

    while( x > 1 )
    {
        rozklad.PB( pierwsza[x] );

        ++r;

        p = pierwsza[x].ST;

        alfa = pierwsza[x].ND;

        x /= fpm( p, alfa );
    }

    REP(i,0,r-1)
    {
        p = rozklad[i].ST;

        alfa = rozklad[i].ND;

        exp[p] = max( exp[p], alfa );
    }

    rozklad.C();

    r = 0;
}


void NWW()
{
    Eratostenes();

    REP(i,0,IleCykli-1)
    {
        if( cykl[i] > 1 )
        {
            rozloz( cykl[i] );
        }
    }

    LL wyn = 1;

    REP(i,2,MAX_N)
    {
        if( pierwsza[i].ST == i )
        {
            wyn = ( wyn * fpm( i, exp[i] ) ) % p;
        }
    }

    printf( "%lld\n", wyn );
}


void oblicz()
{
    if( CzyPermutacja() == false )
    {
        printf( "-1\n" );

        return ;
    }

    DlugosciCykli();

    NWW();
}


int main()
{
    wczytaj();

    oblicz();

    return 0;
}
