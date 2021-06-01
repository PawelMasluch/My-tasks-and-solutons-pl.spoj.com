#include<cstdio> // 100 pkt
#include<new>
#include<vector>
#include<queue>


#define REP(i,a,b) for(i=a; i<=b; ++i)

#define PB push_back

#define MP make_pair

#define P push

#define ND second

#define ST first

using namespace std;


typedef pair < int, int > pII;

typedef pair < pII, int > el;

typedef vector < el > Vel;

typedef priority_queue < pII > PQ_pII;


const int INF = 2000000009;

const int UNDEF = -1;


int main()
{
	pII p;
	
	PQ_pII PQ;
	
	bool *odw;
	
	Vel *G;
	
	int n, m, i, *rozm, *d, *last, u, v, w, num, wyn = 0;
	
	scanf("%d%d", &n, &m);
	
	d = new int [n];
	
	rozm = new int [n];
	
	last = new int [n];
	
	odw = new bool [n];
	
	REP(i,0,n-1)
	{
		rozm[i] = 0;
		
		d[i] = INF;
		
		last[i] = UNDEF;
		
		odw[i] = false;
	}
	
	d[0] = 0;
	
	G = new Vel [n];
	
	REP(i,0,m-1)
	{
		scanf("%d%d%d", &u, &v, &w);
		
		--u;
		
		--v;
		
		G[u].PB( MP( MP( w, v ), i ) );
		
		++rozm[u];
		
		G[v].PB( MP( MP( w, u ), i ) );
		
		++rozm[v];
	}
	
	PQ.P( MP( 0, 0 ) );
	
	while( !PQ.empty() )
	{
		p = PQ.top();
		
		PQ.pop();
		
		u = p.ND;
		
		if( !odw[u] )
		{
			REP(i,0,rozm[u]-1)
			{
				v = G[u][i].ST.ND;
				
				w = G[u][i].ST.ST;
				
				num = G[u][i].ND;
				
				if( d[v] > d[u] + w )
				{
					d[v] = d[u] + w;
					
					last[v] = num;
					
					PQ.P( MP( -d[v], v ) );
				}
			}
			
			odw[u] = true;
		}
	}
	
	REP(i,0,n-1)
	{
		if( last[i] != UNDEF )
		{
			++wyn;
		}
	}
	
	printf("%d\n", wyn);
	
	REP(i,0,n-1)
	{
		if( last[i] != UNDEF )
		{
			printf("%d ", last[i] + 1);
		}
	}
	
	printf("\n");
	
	return 0;
}
