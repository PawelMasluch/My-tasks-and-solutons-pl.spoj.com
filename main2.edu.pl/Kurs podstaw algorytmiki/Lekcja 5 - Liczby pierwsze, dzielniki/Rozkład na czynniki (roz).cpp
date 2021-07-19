#include<cstdio> // do sprawdzenia
#include<vector>

using namespace std;

typedef long long LL;

int main()
{
	vector <LL> a,exp;
	LL n, r = 0, i, ile = 0, temp, t, l;
	scanf("%lld", &t);
	for(l=1; l<=t; l++)
	{
		scanf("%lld", &n);
		temp = n;
		for(i = 2; i*i<=temp && temp>1; i++)
		{
			while(temp%i==0)
			{
				temp /= i;
				ile++;
			}
			if(ile>0)
			{
				a.push_back(i);
				exp.push_back(ile);
				r++;
			}
			ile = 0;
		}
		
		if(temp>1)
		{
			a.push_back(temp);
			exp.push_back(1);
			r++;
		}
		
		printf("%lld = ", n);
		
		for(i=0; i<=r-2; i++)
		{
			if(exp[i]>1)
			{
				printf("%lld^%lld*", a[i], exp[i]);
			}
			else
			{
				printf("%lld*", a[i]);
			}
		}
		
		if(exp[r-1]>1)
		{
			printf("%lld^%lld\n", a[i], exp[i]);
		}
		else
		{
			printf("%lld\n", a[i]);
		}
		
		a.clear();
		exp.clear();
		r = 0;
	}
	
	return 0;
}