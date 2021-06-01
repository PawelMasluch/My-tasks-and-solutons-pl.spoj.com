#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)

#define FORD(i,b,a) for(LL i=b; i>=a; --i)


const LL MAX_N = 1000000, INF = (LL)1000000099 * 1000000009;


LL n, r = 0, S[MAX_N+1], minpref[MAX_N+1], minsuf[MAX_N+1], wyn[MAX_N];


LL min(LL x, LL y)
{
	return ( x < y ) ? x : y ;
}


void preprocessing()
{
	scanf( "%lld", &n );
	
	S[0] = 0;
	
	minpref[0] = INF;
	
	int a;
	
	REP(i,1,n)
	{
		scanf( "%lld", &a );
		
		S[i] = S[ i - 1 ] + a;
		
		minpref[i] = min( minpref[ i - 1 ], S[i] );
	}
	
	minsuf[n] = S[n];
	
	FORD(i,n-1,1)
	{
		minsuf[i] = min( minsuf[ i + 1 ], S[i] );
	}	
}


void oblicz()
{
	if( minpref[n] >= 0 )
	{
		wyn[ r ] = 0;
		
		++r;
	}
	
	REP(i,1,n-1)
	{
		if( minsuf[ i + 1 ] - S[i] >= 0  &&  S[n] - S[i] + minpref[i] >= 0 )
		{
			wyn[ r ] = i;
		
			++r;
		}
	}
}


void wypisz()
{
	printf( "%d\n", r );
	
	REP(i,0,r-1)
	{
		printf( "%d ", wyn[i] );
	}
	
	printf( "\n" );
}


int main()
{
	preprocessing();
	
	oblicz();
	
	wypisz();
	
	return 0;
}
