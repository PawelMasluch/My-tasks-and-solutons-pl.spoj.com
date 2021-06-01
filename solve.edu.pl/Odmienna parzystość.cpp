#include<cstdio> // 100 pkt


using namespace std;


int main()
{
	int n, a, p = 0, np = 0, fp, fnp;
	
	scanf( "%d", &n );
	
	while( n )
	{
		scanf( "%d", &a );
		
		if( a & 1 )
		{
			if( !np )
			{
				fnp = a;
			}
			
			++np;
		}
		else
		{
			if( !p )
			{
				fp = a;
			}
			
			++p;
		}
		
		--n;
	}
	
	if( p == 1 )
	{
		printf( "%d\n", fp );
	}
	else
	{
		printf( "%d\n", fnp );
	}
	
	return 0;
}
