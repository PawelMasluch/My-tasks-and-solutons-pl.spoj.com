#include<cstdio> // do sprawdzenia
#include<new> // liczba inwersji za pomoc¹ algorytmu Mergesort

using namespace std;

typedef long long LL;

LL merge(LL *t, LL *pom, LL pocz, LL sr, LL kon)
{
	LL i1 = pocz, i2 = sr + 1, i = pocz, wyn = 0, ile = 0;
	while(i1<=sr && i2<=kon)
	{
		if(t[i1] <= t[i2])
		{
			pom[i] = t[i1];
			i1++;
			wyn += ile;
		}
		else
		{
			pom[i] = t[i2];
			i2++;
			ile++;
		}
		
		i++;
	}
	
	while(i1<=sr)
	{
		pom[i] = t[i1];
		i1++;
		i++;
		wyn += ile;
	}
	
	while(i2<=kon)
	{
		pom[i] = t[i2];
		i2++;
		i++;
	}
	
	for(i=pocz; i<=kon; i++)
	{
		t[i] = pom[i];
	}
	
	return wyn;
}

LL mergesort(LL *t, LL *pom, LL pocz, LL kon)
{
	if(pocz==kon)
	{
		return 0;
	}
	
	LL sr = (pocz + kon) / 2, wyn = 0;
		
	wyn += mergesort(t,pom,pocz,sr);
		
	wyn += mergesort(t,pom,sr+1,kon);
	
	wyn += merge(t,pom,pocz,sr,kon);
	
	return wyn;
	
}

int main()
{
	LL n, i, *t, wyn, *pom;
	
	scanf("%lld", &n);
	
	t = new LL [n];
	
	pom = new LL [n];
	
	for(i=0; i<=n-1; i++)
	{
		scanf("%lld", &t[i]);
	}
	
	wyn = mergesort(t,pom,0,n-1);
	
	for(i=0; i<=n-1; i++)
	{
		printf("%lld ", t[i]);
	}
	
	printf("\n%lld", wyn);
	
	return 0;
}
