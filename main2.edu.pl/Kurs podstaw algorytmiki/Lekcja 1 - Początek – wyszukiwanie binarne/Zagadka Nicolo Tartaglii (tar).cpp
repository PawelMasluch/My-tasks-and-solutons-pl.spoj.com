#include<cstdio> // do sprawdzenia
#include<new>

using namespace std;

typedef long long LL;

LL bin(LL p, LL q)
{
	LL pocz=1,kon=1000000,sr,pom;
	
	while(pocz<=kon)
	{
		sr = (pocz + kon) >> 1;
		
		pom = sr*((sr*sr)+p);
		
		if(pom==q)
		{
			return sr;
		}
		else
		{
			if(pom<q)
			{
				pocz = sr+1;	
			}
			else
			{
				kon = sr-1;
			}
		}
		
	}
	
	return -1; 
}

int main()
{
	LL p,q,wyn;
	int z,i;
	
	scanf("%d", &z);
	
	for(i=1; i<=z; i++)
	{
		scanf("%lld%lld", &p, &q);
		
		wyn = bin(p,q);
		
		if(wyn==-1)
		{
			printf("NIE\n");
		}
		else
		{
			printf("%lld\n", wyn);
		}
	}
	
	return 0;
}