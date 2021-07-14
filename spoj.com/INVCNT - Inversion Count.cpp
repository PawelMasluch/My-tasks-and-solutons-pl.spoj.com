#include<cstdio> // AC
 
 
using namespace std;
 
 
typedef long long LL;
 
 
#define REP(i,a,b,skok) for(LL i=a; i<=b; i+=skok)
 
 
const LL MAX_N = ( 1 << 18 ), INF = 1e7 + 99;
 
 
LL A[MAX_N], POM[MAX_N], q, n;
 
 
LL scal(LL pocz, LL kon)
{
	LL wyn = 0, sr = ( pocz + kon ) / 2, i1 = pocz, i2 = sr + 1, i = pocz;
	
	while( i1 <= sr  &&  i2 <= kon )
	{
		if( A[ i1 ] <= A[ i2 ] )
		{
			wyn += ( i2 - sr - 1 );
			
			POM[i] = A[ i1 ];
			
			++i1;
		}
		else
		{
			POM[i] = A[ i2 ];
			
			++i2;
		}
		
		++i;
	}
	
	while( i1 <= sr )
	{
		wyn += kon - sr;
		
		POM[i] = A[ i1 ];
		
		++i1;
		
		++i;
	}
	
	while( i2 <= kon )
	{
		POM[i] = A[ i2 ];
		
		++i2;
		
		++i;
	}
	
	REP(j,pocz,kon,1)
	{
		A[j] = POM[j];
	}
	
	return wyn;
}
 
 
LL inv()
{
	LL wyn = 0; 
	
	REP(dl,2,MAX_N,dl)
	{
		REP(j,0,MAX_N-dl,dl)
		{
			wyn += scal( j, j + dl - 1 );
		}
	}
	
	return wyn;
}
 
 
int main()
{
	scanf( "%lld", &q );
	
	while( q )
	{
		scanf( "%lld", &n );
		
		REP(i,0,n-1,1)
		{
			scanf( "%lld", &A[i] );
		}
		
		REP(i,n,MAX_N-1,1)
		{
			A[i] = INF;
		}
		
		printf( "%lld\n", inv() );
		
		--q;
	}
	
	return 0;
} 
