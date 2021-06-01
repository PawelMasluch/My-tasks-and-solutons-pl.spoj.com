#include<cstdio> // 100 pkt
#include<new>
#include<vector>
#include<queue>


#define REP(i,n) for(int i=0; i<n; ++i)

#define PB push_back

#define D delete


using namespace std;


typedef vector < int > VI;

typedef queue < int > QI;


void ustaw(int N, int *r, bool *odw)
{
	REP(i,N)
	{
		r[i] = 0;  odw[i] = false;
	}
}


void wypelnij(int M, VI *G, int *r)
{
	int u, v;
	
	REP(i,M)
	{
		scanf("%d%d", &u, &v);
		
		--u;  --v;
		
		G[u].PB(v);  G[v].PB(u);
		
		++r[u];  ++r[v];
	}
}


void BFS(VI *G, int *r, int s, bool *odw)
{
	int u, v;
	
	QI Q;
	
	Q.push(s);
	
	odw[s] = true;
	
	while( !Q.empty() )
	{
		u = Q.front();
		
		Q.pop();
		
		REP(i,r[u])
		{
			v = G[u][i];
			
			if( !odw[v] )
			{
				odw[v] = true;
				
				Q.push(v);
			}
		}
	}
}


int ile_SS(VI *G, int *r, bool *odw, int N)
{
	int wyn = 0;
	
	REP(v,N)
	{
		if( !odw[v] )
		{
			++wyn;
			
			BFS(G,r,v,odw);
		}
	}
	
	return wyn;
}


/*void skasuj(int N, VI *G, int *r, bool *odw)
{
	REP(i,N)
	{
		G[i].clear();
	}
	
	D [] G;  D [] odw;  D [] r;
}*/


int main()
{
	VI *G;
	
	bool *odw;
	
	int N, M, *r;
	
	scanf("%d%d", &N, &M);
	
	r = new int [N];
	
	odw = new bool [N];
	
	G = new VI [N];
	
	ustaw(N,r,odw);
	
	wypelnij(M,G,r);
	
	printf( "%d\n", ile_SS(G,r,odw,N) );
	
	//skasuj(N,G,r,odw);
	
	return 0;
}
