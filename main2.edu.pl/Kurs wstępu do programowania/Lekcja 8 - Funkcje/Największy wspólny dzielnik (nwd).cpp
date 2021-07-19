#include<cstdio>

using namespace std;

typedef long long LL;

LL NWD(LL a, LL b)
{
	LL temp;
	
	while(b)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	
	return a;
}

int main()
{
	LL n, i, a, wyn = 0;
	
	scanf("%lld", &n);
	
	for(i=1; i<=n; i++)
	{
		scanf("%lld", &a);
		
		wyn = NWD(wyn,a);
	}	
	
	printf("%lld\n", wyn);
	
	return 0;
}