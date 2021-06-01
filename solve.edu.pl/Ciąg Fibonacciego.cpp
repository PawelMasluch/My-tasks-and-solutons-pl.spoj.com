#include<cstdio> // 100 pkt
#include<new>


using namespace std;


typedef long long LL;


#define REP(i,n) for(LL i=0; i<n; ++i)


const LL p = 1e9 + 7;


LL **A, **W, **POM, N;


void init()
{
	A = new LL * [2];
	
	W = new LL * [2];
	
	POM = new LL * [2];
	
	REP(i,2)
	{
		A[i] = new LL [2];
		
		W[i] = new LL [2];
		
		POM[i] = new LL [2];
	}
}


void ustaw(LL **AA, LL val)
{
	REP(i,2)
	{
		REP(j,2)
		{
			AA[i][j] = val;
		}
	}
}


void jednostkowa(LL **AA)
{
	ustaw( AA, 0 );
	
	REP(i,2)
	{
		AA[i][i] = 1;
	}
}


void init2(LL **AA)
{
	ustaw( AA, 1 );
	
	AA[0][0] = 0;	
}


void przepisz(LL **AA, LL **BB)
{
	REP(i,2)
	{
		REP(j,2)
		{
			BB[i][j] = AA[i][j];
		}
	}
}


void mnoz(LL **AA, LL **BB)
{
	ustaw( POM, 0 );
	
	REP(i,2)
	{
		REP(k,2)
		{
			REP(j,2)
			{
				POM[i][j] = ( POM[i][j] + ( AA[i][k] * BB[k][j] ) ) % p;
			}
		}
	}
	
	przepisz( POM, AA );
}


void poteguj(LL **AA, LL NN)
{
	jednostkowa( W );
	
	init2( AA );
	
	while( NN )
	{
		if( NN & 1 )
		{
			mnoz( W, AA );
		}
		
		NN >>= 1;
		
		mnoz( AA, AA );
	}
	
	przepisz( W, AA );
}


LL f()
{
	poteguj( A, N + 3 );
	
	return ( A[0][1] + p - 1 ) % p;
}


int main()
{
	init();
	
	scanf( "%lld", &N );
	
	printf( "%lld\n", f() );
	
	return 0;
}
