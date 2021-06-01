#include<cstdio> // 100 pkt
#include<new>
#include<algorithm>

using namespace std;

typedef long long LL;

LL bin1(LL *t, LL szukany, LL start, LL meta)
{
	LL pocz = start, kon = meta, sr, wyn = -1;
	
	while(pocz <= kon)
	{
		sr = (pocz + kon) / 2;
		
		if(t[sr] == szukany)
		{
			wyn = sr;
			kon = sr - 1;
		}
		else
		{
			if(t[sr] > szukany)
			{
				kon = sr - 1;
			}
			else
			{
				pocz = sr + 1;
			}
		}
	}
	
	return wyn;
}

LL bin2(LL *t, LL szukany, LL start, LL meta)
{
	LL pocz = start, kon = meta, sr, wyn = -1;
	
	while(pocz <= kon)
	{
		sr = (pocz + kon) / 2;
		
		if(t[sr] == szukany)
		{
			wyn = sr;
			pocz = sr + 1;
		}
		else
		{
			if(t[sr] > szukany)
			{
				kon = sr - 1;
			}
			else
			{
				pocz = sr + 1;
			}
		}
	}
	
	return wyn;
}

int main()
{
	LL n, i, *t, s, j1, j2, wyn = 0;
	
	scanf("%lld%lld", &n, &s);
	
	t = new LL [n];
	
	for(i=0; i<=n-1; i++)
	{
		scanf("%lld", &t[i]);
	}
	
	sort(t,t+n);
	
	for(i=0; i<=n-1; i++)
	{
		j1 = bin1(t,s-t[i],i,n-1);
		j2 = bin2(t,s-t[i],i,n-1);
		
		if(j1 != -1  &&  j2 != -1)
		{
			wyn += (j2 - j1 + 1);
		}
	}
	
	printf("%lld\n", wyn);
	
	return 0;
}
