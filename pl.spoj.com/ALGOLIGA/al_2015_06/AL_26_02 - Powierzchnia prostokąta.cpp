#include<cstdio> // AC
 
 
using namespace std;
 
 
typedef long long LL;
 
 
int main()
{
	LL q, a, b, n, P;
	
	scanf( "%lld", &q );
	
	while( q )
	{
		scanf( "%lld", &n );
		
		if( n & 1  ||  n == 2 )
		{
			printf( "BRAK\n" );
		}
		else
		{
			n /= 2;
			
			a = n / 2;
			
			b = n - a;
			
			P = a * b;
			
			printf( "%lld\n", P );
		}
		
		--q;
	}
	
	return 0;
} 
