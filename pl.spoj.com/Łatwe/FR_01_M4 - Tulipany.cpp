#include<cstdio> // AC
#include<new>
#include<algorithm>


using namespace std;


#define REP(i,n) for(int i=0; i<n; ++i)


const int INF = 1000000009;


int min(int a, int b)
{
	return (a<b) ? a : b ;
}


void wczytaj(int *t, int n)
{
	REP(i,n)
	{
		scanf( "%d", &t[i] );
	}
}


int bin1(int *t, int n, int val)
{
	int pocz = 0, kon = n - 1, wyn = -INF, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( t[ sr ] <= val )
		{
			wyn = t[ sr ];
			
			pocz = sr + 1;
		}
		else
		{
			kon = sr - 1;
		}
	}
	
	return wyn;
}


int bin2(int *t, int n, int val)
{
	int pocz = 0, kon = n - 1, wyn = INF, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( t[ sr ] > val )
		{
			wyn = t[ sr ];
			
			kon = sr - 1;
		}
		else
		{
			pocz = sr + 1;
		}
	}
	
	return wyn;
}


int fun(int *t, int n, int val)
{
	int temp1 = bin1( t, n, val ), temp2 = bin2( t, n, val ), pom1 = ( temp1 == -INF ) ? INF : val - temp1, pom2 = ( temp2 == INF ) ? INF : temp2 - val;
	
	return min( pom1, pom2 );
}


int main()
{
	int n, m, *a, *b, wyn = INF;
	
	scanf( "%d", &n );
	
	a = new int [n];
	
	wczytaj( a, n );
	
	scanf( "%d", &m );
	
	b = new int [m];
	
	wczytaj( b, m );
	
	sort( b, b + m );
	
	REP(i,n)
	{
		wyn = min( wyn, fun( b, m, a[i] ) );
	}
	
	printf( "%d\n", wyn );
	
	return 0;
}
