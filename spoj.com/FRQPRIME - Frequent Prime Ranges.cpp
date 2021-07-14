#include<cstdio> // AC
 
 
using namespace std;
 
 
typedef long long LL;
 
 
#define REP(i,a,b,skok) for(LL i=a; i<=b; i+=skok)
 
 
const LL MAX_N = 1e5, ZAKRES = 320;
 
 
bool czy[MAX_N+1];
 
LL q, n, k, i1, i2, wyn, tmp;
 
 
void sieve()
{
	REP(i,2,MAX_N,1)
	{
		czy[i] = true;
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
}
 
 
LL query()
{
	if( k == 0 )
	{
		return ( ( n - 1 ) * n ) / 2;
	}
	
	i1 = 2;  i2 = 2;  wyn = 0;  tmp = 0;
	
	while( i1 <= n )
	{
		while( i2 <= n  &&  tmp < k )
		{
			tmp += ( czy[ i2 ] ) ? 1 : 0 ;
			
			++i2;
		}
		
		if( tmp == k  &&  i2 <= n + 1 )
		{
			wyn += n - i2 + 2;
		}
		
		tmp -= ( czy[ i1 ] ) ? 1 : 0 ;
		
		++i1;
	}
	
	return wyn;
}
 
 
int main()
{
	sieve();
	
	scanf( "%lld", &q );
	
	while( q )
	{
		scanf( "%lld %lld", &n, &k );
		
		printf( "%lld\n", query() );
		
		--q;
	}
	
	return 0;
} 
