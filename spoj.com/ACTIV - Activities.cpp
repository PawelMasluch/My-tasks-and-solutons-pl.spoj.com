#include<cstdio> // AC
#include<algorithm>
 
 
using namespace std;
 
 
typedef pair < int, int > PII;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
#define MP make_pair
 
#define ST first // koniec przedziaA?u
 
#define ND second // poczÄ?tek przedziaA?u
 
 
const int MAX_N = 1e5, p = 1e8;
 
 
PII t[MAX_N+1];
 
int dp[MAX_N+1], n, ile, ind;
 
 
int bin(int x) // x - numer przedziaA?u
{
	int pocz = 0, kon = x - 1, wyn, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) >> 1;
		
		if( t[ sr ].ST <= t[x].ND )
		{
			wyn = sr;
			
			pocz = sr + 1;
		}
		else
		{
			kon = sr - 1;
		}
	}
	
	return wyn;
}
 
 
int f(int x) // liczba cyfr liczby "x" (tym razem mogÄ? zaA?oA1yÄ?, A1e liczba zero ma zero cyfr)
{
	int wyn = 0;
	
	while( x )
	{
		++wyn;  
		
		x /= 10;
	}
	
	return wyn;
}
 
 
int main()
{
	t[0] = MP( 0, 0 );  dp[0] = 0;
	
	scanf( "%d", &n );
	
	while( n != -1 )
	{
		REP(i,1,n)
		{
			scanf( "%d %d", &t[i].ND, &t[i].ST );
		}
		
		sort( t + 1, t + n + 1 );
		
		REP(i,1,n)
		{
			ind = bin( i );
			
			dp[i] = ( dp[ i - 1 ] + 1 + dp[ ind ] ) % p;
		}
		
		ile = f( dp[n] );
		
		REP(i,1,8-ile)
		{
			printf( "0" );
		}
		
		printf( "%d\n", dp[n] );
		
		scanf( "%d", &n );
	}
	
	return 0;
} 
