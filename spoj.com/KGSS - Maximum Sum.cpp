#include<cstdio> // AC
#include<vector>
 
 
using namespace std;
 
 
typedef pair < int, int > PII;
 
typedef vector < int > VI;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
#define FORD(i,b,a) for(int i=b; i>=a; --i)
 
#define PB push_back
 
#define C clear
 
#define MP make_pair
 
#define ST first
 
#define ND second
 
 
const int MAX_R = 131072, INF = 1000000099;
 
 
VI V;
 
PII DP[2*MAX_R];
 
char zn;
 
int q, n, r, rozm = 0, x, y;
 
 
int max(int a, int b)
{
	return ( a > b ) ? a : b ;
}
 
 
int f()
{
	int wyn = 1;
	
	while( wyn < n )
	{
		wyn *= 2;
	}
	
	return wyn;
}
 
 
PII aktualizuj(PII &v1, PII &v2)
{
	PII wyn;
	
	wyn.ST = max( v1.ST, v2.ST );
	
	int ktory = ( v1.ST > v2.ST ) ? 1 : 2 ;
	
	wyn.ND = ( ktory == 1 ) ? max( v1.ND, v2.ST ) : max( v2.ND, v1.ST ) ;
	
	return wyn;
}
 
 
void wczytaj_dane()
{
	scanf( "%d", &n );
	
	r = f();
	
	REP(i,0,n-1)
	{
		scanf( "%d", &x );
		
		DP[ r + i ] = MP( x, -INF );
	}
	
	REP(i,n,r-1)
	{
		DP[ r + i ] = MP( -INF, -INF );
	}
	
	FORD(i,r-1,1)
	{
		DP[i] = aktualizuj( DP[ 2 * i ], DP[ 2 * i + 1 ] );
	}
}
 
 
void aktualizuj_drzewo()
{
	--x;
	
	int tmp = r + x;
	
	DP[ tmp ] = MP( y, -INF );
	
	tmp /= 2;
	
	while( tmp > 0 )
	{
		DP[ tmp ] = aktualizuj( DP[ 2 * tmp ], DP[ 2 * tmp + 1 ] );
		
		tmp /= 2;
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
 
 
void query()
{
	--x;  --y;
	
	bazowe( 1, x, y, 0, r - 1 );
	
	PII wyn = MP( -INF, -INF );
	
	REP(i,0,rozm-1)
	{
		wyn = aktualizuj( wyn, DP[ V[i] ] );
	}
	
	printf( "%d\n", wyn.ST + wyn.ND );
	
	V.C();
	
	rozm = 0;
}
 
 
void obsluz_zapytania()
{
	scanf( "%d", &q );
	
	while( q )
	{
		scanf( " %c %d %d", &zn, &x, &y );
		
		if( zn == 'U' )
		{
			aktualizuj_drzewo();
		}
		else // zn == 'Q'
		{
			query();
		}
		
		--q;
	}
}
 
 
int main()
{
	wczytaj_dane();
	
	obsluz_zapytania();
	
	return 0;
} 
