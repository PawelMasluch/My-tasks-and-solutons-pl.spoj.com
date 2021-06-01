#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 1000;


int n, t[MAX_N], DP[MAX_N], wyn = 0;


int max(int a, int b)
{
	return ( a > b ) ? a : b ;
}


int main()
{
	scanf( "%d", &n );
	
	REP(i,0,n-1)
	{
		scanf( "%d", &t[i] );
		
		REP(j,0,i-1)
		{
			if( t[i] % t[j] == 0 )
			{
				DP[i] = max( DP[i], 1 + DP[j] );
			}
		}
		
		wyn = max( wyn, DP[i] );
	}
	
	printf( "%d\n", wyn );
	
	return 0;
}
