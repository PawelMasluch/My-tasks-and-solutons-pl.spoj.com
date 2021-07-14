#include<cstdio> // AC
#include<vector>
#include<stack>
 
 
using namespace std;
 
 
typedef long long LL;
 
typedef vector < LL > VLL;
 
typedef stack < LL > SLL;
 
 
#define PB push_back
 
#define P push
 
#define E empty
 
 
SLL S;
 
VLL v;
 
LL r = 0, a, b, nr, q, n;
 
 
int main()
{
	scanf( "%lld", &n );
	
	while( n )
	{
		scanf( "%lld", &a );
		
		S.P( a );
		
		--n;
	}
	
	v.PB( 0 );  ++r;
	
	while( !S.E() )
	{
		v.PB( v.back() + S.top() );  ++r;
		
		S.pop();	
	}
	
	scanf( "%lld", &q );
	
	while( q )
	{
		scanf( "%lld", &nr );
		
		if( nr == 1 )
		{
			scanf( "%lld %lld", &a, &b );
			
			printf( "%lld\n", v[ r - a ] - v[ r - b - 1 ] );
		}
		else // nr == 2
		{
			scanf( "%lld", &a );
			
			v.PB( v.back() + a );  ++r;
		}
		
		--q;
	}
	
	return 0;
} 
