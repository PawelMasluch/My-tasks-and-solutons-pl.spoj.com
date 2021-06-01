#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)


const int N = 10000, R = 16384, MX = 20;


int q, DP[2*R], V[MX], r = 0;


void wstaw(int x)
{
	int v = R + x;
	
	while( v > 0 )
	{
		++DP[v];
		
		v /= 2;
	}
}


void bazowe(int v, int L, int R, int a, int b)
{
	if( L == a  &&  R == b )
	{
		V[ r ] = v;
		
		++r;
		
		return;
	}
	
	int sr = ( a + b ) / 2;
	
	if( R <= sr )
	{
		bazowe( 2 * v, L, R, a, sr );
	}
	else
	{
		if( L > sr )
		{
			bazowe( 2 * v + 1, L, R, sr + 1, b );
		}
		else
		{
			bazowe( 2 * v, L, sr, a, sr );
			
			bazowe( 2 * v + 1, sr + 1, R, sr + 1, b );
		}
	}
}


int ile(int x)
{
	bazowe( 1, 1, x, 0, R - 1 );
	
	int wyn = 0;
	
	REP(i,0,r-1)
	{
		wyn += DP[ V[i] ];
	}
	
	r = 0;
	
	return wyn;
}


int query(int k)
{
	int pocz = 1, kon = N, wyn, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( ile( sr ) >= k )
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


void obsluz()
{
	scanf( "%d", &q );
	
	int rodzaj, cena, ktore = 1;
	
	while( q )
	{
		scanf( "%d", &rodzaj );
		
		if( rodzaj == 1 )
		{
			scanf( "%d", &cena );
			
			wstaw( cena );
		}
		else // rodzaj == 0
		{
			printf( "%d\n", query( ktore ) );
			
			++ktore;
		}
		
		--q;
	}
}


int main()
{
	obsluz();
	
	return 0;
}
