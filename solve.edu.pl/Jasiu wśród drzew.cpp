#include<cstdio> // 100 pkt
#include<vector> // to zadanie polega na sprawdzeniu, czy graf wejściowy jest drzewem


using namespace std;


typedef vector < int > VI;


#define REP(i,n) for(int i=0; i<n; ++i)

#define PB push_back

#define S size


const int MAX_N = 500000;


VI G[MAX_N];

bool odw[MAX_N];

int n, m;


void wczytaj()
{
	scanf( "%d %d", &n, &m );
	
	int u, v;
	
	REP(i,m)
	{
		scanf( "%d %d", &u, &v );
		
		--u;  --v;
		
		G[u].PB( v );  G[v].PB( u );
	}
}


void DFS(int u)
{
	odw[u] = true;
	
	int r = G[u].S(), v;
	
	REP(i,r)
	{
		v = G[u][i];
		
		if( !odw[v] )
		{
			DFS(v);
		}
	}
}


bool spojny()
{
	DFS(0);
	
	REP(i,n)
	{
		if( !odw[i] )
		{
			return false;
		}
	}
	
	return true;
}


void wypisz()
{
	if( spojny()  &&  m == n - 1 )
	{
		printf( "TAK\n" );
	}
	else
	{
		printf( "NIE\n" );
	}
}


int main()
{
	wczytaj();
	
	wypisz();
	
	return 0;
}
