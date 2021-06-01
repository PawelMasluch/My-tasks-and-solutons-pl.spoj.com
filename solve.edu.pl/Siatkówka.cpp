#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;

typedef long double LD;


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

LD NWW(LL a, LL b)
{
	LL pom = NWD( a, b );
	
	return ( (LD)a / pom ) * b;
}


int main()
{
	LL N, A, B;
	
	scanf("%lld%lld%lld", &N, &A, &B);
	
	if( N < NWW( A, B ) + 1 )
	{
		printf( "NIE\n" );
	}
	else
	{
		printf( "%.0Lf\n", NWW( A, B ) - 1 );
	}
	
	return 0;
}
