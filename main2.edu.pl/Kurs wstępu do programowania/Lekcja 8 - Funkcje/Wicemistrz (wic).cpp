#include<cstdio> // 100 pkt

using namespace std;

typedef long long LL;

LL f(LL *t, LL n)
{
	LL i, max1 = 0, max2 = 0;
	
	for(i=1; i<=n-1; i++)
	{
		if(t[i] > max1)
		{
			max2 = max1;
			max1 = t[i];
		}
		else
		{
			if(t[i] > max2)
			{
				max2 = t[i];
			}
		}
	}
	
	return max2;
}

int main()
{
	LL n, *t, i;
	
	scanf("%lld", &n);
	
	t = new LL [n+1];
	
	for(i=1; i<=n; i++)
	{
		scanf("%lld", &t[i]);
	}
	
	printf( "%lld\n", f(t,n+1) );
	
	return 0;
}