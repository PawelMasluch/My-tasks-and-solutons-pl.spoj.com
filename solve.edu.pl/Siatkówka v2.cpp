#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


LL NWD(LL a, LL b)
{
	LL temp;
	
	while( b )
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	
	return a;
}


int main()
{
	LL N, A, B, pom;
	
	scanf("%lld%lld%lld", &N, &A, &B);
	
	pom = NWD( A, B );
	
	if( ( ( N - 1 ) / A )  <  ( B / pom ) )
	{
		printf( "NIE\n" );
	}
	else
	{
		printf( "%lld\n", ( ( A / pom ) * B ) - 1 );
	}
	
	return 0;
}
