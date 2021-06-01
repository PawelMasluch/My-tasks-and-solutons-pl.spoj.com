#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)


const int MAX_N = 2000;


int DP[MAX_N+1][MAX_N+1], t[MAX_N+1], pref[MAX_N+1], N;


int max(int a, int b)
{
	return (a>b) ? a : b ;
}

int main()
{
	scanf( "%d", &N );
	
	REP(i,1,N)
	{
		scanf( "%d", &t[i] );
		
		pref[i] = pref[ i - 1 ] + t[i];
		
		DP[i][i] = t[i];
	}
	
	FORD(i,N,1)
	{
		REP(j,i+1,N)
		{
			DP[i][j] = max( t[i] + pref[j] - pref[i] - DP[ i + 1 ][j], t[j] + pref[ j - 1 ] - pref[ i - 1 ] - DP[i][ j - 1 ] );
		}
	}
	
	printf( "%d %d\n", DP[1][N], pref[N] - DP[1][N] );
	
	return 0;
}
