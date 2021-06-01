#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


LL f(LL x)
{
	return ( x >= 0 ) ? x : -x ;
}


int main()
{
	LL a, b;
	
	scanf( "%lld %lld", &a, &b );
	
	printf( "%lld\n", f( a - b ) );
	
	return 0;
}
