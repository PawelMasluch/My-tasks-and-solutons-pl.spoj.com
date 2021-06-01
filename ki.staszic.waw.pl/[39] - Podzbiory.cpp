#include<cstdio> // 100 pkt
#include<vector>

using namespace std;

typedef long long LL;

int main()
{
	vector <LL> v;
	
	LL n, pom, i, temp, j;
	
	scanf("%lld", &n);
	
	pom = (1 << n) - 1;
	
	for(i=0; i<=pom; i++)
	{
		temp = i;
		
		for(j=0; j<=n-1; j++)
		{
			v.push_back(temp%2);
			temp/=2;
		}
		
		for(j=n-1; j>=0; j--)
		{
			printf("%lld", v[j]);
		}
		printf("\n");
		
		v.clear();
		
	}
	
	return 0;
}
