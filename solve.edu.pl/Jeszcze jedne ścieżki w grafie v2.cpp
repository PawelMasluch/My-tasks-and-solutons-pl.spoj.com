#include<cstdio> // 100 pkt
#include<new>
#include<vector>
#include<queue>


#define REP(i,a,b) for(i=a; i<=b; ++i)

#define MP make_pair

#define PB push_back

#define C clear

#define P push

#define ST first

#define ND second


using namespace std;


typedef long long LL;

typedef pair < LL, LL > pLL;

typedef vector < pLL > V_pLL;

typedef priority_queue < pair < LL, LL > > PQ_pLL;


const LL INF = (LL)1000000000 * 1000070000;


int main()
{
	PQ_pLL PQ; // strutura do Dijkstry - najpierw koszt, potem dokąd ten koszt prowadzi
	
	LL n, m, i, j, l, u, v, w, *r, **d, q;
	
	scanf("%lld%lld", &n, &m); // liczba wierzchołków i krawędzi grafu
	
	r = new LL [n+1];
	
	r[0] = n; // z góry wiemy, że stopień wyjściowy dla "0" wynosi n
	
	d = new LL *[n+1];
	
	d[0] = new LL [n+1];
	
	V_pLL *G = new V_pLL [n+1]; // najpierw koszt, potem dokąd dojdę
	
	bool *odw = new bool [n+1]; // nie potrzebuję odw[0]
	
	REP(i,1,n) // inicjacja stopni wyjściowych, krawędzie z "0" do reszty i tworzenie tablicy "d"
	{
		r[i] = 0;
		
		G[0].PB( MP( 0, i ) );
		
		d[i] = new LL [n+1];
	}
	
	REP(i,1,m) // wczytanie każdej krawędzi
	{
		scanf("%lld%lld%lld", &u, &v, &w);
		
		G[u].PB( MP( w, v ) );
		
		++r[u];
	}
	
	/*** Bellman - Ford ***/
	
	REP(i,1,n) // inicjacja najlepszych odległości
	{
		d[0][i] = INF;
	}
	
	d[0][0] = 0;
	
	REP(l,1,n) // |V| - 1 kroków
	{
		REP(u,0,n) // w tej i następnej pętli obchodzę wszystkie krawędzie
		{
			REP(j,0,r[u]-1)
			{
				v = G[u][j].second;
				
				w = G[u][j].first;
				
				d[0][ v ] = min( d[0][ v ], d[0][ u ] + w );
			}
		}	
	}
	
	/*** Zmiana wag krawędzi ***/
	
	REP(i,1,n) // w tej i następnej pętli obchodzę wszystkie krawędzie
	{
		REP(j,0,r[i]-1)
		{
			G[i][j].first += d[0][ i ] - d[0][ G[i][j].second ];
		}
	}
	
	/*** Dijkstra z każdego wierzchołka ***/
	
	REP(i,1,n)
	{
		REP(j,1,n)
		{
			d[i][j] = INF;
			
			odw[j] = false;
		}
		
		d[i][i] = 0;
		
		PQ.P( MP( 0, i ) );
		
		while( !PQ.empty() )
		{
			u = PQ.top().ND;
			
			PQ.pop();
			
			if( !odw[u] )
			{
				REP(j,0,r[u]-1)
				{
					v = G[u][j].ND;
					
					w = G[u][j].ST;
					
					if( d[i][v] > d[i][u] + w )
					{
						d[i][v] = d[i][u] + w;
						
						PQ.P( MP( -d[i][v], v ) );
					}
				}
				
				odw[u] = true;
			}
		}
	}
	
	REP(i,1,n)
	{
		REP(j,1,n)
		{
			if( d[i][j] != INF )
			{
				d[i][j] += d[0][j] - d[0][i];
			}
		}
	}
	
	scanf("%lld", &q);
	
	while( q )
	{
		scanf("%lld%lld", &u, &v);
		
		if( d[u][v] == INF )
		{
			printf( "NIE\n" );
		}
		else
		{
			printf( "%lld\n", d[u][v] );	
		}
		
		--q;
	}
	
	return 0;
}
