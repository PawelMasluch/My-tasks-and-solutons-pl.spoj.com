#include<cstdio> // do sprawdzenia
#include<new>
#include<algorithm>

using namespace std;

typedef long long LL;

int main()
{
	LL n, i, *x, *y;
	
	scanf("%lld", &n);
	
	x = new LL [n];
	
	y = new LL [n];
	
	for(i=0; i<=n-1; ++i)
	{
		scanf("%lld%lld", &x[i], &y[i]);
	}
	
	sort(x,x+n);
	
	sort(y,y+n);
	
	printf("%lld\n", 2 * ( x[ n - 1 ] - x[ 0 ] + y[ n - 1 ] - y[ 0 ] ) );
	
	return 0;
}