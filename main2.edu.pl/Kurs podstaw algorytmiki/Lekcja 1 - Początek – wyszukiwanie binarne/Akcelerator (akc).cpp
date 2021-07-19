#include<cstdio> // do sprawdzenia
#include<new>

using namespace std;

int bin1(int *t, int n, int a)
{
	int pocz=0,kon=n-1,wyn=-1,sr;
	
	while(pocz<=kon)
	{
		sr = (pocz + kon) >> 1;
		
		if(t[sr]==a)
		{
			wyn = sr;
			kon = sr-1;
		}
		else
		{
			if(t[sr]>a)
			{
				kon = sr-1;
			}
			else
			{
				pocz = sr + 1;
			}
		}
		
	}
	
	return wyn; 
}

int bin2(int *t, int n, int a)
{
	int pocz=0,kon=n-1,wyn=-1,sr;
	
	while(pocz<=kon)
	{
		sr = (pocz + kon) >> 1;
		
		if(t[sr]==a)
		{
			wyn = sr;
			pocz = sr+1;
		}
		else
		{
			if(t[sr]>a)
			{
				kon = sr-1;
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
	int n,*t,i,pocz,kon,q,a;
	
	scanf("%d", &n);
	
	t = new int [n];
	
	for(i=0; i<=n-1; i++)
	{
		scanf("%d", &t[i]);
	}
	
	scanf("%d", &q);
	
	for(i=1; i<=q; i++)
	{
		scanf("%d", &a);
		
		pocz = bin1(t,n,a);
		kon = bin2(t,n,a);
		
		if(pocz==-1 && kon==-1)
		{
			printf("0\n");
		}
		else
		{
			printf("%d\n", kon-pocz+1);
		}
		
	}
	
	return 0;
}