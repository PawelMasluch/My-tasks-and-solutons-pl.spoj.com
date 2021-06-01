#include<cstdio>


using namespace std;


#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)


const int MAX_N = 10;


int t[2*MAX_N];


void nawiasy(int n, int przewaga, int indeks)
{
	if( indeks == 2 * n )
	{
		REP(i,0,2*n-1,1)
		{
			printf( "%d ", t[i] );
		}
		
		printf( "\n" );
	}
	else
	{
		REP(i,-1,1,2)
		{
			if( przewaga + i <= 2 * n - indeks  &&  przewaga + i >= 0 )
			{
				t[ indeks ] = i;
				
				nawiasy( n, przewaga + i, indeks + 1 );
			}
		}
	}
}


int main()
{
	nawiasy( 3, 0, 0 );
		
	return 0;
}
