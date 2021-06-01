#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 100000;


LL DP[MAX_N+1][2], dp[MAX_N+1][4][2];

int n, t[MAX_N+1];


void wczytaj()
{
	scanf( "%d", &n );
	
	REP(i,1,n)
	{
		scanf( "%d", &t[i] );
	}
}


void init()
{
	dp[1][1][0] = DP[1][0] = t[1];
}


LL max(LL a, LL b)
{
	return ( a > b ) ? a : b ;
}


void oblicz()
{
	init();
	
	REP(i,2,n)
	{
		dp[i][1][0] = DP[ i - 2 ][0] + t[i];
		
		dp[i][2][0] = dp[ i - 1 ][1][0] + t[i];
		
		dp[i][1][1] = DP[ i - 2 ][1] + t[i];
		
		dp[i][2][1] = dp[ i - 1 ][1][1] + t[i];
		
		dp[i][3][1] = dp[ i - 1 ][2][0] + t[i];
		
		DP[i][0] = max( DP[ i - 1 ][0], max( dp[i][1][0], dp[i][2][0] ) );
		
		DP[i][1] = max( max( DP[ i - 1 ][1], dp[i][1][1] ), max( dp[i][2][1], dp[i][3][1]) );
	}
}


void wypisz()
{
	printf( "%lld\n", max( DP[n][0], DP[n][1] ) );
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
