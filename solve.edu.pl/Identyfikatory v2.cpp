#include<cstdio> // 100 pkt
#include<vector>


using namespace std;


typedef vector < int > VI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back

#define pb pop_back


VI v;

int n, k, a, r = 0;


int main()
{
	scanf( "%d %d", &n, &k );
	
	v.PB( -1 ); // tu mogę wstawić cokolwiek, bo i tak się do tego nie odwołuję ( w sensie, do v[0] )
	
	REP(i,1,n)
	{
		scanf( "%d", &a );
		
		while( r >= 1  &&  v[r] > a  &&  r + n - i >= k )
		{
			v.pb();
			
			--r;
		}
		
		if( r <= k - 1 )
		{
			v.PB( a );
			
			++r;
		}
	}
	
	REP(i,1,k)
	{
		printf( "%d ", v[i] );
	}
	
	printf( "\n" );
	
	return 0;
}