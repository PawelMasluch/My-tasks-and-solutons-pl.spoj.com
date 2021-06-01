#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 1000000;


int n, t[MAX_N];


int max(int a, int b)
{
	return ( a > b ) ? a : b ;
}


void wczytaj()
{
	scanf( "%d", &n );
	
	REP(i,0,n-1)
	{
		scanf( "%d", &t[i] );
		
		--t[i];
	}
}


void oblicz_ilosc_skladowych()
{
	int maximum = -1, wyn = 0;
	
	REP(i,0,n-1)
	{
		maximum = max( maximum, t[i] );
		
		if( maximum == i )
		{
			++wyn;
		}
	}
	
	printf( "%d\n", wyn );	
}


void wyznacz_skladowe()
{
	int maximum = -1, prev = -1;
	
	REP(i,0,n-1)
	{
		maximum = max( maximum, t[i] );
		
		if( maximum == i )
		{
			printf( "%d ", i - prev );
			
			REP(j,prev+1,i)
			{
				printf( "%d ", j + 1 );
			}
			
			printf( "\n" );
			
			prev = i;
		}
	}
}


int main()
{
	wczytaj();
	
	oblicz_ilosc_skladowych();
	
	wyznacz_skladowe();
	
	return 0;
}
