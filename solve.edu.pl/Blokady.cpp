#include<cstdio> // 100 pkt
#include<new>
#include<vector>
#include<queue>


#define REP(i,a,b) for(i=a; i<=b; ++i)

#define FORD(i,b,a) for(i=b; i>=a; --i)

#define PB push_back

#define P push


using namespace std;


typedef vector < int > VI;

typedef queue < int > QI;


int max(int a, int b)
{
	return (a>b) ? a : b ;
}

int main()
{
	int N, i, j, k, u, v, depth = 0;
	
	scanf("%d", &N);
	
	QI Q;
	
	VI *layer = new VI [N], *syn = new VI [N], *G = new VI [N];
	
	int *Ssyn = new int [N], *d = new int [N], *rlayer = new int [N], *rsyn = new int [N], *rG = new int [N], *DP = new int [N];
	
	bool *odw = new bool [N];
	
	REP(i,0,N-1)
	{
		rlayer[i] = rG[i] = rsyn[i] = Ssyn[i] = DP[i] = 0;
		
		odw[i] = false;
	}
	
	REP(i,1,N-1)
	{
		scanf("%d%d", &u, &v);
		
		--u;  --v;
		
		G[u].PB(v);  G[v].PB(u);
		
		++rG[u];  ++rG[v];
	}
	
	layer[0].PB(0);
	
	++rlayer[0]; // jest wiêcej w warstwie "0"
	
	d[0] = 0;
	
	Q.P(0);
	
	odw[0] = true;
	
	while( !Q.empty() )
	{
		u = Q.front();
		
		Q.pop();
		
		REP(i,0,rG[u]-1)
		{
			v = G[u][i];
			
			if( !odw[v] )
			{
				odw[v] = true;
				
				d[v] = 1 + d[u];
				
				depth = max( depth, d[v] );
				
				Q.P(v);
				
				layer[ d[v] ].PB(v);  syn[u].PB(v);
				
				++rlayer[ d[v] ];  ++rsyn[u];
			}
		}
	}
	
	FORD(i,depth,0) // dla ka¿dej warstwy
	{
		REP(j,0,rlayer[i]-1) // po wszystkich wierzcho³kach z warstwy "i"
		{			
			u = layer[i][j]; // jakiœ wierzcho³ek z warstwy "i"
			
			REP(k,0,rsyn[u]-1) // ka¿dy syn "u"
			{
				v = syn[u][k]; // syn "u"
				
				Ssyn[u] += DP[ syn[u][k] ];
			}
			
			DP[u] = Ssyn[u];
			
			REP(k,0,rsyn[u]-1)
			{
				v = syn[u][k];
				
				DP[u] = max( DP[u], Ssyn[u] - DP[v] + Ssyn[v] + 1 );
			}
		}
	}
	
	printf("%d\n", DP[0]);
	
	return 0;
}

/*

test :


wejœcie :

15

1 2
1 3
1 4
2 5
2 6
3 7
4 11
4 12
5 8
6 9
6 10
12 13
12 14
12 15


wyjœcie : 

6

*/
