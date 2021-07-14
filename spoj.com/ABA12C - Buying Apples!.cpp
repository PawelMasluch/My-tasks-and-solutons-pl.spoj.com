#include<cstdio> // AC
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
const int MAX_N = 100, MAX_K = 100, INF = 1e9 + 99;
 
 
int DP[MAX_N+1][MAX_K+1], c[MAX_K+1], q, n, k, wyn;
 
 
void init()
{
	wyn = INF;
	
	REP(i,0,MAX_N)
	{
		REP(j,0,MAX_K)
		{
			DP[i][j] = INF;
		}
	}
	
	DP[0][0] = 0;
}
 
 
int min(int a, int b)
{
	return ( a < b ) ? a : b ;
}
 
 
int main()
{
	scanf( "%d", &q );
	
	while( q )
	{
		scanf( "%d %d", &n, &k );
		
		REP(i,1,k)
		{
			scanf( "%d", &c[i] );
		}
		
		init();
		
		
		
		
		REP(l,1,k)
		{
			if( c[l] != -1 )
			{
				REP(i,1,n)
				{
					REP(j,l,k)
					{
						DP[i][j] = min( DP[i][j], DP[ i - 1 ][ j - l ] + c[l] );
					}
				}
			}
		}
		
		
		
		
		/*REP(i,1,n)
		{
			REP(j,1,k)
			{
				REP(l,1,j)
				{
					if( c[l] != -1 )
					{
						DP[i][j] = min( DP[i][j], DP[ i - 1 ][ j - l ] + c[l] );
					}
				}
			}
		}*/
		
		REP(i,1,n)
		{
			wyn = min( wyn, DP[i][k] );
		}
		
		if( wyn == INF )
		{
			printf( "-1\n" );
		}
		else
		{
			printf( "%d\n", wyn );
		}
		
		--q;
	}
	
	return 0;
} 
