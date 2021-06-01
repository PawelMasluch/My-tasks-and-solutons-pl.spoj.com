#include<cstdio> // 83/100 pkt; zaliczylem wszystkie testy
#include<new>


using namespace std;


typedef long long LL;


#define REP(i,n) for(LL i=0; i<n; ++i)


const LL p = 1e9 + 7;


LL N, M, K, a, b, **A, **I;


void init()
{
	A = new LL * [N];
	
	I = new LL * [N];
	
	REP(i,N)
	{
		A[i] = new LL [N];
		
		I[i] = new LL [N];
		
		REP(j,N)
		{
			A[i][j] = 0;
			
			I[i][j] = 0;
		}
		
		I[i][i] = 1;
	} 
}


LL ** dodaj(LL **X, LL **Y)
{
	LL ** WYN = new LL * [N];
	
	REP(i,N)
	{
		WYN[i] = new LL [N];
		
		REP(j,N)
		{
			WYN[i][j] = 0;
		}
	}
	
	REP(i,N)
	{
		REP(j,N)
		{
			WYN[i][j] = ( X[i][j] + Y[i][j] ) % p;
		}
	}
	
	return WYN;
}


LL ** mnoz(LL **X, LL **Y)
{
	LL ** WYN = new LL * [N];
	
	REP(i,N)
	{
		WYN[i] = new LL [N];
		
		REP(j,N)
		{
			WYN[i][j] = 0;
		}
	}
	
	REP(i,N)
	{
		REP(k,N)
		{
			REP(j,N)
			{
				WYN[i][j] = ( WYN[i][j] + ( X[i][k] * Y[k][j] ) ) % p;
			}
		}
	}
	
	return WYN;
}


LL ** poteguj(LL **X, LL k)
{
	LL ** WYN = new LL * [N];
	
	REP(i,N)
	{
		WYN[i] = new LL [N];
		
		REP(j,N)
		{
			WYN[i][j] = 0;
		}
		
		WYN[i][i] = 1;
	}
	
	while( k )
	{
		if( k & 1 )
		{
			WYN = mnoz( WYN, X );
		}
		
		X = mnoz( X, X );
		
		k >>= 1;
	}
	
	return WYN;
}


LL ** fun(LL **X, LL k)
{
	if( !k )
	{
		return I;
	}
	
	if( k & 1 )
	{
		return mnoz( dodaj( X, I ), fun( mnoz( X, X ), ( k - 1 ) / 2 ) );
	}
	
	return dodaj( poteguj( X, k ), mnoz( dodaj( X, I ), fun( mnoz( X, X ), ( k - 2 ) / 2 ) ) );
}


int main()
{
	scanf( "%lld %lld %lld", &N, &M, &K );
	
	init();
	
	REP(i,M)
	{
		scanf( "%lld %lld", &a, &b );
		
		--a;  --b;
		
		if( !A[a][b] )
		{
			++A[ a ][ b ];
		}
	}
	
	A = fun( A, K );
	
	printf( "%lld\n", A[ 1 - 1 ][ N - 1 ] );
	
	return 0;
}
