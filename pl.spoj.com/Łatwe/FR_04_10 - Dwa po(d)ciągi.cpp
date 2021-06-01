#include<cstdio> // AC


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)


const LL MAX_N = 1e5;


LL n, q, a[MAX_N+1], wyn = 0;


int main()
{
	a[0] = 0;
	
	scanf( "%lld", &q );
	
	while( q )
	{
		scanf( "%lld", &n );
		
		REP(i,1,n)
		{
			scanf( "%lld", &a[i] );
			
			a[i] += a[ i - 1 ]; 
		}
		
		REP(i,1,n-1)
		{
			if( a[i] == a[n] - a[i] )
			{
				++wyn;
			}
		}
		
		printf( "%lld\n", wyn );
		
		wyn = 0;
		
		--q;
	}
	
	return 0;
}
