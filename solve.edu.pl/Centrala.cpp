#include<cstdio> // 100 pkt
#include<new>
#include<vector>
#include<queue>


#define REP(i,n) for(i=0; i<n; ++i)

#define PB push_back

#define MP make_pair

#define ST first

#define ND second


using namespace std;


typedef long long LL;

typedef pair < int, int > PII;

typedef vector < PII > VPII;

typedef queue < int > QI;


void f(int u, VPII *G, int *rG, bool *odw, int *r) // wyliczam rozmiary poddrzew
{
	int i, v;
	
	REP(i,rG[u])
	{
		v = G[u][i].ND;
		
		if( !odw[v] )
		{
			odw[v] = true;
			
			f( v, G, rG, odw, r );
			
			r[u] += r[v];
		} 
	}
}


int main()
{
	QI Q;
	
	VPII *G;
	
	bool *odw;
	
	int N, i, *rG, u, v, w, *r;
	
	LL *d, *DP, SUMA = 0, wyn;
	
	scanf("%d", &N);
	
	G = new VPII [N];
	
	rG = new int [N];
	
	DP = new LL [N];
	
	odw = new bool [N];
	
	d = new LL [N];
	
	r = new int [N];
	
	REP(i,N)
	{
		rG[i] = 0;
		
		r[i] = 1;
		
		odw[i] = false;
	}
	
	REP(i,N-1)
	{
		scanf("%d%d%d", &u, &v, &w);
		
		--u;   --v;
		
		G[u].PB( MP( w, v ) );   G[v].PB( MP( w, u ) );
		
		++rG[u];   ++rG[v];
	}
	
	d[0] = 0;
	
	odw[0] = true;
	
	Q.push(0);
	
	while( !Q.empty() )
	{
		u = Q.front();
		
		Q.pop();
		
		REP(i,rG[u])
		{
			v = G[u][i].ND;
			
			w = G[u][i].ST;
			
			if( !odw[v] )
			{
				odw[v] = true;
				
				Q.push(v);
				
				d[v] = d[u] + w;
				
				SUMA += d[v];
			}
		}
	}
	
	DP[0] = wyn = SUMA;
	
	REP(i,N)
	{
		odw[i] = false;
	}
	
	odw[0] = true;
	
	f( 0, G, rG, odw, r );
	
	REP(i,N)
	{
		odw[i] = false;
	}
	
	odw[0] = true;
	
	Q.push(0);
	
	while( !Q.empty() )
	{
		u = Q.front();
		
		Q.pop();
		
		REP(i,rG[u])
		{
			v = G[u][i].ND;
			
			w = G[u][i].ST;
			
			if( !odw[v] )
			{
				odw[v] = true;
				
				Q.push(v);
				
				DP[v] = DP[u] + (LL)w * ( N - 2 * r[v] );
				
				wyn = min( wyn, DP[v] );
			}
		}
	}
	
	printf("%lld\n", wyn);
	
	return 0;
}
