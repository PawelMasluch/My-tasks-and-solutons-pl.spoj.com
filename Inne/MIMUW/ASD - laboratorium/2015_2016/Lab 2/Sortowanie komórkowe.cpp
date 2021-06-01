#include<cstdio> // do sprawdzenia


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)


const int MAX_N = 1000, p = 1000000000;


int n, t[MAX_N], DP[MAX_N][MAX_N];


void wczytaj()
{
	scanf( "%d", &n );
	
	REP(i,0,n-1)
	{
		scanf( "%d", &t[i] );
	}
}


void oblicz()
{
	// w tej procedurze obliczamy tablice DP, gdzie DP[i][j], oznacza, na ile sposobow mozna stworzyc ciag t[i], ..., t[j]
	
	REP(i,0,n-1)
	{
		DP[i][i] = 1;
	}
	
	FORD(i,n-1,0)
	{
		REP(j,i+1,n-1)
		{
			// obliczamy teraz DP[i][j]
			
			if( t[i] < t[ i + 1 ]  ||  t[i] < t[j] ) // ostatnim elementem moglo byc t[i]
			{
				DP[i][j] = ( DP[i][j] + DP[ i + 1 ][j] ) % p;
			}
			
			if( t[j] > t[ j - 1 ]  ||  t[j] > t[i] ) // ostatnim elementem moglo byc t[j]
			{
				DP[i][j] = ( DP[i][j] + DP[i][ j - 1 ] ) % p;
			}
		}
	}
	
	printf( "%d\n", DP[0][ n - 1 ] );
}


int main()
{
	wczytaj();
	
	oblicz();
	
	return 0;
}
