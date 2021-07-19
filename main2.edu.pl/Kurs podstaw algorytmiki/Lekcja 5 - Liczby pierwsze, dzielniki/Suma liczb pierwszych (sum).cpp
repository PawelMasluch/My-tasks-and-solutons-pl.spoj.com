#include<cstdio> // do sprawdzenia
#include<new>

using namespace std;

typedef long long LL;

int main()
{
	bool *czy = new bool [2000001];
	czy[0] = false;
	czy[1] = false;
	
	LL i,j, *S = new LL [2000001], t, a, b;
	S[0] = 0;
	
	for(i=2; i<=2000000; i++)
	{
		czy[i] = true;
	}
	
	for(i=2; i*i<=2000000; i++)
	{
		if(czy[i] == true)
		{
			for(j=i*i; j<=2000000; j+=i)
			{
				czy[j] = false;
			}
		}
	}
	
	for(i=1; i<=2000000; i++)
	{
		S[i] = S[i-1];
		if(czy[i] == true)
		{
			S[i] += i;
		}
	}
	
	scanf("%lld", &t);
	
	for(i=1; i<=t; i++)
	{
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", S[b] - S[a-1]);
	}
	
	return 0;
	
}