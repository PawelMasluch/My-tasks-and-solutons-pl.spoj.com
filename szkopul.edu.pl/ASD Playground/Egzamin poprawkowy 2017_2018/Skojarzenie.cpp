#include<cstdio>


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 100000, INF = 1000000000 + 199, MX = 50000;


int n, m, G[MAX_N+1][2], DP[MX+1];


void init()
{
	REP(u,1,n)
	{
		REP(i,0,1)
		{
			G[u][i] = INF;
		}
	}
	
	REP(k,0,n/2)
	{
		DP[k] = INF;
	}
}


void wczytaj()
{
	scanf( "%d %d", &n, &m );
	
	init();
	
	int u, v, w;
	
	REP(i,1,m)
	{
		scanf( "%d %d %d", &u, &v, &w );
		
		if( u != v )
		{
			if( v < u ) // zamieniamy miejscami
			{
				u = u + v;
				
				v = u - v;
				
				u = u - v;
			}
			
			G[v][ 2 - ( v - u ) ] = w;
		}
	}
}


int min(int a, int b)
{
	return ( a < b ) ? a : b ;
}


void oblicz()
{
	if( n % 2 == 1 )
	{
		printf( "-1\n" );
	}
	else
	{
		DP[0] = 0;    DP[1] = G[2][1];
		
		int kand1, kand2;
		
		REP(k,2,n/2)
		{
			// kand1
			
			kand1 = ( G[2*k][1] == INF  ||  DP[k-1] == INF ) ? INF : DP[k-1] + G[2*k][1];
			
			
			// kand2
			
			kand2 = ( G[2*k][0] == INF  ||  G[2*k-1][0] == INF  ||  DP[k-2] == INF ) ? INF : G[2*k][0] + G[2*k-1][0] + DP[k-2];
			
			
			DP[k] = min( kand1, kand2 );
		}
		
		
		// wypisanie wyniku
		
		if( DP[ n / 2 ] == INF )
		{
			printf( "-1\n" );
		}
		else
		{
			printf( "%d\n", DP[ n / 2 ] );
		}
	}
}


void solve()
{
	wczytaj();
	
	oblicz();
}


int main()
{
	solve();
	
	return 0;
}
