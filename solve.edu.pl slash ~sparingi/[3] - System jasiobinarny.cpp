#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


LL f(LL n)
{
	LL wyn = 1;
	
	while( wyn <= n )
	{
		wyn <<= 1;
	}
	
	return wyn >> 1;
}


void wypisz(LL n)
{
	if( !( n & 1 ) )
	{
		printf( "NIE\n" );
		
		return;
	}
	
	LL tmp = f( n ), S = ( n + ( tmp << 1 ) - 1 ) >> 1;
	
	while( tmp > 0 )
	{
		if( S >= tmp )
		{
			printf( "+" );
			
			S -= tmp;
		}
		else
		{
			printf( "-" );
		}
		
		tmp >>= 1;
	}
}


int main()
{
	LL n;
	
	scanf( "%lld", &n );
	
	wypisz( n );
	
	return 0;
}
