#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


LL fpm(LL a, LL b)
{
	LL wyn = 1;
	
	while( b )
	{
		if( b & 1 )
		{
			wyn *= a;
		}
		
		b >>= 1;
		
		if( b )
		{
			a *= a;
		}
	}
	
	return wyn;
}


LL f(LL n)
{
	LL wyn = 0, tmp = n, S, ile = -1;
	
	while( tmp )
	{
		tmp >>= 1;
		
		++ile;
	}
	
	S = fpm( 2, ile );
	
	while( n )
	{
		if( n & 1 )
		{
			wyn += S;
		}
		
		n >>= 1;
		
		S >>= 1;
	}
	
	return wyn;
}


int main()
{
	LL n;
	
	scanf( "%lld", &n );
	
	printf( "%lld\n", f( n ) );
	
	return 0;
}
