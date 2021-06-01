#include<cstdio> // 100 pkt
#include<vector>
#include<algorithm>


using namespace std;


typedef long long LL;

typedef pair < LL, LL > PLL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)

#define MP make_pair

#define r first

#define x second


const LL INF = 1000000099, MAX_N = 15, MAX_R = 1 << MAX_N;


PLL DP[2][MAX_R], A[2][MAX_N];

LL R[2], r[2];


LL min(LL a, LL b)
{
	return ( a < b ) ? a : b ;
}


LL fun(LL p) // min x : 2^x > p
{
	LL wyn = 0, tmp = 1;
	
	while( tmp <= p )
	{
		++wyn;
		
		tmp *= 2;
	}
	
	return wyn;
}


LL fpm(LL a, LL b, LL p) // (a^b) mod p
{
	LL wyn = 1;
	
	while( b )
	{
		if( b & 1 )
		{
			wyn = ( wyn * a ) % p;
		}
		
		b >>= 1;
		
		a = ( a * a ) % p; 
	}
	
	return wyn;
}


void g(LL X, LL &a, LL &exp, LL p)
{
	REP(i,0,r[X]-1)
	{
		A[X][i] = MP( a, exp );
		
		a = ( a * a ) % p;
		
		exp *= 2;
	}	
}


void f(LL X, LL p)
{
	DP[X][0] = MP( 1, 0 );
	
	LL last = 0, ind = 1;
	
	REP(i,0,r[X]-1)
	{
		REP(j,0,last)
		{
			DP[X][ ind ] = MP( ( DP[X][j].r * A[X][i].r ) % p, DP[X][j].x + A[X][i].x );
			
			++ind;
		}
		
		last = ind - 1;
	}
}


LL bin(LL x)
{
	LL pocz = 0, kon = R[1] - 1, wyn = -1, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( DP[1][ sr ].r >= x )
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
	LL a, b, p, N, exp = 1, wyn = INF, ind;
	
	scanf( "%lld %lld %lld", &a, &b, &p );
	
	a %= p;
	
	b %= p;
	
	if( !a )
	{
		if( !b )
		{
			printf( "1\n" );
		}
		else
		{
			printf( "NIE\n" );
		}
		
		return 0;
	}
	
	N = fun( p );
	
	r[0] = N / 2;
	
	r[1] = N - r[0];
	
	R[0] = 1 << r[0];
	
	R[1] = 1 << r[1];
	
	REP(i,0,1)
	{
		g( i, a, exp, p );
		
		f( i, p );
	}
	
	REP(i,0,R[1]-1)
	{
		DP[1][i].r = ( b * fpm( DP[1][i].r, p - 2, p ) ) % p;
	}
	
	REP(i,0,1)
	{
		sort( DP[i], DP[i] + R[i] );
	}
	
	REP(i,0,R[0]-1)
	{
		ind = bin( DP[0][i].r );
		
		if( ind != -1 )
		{
			if( DP[1][ ind ].r == DP[0][i].r )
			{
				wyn = min( wyn, DP[0][i].x + DP[1][ ind ].x );
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
