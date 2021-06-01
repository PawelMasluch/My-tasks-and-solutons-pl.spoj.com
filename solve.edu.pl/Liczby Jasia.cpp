#include<cstdio> // 100 pkt
#include<new>
#include<vector>

using namespace std;

typedef long long LL;

int main()
{
	vector <LL> v;
	
	LL N = 1299722, i, j, n;
	
	bool *czy = new bool [N];
	
	czy[0]=false;
	czy[1]=false;
	
	for(i=2; i<=N-1; i++)
	{
		czy[i] = true;
	}
	
	for(i=2; i*i<=N-1; i++)
	{
		if(czy[i]==true)
		{
			for(j=i*i; j<=N-1; j+=i)
			{
				czy[j]=false;
			}
		}
	}
	
	for(i=2; i<=N-1; i++)
	{
		if(czy[i]==true)
		{
			v.push_back(i);
		}
	}
	
	scanf("%lld", &n);
	
	printf("%lld\n", v[(n-1)+1]*v[(n-1)+1]);
	
	return 0;

}
