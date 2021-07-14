#include<cstdio> // AC
#include<vector>
#include<algorithm>
 
 
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
 
 
const int MAX_N = 10000, MAX_K = 50, p = 5000000, INF = 1000000099, MAX_R = 16384;
 
 
VI V;
 
PII pom[MAX_N];
 
int n, k, rozm = 0, a[MAX_N], M = 0, R, DP[2*MAX_R][MAX_K+1];
 
 
void wczytaj_dane()
{
	scanf( "%d %d", &n, &k );
	
	REP(i,0,n-1)
	{
		scanf( "%d", &a[i] );
		
		pom[i] = MP( a[i], i );
	}
}
 
 
void przeskaluj()
{
	sort( pom, pom + n );
	
	a[ pom[0].ND ] = M;
	
	REP(i,1,n-1)
	{
		M += ( ( pom[i].ST == pom[ i - 1 ].ST ) ? 0 : 1 ) ;
		
		a[ pom[i].ND ] = M;
	}
	
	++M;
}
 
 
int f(int x)
{
	int wyn = 1;
	
	while( wyn < x )
	{
		wyn *= 2;
	}
	
	return wyn;
}
 
 
void preprocessing()
{
	R = f( M );
}
 
 
void aktualizuj(int v)
{
	while( v > 0 )
	{
		REP(j,1,k)
		{
			DP[v][j] = ( DP[ 2 * v ][j] + DP[ 2 * v + 1 ][j] ) % p;
		}
		
		v /= 2;
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
 
 
int query(int x, int dl)
{
	bazowe( 1, 0, x - 1, 0, R - 1 );
	
	int wyn = 0;
	
	REP(i,0,rozm-1)
	{
		wyn = ( wyn + DP[ V[i] ][ dl ] ) % p;
	}
	
	V.C();
	
	rozm = 0;
	
	return wyn;
}
 
 
void oblicz()
{
	int tmp;
	
	REP(i,0,n-1)
	{
		tmp = R + a[i];
		
		DP[ tmp ][1] = ( DP[ tmp ][1] + 1 ) % p;
		
		if( a[i] > 0 )
		{
			REP(j,2,k)
			{
				DP[ tmp ][j] = ( DP[ tmp ][j] + query( a[i], j - 1 ) ) % p;
			}
		}
		
		aktualizuj( tmp / 2 );
	}
}
 
 
void wypisz_wynik()
{
	printf( "%d\n", DP[1][k] );
}
 
 
int main()
{
	wczytaj_dane();
	
	przeskaluj();
	
	preprocessing();
	
	oblicz();
	
	wypisz_wynik();
	
	return 0;
} 
