#include<cstdio> // AC


using namespace std;


#define FORD(i,b,a) for(int i=b; i>=a; --i)


int main()
{
	int k, p = 0, tmp = 2; // "tmp" to jakby 2^(p+1), dla aktualnego "p"
	
	scanf( "%d", &k );
	
	while( tmp < k + 2 )
	{
		tmp <<= 1;
		
		++p;
	}
	
	tmp >>= 1; // 2^p
	
	k -= ( tmp - 2 );
	
	FORD(i,p,1)
	{
		if( 2 * k > tmp )
		{
			printf( "6" );
			
			k -= ( tmp >> 1 );
		}
		else
		{
			printf( "5" );
		}
		
		tmp >>= 1;
	}
	
	printf( "\n" );
	
	return 0;
}
