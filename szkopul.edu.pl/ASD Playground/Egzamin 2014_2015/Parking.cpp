#include<cstdio> // 100 pkt
#include<queue>
#include<vector>


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


VI G[MAX_N];

int n, m, b[MAX_N], d[MAX_N];


void wczytaj()
{
	scanf( "%d %d", &n, &m );
	
	REP(u,0,n-1)
	{
		scanf( "%d", &b[u] );
	}
	
	int u, v;
	
	REP(i,1,m)
	{
		scanf( "%d %d", &u, &v );
		
		--u;    --v;
		
		G[u].PB( v );
		
		G[v].PB( u );
	}
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
			
			if( d[u] + b[v] < d[v] )
			{
				d[v] = d[u] + b[v];
				
				Q.P( v );
			}
		}
	}
}


void init()
{
	d[0] = 0;
	
	REP(u,1,n-1)
	{
		d[u] = INF;
	}
}


void oblicz()
{
	BFS( 0 );
}


void wypisz()
{
	REP(u,1,n-1)
	{
		if( b[u] == 1  &&  d[u] == 1 )
		{
			printf( "%d\n", u + 1 );
		}
	}
}


void solve()
{
	wczytaj();
	
	init();
	
	oblicz();
	
	wypisz();
}


int main()
{
	solve();
	
	return 0;
}
