#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


int F(int n)
{
	if( n <= 1 )
	{
		return 1;
	}
	
	return F( n - 1 ) + F( n - 2 );
}


void zapytania()
{
	int q, n;
	
	scanf( "%d", &q );
	
	while( q )
	{
		scanf( "%d", &n );
		
		printf( "%d ", F( n ) );
		
		--q;
	}
	
	printf( "\n" );
}


int main()
{
	zapytania();
	
	return 0;
}
