#include<cstdio> // 100 pkt
#include<new>

using namespace std;

typedef long long LL;

inline LL f(LL x) // modu? liczby ca?kowitej
{
	return (x>0) ? x : -x ;
}

inline LL r(LL a, LL p) // reszta
{
	return (a>=0) ? (a-((a/f(p))*f(p))) : (a+(((f(a)+f(p)-1)/f(p))*f(p))) ;
}

LL fun(LL *a, LL n, LL x0, LL m)
{
	LL i, wyn = 0;
	
	for(i=n; i>=0; i--)
	{
		wyn = r( r(wyn*x0,m) + a[i], m );
	}
	
	return wyn;
}

int main()
{
	LL n, m, x0, i, *a;
	
	scanf("%lld", &n);
	
	a = new LL [n+1];
	
	for(i=0; i<=n; i++)
	{
		scanf("%lld", &a[i]);
	}
	
	scanf("%lld%lld", &m, &x0);
	
	printf("%lld\n", fun(a,n,x0,m));
	
	return 0;
}
