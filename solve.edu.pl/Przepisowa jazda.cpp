#include<cstdio> // 100 pkt
#include<new>
#include<vector>
#include<queue>


using namespace std;


typedef long long LL;

typedef pair < LL, LL > pLL;

typedef pair < pLL, LL > pLLL;

typedef vector < pLLL > VpLLL;

typedef priority_queue < pLL > PQpLL;


#define REP(i,n) for(LL i=0; i<n; ++i)

#define PB push_back

#define MP make_pair

#define ST first

#define ND second


const LL INF = (LL)1009000000 * 1000000000;


LL u, v, w;


void wypisz(LL *t, LL N)
{
	REP(i,N)
	{
		if( t[i] == INF )
		{
			printf( "INF " );
		}
		else
		{
			printf( "%lld ", t[i] );
		}
	}
	
	printf("\n");
}


void ustaw(bool *odw, LL N)
{
	REP(i,N)
	{
		odw[i] = false;
	}
}


void inicjuj(LL *t, LL N, LL val)
{
	REP(i,N)
	{
		t[i] = val;
	}
}


void wypelnij(LL N, LL M, VpLLL *G, LL *rG)
{
	inicjuj( rG, N, 0 );
	
	REP(i,M)
	{
		scanf( "%lld%lld%lld", &u, &v, &w );
		
		--u;  --v;
		
		G[u].PB( MP( MP( w, v ), 0 ) ); // oryginalnana krawêdŸ to "0"
		
		G[v].PB( MP( MP( w, u ), 1 ) ); // nieoryginalnana krawêdŸ to "1"
		
		++rG[u];  ++rG[v];
	}
}


void Dijkstra(VpLLL *G, LL N, LL *rG, bool *odw, LL *d)
{
	PQpLL PQ;
	
	ustaw( odw, N );
	
	inicjuj( d, N, INF );
	
	d[0] = 0;
	
	PQ.push( MP( 0, 0 ) );
	
	while( !PQ.empty() )
	{
		u = PQ.top().ND;
		
		PQ.pop();
		
		if( !odw[u] )
		{
			REP(i,rG[u])
			{
				v = G[u][i].ST.ND;
				
				w = G[u][i].ST.ST;
				
				if( G[u][i].ND == 0 )
				{
					if( d[u] + w < d[v] )
					{
						d[v] = d[u] + w;
						
						PQ.push( MP( -d[v], v ) );
					}
				}
			}
			
			odw[u] = true;
		}
	}
}


void Dijkstra1(VpLLL *G, LL N, LL *rG, bool *odw, LL faza, LL **d)
{
	PQpLL PQ;
	
	LL zm;
	
	ustaw( odw, N );
	
	inicjuj( d[faza], N, INF );
	
	d[faza][0] = 0;
	
	PQ.push( MP( 0, 0 ) );
	
	while( !PQ.empty() )
	{
		u = PQ.top().ND;
		
		PQ.pop();
		
		if( !odw[u] )
		{
			REP(i,rG[u])
			{
				v = G[u][i].ST.ND;
				
				w = G[u][i].ST.ST;
				
				zm = G[u][i].ND;
						
				if( d[ faza - zm ][u] + w < d[faza][v] )
				{
					d[faza][v] = d[ faza - zm ][u] + w;
					
					PQ.push( MP( -d[faza][v], v ) );
				}
			}
			
			odw[u] = true;
		}
	}
}


int main()
{
	VpLLL *G;
	
	bool *odw;
	
	LL N, M, K, *rG, i, **d;
	
	scanf( "%lld%lld%lld", &N, &M, &K );
	
	odw = new bool [N];
	
	d = new LL *[K+1];
	
	REP(i,K+1)
	{
		d[i] = new LL [N];
	}
	
	rG = new LL [N];
	
	G = new VpLLL [N];
	
	wypelnij( N, M, G, rG );
	
	Dijkstra( G, N, rG, odw, d[0] ); // uwzglêdniamy tylko oryginalne krawêdzie
	
	//wypisz( d[0], N );
	
	REP(i,K)
	{
		Dijkstra1( G, N, rG, odw, i + 1, d ); // uwzglêdniamy te¿ nieoryginalne krawêdzie 
		
		//wypisz( d[ i + 1 ], N );
	}
	
	if( d[K][ N - 1 ] == INF )
	{
		printf( "NIE\n" );
	}
	else
	{
		printf( "%lld\n", d[K][ N - 1 ] );
	}
	
	return 0;
}
