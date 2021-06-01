#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 1000000, MAX_EXP = 29;


int n, p[MAX_N], repr[MAX_N], r[MAX_N];


void wczytaj()
{
	scanf( "%d", &n );
	
	REP(u,0,n-1)
	{
		scanf( "%d", &p[u] );
	}
}


void init()
{
	REP(u,0,n-1)
	{
		repr[u] = u;
		
		r[u] = 1;
	}
}


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


void Union(int u, int v) // zakladam, ze u, v sa w roznych zbiorach
{
	int ru = Find( u ), rv = Find( v );
	
	if( r[ ru ] >= r[ rv ] )
	{
		repr[ rv ] = ru;
		
		r[ ru ] += r[ rv ];
	}
	else // r[ ru ] < r[ rv ]
	{
		repr[ ru ] = rv;
		
		r[ rv ] += r[ ru ];
	}
}


void oblicz()
{
	int u, prev;
	
	REP(i,0,MAX_EXP)
	{
		u = 0;
		
		while(   ( p[u] & ( 1 << i ) ) == 0  &&  u < n   )
		{
			++u;
		}
		
		prev = u;
		
		REP(v,u+1,n-1)
		{
			if(   ( p[v] & ( 1 << i ) ) != 0 )
			{
				if( Find( prev )  !=  Find( v ) )
				{
					Union( prev, v );
				}
				
				prev = v;
			}
		}
	}	
}


void wypisz()
{
	int wyn = 0;
	
	REP(u,0,n-1)
	{
		if( repr[u] == u )
		{
			++wyn;
		}
	}
	
	printf( "%d\n", wyn );
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
