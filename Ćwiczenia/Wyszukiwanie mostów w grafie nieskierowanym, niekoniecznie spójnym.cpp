#include<cstdio>
#include<vector>


using namespace std;


typedef pair < int, int > PII;

typedef vector < int > VI;

typedef vector < PII > VPII;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define MP make_pair

#define ST first // sasiad jakiegos wierzcholka (struktura G)

#define ND second // numer krawedzi na liscie krawedzi (struktura G)

#define PB push_back

#define S size


const int MAX_N = 1000000, MAX_M = 1000000, INF = MAX_N + 199, UNDEF = -1;


bool odw[MAX_N], most[MAX_M];

PII edge[MAX_M]; // w tej strukturze elementy pary to wierzcholki stanowiace konce krawedzi 

VPII G[MAX_N];

int n, m, low[MAX_N], preorder[MAX_N], czas = 0; 


void wczytaj() // wszystko numerowane od zera
{
	scanf( "%d %d", &n, &m );
	
	int u, v;
	
	REP(i,0,m-1)
	{
		scanf( "%d %d", &u, &v );
		
		edge[i].ST = u;
		
		edge[i].ND = v;;
		
		G[u].PB( MP( v, i ) );
		
		G[v].PB( MP( u, i ) );
	}
}


void init()
{
	REP(u,0,n-1)
	{
		odw[u] = false; // nie trzeba tej linijki, ale dla porzadku niech bedzie
		
		low[u] = INF;
	}
	
	REP(i,0,m-1)
	{
		most[i] = false; // poczatkowo zakladamy, ze i-ta krawedz nie jest mostem
	}
}


int min(int a, int b)
{
	return ( a < b ) ? a : b ;
}


void DFS(int u, int ojciec, int nr_krawedzi)
{
	odw[u] = true;
	
	preorder[u] = czas;
	
	++czas;
	
	low[u] = min( low[u], preorder[u] );
	
	int r = G[u].S(), v, nr;
	
	REP(i,0,r-1)
	{
		v = G[u][i].ST;
		
		nr = G[u][i].ND; // nr krawedzi u-v na liscie krawedzi
		
		if( v != ojciec )
		{
			if( !odw[v] )
			{
				DFS( v, u, nr );
				
				low[u] = min( low[u], low[v] ); // uwzgledniamy low dla syna
			}
		}
	}
	
	REP(i,0,r-1)
	{
		v = G[u][i].ST;
		
		if( v != ojciec )
		{
			if( odw[v] )
			{
				low[u] = min( low[u], low[v] ); // uwzgledniamy low dla konca krawedzi wtornej
			}
		}
	}
	
	if( low[u] == preorder[u] )
	{
		if( ojciec != UNDEF )
		{
			most[ nr_krawedzi ] = true;
		}
	}
}


void oblicz()
{
	REP(u,0,n-1)
	{
		if( !odw[u] )
		{
			DFS( u, UNDEF, UNDEF );
		}
	}
}


void wypisz()
{
	int u, v;
	
	REP(u,0,n-1)
	{
		printf( "low[%d] = %d\n", u, low[u] );
	}
	
	printf( "\n\n\n" );
	
	REP(i,0,m-1)
	{
		u = edge[i].ST;
		
		v = edge[i].ND;
		
		if( most[i] == true )
		{
			printf( "krawedz nr %d, czyli z wierzcholka %d do wierzcholka %d, jest mostem\n", i, u, v );
		}
		else
		{
			printf( "krawedz nr %d, czyli z wierzcholka %d do wierzcholka %d, nie jest mostem\n", i, u, v );
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
