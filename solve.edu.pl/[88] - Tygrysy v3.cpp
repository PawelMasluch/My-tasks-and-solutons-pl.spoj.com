#include<cstdio> // 100 pkt
#include<algorithm>
#include<new> 
using namespace std;
typedef long long LL;
int main()
{
	LL n,i,wyn=0,j,*t;
	scanf("%lld", &n);
	t = new LL [n+1]; 
	t[0]=0; // wartownik
	for(i=1; i<=n; i++)
	{
		scanf("%lld", t+i);
	}
	sort(t+1,t+n+1);
	i=n-1;
	for(j=n; j>=1; j--) // niezmiennik : przed pętlą while zachodzi i=j-1
	{
		while(2*t[i]>t[j])
		{
			i--;
		}
		wyn=max(wyn,j-i);
		if(j==i+1)
		{
			i--;
		}
	}
	printf("%lld\n", wyn);
	delete [] t;
	return 0;
}
