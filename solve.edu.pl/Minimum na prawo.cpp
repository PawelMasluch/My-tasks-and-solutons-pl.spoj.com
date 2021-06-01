#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)


const int MAX_N = 1000000;


int n, t[MAX_N], min_prawo[MAX_N];


int min(int a, int b)
{
	return ( a < b ) ? a : b ;
}


void wczytaj()
{
	scanf( "%d", &n );
	
	REP(i,0,n-1)
	{
		scanf( "%d", &t[i] );
	}
	
	min_prawo[ n - 1 ] = t[ n - 1 ];
	
	FORD(i,n-2,0)
	{
		min_prawo[i] = min( t[i], min_prawo[ i + 1 ] );
	}
}


void oblicz()
{
	min_prawo[ n - 1 ] = t[ n - 1 ];
	
	FORD(i,n-2,0)
	{
		min_prawo[i] = min( t[i], min_prawo[ i + 1 ] );
	}
}


void wypisz()
{
	REP(i,0,n-1)
	{
		printf( "%d ", min_prawo[i] );
	}
}


int main()
{
	wczytaj();
	
	oblicz();
	
	wypisz();
	
	return 0;
}
