#include<cstdio>
 
 
using namespace std;
 
 
typedef long long LL;
 
 
const LL p = 1010101011, C = 252525253;
 
 
LL f(LL a, LL b)
{
	LL A = ( b * ( b + 1 ) + a * ( a - 1 ) ) % p, B = ( b * ( b + 1 ) - a * ( a - 1 ) ) % p;
	
	return ( ( ( A * B ) % p ) * C ) % p;
}
 
 
int main()
{
	LL a, b;
	
	while( scanf( "%lld%lld", &a, &b ) != EOF )
	{
		printf( "%lld\n", f( a, b ) );
	}
	
	return 0;
} 
