#include<cstdio> // 100 pkt
#include<vector>
#include<queue>


using namespace std;


typedef pair < int, int > PII;

typedef vector < int > VI;

typedef vector < PII > VPII;

typedef queue < int > QI;

typedef priority_queue < PII > PQPII;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back

#define C clear

#define MP make_pair

#define ST first

#define ND second

#define S size

#define P push

#define F front

#define p pop

#define E empty


const int MAX_N = 500000, UNDEF = -1, INF = 1000000099;


QI Q;

PQPII PQ;

VI last[MAX_N];

VPII G[MAX_N];

int n, m, d[MAX_N];

bool odw[MAX_N];


void wczytaj()
{
	scanf( "%d %d", &n, &m );
	
	int a, b, c; 
	
	REP(i,0,m-1)
	{
		scanf( "%d %d %d", &a, &b, &c );
		
		--a;  --b;
		
		G[a].PB( MP( c, b ) );
		
		G[b].PB( MP( c, a ) );
	}
}


void Dijkstra()
{
	REP(i,0,n-1)
	{
		d[i] = INF;
		
		odw[i] = false;
	}
	
	d[0] = 0;
	
	PQ.P( MP( 0, 0 ) );
	
	int u, v, w, r;
	
	while( !PQ.E() )
	{
		u = PQ.top().ND;
		
		PQ.pop();
		
		if( !odw[u] )
		{
			r = G[u].S();
		
			REP(i,0,r-1)
			{
				v = G[u][i].ND;
				
				w = G[u][i].ST;
				
				if( d[u] + w < d[v] )
				{
					d[v] = d[u] + w;
					
					last[v].C();
					
					last[v].PB( u );
					
					PQ.P( MP( -d[v], v ) );
				}
				else
				{
					if( d[u] + w == d[v] )
					{
						last[v].PB( u );
					}
				}
			}
			
			odw[u] = true;
		}
	}
}


void wypisz()
{
	REP(i,0,n-1)
	{
		odw[i] = false;
	}
	
	int u = n - 1, v, r;
	
	Q.P( u );
	
	while( !Q.E() )
	{
		u = Q.F();
		
		Q.p();
		
		if( !odw[u] )
		{
			r = last[u].S();
		
			REP(i,0,r-1)
			{
				v = last[u][i];
				
				if( !odw[v] )
				{
					Q.P( v );
				}
			}
			
			odw[u] = true;
		}
	}
	
	REP(i,0,n-1)
	{
		if( odw[i] )
		{
			printf( "%d\n", i + 1 );
		}
	}
}


int main()
{
	wczytaj();
	
	Dijkstra();
	
	wypisz();
	
	return 0;
}
