#include<cstdio> // 100 pkt
#include<vector>
#include<algorithm>
using namespace std; 
typedef long long LL;
int main()
{
	vector <LL> v;
	LL n,i,r=0;
	scanf("%lld", &n);
	for(i=1; i*i<=n; i++)
	{
		if(!(n%i))
		{
			v.push_back(i);
			r++;
			if(i*i<n)
			{
				v.push_back(n/i);
				r++;
			}
		}
	}
	sort(v.begin(),v.begin()+r);
	for(i=0; i<r; i++)
	{
		printf("%lld ", v[i]);
	}
	printf("\n");
	v.clear();
	return 0;
}
