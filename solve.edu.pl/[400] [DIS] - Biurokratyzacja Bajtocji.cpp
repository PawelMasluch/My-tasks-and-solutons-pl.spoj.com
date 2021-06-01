#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 250, INF = 1000000099;


int q, n, m, G[MAX_N][MAX_N];


void init()
{
	REP(u,0,n-1)
	{
		REP(v,0,u-1)
		{
			G[u][v] = INF;
		}
		
		G[u][u] = 0;
		
		REP(v,u+1,n-1)
		{
			G[u][v] = INF;
		}
	}
}


int min(int a, int b)
{
	return ( a < b ) ? a : b ;
}


void wczytaj()
{
	scanf( "%d %d", &n, &m );
	
	init();
	
	int u, v, w;
	
	REP(i,1,m)
	{
		scanf( "%d %d %d", &u, &v, &w );
		
		--u;    --v;
		
		G[u][v] = min( G[u][v], w );
		
		G[v][u] = G[u][v];
	}
}


void oblicz()
{
	REP(k,0,n-1)
	{
		REP(u,0,n-1)
		{
			REP(v,u+1,n-1)
			{
				G[u][v] = min( G[u][v], G[u][k] + G[k][v] );
				
				G[v][u] = G[u][v];
			}
		}
	}
}


void wypisz()
{
	REP(u,0,n-1)
	{
		REP(v,0,n-1)
		{
			if( G[u][v] == INF )
			{
				printf( "-1 " );
			}
			else
			{
				printf( "%d ", G[u][v] );
			}
		}
		
		printf( "\n" );
	}
}


void pojedynczy_zestaw_danych()
{
	wczytaj();
	
	oblicz();
	
	wypisz();
}


void obsluz_zestawy_danych()
{
	scanf( "%d", &q );
	
	while( q )
	{
		pojedynczy_zestaw_danych();
		
		--q;
	}
}


int main()
{
	obsluz_zestawy_danych();
	
	return 0;
}
