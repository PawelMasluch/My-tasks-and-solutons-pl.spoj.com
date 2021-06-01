#include<cstdio>
#include<vector>


using namespace std;


typedef vector < int > VI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back

#define S size


const int MAX_N = 1000000, MAX_M = 1000000, INF = MAX_N + 199, UNDEF = -1;


bool odw[MAX_N], punkt_artykulacji[MAX_N];

VI G[MAX_N];

int n, m, low[MAX_N], preorder[MAX_N], czas = 0; 


void wczytaj() // wszystko numerowane od zera
{
	scanf( "%d %d", &n, &m );
	
	int u, v;
	
	REP(i,0,m-1)
	{
		scanf( "%d %d", &u, &v );
		
		G[u].PB( v );
		
		G[v].PB( u );
	}
}


void init()
{
	REP(u,0,n-1)
	{
		odw[u] = false; // nie trzeba tej linijki, ale dla porzadku niech bedzie
		
		low[u] = INF;
		
		punkt_artykulacji[u] = false; // nie trzeba tej linijki, ale dla porzadku niech bedzie
	}
}


int min(int a, int b)
{
	return ( a < b ) ? a : b ;
}


void DFS(int u, int ojciec)
{
	odw[u] = true;
	
	preorder[u] = czas;
	
	++czas;
	
	low[u] = min( low[u], preorder[u] );
	
	bool test = false;
	
	int r = G[u].S(), v, synowie = 0;
	
	REP(i,0,r-1)
	{
		v = G[u][i];
		
		if( v != ojciec )
		{
			if( !odw[v] )
			{
				++synowie;
				
				DFS( v, u );
				
				if( low[v] >= preorder[u] )
				{
					test = true;
				}
				
				low[u] = min( low[u], low[v] ); // uwzgledniamy low dla syna
			}
		}
	}
	
	REP(i,0,r-1)
	{
		v = G[u][i];
		
		if( v != ojciec )
		{
			if( odw[v] )
			{
				low[u] = min( low[u], low[v] ); // uwzgledniamy low dla konca krawedzi wtornej
			}
		}
	}
	
	if( ojciec == UNDEF ) // jesli u - korzen
	{
		if( synowie >= 2 ) // jesli mamy przynajmniej 2 synow dla korzenia
		{
			punkt_artykulacji[u] = true;
		}
	}
	else
	{
		if( test == true ) // jesli istnieje syn (dla wierzcholka 'u'), z ktorego nie pojdziemy krawedzia wtorna do jakiegos przodka wierzcholka 'u' 
		{
			punkt_artykulacji[u] = true;
		}
	}
}


void oblicz()
{
	REP(u,0,n-1)
	{
		if( !odw[u] )
		{
			DFS( u, UNDEF );
		}
	}
}


void wypisz()
{
	REP(u,0,n-1)
	{
		printf( "low[%d] = %d\n", u, low[u] );
	}
	
	printf( "\n\n\n" );
	
	REP(u,0,n-1)
	{
		if( punkt_artykulacji[u] == true )
		{
			printf( "wierzcholek nr %d jest punktem artykulacji\n", u );
		}
		else
		{
			printf( "wierzcholek nr %d nie jest punktem artykulacji\n", u );
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
