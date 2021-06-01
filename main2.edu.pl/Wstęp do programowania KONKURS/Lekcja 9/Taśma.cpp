#include<cstdio> // AC (100 pkt)


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)


const int MAX_N = 500000;


int n, t[MAX_N], wyn = -1;


void wczytaj()
{
	scanf( "%d", &n );
	
	REP(i,0,n-1)
	{
		scanf( "%d", &t[i] );
	}
}


int max(int a, int b)
{
	return ( a > b ) ? a : b ;
}


void oblicz()
{
	FORD(i,n-1,1)
	{
		if( t[i] != t[0] )
		{
			wyn = i;
			
			break;
		}
	}
	
	REP(i,0,n-2)
	{
		if( t[i] != t[ n - 1 ] )
		{
			wyn = max( wyn, n - 1 - i );
			
			break;
		}
	}
}


void wypisz()
{
	if( wyn == -1 )
	{
		printf( "BRAK" );
	}
	else
	{
		printf( "%d\n", wyn );
	}
}


int main()
{
	wczytaj();
	
	oblicz();
	
	wypisz();
	
	return 0;
}
