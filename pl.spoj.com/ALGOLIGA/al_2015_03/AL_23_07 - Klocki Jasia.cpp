#include<cstdio> // AC
#include<new>
 
 
using namespace std;
 
 
typedef long long LL;
 
 
#define REP(i,a,b) for(LL i=a; i<=b; ++i)
 
#define D delete
 
 
LL merge(LL *t, LL *pom, LL pocz, LL sr, LL kon)
{
	LL i1 = pocz, i2 = sr + 1, i = pocz, wyn = 0, ile = 0;
	
	while( i1 <= sr  &&  i2 <= kon )
	{
		if( t[ i1 ] <= t[ i2 ] )
		{
			pom[i] = t[i1];
			
			++i1;
			
			wyn += ile;
		}
		else
		{
			pom[i] = t[i2];
			
			++i2;
			
			++ile;
		}
		
		++i;
	}
	
	while( i1 <= sr )
	{
		pom[i] = t[i1];
		
		++i1;
		
		++i;
		
		wyn += ile;
	}
	
	while(i2<=kon)
	{
		pom[i] = t[i2];
		
		++i2;
		
		++i;
	}
	
	for(i=pocz; i<=kon; ++i)
	{
		t[i] = pom[i];
	}
	
	return wyn;
}
 
 
LL mergesort(LL *t, LL *pom, LL pocz, LL kon)
{
	if( pocz == kon )
	{
		return 0;
	}
	
	LL sr = ( pocz + kon ) / 2, wyn = 0;
		
	wyn += mergesort( t, pom, pocz, sr );
		
	wyn += mergesort( t, pom, sr + 1, kon );
	
	wyn += merge( t, pom, pocz, sr, kon );
	
	return wyn;
	
}
 
 
int main()
{
	LL *t, *pom, n, q;
	
	scanf( "%lld", &q );
	
	while( q )
	{
		scanf( "%lld", &n );
		
		t = new LL [n];
		
		pom = new LL [n];
		
		REP(i,0,n-1)
		{
			scanf( "%lld", &t[i] );
		}
		
		if( mergesort( t, pom, 0, n - 1 ) % 2 == 0 )
		{
			printf( "TAK\n" );
		}
		else
		{
			printf( "NIE\n" );
		}
		
		D [] t;
		
		D [] pom;
		
		--q;
	}
	
	return 0;
} 
