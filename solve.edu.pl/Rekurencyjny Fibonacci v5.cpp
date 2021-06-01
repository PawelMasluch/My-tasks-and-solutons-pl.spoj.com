#include<cstdio> // 100 pkt
#include<map>


using namespace std;


typedef map < int, int > MII;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 35;


MII M;


void preprocessing()
{
	M[0] = M[1] = 1;
}


int F(int n)
{
	if( !M.count( n ) )
	{
		M[n] = F( n - 1 ) + F( n - 2 );
	}
	
	return M[n];
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
	preprocessing();
	
	zapytania();
	
	return 0;
}
