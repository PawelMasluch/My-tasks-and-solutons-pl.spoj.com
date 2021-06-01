#include<cstdio> // 100 pkt
#include<map> // UWAGA. jesli chcialbym sam sie pobawic z testowaniem, to musze uwazac, zeby suma_wartosci_k <= suma_wartosci_m - n (albo moge przerobic program)
// Dla stosu wysokosci 'x' (x>=1) wykonamy 'x-1' ruchow

using namespace std;


typedef long long LL;

typedef map < LL, LL > MLL;


MLL M;

MLL::iterator it;

LL n, z, wyn = 0, S = 0, ile = 0, val, best;


void wczytaj()
{
	scanf( "%lld", &n );
	
	LL m;
	
	while( n )
	{
		scanf( "%lld", &m );
		
		if( !M.count( m ) )
		{
			++wyn;
		}
		
		++M[m];
		
		--n;
	}
}


void g(LL x, LL ile_dodac)
{
	if( !M.count( x ) )
	{
		++wyn;
	}
	
	M[x] += ile_dodac;
}


void f(LL x, LL ile_dodac)
{
	g( x / 2, ile_dodac );
	
	g( ( x + 1 ) / 2, ile_dodac );
}


void oblicz(LL x)
{
	S += x;
	
	while( ile < S )
	{
		it = M.end();    --it;
		
		best = it -> first;
		
		val = it -> second;
		
		if( ile + val <= S )
		{
			f( best, val );
			
			M.erase( it );
			
			--wyn;
			
			ile += val;
		}
		else // ile + val > S
		{
			f( best, S - ile );
			
			it -> second -= ( S - ile ); // ew. M[ best ] -= (S - ile);   zauwazmy, ze M[ best ] = it -> second = val
			
			ile += ( S - ile );
		}
	}
}


void wypisz()
{
	printf( "%lld\n", wyn );
}


void obsluz_zapytania()
{
	scanf( "%lld", &z );
	
	LL k;
	
	while( z )
	{
		scanf( "%lld", &k );
		
		oblicz( k );
		
		wypisz();
		
		--z;
	}
}


void solve()
{
	wczytaj();
	
	obsluz_zapytania();
}


int main()
{
	solve();
	
	return 0;
}
