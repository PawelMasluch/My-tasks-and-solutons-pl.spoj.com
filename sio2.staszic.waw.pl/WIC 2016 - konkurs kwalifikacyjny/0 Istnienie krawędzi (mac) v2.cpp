#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 1000;


bool T[MAX_N][MAX_N];

int n, m, q;


void preprocessing()
{
	REP(i,0,MAX_N-1)
	{
		REP(j,0,MAX_N-1)
		{
			T[i][j] = false;
		}
	}
}


void wczytaj()
{
	int a, b;
	
	scanf( "%d %d", &n, &m );
	
	REP(i,1,m)
	{
		scanf( "%d %d", &a, &b );
		
		T[ a - 1 ][ b - 1 ] = true;
		
		T[ b - 1 ][ a - 1 ] = true;
	}
}


void obsluz_zapytania()
{
	int a, b;
	
	scanf( "%d", &q );
	
	while( q )
	{
		scanf( "%d %d", &a, &b );
		
		if( T[ --a ][ --b ] == true )
		{
			printf( "TAK\n" );
		}
		else
		{
			printf( "NIE\n" );
		}
		
		--q;
	}	
}


int main()
{
	preprocessing();
	
	wczytaj();
	
	obsluz_zapytania();
	
	return 0;
}
