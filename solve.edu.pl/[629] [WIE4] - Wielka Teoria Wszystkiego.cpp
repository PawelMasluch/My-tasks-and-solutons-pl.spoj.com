#include<cstdio> // 100 pkt
#include<vector>


using namespace std;


typedef pair < int, int > PII;

typedef vector < PII > VPII;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back

#define S size

#define MP make_pair

#define ST first

#define ND second


const int MAX_N = 7000, INF = 1000099;


VPII G[MAX_N];

bool odw[MAX_N];

int n, m, wyn = 0, d[MAX_N];


void init()
{
	REP(u,0,n-1)
	{
		d[u] = INF;
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
		
		--u;    --v;
		
		G[u].PB( MP( w, v ) );
		
		G[v].PB( MP( w, u ) );
	}
}


int min(int a, int b)
{
	return ( a < b ) ? a : b ;
}


void oblicz()
{
	int ile = 1, r = G[0].S(), v, w, u_min, w_min = INF;
	
	odw[0] = true;
	
	REP(i,0,r-1)
	{
		w = G[0][i].ST;
		
		v = G[0][i].ND;
		
		d[v] = w;
	}
	
	while( ile < n )
	{
		w_min = INF;
		
		REP(u,0,n-1)
		{
			if( odw[u] == false )
			{
				if( d[u] < w_min )
				{
					w_min = d[u];
					
					u_min = u;
				}
			}
		}
		
		wyn += w_min;
		
		odw[ u_min ] = true;
		
		++ile;
		
		r = G[ u_min ].S();
		
		REP(i,0,r-1)
		{
			w = G[ u_min ][i].ST;
			
			v = G[ u_min ][i].ND;
			
			if( odw[v] == false )
			{
				d[v] = min( d[v], w );
			}
		}
	}
}


void wypisz()
{
	printf( "%d\n", wyn );
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
