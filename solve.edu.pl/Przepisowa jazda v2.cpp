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


#define REP(i,a,b) for(LL i=a; i<=b; ++i)

#define PB push_back

#define MP make_pair

#define ST first

#define ND second


const LL INF = (LL)1009000000 * 1000000000;


LL u, v, w;


void ustaw(bool *odw, LL N)
{
	REP(i,0,N-1)
	{
		odw[i] = false;
	}
}


void inicjuj(LL *t, LL N, LL val)
{
	REP(i,0,N-1)
	{
		t[i] = val;
	}
}


void wypelnij(VpLLL *G, LL *rG, LL N, LL M)
{
	inicjuj( rG, N, 0 );
	
	REP(i,0,M-1)
	{
		scanf( "%lld%lld%lld", &u, &v, &w );
		
		--u;  --v;
		
		G[u].PB( MP( MP( w, v ), 0 ) ); // oryginalna krawêdŸ to "0"
		
		++rG[u];
	}
}


void dodaj_krawedzie(VpLLL *G, LL *rG, LL N)
{
	LL j = 0;
	
	REP(i,0,N-1)
	{
		while( j <= rG[i] - 1 )
		{
			if( G[i][j].ND == 0 )
			{
				v = G[i][j].ST.ND;
				
				w = G[i][j].ST.ST;
				
				G[v].PB( MP( MP( w, i ), 1 ) ); // nieoryginalna krawêdŸ to "1"
				
				++rG[v];
				
				++j;
			}
			else
			{
				break;
			}
		}
		
		j = 0;
	}
}


void Dijkstra(VpLLL *G, LL *rG, LL N, bool *odw, LL faza, LL **d)
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
			REP(i,0,rG[u]-1)
			{
				v = G[u][i].ST.ND;
				
				w = G[u][i].ST.ST;
				
				zm = G[u][i].ND;
						
				if( d[ faza - zm ][u] + w < d[ faza ][v] )
				{
					d[ faza ][v] = d[ faza - zm ][u] + w;
					
					PQ.push( MP( -d[ faza ][v], v ) );
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
	
	LL N, M, K, *rG, **d;
	
	scanf( "%lld%lld%lld", &N, &M, &K );
	
	odw = new bool [N];
	
	d = new LL *[K+1];
	
	REP(i,0,K)
	{
		d[i] = new LL [N];
	}
	
	rG = new LL [N];
	
	G = new VpLLL [N];
	
	wypelnij( G, rG, N, M );
	
	Dijkstra( G, rG, N, odw, 0, d ); // uwzglêdniamy tylko oryginalne krawêdzie
	
	dodaj_krawedzie( G, rG, N );
	
	REP(i,1,K)
	{
		Dijkstra( G, rG, N, odw, i, d ); // uwzglêdniamy te¿ nieoryginalne krawêdzie
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
