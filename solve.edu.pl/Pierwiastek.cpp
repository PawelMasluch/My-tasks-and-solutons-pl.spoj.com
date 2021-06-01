#include<cstdio> // 100 pkt

using namespace std;

typedef long long LL;

LL f(LL x)
{
	LL pocz=1, kon=1000000, wyn, sr;
	while(pocz<=kon)
	{
		sr = (pocz+kon) >> 1;
		if(sr*sr*sr <= x)
		{
			wyn = sr;
			pocz = sr + 1;
		}
		else
		{
			kon = sr - 1;
		}
	}
	return wyn;
}

int main()
{
	LL n,i,q;
	scanf("%lld", &q);
	for(i=1; i<=q; i++)
	{
		scanf("%lld", &n);
		printf("%lld\n", f(n));
	}
	return 0;
}
