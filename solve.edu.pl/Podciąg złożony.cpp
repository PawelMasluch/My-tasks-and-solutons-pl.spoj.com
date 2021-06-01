#include<cstdio> // 100 pkt
#include<vector>


using namespace std;


typedef pair < int, int > PII;

typedef vector < int > VI;

typedef vector < PII > VPII;


#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)

#define FORD(i,b,a,skok) for(int i=b; i>=a; i-=skok)

#define PB push_back

#define C clear

#define MP make_pair

#define ST first

#define ND second


const int R = 524288, MAX_N = 4000000, ZAKRES = 2000;


VPII luka;

VI V;

bool czy[MAX_N+1];

int nr[MAX_N+1], q, n = 0, DP[2*R], rozm = 0;


int max(int a, int b)
{
	return ( a > b ) ? a : b ;
}


void preprocessing()
{
	REP(i,0,1,1)
	{
		czy[i] = false;
		
		nr[i] = -1;
	}
	
	REP(i,2,MAX_N,1)
	{
		czy[i] = true;
		
		nr[i] = -1;
	}
	
	REP(i,2,ZAKRES,1)
	{
		if( czy[i] )
		{
			REP(j,i*i,MAX_N,i)
			{
				czy[j] = false;
			}
		}
	}
	
	int pocz = 4, kon = 4;
	
	while( kon <= MAX_N )
	{
		if( !czy[ kon ] )
		{
			nr[ kon ] = n;
			
			++kon;
		}
		else
		{
			luka.PB( MP( pocz, kon - 1 ) );
			
			DP[ R + n ] = kon - pocz;
			
			++n;
			
			pocz = ++kon;
		}
	}
	
	luka.PB( MP( pocz, MAX_N ) );
	
	DP[ R + n ] = MAX_N - pocz + 1;
	
	++n;
	
	REP(i,n,R-1,1)
	{
		DP[ R + i ] = 0;
	}
	
	FORD(i,R-1,1,1)
	{
		DP[i] = max( DP[ 2 * i ], DP[ 2 * i + 1 ] );
	}
}


void bazowe(int v, int a, int b, int lewy, int prawy)
{
	if( a == lewy  &&  b == prawy )
	{
		V.PB( v );
		
		++rozm;
		
		return;	
	}
	
	int sr = ( lewy + prawy ) / 2;
	
	if( b <= sr )
	{
		bazowe( 2 * v, a, b, lewy, sr );
	}
	else
	{
		if( a > sr )
		{
			bazowe( 2 * v + 1, a, b, sr + 1, prawy );
		}
		else
		{
			bazowe( 2 * v, a, sr, lewy, sr );
			
			bazowe( 2 * v + 1, sr + 1, b, sr + 1, prawy );
		}
	}
}


int query(int a, int b)
{
	if( b < 4 )
	{
		return 0;
	}
	
	a = max( a, 4 );
	
	while( czy[a] )
	{
		++a;
	}
	
	while( czy[b] )
	{
		--b;
	}
	
	if( a > b )
	{
		return 0;
	}
	
	if( nr[a] == nr[b] )
	{
		return b - a + 1;
	}
	
	int wyn = max( luka[ nr[a] ].ND - a + 1, b - luka[ nr[b] ].ST + 1 );
	
	a = nr[a] + 1;
	
	b = nr[b] - 1;
	
	if( a <= b )
	{
		bazowe( 1, a, b, 0, R - 1 );
		
		REP(i,0,rozm-1,1)
		{
			wyn = max( wyn, DP[ V[i] ] );
		}
		
		V.C();
	
		rozm = 0;
	}
	
	return wyn;
}


void obsluz_zapytania()
{
	scanf( "%d", &q );
	
	int a, b;
	
	while( q )
	{
		scanf( "%d %d", &a, &b );
		
		printf( "%d\n", query( a, b ) );
		
		--q;
	}
}


int main()
{
	preprocessing();
	
	obsluz_zapytania();
	
	return 0;
}
