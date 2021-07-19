#include<cstdio> // 100 pkt
#include<vector>
#include<queue>


using namespace std;


typedef long long LL;

typedef pair < LL, LL > PLL;

typedef vector < PLL > VPLL;

typedef priority_queue < PLL > PQ_PLL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)

#define PB push_back

#define S size

#define MP make_pair

#define ST first

#define ND second

#define P push

#define p pop

#define E empty

#define T top


const LL INF = (LL)1000000009 * 1000000009,   MAX_N = 20000,   MAX_K = 10,   MAX_LICZBA_WIERZCHOLKOW = MAX_N * ( MAX_K + 1 );


bool odw[MAX_LICZBA_WIERZCHOLKOW];

VPLL G[MAX_LICZBA_WIERZCHOLKOW];

LL n, m, k, d[MAX_LICZBA_WIERZCHOLKOW];


LL min(LL a, LL b)
{
	return ( a < b ) ? a : b ;
}


void inicjuj()
{
	d[0] = 0;
	
	REP(u,1,MAX_LICZBA_WIERZCHOLKOW-1)
	{
		d[u] = INF;
	}
}


void wczytaj()
{
	scanf( "%lld %lld %lld", &n, &m, &k );
	
	LL u, v, b, c;
	
	while( m )
	{
		scanf( "%lld %lld %lld %lld", &u, &v, &b, &c );
		
		
		// Etap I: krawędź u->v po zwykłej cenie, w każdym egzemplarzu grafu 
		
		REP(j,0,k)
		{
			G[ u + j*n ].PB( MP( v + j*n, c ) );
		}
		
		
		// Etap II: krawędź po niższej cenie, z wierzchołka u (egzemplarz grafu nr j) do wierzchołka v (egzemplarz grafu nr j+1)
		
		REP(j,0,k-1)
		{
			G[ u + j*n ].PB( MP( v + (j+1)*n, c - b ) );
		}
		
		--m;
	}	
}


void Dijkstra()
{
	PQ_PLL PQ;
	
	LL u, v, w, r, kandydat;
	
	
	PQ.P( MP( -d[0], 0 ) );
	
	
	while( !PQ.E() )
	{
		u = PQ.T().ND;
		
		PQ.p();
		
		if( !odw[u] )
		{
			r = G[u].S();
		
			REP(i,0,r-1)
			{
				v = G[u][i].ST;
				
				w = G[u][i].ND;
				
				kandydat = d[u] + w;
					
				if( kandydat < d[v] )
				{
					d[v] = kandydat;
					
					PQ.P( MP( -d[v], v ) );
				}
			}
			
			odw[u] = true;
		}
	}
}


void oblicz()
{
	Dijkstra();
}


void wypisz()
{
	LL wyn = INF;
	
	REP(j,0,k)
	{
		wyn = min( wyn, d[ ( n - 1 ) + j*n ] );
	}
	
	if( wyn == INF )
	{
		printf( "-1\n" );
	}
	else
	{
		printf( "%lld\n", wyn );
	}
}


int main()
{
	inicjuj();
	
	wczytaj();
	
	oblicz();
	
	wypisz();
	
	return 0;
}