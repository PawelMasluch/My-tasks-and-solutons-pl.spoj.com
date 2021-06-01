#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_K = 1e6;


int n, k, a, r = 0, v[MAX_K+1];


int main()
{
	scanf( "%d %d", &n, &k );
	
	v[0] = -1; // tu mogę wstawić cokolwiek, bo i tak się do tego nie odwołuję ( w sensie, do v[0] )
	
	REP(i,1,n)
	{
		scanf( "%d", &a );
		
		while( r >= 1  &&  v[r] > a  &&  r + n - i >= k )
		{
			--r;
		}
		
		if( r <= k - 1 )
		{
			v[ ++r ] = a;
		}
	}
	
	REP(i,1,k)
	{
		printf( "%d ", v[i] );
	}
	
	printf( "\n" );
	
	return 0;
}
