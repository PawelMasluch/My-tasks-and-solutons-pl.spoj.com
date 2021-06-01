#include<cstdio> // AC


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)


LL mnoz_modulo(LL a, LL b, LL p)
{
	LL wyn = 0;
	
	while( b )
	{
		if( b & 1 )
		{
			wyn = ( wyn + a ) % p;
		}
		
		a = ( a << 1 ) % p;
		
		b >>= 1;
	}
	
	return wyn;
}


LL f(LL a, LL b, LL p)
{
	LL wyn = 1;
	
	REP(i,a,b)
	{
		wyn = mnoz_modulo( wyn, i, p );
	}
	
	return wyn;
}


int main()
{
	LL q, a, b, p = 4611686018427387847, wyn;
	
	scanf( "%lld", &q );
	
	while( q )
	{
		scanf( "%lld %lld", &a, &b );
		
		wyn = f( a, b, p );
		
		printf( "%lld\n", wyn );
		
		--q;
	}
	
	return 0;
}
