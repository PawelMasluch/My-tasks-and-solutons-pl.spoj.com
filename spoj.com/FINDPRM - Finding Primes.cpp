#include<cstdio> // AC
 
 
using namespace std;
 
 
#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)
 
 
const int MAX_N = 1e7, ZAKRES = 32e2;
 
 
int q, n, czy[MAX_N+1];
 
 
void sieve()
{
	REP(i,2,MAX_N,1)
	{
		czy[i] = 1;
	}
	
	REP(i,2,ZAKRES,1)
	{
		if( czy[i] )
		{
			REP(j,i*i,MAX_N,i)
			{
				czy[j] = 0;
			}
		}
	}
}
 
 
void compute_prefix_sums()
{
	REP(i,1,MAX_N,1)
	{
		czy[i] += czy[ i - 1 ];
	}
}
 
 
void preprocessing()
{
	sieve();
	
	compute_prefix_sums();
}
 
 
int main()
{
	preprocessing();
	
	scanf( "%d", &q );
	
	while( q )
	{
		scanf( "%d", &n );
		
		printf( "%d\n", czy[n] - czy[ n >> 1 ] );
		
		--q;
	}
	
	return 0;
} 
