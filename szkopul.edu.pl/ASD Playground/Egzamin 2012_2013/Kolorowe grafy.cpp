#include<cstdio> // 100 pkt
#include<vector>
#include<queue>


using namespace std;


typedef vector < int > VI;

typedef queue < int > QI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back

#define S size

#define F front

#define P push

#define p pop

#define E empty


const int MAX_N = 500000, INF = 1000000000 + 199;


VI G[2*MAX_N+1];

int n, m, d[2*MAX_N+1];


void wczytaj()
{
	scanf( "%d %d", &n, &m );
	
	int u, v, k;
	
	REP(i,1,m)
	{
		scanf( "%d %d %d", &u, &v, &k );
		
		if( k == 0 ) // krawedz czerwona
		{
			G[ 2*u ].PB( 2*v - 1 );
			
			G[ 2*v ].PB( 2*u - 1 );
		}
		else // k == 1, czyli krawedz zielona
		{
			G[ 2*u - 1 ].PB( 2*v );
			
			G[ 2*v - 1 ].PB( 2*u );
		}
	}
	
	G[0].PB( 1 );    G[0].PB( 2 ); // z wierzcholka '0' specjalnie wychodza krawedzie skierowane
}


void init()
{
	REP(u,0,2*n)
	{
		d[u] = INF;
	}
	
	d[0] = 0;
}


void BFS(int x)
{
	QI Q;
	
	Q.P( x );
	
	int u, v, r;
	
	while( !Q.E() )
	{
		u = Q.F();
		
		Q.p();
		
		r = G[u].S();
		
		REP(i,0,r-1)
		{
			v = G[u][i];
			
			if( d[u] + 1 < d[v] )
			{
				d[v] = d[u] + 1;
				
				Q.P( v );
			}
		}
	}
}


void oblicz()
{
	init();
	
	BFS( 0 );
}


int min(int a, int b)
{
	return ( a < b ) ? a : b ;
}


void wypisz()
{
	REP(u,2,n)
	{
		if( d[ 2*u - 1 ] == INF  &&  d[ 2*u ] == INF )
		{
			printf( "-1\n" );	
		}
		else
		{
			printf( "%d\n", min( d[ 2*u - 1 ], d[ 2*u ] ) - 1 );
		}
	}
}


void solve()
{
	wczytaj();
	
	oblicz();
	
	wypisz();
}


int main()
{
	solve();
	
	return 0;
}
