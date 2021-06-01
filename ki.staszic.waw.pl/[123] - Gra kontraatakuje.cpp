#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)


const int MAX_N = 2000, INF = 1000000709;


int dp[MAX_N+1][MAX_N+1], DP[MAX_N+2][MAX_N+2], n, t[MAX_N+1], pref[MAX_N+1], wyn = INF;


int min(int a, int b)
{
	return (a<b) ? a : b ;
}


int max(int a, int b)
{
	return (a>b) ? a : b ;
}


int main()
{
	scanf( "%d", &n );
	
	REP(i,1,n)
	{
		scanf( "%d", &t[i] );
		
		pref[i] = pref[ i - 1 ] + t[i];
		
		dp[i][i] = t[i]; // warunek brzegowy
	}
	
	
	// tablica "dp"
	
	FORD(i,n,1)
	{
		REP(j,i+1,n)
		{
			dp[i][j] = pref[j] - pref[ i - 1 ] - min( dp[ i + 1 ][j], dp[i][ j - 1 ] );
		}
	}
	
	
	// pusty prefiks, niepusty sufiks
	
	DP[0][n] = t[n];
	
	FORD(j,n-1,1)
	{
		DP[0][j] = pref[n] - pref[ j - 1 ] - min( DP[0][ j + 1 ], dp[j][ n - 1 ] );
	}
	
	
	// pusty sufiks, niepusty prefiks
	
	DP[1][ n + 1 ] = t[1];
	
	REP(i,2,n)
	{
		DP[i][ n + 1 ] = pref[i] - min( DP[ i - 1 ][ n + 1 ], dp[2][i] );
	}
	
	
	// niepusty prefiks, niepusty sufiks
	
	REP(i,1,n)
	{
		FORD(j,n,i+1)
		{
			DP[i][j] = pref[i] + pref[n] - pref[ j - 1 ] - min( DP[ i - 1 ][j], DP[i][ j + 1 ] );
		}
	}
	
	
	// minimalny wynik
	
	REP(i,0,n-1)
	{
		wyn = min( wyn, DP[i][ i + 2 ] );
	}
	
	printf( "%d %d\n", pref[n] - wyn, wyn );
	
	return 0;
}
