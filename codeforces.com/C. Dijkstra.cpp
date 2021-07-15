#include<iostream> // AC
#include<vector>
#include<queue>
#include<stack>
 
 
using namespace std;
 
 
typedef long long LL;
 
typedef pair < LL, LL > PLL;
 
typedef vector < PLL > VPLL;
 
typedef stack < LL > SLL;
 
typedef priority_queue < PLL > PQPLL;
 
 
#define REP(i,a,b) for(LL i=a; i<=b; ++i)
 
#define MP make_pair
 
#define ST first
 
#define ND second
 
#define PB push_back
 
#define S size
 
#define C clear
 
#define P push
 
#define T top
 
#define p pop
 
#define E empty
 
 
const LL MAX_N = 100000, INF = (LL)1000000099 * 1000000009, UNDEF = -1;
 
 
SLL STOS;
 
PQPLL PQ;
 
VPLL G[MAX_N];
 
bool czy[MAX_N];
 
LL n, m, d[MAX_N], last[MAX_N];
 
 
void wczytaj()
{
	cin >> n >> m;
	
	LL u, v, w;
	
	REP(i,0,m-1)
	{
		cin >> u >> v >> w;
		
		--u;  --v;
		
		G[u].PB( MP( w, v ) );
		
		G[v].PB( MP( w, u ) );
	}
}
 
 
void Dijkstra(LL s)
{
	REP(i,0,n-1)
	{
		czy[i] = false;
		
		d[i] = INF;
		
		last[i] = UNDEF;
	}
	
	d[s] = 0;
	
	PQ.P( MP( -d[s], s ) );
	
	LL u, v, w, r;
	
	while( !PQ.E() )
	{
		u = PQ.T().ND;
		
		PQ.p();
		
		if( czy[u] == false )
		{
			r = G[u].S();
			
			REP(i,0,r-1)
			{
				v = G[u][i].ND;
				
				w = G[u][i].ST;
				
				if( d[v] > d[u] + w )
				{
					d[v] = d[u] + w;
					
					last[v] = u;
					
					PQ.P( MP( -d[v], v ) );
				}
			}
			
			czy[u] = true;
		}
	}
}
 
 
void wypisz()
{
	LL tmp = n - 1;
	
	if( d[ tmp ] == INF )
	{
		cout << "-1\n";
		
		return;
	}
	
	while( last[ tmp ] != UNDEF )
	{
		STOS.P( tmp + 1 );
		
		tmp = last[ tmp ];
	}
	
	STOS.P( 1 );
	
	while( !STOS.E() )
	{
		cout << STOS.T() << " ";
		
		STOS.p();
	}
	
	cout << endl;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	wczytaj();
	
	Dijkstra( 0 );
	
	wypisz();
	
	return 0;
}
