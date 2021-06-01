#include<cstdio>


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 50;


int n, k, t[MAX_N];


void podzialy(int n, int k, int *t, int ile, int ogr_dolne)
{
	if( ile == k - 1 )
	{
		REP(i,0,ile-1)
		{
			printf( "%d ", t[i] );
		}
		
		printf( "%d\n", n );
	}
	else
	{
		REP( i, ogr_dolne, n/2 )
		{
			t[ ile ] = i;
			
			podzialy( n - i, k, t, ile + 1, i );
		}
	}
}


int main()
{
	scanf( "%d %d", &n, &k );
	
	podzialy( n, k, t, 0, 1 );
	
	return 0;
}
