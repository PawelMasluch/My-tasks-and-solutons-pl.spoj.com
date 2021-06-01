#include<cstdio> // 100 pkt
#include<algorithm>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,k,n) for(int i=k; i<n; i++)
#define f(x) scanf("%d", &x)
#define g(x) printf("%d\n", x)
using namespace std;	
int main()
{
	int n,i,w=1;
	f(n);
	int t[n];
	REP(i,n)
	{
		f(t[i]);
	}
	sort(t,t+n);
	FOR(i,1,n)
	{
		if(t[i]!=t[i-1])
		{
			w++;
		}
	}
	g(w);
	return 0;
}
