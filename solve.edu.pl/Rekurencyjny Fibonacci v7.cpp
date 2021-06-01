#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_Q = 35;


int t[MAX_Q];


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
	int q;
	
	scanf( "%d", &q );
	
	REP(i,0,q-1)
	{
		scanf( "%d", &t[i] );
	}
	
	REP(i,0,q-1)
	{
		printf( "%d ", F( t[i] ) );
	}
	
	printf( "\n" );
}


int main()
{
	zapytania();
	
	return 0;
}
