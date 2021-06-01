#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)


const LL MAX_N = 35;


LL F[MAX_N+1], q;


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
	scanf( "%lld", &q );
	
	LL n;
	
	while( q )
	{
		scanf( "%lld", &n );
		
		printf( "%lld ", F[n] );
		
		--q;
	}
}


int main()
{
	preprocessing();
	
	zapytania();
	
	return 0;
}
