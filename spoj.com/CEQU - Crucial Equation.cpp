#include<cstdio> // AC
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int NWD(int a, int b)
{
	int tmp;
	
	while( b )
	{
		tmp = a % b;
		
		a = b;
		
		b = tmp;
	}
	
	return a;
}
 
 
int main()
{
	int q, a, b, c;
	
	scanf( "%d", &q );
	
	REP(i,1,q)
	{
		scanf( "%d %d %d", &a, &b, &c );
		
		printf( "Case %d: ", i );
		
		if( c % NWD( a, b ) == 0 )
		{
			printf( "Yes" );
		}
		else
		{
			printf( "No" );
		}
		
		if( i < q )
		{
			printf( "\n" );
		}
	}
	
	return 0;
} 
