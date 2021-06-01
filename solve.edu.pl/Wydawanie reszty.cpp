#include<cstdio> // 100 pkt
#include<vector>
#include<algorithm>


using namespace std;


typedef long long LL;

typedef pair < LL, LL > PLL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)

#define MP make_pair

#define S first

#define ile second


const LL INF = 1e9 + 99, MAX_N = 20, MAX_R = 1 << MAX_N;


PLL DP[2][MAX_R];

LL A[2][MAX_N], N, K, wyn = INF, r[2], R[2], last, ind;


LL min(LL a, LL b)
{
	return ( a < b ) ? a : b ;
}


void f(LL x)
{
	DP[x][0] = MP( 0, 0 );
	
	last = 0;
	
	ind = 1;
	
	REP(i,0,r[x]-1)
	{
		REP(j,0,last)
		{
			DP[x][ ind ] = MP( DP[x][j].S + A[x][i], DP[x][j].ile + 1 );
			
			++ind;
		}
		
		last = ind - 1;
	}
	
	sort( DP[x], DP[x] + R[x] );
}


LL bin(LL x)
{
	LL pocz = 0, kon = R[1] - 1, wyn = -1, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( DP[1][ sr ].S >= x )
		{
			wyn = sr;
			
			kon = sr - 1;
		}
		else
		{
			pocz = sr + 1;
		}
	}
	
	return wyn;
}


int main()
{
	scanf( "%lld %lld", &N, &K );
	
	r[0] = N / 2;
	
	r[1] = N - r[0];
	
	R[0] = 1 << r[0];
	
	R[1] = 1 << r[1];
	
	REP(i,0,1)
	{
		REP(j,0,r[i]-1)
		{
			scanf( "%lld", &A[i][j] );
		}
	}
	
	REP(i,0,1)
	{
		f( i );
	}
	
	REP(i,0,R[0]-1)
	{
		ind = bin( K - DP[0][i].S );
		
		if( ind != -1 )
		{
			if( DP[0][i].S + DP[1][ ind ].S == K )
			{
				wyn = min( wyn, DP[0][i].ile + DP[1][ ind ].ile );	
			}
		}
	}
	
	if( wyn == INF )
	{
		printf( "NIE\n" );
	}
	else
	{
		printf( "%lld\n", wyn );
	}
	
	return 0;
}
