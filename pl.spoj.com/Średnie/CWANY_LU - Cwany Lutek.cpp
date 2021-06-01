#include<cstdio> // 100 pkt


using namespace std;


typedef unsigned int UI;


UI q, n, k;


UI ile(UI x)
{
	UI wyn = 0, tmp = 2;
	
	while( tmp <= x )
	{
		wyn += ( x / tmp );
		
		tmp *= 2;
	}
	
	return wyn;
}


bool f()
{
	if( n < k )
	{
		return true;
	}
	
	UI exp = ile( n ) - ile( k ) - ile( n - k );
	
	if( exp > 0 )
	{
		return true;
	}
	
	return false;
}


void g()
{
	if( f() )
	{
		printf( "P\n" );
	}
	else
	{
		printf( "N\n" );
	}
}


void zapytania()
{
	scanf( "%u", &q );
	
	while( q )
	{
		scanf( "%u %u", &n, &k );
		
		g();
		
		--q;
	}
}


int main()
{
	zapytania();
	
	return 0;
}
