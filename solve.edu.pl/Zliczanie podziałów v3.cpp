#include<cstdio> // 97 pkt (na 100 możliwych); rozwiązanie poprawne


using namespace std;


typedef unsigned int UI;


#define REP(i,a,b) for(UI i=a; i<=b; ++i)


const UI MAX_N = 300000, MAX_Q = 1000, p = 1000000007;


UI ile[MAX_N+1], pent[MAX_N+1], q, n = 1, query[MAX_Q];


UI max(UI a, UI b)
{
	return ( a > b ) ? a : b ;
}


void wczytaj_zapytania()
{
	scanf( "%u", &q );
	
	REP(i,0,q-1)
	{
		scanf( "%u", &query[i] );
		
		n = max( n, query[i] );
	}
}


void f(UI i, UI j, int zm)
{
	ile[i] = ( ile[i] + p + ile[ i - pent[j] ] * zm ) % p;
				
	if( pent[j] + j <= i )
	{
		ile[i] = ( ile[i] + p + ile[ i - pent[j] - j ] * zm ) % p;
	}
}


void preprocessing()
{
	ile[0] = 1;
	
	pent[0] = 0;
	
	REP(i,1,n)
	{
		pent[i] = pent[ i - 1 ] + 3 * i - 2;
	}
	
	UI j;
	
	REP(i,1,n)
	{
		j = 1;
		
		while( pent[j] <= i )
		{
			if( j % 2 == 1 )
			{
				f( i, j, 1 );
			}
			else
			{
				f( i, j, -1 );
			}
			
			++j;
		}
	}
}


void obsluz_zapytania()
{
	REP(i,0,q-1)
	{
		printf( "%u\n", ile[ query[i] ] );
	}
}


int main()
{
	wczytaj_zapytania();
	
	preprocessing();
	
	obsluz_zapytania();
	
	return 0;
}