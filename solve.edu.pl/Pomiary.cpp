#include<cstdio> // 100 pkt
#include<new>

using namespace std;

typedef long long LL;

int main()
{
	LL N, S, K, *t, i, r;
	
	scanf("%lld%lld%lld", &N, &S, &K);
	
	if( S < K * (K+1) / 2  ||  S > ( ( 2 * N ) - K + 1) * K / 2 )
	{
		printf("NIE\n");
		return 0;
	}
	
	t = new LL [N+1];
	
	for(i=1; i<=K; ++i)
	{
		t[i] = 1;
	}
	
	for(i=K+1; i<=N; ++i)
	{
		t[i] = 0;
	}
	
	r = S - ( K * ( K + 1 ) / 2 );
	
	i = K;
	
	while( r > N - K )
	{
		t[ i ] = 0;
		
		t[ i + N - K ] = 1;
		
		r -= ( N - K );
		
		--i;
	}
	
	t[ i ] = 0;
	t[ i + r ] = 1;
	r = 0;
	
	for(i=1; i<=N; ++i)
	{
		printf("%lld", t[i]);
	}
	printf("\n");
	
	return 0;
}
