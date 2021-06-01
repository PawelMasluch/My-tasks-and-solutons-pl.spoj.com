#include<cstdio> // AC


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 500000;


int n, r = 0, podciag[MAX_N], odp[MAX_N+2];


void wczytaj()
{
	scanf( "%d", &n );
	
	int a, b, dl = 1;
	
	scanf( "%d", &a );
	
	REP(i,1,n-1)
	{
		scanf( "%d", &b );
		
		if( b > a )
		{
			++dl;
		}
		else
		{
			podciag[ r ] = dl;
			
			++r;
			
			dl = 1;
		}
		
		a = b;
	}
	
	podciag[r] = dl;
	
	++r;
}


void oblicz()
{
	int dl;
	
	REP(i,0,r-1)
	{
		dl = podciag[i];
		
		REP(j,1,dl)
		{
			odp[j] += dl - j + 1;
		}
	}
}


void wypisz()
{
	int ind = 1;
	
	while( odp[ ind ] > 0 )
	{
		printf( "%d ", odp[ ind ] );
		
		++ind;
	}
	
	if( ind <= n )
	{
		printf( "%d", odp[ ind ] );
	}
	
	printf( "\n" );
}


int main()
{
	wczytaj();
	
	oblicz();
	
	wypisz();
	
	return 0;
}
