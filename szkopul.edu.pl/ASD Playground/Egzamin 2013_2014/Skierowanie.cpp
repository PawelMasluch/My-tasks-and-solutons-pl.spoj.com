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


const int MAX_N = 500000, UNDEF = -1;


VI G[MAX_N];

bool odw[MAX_N];

int n, m, status[MAX_N], DaSie = 1;


void wczytaj()
{
	scanf( "%d %d", &n, &m );
	
	int u, v;
	
	REP(i,1,m)
	{
		scanf( "%d %d", &u, &v );
		
		--u;    --v;
		
		G[u].PB( v );
		
		G[v].PB( u );
	}
}


int BFS(int x)
{
	QI Q;
	
	odw[x] = true;
	
	status[x] = 0;
	
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
			
			if( !odw[v] )
			{
				odw[v] = true;
	
				status[v] = status[u] ^ 1;
				
				Q.P( v );
			}
			else
			{
				if( status[u] == status[v] )
				{
					return 0;
				}
			}
		}
	}
	
	return 1;
}


void oblicz()
{
	REP(u,0,n-1)
	{
		if( !odw[u] )
		{
			DaSie &= BFS( u );
		}
	}
}


void wypisz()
{
	if( DaSie )
	{
		printf( "TAK\n" );
	}
	else
	{
		printf( "NIE\n" );
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
