#include<cstdio> // 76/100 pkt; zaliczylem wszystkie testy
#include<algorithm>


using namespace std;


#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)


const int MAX_N = 8e6, ZAKRES = 2828, NUM = 22;


int dz[MAX_N+1], czynnik[NUM], r = -1;


void sito()
{
	dz[0] = 1; // dla porządku
	
	REP(i,1,MAX_N,1)
	{
		dz[i] = i;
	}
	
	REP(i,2,ZAKRES,1)
	{
		if( dz[i] == i )
		{
			REP(j,i*i,MAX_N,i)
			{
				dz[j] = i;
			}
		}
	}
}


void rozklad(int n)
{
	if( n == 1 )
	{
		printf( "1\n" );
		
		return;
	}
	
	while( n > 1 )
	{
		czynnik[ ++r ] = dz[n];
		
		n /= dz[n];
	}
	
	sort( czynnik, czynnik + r + 1 );
	
	REP(i,0,r,1)
	{
		printf( "%d ", czynnik[i] );
	}
	
	printf( "\n" );
	
	r = -1;
}


int main()
{
	sito();
	
	int N, Q;
	
	scanf( "%d", &Q );
	
	while( Q )
	{
		scanf( "%d", &N );
		
		rozklad( N );
		
		--Q;
	}
	
	return 0;
}
