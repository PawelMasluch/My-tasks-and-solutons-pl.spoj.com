#include<cstdio> // 100 pkt
#include<vector>


using namespace std;


typedef long long LL;

typedef vector < int > VI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back

#define S size


const int MAX_N = 500000, UNDEF = -1;


VI G[MAX_N];

LL S[MAX_N], T[MAX_N];

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
		poddrzewo[u] = 1;
		
		S[u] = 0;
		
		T[u] = 0;
	}
}


void DFS_S(int u, int ojciec)
{
	int r = G[u].S(), v;
	
	REP(i,0,r-1)
	{
		v = G[u][i];
		
		if( v != ojciec )
		{
			DFS_S( v, u );
			
			S[u] += ( S[v] + poddrzewo[v] );
			
			poddrzewo[u] += poddrzewo[v];
		}
	}
}


void DFS_T(int u, int ojciec)
{
	int r = G[u].S(), v;
	
	REP(i,0,r-1)
	{
		v = G[u][i];
		
		if( v != ojciec )
		{
			T[v] = T[u] + S[u] + n - S[v] - 2*poddrzewo[v];
			
			DFS_T( v, u );
		}
	}
}


void oblicz()
{
	DFS_S( 0, UNDEF ); // wyliczamy tablice 'poddrzewo' oraz 'S'
	
	DFS_T( 0, UNDEF ); // wyliczamy tablice 'T'
}


void wypisz() // dla kazdego wierzcholka 'u' drzewa, wypisywanie sum odleglosci od 'u' do pozostalych wierzcholkow drzewa 
{
	REP(u,0,n-1)
	{
		printf( "%lld\n", S[u] + T[u] ); // dla wierzcholka 'u' drzewa, wynik to S[u] + T[u]
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
