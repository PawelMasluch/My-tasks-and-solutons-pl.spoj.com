#include<cstdio> // 100 pkt
#include<map>


using namespace std;


typedef map < int, int > MII;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 500000;


MII last;

int n, t[MAX_N+1], DP[MAX_N+1];


void wczytaj()
{
	scanf( "%d", &n );
	
	REP(i,1,n)
	{
		scanf( "%d", &t[i] );
	}
}


int max(int a, int b)
{
	return ( a > b ) ? a : b ;
}


void oblicz()
{
	REP(i,1,n)
	{
		DP[i] = DP[ i - 1 ];
		
		if( last[ t[i] ] != 0 )
		{
			DP[i] = max( DP[i], DP[ last[ t[i] ] - 1 ] + 1 );
		}
		
		last[ t[i] ] = i;
	}
}


void wypisz()
{
	printf( "%d\n", DP[n] );
}


void solve()
{
	wczytaj();
	
	oblicz();
	
	wypisz();
}


int main()
{
	solve();
	
	return 0;
}
