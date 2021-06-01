#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 1000000;


LL wyn[MAX_N+1];

int n, q, prefR[MAX_N+1], prefN[MAX_N+1];


void wczytaj()
{
	scanf( "%d", &n );
	
	char zn;
	
	REP(i,1,n)
	{
		scanf( " %c", &zn );
		
		prefR[i] = prefR[ i - 1 ];
		
		prefN[i] = prefN[ i - 1 ];
		
		wyn[i] = wyn[ i - 1 ];
		
		switch( zn )
		{
			case 'R':
				++prefR[i];
				break;
				
			case 'N':
				++prefN[i];
				wyn[i] += prefR[ i - 1 ];
				break;
		}
	}
}


void zapytania()
{
	scanf( "%d", &q );
	
	int a, b;
	
	while( q )
	{
		scanf( "%d %d", &a, &b );
		
		printf(   "%lld\n",   wyn[b]  -  wyn[ a - 1 ]  -  (LL)prefR[ a - 1 ] * ( prefN[b] - prefN[ a - 1 ] )   );
		
		--q;
	}
}


int main()
{
	wczytaj();
	
	zapytania();
	
	return 0;
}
