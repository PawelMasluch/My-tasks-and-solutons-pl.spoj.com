#include<cstdio>
#include<vector>


using namespace std;


typedef vector < int > VI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back

#define S size


const int MAX_N = 1000000, UNDEF = -1;


VI G[MAX_N];

bool odw[MAX_N], centroid[MAX_N];

int n, m, poddrzewo[MAX_N];


void wczytaj() // wszystko numerowane od zera
{
	scanf( "%d %d", &n, &m );
	
	int u, v;
	
	REP(i,1,m)
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
		odw[u] = false;
		
		centroid[u] = true;
		
		poddrzewo[u] = 1;
	}
}


void DFS_1(int u, int ojciec) // sprawdzam, czy jakis syn wierzcholka 'u' ma za duze poddrzewo
{
	odw[u] = true;
	
	int r = G[u].S(), v;
	
	REP(i,0,r-1)
	{
		v = G[u][i];
		
		if( v != ojciec ) // mozna te¿ !odw[v]
		{
			DFS_1( v, u );
			
			if( poddrzewo[v] > n / 2 )
			{
				centroid[u] = false;
			}
			
			poddrzewo[u] += poddrzewo[v];
		}
	}
}


void DFS_2(int u, int ojciec, int rozmiar_skladowej) // sprawdzam, czy poza poddrzewem wierzcholka 'u' jest za duzo wierzcholkow
{
	if( rozmiar_skladowej - poddrzewo[u] > rozmiar_skladowej / 2 ) // jesli poza poddrzewem wierzcholka 'u' jest za duzo wiezcholkow
	{
		centroid[u] = false;	
	}
	
	int r = G[u].S(), v;
	
	REP(i,0,r-1)
	{
		v = G[u][i];
		
		if( v != ojciec )
		{
			DFS_2( v, u, rozmiar_skladowej );
		}
	}	
}


void oblicz()
{
	REP(u,0,n-1)
	{
		if( !odw[u] )
		{
			DFS_1( u, UNDEF );
			
			DFS_2( u, UNDEF, poddrzewo[u] );
		}
	}
}


void wypisz()
{
	REP(u,0,n-1)
	{
		if( centroid[u] == true )
		{
			printf( "wierzcholek %d jest centroidem\n", u );
		}
		else
		{
			printf( "wierzcholek %d nie jest centroidem\n", u );
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
