#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 35;


int F[MAX_N+1], q;


void preprocessing()
{
	F[0] = F[1] = 1;
	
	REP(i,2,MAX_N)
	{
		F[i] = F[ i - 1 ] + F[ i - 2 ];
	}
}


void zapytania()
{
	scanf( "%d", &q );
	
	int n;
	
	while( q )
	{
		scanf( "%d", &n );
		
		printf( "%d ", F[n] );
		
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
