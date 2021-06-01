#include<cstdio> // 100 pkt
#include<vector>


using namespace std;


typedef vector < int > VI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back

#define S size


const int MAX_N = 1000000, UNDEF = -1;


VI G[MAX_N];

bool centroid[MAX_N];

int n, poddrzewo[MAX_N];


void wczytaj()
{
	scanf( "%d", &n );
	
	int u, v;
	
	REP(i,1,n-1)
	{
		scanf( "%d %d", &u, &v );
		
		--u;    --v;
		
		G[u].PB( v );
		
		G[v].PB( u );
	}
}


void init()
{
	REP(u,0,n-1)
	{
		centroid[u] = true;
		
		poddrzewo[u] = 1;
	}
}


void DFS(int u, int ojciec)
{
	int r = G[u].S(), v;
	
	REP(i,0,r-1)
	{
		v = G[u][i];
		
		if( v != ojciec )
		{
			DFS( v, u );
			
			if( poddrzewo[v] > n / 2 )
			{
				centroid[u] = false;
			}
			
			poddrzewo[u] += poddrzewo[v];
		}
	}
	
	if( n - poddrzewo[u] > n / 2 ) // jesli poza poddrzewem wierzcholka 'u' jest za duzo wiezcholkow
	{
		centroid[u] = false;	
	}
}


void oblicz()
{
	DFS( 0, UNDEF );
}


void wypisz()
{
	REP(u,0,n-1)
	{
		if( centroid[u] == true )
		{
			printf( "%d ", u + 1 );
		}
	}
	
	printf( "\n" );
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
