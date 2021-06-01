#include<cstdio> // 100 pkt
#include<vector>


using namespace std;


typedef pair < int, int > PII;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)

#define MP make_pair

#define MIN_PREF first

#define SUM second


const int MAX_R = 131072;


PII DP[2*MAX_R];

int n, R;


int f()
{
	int wyn = 1;
	
	while( wyn < n )
	{
		wyn <<= 1;
	}
	
	return wyn;
}


int min(int a, int b)
{
	return ( a < b ) ? a : b ;
}


void wczytaj()
{
	scanf( "%d", &n );
	
	R = f();
	
	REP(i,0,n-1)
	{
		scanf( "%d", &DP[ R + i ].SUM );
		
		DP[ R + i ].MIN_PREF = DP[ R + i ].SUM;
	}
	
	REP(i,n,R-1)
	{
		DP[ R + i ].MIN_PREF = DP[ R + i ].SUM = 0;
	}
	
	FORD(i,R-1,1)
	{
		DP[i].SUM = DP[ 2 * i ].SUM + DP[ 2 * i + 1 ].SUM;
		
		DP[i].MIN_PREF = min( DP[ 2 * i ].MIN_PREF, DP[ 2 * i ].SUM + DP[ 2 * i + 1 ].MIN_PREF );
	}
}


void query()
{
	if( DP[1].SUM == 0  &&  DP[1].MIN_PREF == 0 )
	{
		printf( "TAK\n" );
	}
	else
	{
		printf( "NIE\n" );
	}
}


void zamien(int v)
{
	DP[v].SUM *= (-1);
	
	DP[v].MIN_PREF = DP[v].SUM;
	
	v /= 2;
	
	while( v > 0 )
	{
		DP[v].SUM = DP[ 2 * v ].SUM + DP[ 2 * v + 1 ].SUM;
		
		DP[v].MIN_PREF = min( DP[ 2 * v ].MIN_PREF, DP[ 2 * v ].SUM + DP[ 2 * v + 1 ].MIN_PREF );
		
		v /= 2;
	}
}


void zapytania()
{
	int a;
	
	scanf( "%d", &a );
	
	while( a != -1 )
	{
		if( a == 0 )
		{
			query();
		}
		else // a > 0
		{
			zamien( --a + R );
		}
		
		scanf( "%d", &a );
	}
}


int main()
{
	wczytaj();
	
	zapytania();
	
	return 0;
}
