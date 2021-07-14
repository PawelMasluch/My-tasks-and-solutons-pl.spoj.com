#include<cstdio> // AC
#include<algorithm>
 
 
using namespace std;
 
 
#define REP(i,n) for(int i=0; i<n; ++i)
 
 
const int MAX_N = 1e5, MAX_WYN = 1e9;
 
 
int q, n, x[MAX_N], c;
 
 
bool czy(int d)
{
	int ile = 1, i1 = 0, i2 = 1;
	
	while( i2 <= n - 1 )
	{
		if( x[ i2 ] - x[ i1 ] < d )
		{
			++i2;
		}
		else
		{
			++ile;
			
			if( ile == c )
			{
				return true;
			}
			
			i1 = i2;
			
			++i2;
		}
	}
	
	return false;
}
 
 
int f()
{
	int pocz = 1, kon = MAX_WYN, wyn, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( czy( sr ) == true )
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
 
 
int main()
{
	scanf( "%d", &q );
	
	while( q )
	{
		scanf( "%d %d", &n, &c );
		
		REP(i,n)
		{
			scanf( "%d", &x[i] );
		}
		
		sort( x, x + n );
		
		printf( "%d\n", f() );
		
		--q;
	}
	
	return 0;
} 
