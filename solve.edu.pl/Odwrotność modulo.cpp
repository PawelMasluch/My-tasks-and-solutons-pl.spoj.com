#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


LL fpm(LL a, LL b, LL p)
{
	LL wyn = 1;
	
	while( b )
	{
		if( b & 1 )
		{
			wyn = ( wyn * a ) % p;
		}
		
		a = ( a * a ) % p;
		
		b >>= 1;
	}
	
	return wyn;
}


void query()
{
	LL n, p;
	
	scanf( "%lld %lld", &n, &p );
	
	printf( "%lld\n", fpm( n, p - 2, p ) );
}


void obsluz_zapytania()
{
	LL q;
	
	scanf( "%lld", &q );
	
	while( q )
	{
		query();
		
		--q;
	}
}


int main()
{
	obsluz_zapytania();
	
	return 0;
}
