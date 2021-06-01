#include<cstdio> // 100 pkt
#include<new>


using namespace std;


typedef long long LL;


#define REP(i,n) for(LL i=0; i<n; ++i)


const LL p = 1000000000, MAX_K = 50;


LL **A, **wyn, **pom, *b, *c, q, k = MAX_K, n;


LL min(LL a, LL b)
{
	return (a<b) ? a : b ;
}


LL max(LL a, LL b)
{
	return (a>b) ? a : b ;
}


void nadpisz(LL **AA, LL **BB)
{
	REP(i,k)
	{
		REP(j,k)
		{
			AA[i][j] = BB[i][j];
		}
	}
}


void nadpisz(LL *aa, LL *bb)
{
	REP(i,k)
	{
		aa[i] = bb[i];
	}
}


void wyzeruj(LL **AA)
{
	REP(i,k)
	{
		REP(j,k)
		{
			AA[i][j] = 0;
		}
	}	
}


void wyzeruj(LL *aa)
{
	REP(i,k)
	{
		aa[i] = 0;
	}	
}


void jednostkowa(LL **AA)
{
	REP(i,k)
	{
		AA[i][i] = 1;
	}
}


void inicjuj()
{
	b = new LL [MAX_K];
	
	c = new LL [MAX_K];
	
	A = new LL *[MAX_K];
	
	wyn = new LL *[MAX_K];
	
	pom = new LL *[MAX_K];
	
	REP(i,MAX_K)
	{
		A[i] = new LL [MAX_K];
		
		wyn[i] = new LL [MAX_K];
		
		pom[i] = new LL [MAX_K];
	}
	
	wyzeruj( c );
	
	wyzeruj( A );
	
	wyzeruj( wyn );
	
	wyzeruj( pom );
}


void mnozenie_macierzy(LL **AA, LL **BB)
{
	REP(i,k)
	{
		REP(l,k)
		{
			REP(j,k)
			{
				if( l & 7 == 7 )
				{
					pom[i][j] %= p;
				}
				
				pom[i][j] += AA[i][l] * BB[l][j];
			}
		}
	}
	
	REP(i,k)
	{
		REP(j,k)
		{
			pom[i][j] %= p;
		}
	}
	
	nadpisz( AA, pom );
	
	wyzeruj( pom );
}


void potega_macierzy(LL **AA, LL x)
{
	jednostkowa( wyn );
	
	while( x )
	{
		if( x & 1 )
		{
			mnozenie_macierzy( wyn, AA );
		}
		
		x /= 2;
		
		mnozenie_macierzy( AA, AA );
	}
	
	nadpisz( AA, wyn );
	
	wyzeruj( wyn );
}


void macierz_razy_wektor(LL **AA, LL *bb)
{
	REP(i,k)
	{
		REP(j,k)
		{
			c[i] = ( c[i] + ( ( AA[i][j] * bb[j] ) % p ) ) % p;
		}
	}
	
	nadpisz( bb, c );
	
	wyzeruj( c );
}


int main()
{
	inicjuj();
	
	scanf( "%lld", &q );
	
	while( q )
	{
		scanf( "%lld", &k );
		
		REP(i,k)
		{
			scanf( "%lld", &b[i] );
		}
		
		REP(i,k-1)
		{
			A[i][ i + 1 ] = 1;
		}
		
		REP(i,k) // wsp?czynniki r?wnania rekurencyjnego, zapisane od razu w macierzy
		{
			scanf( "%lld", &A[ k - 1 ][ k - 1 - i ] );
		}
		
		scanf( "%lld", &n );
		
		potega_macierzy( A, max( 0, n - k ) );
		
		macierz_razy_wektor( A, b );
		
		printf( "%lld\n", b[ min( n, k ) - 1 ] );
		
		wyzeruj( A );
		
		--q;
	}
	
	return 0;
}
