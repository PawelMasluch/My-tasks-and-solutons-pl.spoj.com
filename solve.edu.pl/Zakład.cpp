/*

W tym zadaniu sprawdzam pierwszość dodatnich liczb całkowitych (dla liczby 1 oraz liczb parzystych odpowiadam ręcznie, dla reszty stosuję test Millera-Rabina)

    Algorytm testu Millera-Rabina (dla ustalonej nieparzystej liczby N > 1):

 - znajduję takie s,d, że  N - 1 = 2^s * d
 
 - dla każdego testu (jest ich łącznie K):
 
    - losuję wartość 1 <= a <= N - 1
    
    - jeśli a^d != 1 (mod N) oraz a^( 2^r * d ) != -1 (mod N) (dla r = 0,1,...,s-1), to N - złożona
    
 - jeśli żaden test nie wykazał złożoności liczby N, to mówimy, że N - prawdopodobnie pierwsza

*/

#include<stdio.h> // 100 pkt
#include<stdlib.h>
#include<time.h>


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)


LL mnoz(LL a, LL b, LL p)
{
	LL wyn = 0;
	
	while( b )
	{
		if( b & 1 )
		{
			wyn = ( wyn + a ) % p;
		}
		
		b >>= 1;
		
		a = ( a << 1 ) % p;
	}
	
	return wyn;
}


LL fpm(LL a, LL b, LL p)
{
	LL wyn = 1;
	
	while( b )
	{
		if( b & 1 )
		{
			wyn = mnoz( wyn, a, p );
		}
		
		b >>= 1;
		
		a = mnoz( a, a, p );
	}
	
	return wyn;
}


bool Miller_Rabin_Test(LL N) // N > 1 oraz N - nieparzyste
{
	bool flaga = true; // ta zmienna informuje, czy udało się w jakimś teście wykazać złożoność liczby N
	
	LL d = N - 1, s = 0, tmp, K = 100, a; // K - liczba testów liczby N
	
	while( !( d & 1 ) )
	{
		d >>= 1;
		
		++s;
	}
	
	REP(i,1,K)
	{
		a = ( (LL)rand() % ( N - 1 ) ) + 1;
		
		tmp = fpm( a, d, N ); // tmp = (a^d) mod N
		
		if( tmp == 1 )
		{
			flaga = false; // w tym teście nie udało się wykazać złożoności liczby N
		}
		
		REP(j,0,s-1)
		{
			// teraz tmp = a^( 2^j * d )
			
			if( tmp == N - 1 )
			{
				flaga = false; // w tym teście nie udało się wykazać złożoności liczby N
			}
			
			tmp = mnoz( tmp, tmp, N );
		}
		
		if( flaga ) // jeśli aktualny test wykazał złożoność liczby N
		{
			return false; // liczba N - złożona
		}
		
		flaga = true; // jeśli jeszcze muszę wykonywać testy, to ustawiam z powrotem zmienną "flaga" na wartość "true"
	}
	
	return true; // liczba N - prawdopodobnie pierwsza
}


bool czy_pierwsza(LL N)
{
	if( N == 1 )
	{
		return false;
	}
	
	if( !( N & 1 ) )
	{
		if( N > 2 )
		{
			return false;
		}
		
		return true;
	}
	
	return Miller_Rabin_Test( N );
}


void f(LL N)
{
	if( czy_pierwsza( N ) )
	{
		printf( "TAK\n" );
	}
	else
	{
		printf( "NIE\n" );
	}
}


int main()
{
	srand( 599 );
	
	LL Q, N;
	
	scanf( "%lld", &Q );
	
	REP(i,1,Q)
	{
		scanf( "%lld", &N );
		
		f( N );
	}
	
	return 0;
}
