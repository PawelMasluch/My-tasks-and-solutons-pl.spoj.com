#include<cstdio> // 100 pkt; ważony graf skierowany ; brak ujemnych cykli
#include<new>


#define REP(i,n) for(i=0; i<n; ++i)


using namespace std;


typedef long long LL;


LL min(LL a, LL b)
{
	return (a<b) ? a : b ;
}


int main()
{
	LL n, INF = (LL)1000000000 * 1007000000, j, **best_path, i, m, u, v, w, k, wyn = INF;
	
	scanf("%lld%lld", &n, &m);
	
	best_path = new LL *[n];
	
	REP(i,n)
	{
		best_path[i] = new LL [n];
		
		REP(j,n)
		{
			best_path[i][j] = INF;
		}
	}
	
	REP(i,m)
	{
		scanf("%lld%lld%lld", &u, &v, &w);
		
		--u;
		
		--v;
		
		best_path[u][v] = min( best_path[u][v], w );
	}
	
	REP(k,n)
	{	
		REP(i,n)
		{
			REP(j,n)
			{
				if( best_path[i][j] > best_path[i][k] + best_path[k][j] )
				{
					best_path[i][j] = best_path[i][k] + best_path[k][j];	
				}
			}
		}
	}
	
	REP(i,n)
	{
		wyn = min( wyn, best_path[i][i] );
	}
	
	if( wyn == INF )
	{
		printf( "NIE\n" );
	}
	else
	{
		printf("%lld\n", wyn);
	}
	
	return 0;
}
