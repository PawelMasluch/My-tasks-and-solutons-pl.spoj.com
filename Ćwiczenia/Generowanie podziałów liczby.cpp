#include<cstdio>


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 50;


int n, t[MAX_N];


void podzialy(int n, int *t, int ile, int ogr_dolne)
{
	if( n == 0 )
	{
		REP(i,0,ile-1)
		{
			printf( "%d ", t[i] );
		}
		
		printf( "\n" );
	}
	else
	{
		REP(i,ogr_dolne,n)
		{
			t[ ile ] = i;
			
			podzialy( n - i, t, ile + 1, i );
		}
	}
}


/*void podzialy(int n, int *t, int ile, int ogr_dolne)
{
	REP( i, ogr_dolne, n/2 )
	{
		t[ ile ] = i;
		
		podzialy( n - i, t, ile + 1, i );
	}
	
	REP(i,0,ile-1)
	{
		printf( "%d ", t[i] );
	}
	
	printf( "%d\n", n );
}*/


int main()
{
	scanf( "%d", &n );
	
	podzialy( n, t, 0, 1 );
	
	return 0;
}
