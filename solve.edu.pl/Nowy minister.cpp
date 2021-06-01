#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,n) for(int i=0; i<n; ++i)


const int MAX_N = 300000;


int n, m, q, repr[MAX_N], ile[MAX_N];


int Find(int u)
{
	int v = u;
	
	while( repr[v] != v )
	{
		v = repr[v];
	}
	
	repr[u] = v;
	
	return v;
}


void Union(int u, int v)
{
	int ru = Find( u ), rv = Find( v );
	
	if( ile[ ru ] >= ile[ rv ] )
	{
		ile[ ru ] += ile[ rv ];
		
		repr[ rv ] = ru;
	}
	else
	{
		ile[ rv ] += ile[ ru ];
		
		repr[ ru ] = rv;
	}
}


void init()
{
	REP(u,MAX_N)
	{
		repr[u] = u;
		
		ile[u] = 1;
	}
}


void wczytaj_dane()
{
	int u, v;
	
	scanf( "%d %d %d", &n, &m, &q );
	
	REP(i,m)
	{
		scanf( "%d %d", &u, &v );
		
		Union( --u, --v );
	}
}


void obsluz_zapytania()
{
	int w, u, v;
	
	while( q )
	{
		scanf( "%d %d %d", &w, &u, &v );
		
		if( w == 1 )
		{
			Union( --u, --v );
		}
		else // w == 0
		{
			if(   Find( --u ) == Find( --v )   )
			{
				printf( "TAK\n" );
			}
			else
			{
				printf( "NIE\n" );
			}
		}
		
		--q;
	}
}


int main()
{
	init();
	
	wczytaj_dane();
	
	obsluz_zapytania();
	
	return 0;
}
