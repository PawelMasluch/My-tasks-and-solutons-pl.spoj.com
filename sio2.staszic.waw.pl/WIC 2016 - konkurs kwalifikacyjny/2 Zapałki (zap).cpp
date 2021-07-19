#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)


const int MAX_N = 1000000;


int n, h[MAX_N], ile1[MAX_N], ile2[MAX_N];


int max(int a, int b)
{
	return ( a > b ) ? a : b ;
}


int main()
{
	scanf( "%d", &n );
	
	REP(i,0,n-1)
	{
		scanf( "%d", &h[i] );
	}
	
	ile1[0] = 1;
	
	REP(i,1,n-1)
	{
		ile1[i] = ( h[i] >= h[ i - 1 ] ) ? ile1[ i - 1 ] + 1 : 1 ;
	}
	
	ile2[ n - 1 ] = 1;
	
	FORD(i,n-2,0)
	{
		ile2[i] = ( h[i] >= h[ i + 1 ] ) ? ile2[ i + 1 ] + 1 : 1 ;
	}
	
	int wyn = 0;
	
	REP(i,0,n-1)
	{
		wyn = max( wyn, ile1[i] + ile2[i] - 1 );
	}
	
	printf( "%d\n", wyn );
	
	return 0;
}
