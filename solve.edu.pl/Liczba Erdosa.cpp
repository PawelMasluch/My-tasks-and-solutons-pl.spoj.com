#include<cstdio> // 100 pkt
#include<new>
#include<queue>
#include<vector>


#define REP(i,n) for(i=0; i<n; ++i)

#define D delete

#define C clear

#define PB push_back


using namespace std;


typedef queue < int > QI;

typedef vector < int > VI;


const int INF = 10000009;


int main()
{
	QI Q;
	
	int N, M, E, i, j, u, v;
	
	scanf("%d%d%d", &N, &M, &E);
	
	--E;
	
	VI *G = new VI [N];
	
	int *rozm = new int [N], *d = new int [N];
	
	bool *odw = new bool [N];
	
	REP(i,N)
	{
		odw[i] = false;
		
		rozm[i] = 0;
		
		d[i] = INF;
	}
	
	d[E] = 0;
	
	REP(i,M)
	{
		scanf("%d%d", &u, &v);
		
		--u;
		--v;
		
		G[u].PB(v);
		++rozm[u];
		
		G[v].PB(u);
		++rozm[v];
	}
	
	Q.push(E);
	
	odw[E] = true;
	
	while( !Q.empty() )
	{
		u = Q.front();
		
		Q.pop();
		
		REP(i,rozm[u])
		{
			v = G[u][i];
			
			if( !odw[v] )
			{
				odw[v] = true;
				
				Q.push(v);
			}
			
			d[v] = min( d[v], d[u] + 1 );
		}
	}
	
	D [] rozm;
	
	D [] odw;
	
	REP(i,N)
	{
		G[i].C();
		
		if( d[i] != INF )
		{
			printf("%d\n", d[i]);
		}
		else
		{
			printf("-1\n");
		}
	}
	
	D [] G;
	
	D [] d;
	
	return 0;
}
