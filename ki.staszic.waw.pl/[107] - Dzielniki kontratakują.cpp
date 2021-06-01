#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


LL NWD(LL a, LL b)
{
	LL tmp;
	
	while( b )
	{
		tmp = a % b;
		
		a = b;
		
		b = tmp;
	}
	
	return a;
}


void zapytania()
{
	int n;
	
	scanf( "%d", &n );
	
	LL a, b, d;
	
	while( n )
	{
		scanf( "%lld %lld", &a, &b );
		
		d = NWD( a, b );
		
		a /= d;
		
		b /= d;
		
		b /= NWD( b, d );
		
		printf( "%lld %lld\n", a, b );
		
		--n;
	}
}


int main()
{
	zapytania();
	
	return 0;
}
