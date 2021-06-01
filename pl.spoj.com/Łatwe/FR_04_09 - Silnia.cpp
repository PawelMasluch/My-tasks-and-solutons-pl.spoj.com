#include<cstdio> // AC


using namespace std;


typedef long long LL;


LL f(LL n, LL z)
{
	LL wyn = 0, tmp = z;
	
	while( tmp <= n )
	{
		wyn += ( n / tmp );
		
		tmp *= z;
	}
	
	return wyn;
}


int main()
{
	LL q, z, n, wyn;
	
	scanf( "%lld", &q );
	
	while( q )
	{
		scanf( "%lld %lld", &n, &z );
		
		wyn = f( n, z );
		
		printf( "%lld\n", wyn );
		
		--q;
	}
	
	return 0;
}
