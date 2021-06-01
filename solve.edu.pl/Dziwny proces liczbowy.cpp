#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


const LL MX = 1458; // 1458 = 18 * 9^2


bool odw[MX+1];

LL n;


void wczytaj()
{
	scanf( "%lld", &n );
}


LL min(LL a, LL b)
{
	return ( a < b ) ? a : b ;
}


LL f(LL x)
{
	LL wyn = 0, r;
	
	while( x > 0 )
	{
		r = x % 10;
		
		wyn += r*r;
		
		x /= 10;
	}
	
	return wyn;
}


void oblicz(LL x)
{
	LL wyn = x;
	
	if( x > MX )
	{
		x = f( x );
	}
	
	while( !odw[x] )
	{
		odw[x] = true;
		
		wyn = min( wyn, x );
		
		x = f(x);
	}
	
	
	printf( "%lld\n", wyn );
}


void solve()
{
	wczytaj();
	
	oblicz( n );
}


int main()
{
	solve();
	
	return 0;
}
