#include<cstdio> // 100 pkt
#include<new>


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)


void wczytaj(LL *A, LL N)
{
	REP(i,0,N-1)
	{
		scanf("%lld", &A[i]);
	}
}


void wypisz(LL *A, LL N)
{
	REP(i,0,N-1)
	{
		printf("%lld ", A[i]);
	}
	
	printf("\n");
}


LL r(LL a, LL p)
{
	return ( a + p ) % p;
}


void inicjuj(LL *a, LL N, LL val) // wszystkie elementy ci¹gu "a" ustawione na "val"
{
	REP(i,0,N-1)
	{
		a[i] = val;
	}
}


void ustaw(LL *V, LL N, LL D) // ustawienie pierwszego wiersza reprezentuj¹cego macierz przekszta³cenia ci¹gu
{
	inicjuj( V, N, 0 );
	
	REP(i,0-D,0+D)
	{
		V[ r( i, N ) ] = 1;
	}
}


void nadpisz(LL *a, LL N, LL *b) // pod wektor "b" nadpisujê to, co w wektorze "a"
{
	REP(i,0,N-1)
	{
		b[i] = a[i];
	}
}


void mnoz(LL *a, LL *b, LL N, LL P, LL *pom) // reprezentant macierzy * wektor
{
	inicjuj( pom, N, 0 );
	
	REP(i,0,N-1)
	{
		REP(j,0,N-1)
		{
			pom[i] = ( pom[i] + ( ( a[j] * b[ r( j + i, N ) ] ) % P ) ) % P; // "przesuwam" tylko wektor 	
		}
	}
	
	nadpisz( pom, N, b ); // nadpisujê pod wektor
}


void poteguj(LL *V, LL N, LL K, LL P, LL *wyn, LL *pom) // dany wektor "V", ale do niego wpiszê wynik
{
	inicjuj( wyn, N, 0 );
	
	wyn[0] = 1;
	
	while( K )
	{
		if( K & 1 )
		{
			mnoz( V, wyn, N, P, pom ); // wynik wpisany do "wyn"
		}
		
		mnoz( V, V, N, P, pom ); // wynik wpisany do "V"
		
		K >>= 1;
	}
	
	nadpisz( wyn, N, V );
}


int main()
{
	LL N, P, D, K, *A, *V, *wyn, *pom;
	
	scanf("%lld%lld%lld%lld", &N, &P, &D, &K);
	
	A = new LL [N];
	
	V = new LL [N];
	
	wyn = new LL [N];
	
	pom = new LL [N];
	
	wczytaj( A, N );
	
	ustaw( V, N, D ); // pierwszy wiersz macierzy przekszta³cenia ci¹gu
	
	poteguj( V, N, K, P, wyn, pom ); // wynik wpisany do "V"
	
	mnoz( V, A, N, P, pom ); // wynik wpisany do "A"
	
	wypisz( A, N );
	
	return 0;
}
