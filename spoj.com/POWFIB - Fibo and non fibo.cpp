#include<cstdio> // AC
#include<new>
 
 
using namespace std;
 
 
typedef unsigned long long ULL;
 
 
#define REP(i,a,b) for(ULL i=a; i<=b; ++i)
 
 
const ULL p = 1e9 + 7, INF = (ULL)1e9 * 1e9 * 9 + 1e6;
 
 
ULL *F, **A, **W, **POM;
 
 
void init()
{
	F = new ULL [94];
	
	F[0] = 0;  F[1] = 1;
	
	REP(i,2,93)
	{
		F[i] = F[ i - 1 ] + F[ i - 2 ];
	}
	
	A = new ULL * [2];  
	
	W = new ULL * [2];
	
	POM = new ULL * [2];
	
	REP(i,0,1)
	{
		A[i] = new ULL [2];
		
		W[i] = new ULL [2];
		
		POM[i] = new ULL [2];
	}
}
 
 
void initA()
{
	REP(i,0,1)
	{
		REP(j,0,1)
		{
			A[i][j] = 1;
		}
	}
	
	A[0][0] = 0;
}
 
 
void zero(ULL **X)
{
	REP(i,0,1)
	{
		REP(j,0,1)
		{
			X[i][j] = 0;
		}
	}
}
 
 
void unit(ULL **X)
{
	zero( X );
	
	REP(i,0,1)
	{
		X[i][i] = 1;
	}
}
 
 
ULL ile(ULL n)
{
	ULL pocz = 2, kon = 93, wyn, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) >> 1;
		
		if( F[ sr ] <= n )
		{
			wyn = sr;
			
			pocz = sr + 1;
		}
		else
		{
			kon = sr - 1;
		}
	}
	
	return wyn - 2 + 1;
}
 
 
ULL nonfib(ULL n)
{
	ULL pocz = 1, kon = INF, wyn, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) >> 1;
				
		if( sr - ile( sr ) >= n )
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
 
 
void nadpisz(ULL **X, ULL **Y)
{
	REP(i,0,1)
	{
		REP(j,0,1)
		{
			X[i][j] = Y[i][j];
		}
	}
}
 
 
void mnoz(ULL **X, ULL **Y)
{
	zero( POM );
	
	REP(i,0,1)
	{
		REP(k,0,1)
		{
			REP(j,0,1)
			{
				POM[i][j] = ( POM[i][j] + X[i][k] * Y[k][j] ) % p;
			}
		}
	}
	
	nadpisz( X, POM );
}
 
 
ULL fib(ULL n)
{
	initA();
	
	unit( W );
	
	while( n )
	{
		if( n & 1 )
		{
			mnoz( W, A );
		}
		
		n >>= 1;
		
		mnoz( A, A );
	}
	
	return W[0][1];
}
 
 
ULL fpm(ULL a, ULL b)
{
	ULL wyn = 1;
	
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
 
 
ULL f(ULL n)
{
	ULL a = nonfib( n ), b = fib( n );
	
	return fpm( a, b );
}
 
 
int main()
{
	init();
	
	ULL q, n;
	
	scanf( "%llu", &q );
	
	while( q )
	{
		scanf( "%llu", &n );
		
		printf( "%llu\n", f( n ) );
		
		--q;
	}
	
	return 0;
} 
