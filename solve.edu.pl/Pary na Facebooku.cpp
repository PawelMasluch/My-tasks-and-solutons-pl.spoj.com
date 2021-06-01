#include<cstdio> // 100 pkt
#include<algorithm>


using namespace std;


typedef long long LL;


#define REP(i,N) for(LL i=0; i<N; ++i)


const LL MAX_N = 1e6, INF = 1e9 + 99;


LL a[MAX_N+1], n, wyn = 0, i1 = 0, i2 = 1;


int main()
{
	scanf( "%lld", &n );
	
	REP(i,n)
	{
		scanf( "%lld", &a[i] );
	}
	
	a[n] = INF;
	
	sort( a, a + n );
	
	while( i2 <= n - 1 )
	{
		if( a[ i2 ] != a[ i2 - 1 ] )
		{
			wyn += ( ( i2 - i1 ) * ( n - i2 ) );
			
			i1 = i2;
		}
		
		++i2;
	}
	
	printf( "%lld\n", wyn );
	
	return 0;
}
