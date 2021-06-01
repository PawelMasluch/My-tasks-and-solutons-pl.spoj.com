#include<cstdio> // AC


using namespace std;


typedef long long LL;


int main()
{
	LL a, s = 0, S = 0, b;
	
	while( scanf( "%lld", &a ) != EOF )
	{
		if( a == 0 )
		{
			printf( "0\n" );
		}
		else
		{
			s = a;    S += a;
			
			scanf( "%lld", &b );
			
			while( b )
			{
				s += b;    S += b;
				
				scanf( "%lld", &b );
			}
			
			printf( "%lld\n", s );
			
			s = 0;
		}
	}
	
	printf( "%lld\n", S );
	
	return 0;
}
