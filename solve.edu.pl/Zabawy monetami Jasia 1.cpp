#include<cstdio> // 100 pkt
#include<algorithm>
#include<new>

using namespace std;

typedef long long LL;

int main()
{
	LL N,i,*T,wyn=0;
	scanf("%lld", &N);
	T = new LL [N+1];
	T[N] = (LL)1000000000*1000000000;
	for(i=0; i<=N-1; i++)
	{
		scanf("%lld", &T[i]);
	}
	sort(T,T+N+1);
	
	for(i=0; i<=N; i++)
	{
		if(wyn+1>=T[i])
		{
			wyn += T[i];
		}
		else
		{
			printf("%lld\n", wyn + 1);
			return 0;
		}
	}
	
	return 0;
	
}
