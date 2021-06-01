#include<cstdio> // AC

using namespace std;

typedef long long LL;

LL f(LL &x) // 1 + G(x)
{
	return ( x * ( x + 1 ) / 2 ) + 1;
}

LL ile(LL &n) // takie k, ¿e 1 + G(k) >= n
{
	LL pocz = 0, kon = 4000001, sr, wyn;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( f(sr) >= n )
		{
			kon = sr - 1;
			wyn = sr;
		}
		else
		{
			pocz = sr + 1;
		}
	}
	
	return wyn;
}

int main()
{
	LL n;
	
	while( scanf("%lld", &n)  !=  EOF )
	{
		printf("%lld\n", ile(n) );
	}
	
	return 0;
}
