#include<cstdio> // 100 pkt
#include<vector>


using namespace std;


typedef pair < int, int > PII;

typedef vector < PII > VPII;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back

#define S size

#define MP make_pair

#define ST first

#define ND second


const int MAX_N = 300000, UNDEF = -1;


VPII G[MAX_N];

int n, dp[MAX_N], best[MAX_N];


/*

best[u] - najciezsze skojarzenie dla poddrzewa wierzcholka 'u'

dp[u] - najciezsze skojarzenie dla poddrzewa wierzcholka 'u', ktore to skojarzenie nie zawiera wierzcholka 'u'

*/


void wczytaj()
{
	scanf( "%d", &n );
	
	int u, v, w;
	
	REP(i,1,n-1)
	{
		scanf( "%d %d %d", &u, &v, &w );
		
		--u;    --v;
		
		G[u].PB( MP( w, v ) );
		
		G[v].PB( MP( w, u ) );
	}
}


int max(int a, int b)
{
	return ( a > b ) ? a : b ;
}


void DFS(int u, int ojciec)
{
	int r = G[u].S(), v, w;
	
	REP(i,0,r-1)
	{
		w = G[u][i].ST;
		
		v = G[u][i].ND;
		
		if( v != ojciec )
		{
			DFS( v, u );
			
			dp[u] += best[v];
		}
	}
	
	best[u] = dp[u];
	
	REP(i,0,r-1)
	{
		w = G[u][i].ST;
		
		v = G[u][i].ND;
		
		if( v != ojciec )
		{
			best[u] = max( best[u], w + dp[v] + dp[u] - best[v] );
		}
	}
}


void oblicz()
{
	DFS( 0, UNDEF );
}


void wypisz()
{
	printf( "%d\n", best[0] );
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
