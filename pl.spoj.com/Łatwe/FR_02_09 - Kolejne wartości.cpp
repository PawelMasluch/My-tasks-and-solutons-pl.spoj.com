#include<cstdio> // AC
#include<new>
#include<algorithm>


using namespace std;


#define REP(i,n) for(int i=0; i<n; ++i)


void wczytaj(int *t, int n)
{
	REP(i,n)
	{
		scanf( "%d", &t[i] );
	}
}


int bin1(int *t, int n, int val)
{
	int pocz = 0, kon = n - 1, wyn = -1, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( t[ sr ] >= val )
		{
			if( t[ sr ] == val )
			{
				wyn = sr;
			}
			
			kon = sr - 1;
		}
		else
		{
			pocz = sr + 1;
		}
	}
	
	return wyn;
}


int bin2(int *t, int n, int val)
{
	int pocz = 0, kon = n - 1, wyn = -1, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( t[ sr ] <= val )
		{
			if( t[ sr ] == val )
			{
				wyn = sr;
			}
			
			pocz = sr + 1;
		}
		else
		{
			kon = sr - 1;
		}
	}
	
	return wyn;
}


int ile(int *t, int n, int a)
{
	int pocz = bin1( t, n, a ), kon = bin2( t, n, a );
	
	return ( pocz == -1  &&  kon == -1 ) ? 0 : kon - pocz + 1 ;
}


void g(int *t, int n, int a)
{
	int pom = ile( t, n, a );
	
	if( pom >= 3 )
	{
		printf( "Tak\n" );
	}
	else
	{
		if( pom >= 1 )
		{
			printf( "Nie\n" );
		}
		else
		{
			printf( "brak\n" );
		}
	}
}


int main()
{
	int n, q, *t, a;
	
	scanf( "%d", &n );
	
	t = new int [n];
	
	wczytaj( t, n );
	
	sort( t, t + n );
	
	scanf( "%d", &q );
	
	REP(i,q)
	{
		scanf( "%d", &a );
		
		g( t, n, a );
	}
	
	return 0;
}
