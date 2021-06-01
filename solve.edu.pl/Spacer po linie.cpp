#include<cstdio> // 100 pkt
#include<new>

using namespace std;

typedef long long LL;

LL min(LL a, LL b)
{
	return (a<b) ? a : b ;
}

int main()
{
	LL N, i, *DP, a;
	
	scanf("%lld", &N);
	
	DP = new LL [N+3];
	
	DP[0] = DP[1] = DP[N+2] = 0;
	
	for(i=2; i<=N+1; ++i)
	{
		scanf("%lld", &a);
		
		DP[ i ] = min( DP[ i - 1 ], DP[ i - 2 ] ) + a;
	}
	
	DP[ N + 2 ] = min( DP[ N + 1 ], DP[ N ] );
	
	printf("%lld\n", DP[N+2]);
	
	delete [] DP;
	
	return 0;
}
