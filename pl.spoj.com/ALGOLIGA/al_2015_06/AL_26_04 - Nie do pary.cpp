#include<cstdio> // AC
 
 
using namespace std;
 
 
int main()
{
	int q, n, a, wyn = 0;
	
	scanf( "%d", &q );
	
	while( q )
	{
		scanf( "%d", &n );
		
		while( n )
		{
			scanf( "%d", &a );
			
			wyn ^= a;
			
			--n;
		}
		
		printf( "%d\n", wyn );
		
		wyn = 0;
		
		--q;
	}
	
	return 0;
} 
