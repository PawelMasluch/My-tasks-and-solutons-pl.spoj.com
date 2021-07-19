#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)


const LL MAX_N = 1000000, INF = (LL)1000000099 * 1000000009;


LL n, a, pref[MAX_N+1], minpref[MAX_N+1], maxpref[MAX_N+1], wyn = -INF;


LL min(LL a, LL b)
{
	return ( a < b ) ? a : b ;
}


LL max(LL a, LL b)
{
	return ( a > b ) ? a : b ;
}


int main()
{
	scanf( "%lld", &n );
	
	pref[0] = minpref[0] = maxpref[0] = 0;
	
	REP(i,1,n)
	{
		scanf( "%lld", &a );
		
		pref[i] = pref[ i - 1 ] + a;
		
		minpref[i] = min( minpref[ i - 1 ], pref[i] );
		
		maxpref[i] = max( maxpref[ i - 1 ], pref[i] );
	}
	
	REP(i,1,n)
	{
		wyn = max( wyn, pref[i] - minpref[ i - 1 ] );
	}
	
	REP(i,1,n)
	{
		wyn = max( wyn, pref[n] - pref[ i - 1 ] + maxpref[ i - 1 ] );
	}
	
	printf( "%lld\n", wyn );
	
	return 0;
}
