#include<cstdio>
#include<vector>


using namespace std;


typedef vector < int > VI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back

#define S size


const int MAX_N = 1000000;


VI G[MAX_N];

int n, d1[MAX_N], d2[MAX_N], wyn = 0;


int max(int a, int b)
{
	return ( a > b ) ? a : b ;
}


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


void oblicz(int u, int ojciec)
{
	int r = G[u].S(), v;
	
	REP(i,0,r-1)
	{
		v = G[u][i];
		
		if( v != ojciec )
		{
			oblicz( v, u );
			
			if( d1[v] + 1 > d1[u] )
			{
				d2[u] = d1[u];
				
				d1[u] = d1[v] + 1;
			}
			else
			{
				d2[u] = max( d2[u], d1[v] + 1 );
			}
		}
	}
	
	wyn = max( wyn, d1[u] + d2[u] );
}


void wypisz()
{
	printf( "%d\n", wyn );
}


int main()
{
	wczytaj();
	
	oblicz( 0, -1 );
	
	wypisz();
	
	return 0;
}
