#include<cstdio> // 100 pkt
using namespace std;
typedef long long ll;
int main()
{
	int q,n,i,a,b;
	scanf("%d", &n);
	int t[n];
	ll pref[n+1]; pref[0]=0;
	for(i=0; i<n; i++)
	{
		scanf("%d", &t[i]);
		pref[i+1]=pref[i]+t[i];
	}
	scanf("%d", &q);
	for(i=0; i<q; i++)
	{
		scanf("%d%d", &a, &b);
		printf("%lld\n", pref[b]-pref[a-1]);
	}
	return 0;
}
