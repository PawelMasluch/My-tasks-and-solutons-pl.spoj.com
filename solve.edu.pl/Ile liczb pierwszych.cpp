#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)


const int MAX_N = 4e6, ZAKRES = 2e3;


int czy[MAX_N+1];


void sito()
{
	czy[0] = czy[1] = 0; // 0 oraz 1 nie są pierwsze
	
	REP(i,2,MAX_N,1)
	{
		czy[i] = 1;
	}
	
	REP(i,2,ZAKRES,1)
	{
		if( czy[i] == 1 )
		{
			REP(j,i*i,MAX_N,i)
			{
				czy[j] = 0;
			}
		}
	}
	
	REP(i,1,MAX_N,1)
	{
		czy[i] += czy[ i - 1 ];
	}
}


int ile(int a, int b)
{
	return czy[b] - czy[ a - 1 ];
}


int main()
{
	sito();
	
	int A, B, Q;
	
	scanf( "%d", &Q );
	
	while( Q )
	{
		scanf( "%d %d", &A, &B );
		
		printf( "%d\n", ile( A, B ) );
		
		--Q;
	}
	
	return 0;
}
