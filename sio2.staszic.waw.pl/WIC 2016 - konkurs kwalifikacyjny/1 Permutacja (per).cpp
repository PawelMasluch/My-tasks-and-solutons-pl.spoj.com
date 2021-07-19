#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i) 


int main()
{
	int n;
	
	scanf( "%d", &n );
	
	if( n == 1 )
	{
		printf( "BRAK\n" );
		
		return 0;
	}
	
	REP(i,1,n-2)
	{
		if( i % 2 == 1 )
		{
			printf( "%d ", i + 1 );
		}
		else
		{
			printf( "%d ", i - 1 );
		}
	}
	
	if( n % 2 == 0 )
	{
		printf( "%d %d\n", n, n - 1 );
	}
	else
	{
		printf( "%d %d\n", n, n - 2 );
	}
	
	return 0;
}
