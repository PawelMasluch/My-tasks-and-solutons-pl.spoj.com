#include<cstdio> // 100 pkt
#include<new>

using namespace std;

typedef long long LL;

LL max(LL a, LL b)
{
	return (a > b) ? a : b ;
}

int main()
{
	LL m, n, **DP, i, j, a, l, T;
	
	scanf("%lld", &T);
	
	for(l=1; l<=T; l++)
	{
		scanf("%lld%lld", &m, &n);
		
		DP = new LL *[n+1];
		
		for(i=0; i<=n; i++)
		{
			DP[i] = new LL [m+1];
		}
		
		for(j=0; j<=m; j++)
		{
			DP[0][j] = 0;
		}
		
		for(i=1; i<=n; i++)
		{
			DP[i][0] = 0;
		}
		
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=m; j++)
			{
				scanf("%lld", &a);
				
				DP[i][j] = max( DP[i-1][j], DP[i][j-1] ) + a;
			}
		}
		
		printf("%lld\n", DP[n][m]);
		
		for(i=0; i<=n; i++)
		{
			delete [] DP[i];
		}
		
		delete [] DP;
	
	}
	
	return 0;
}