#include<cstdio> // 100 pkt
#include<vector>


using namespace std;


typedef vector < int > VI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back

#define S size


const int MAX_N = 1000000; 


VI G[MAX_N];

bool odw[MAX_N];

int n, m;


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


void oblicz()
{
	int u = 0, r = G[u].S(), v, r1, w;
	
	odw[u] = true;
	
	REP(i,0,r-1)
	{
		v = G[u][i];
		
		if( odw[v] == false )
		{
			odw[v] = true;
		
			r1 = G[v].S();
			
			REP(j,0,r1-1)
			{
				w = G[v][j];
				
				odw[w] = true;
			}
		}
	}
}


void wypisz()
{
	REP(u,0,n-1)
	{
		if( odw[u] == true )
		{
			printf( "%d ", u + 1 );
		}
	}
	
	printf( "\n" );
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
