#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 100000, INF = 1000000099;


int q, n, a[MAX_N], S[MAX_N+1];


void preprocessing()
{
	S[0] = -INF;
	
	REP(i,1,n)
	{
		S[i] = INF;
	}
}


void wczytaj()
{
	scanf( "%d", &n );
	
	preprocessing();
	
	REP(i,0,n-1)
	{
		scanf( "%d", &a[i] );
	}
}


int max(int a, int b)
{
	return ( a > b ) ? a : b ;
}


int bin(int x)
{
	int pocz = 1, kon = n, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( S[ sr - 1 ] < x )
		{
			if( x <= S[ sr ] )
			{
				S[ sr ] = x;
				
				return sr;
			}
				
			pocz = sr + 1;
		}
		else
		{
			kon = sr - 1;
		}
	}
}


void oblicz()
{
	int ind, wyn = 0;
	
	REP(i,0,n-1)
	{
		ind = bin( a[i] );
		
		wyn = max( wyn, ind );
	}
	
	printf( "%d\n", wyn );
}


void zapytania()
{
	scanf( "%d", &q );
	
	while( q )
	{
		wczytaj();
		
		oblicz();
		
		--q;
	}
}


int main()
{
	zapytania();
	
	return 0;
}
