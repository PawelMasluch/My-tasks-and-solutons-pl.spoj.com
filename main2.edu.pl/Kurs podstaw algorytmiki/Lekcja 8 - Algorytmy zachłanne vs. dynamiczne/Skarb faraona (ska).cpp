#include<cstdio>
#include<new>

using namespace std;

typedef long long LL;

LL max(LL a, LL b)
{
	return (a > b) ? a : b ;
}

int main()
{
	LL T, l, n, p, s, v, *DP, i, j;
	
	scanf("%lld", &T);
	
	for(l=1; l<=T; l++)
	{
		scanf("%lld%lld", &n, &p);
		
		DP = new LL [p+1];
		
		for(i=0; i<=p; i++)
		{
			DP[i] = 0;
		}
		
		for(i=1; i<=n; i++)
		{
			scanf("%lld%lld", &s, &v);
			
			for(j=p; j>=s; j--)
			{
				DP[j] = max( DP[j], DP[j - s] + v );
			}
		}
		
		printf("%lld\n", DP[p]);
		
		delete [] DP;
	}
	
	return 0;
}