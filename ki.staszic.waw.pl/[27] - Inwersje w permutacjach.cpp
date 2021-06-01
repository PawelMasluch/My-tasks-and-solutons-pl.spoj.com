#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)


const LL MAX_N = 20, MAX_K = 200;


LL DP[MAX_N+1][MAX_K+1], n, k;


LL min(LL a, LL b)
{
	return (a<b) ? a : b ;
}


int main()
{
	scanf( "%lld %lld", &n, &k ); // 1 <= n <= 20  ;  1 <= k <= 200
	
	REP(j,0,k)
	{
		DP[0][j] = 1;
	}
	
	REP(i,1,n)
	{
		DP[i][0] = 1;
		
		REP(j,1,k)
		{
			DP[i][j] = DP[ i - 1 ][j];
			
			if( j >= i )
			{
				DP[i][j] -= DP[ i - 1 ][ j - i ];
			}
			
			DP[i][j] += DP[i][ j - 1 ];
		}
	}
	
	printf( "%lld\n", DP[n][k] - DP[n][ k - 1 ] );
	
	return 0;
}
