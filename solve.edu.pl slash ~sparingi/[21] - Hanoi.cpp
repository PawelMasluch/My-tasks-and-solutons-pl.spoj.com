#include<cstdio> // AC
#include<vector>
#include<algorithm>


using namespace std;


typedef pair < int, int > PII;

typedef vector < int > VI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back

#define C clear

#define E empty

#define MP make_pair

#define val first

#define ind second


/*

Def.  Akcja to dodanie kr��ka na szczyt wie�y lub zdj�cie kr��ka ze szczytu wie�y

Za�o�enie.  Przed wykonywaniem pierwszej akcji wie�a jest bez kr��k�w oraz nie b�dziemy usuwa� kr��ka ze szczytu wie�y, podczas gdy wie�a jest pusta

*/


const int MAX_N = 500000, MAX_R = 524288, MX = 30; // MAX_N - maksymalna liczba akcji wykonywanych na wie�y, MAX_R - maksymalna liczba li�ci w drzewie przedzia�owym 'DP', MX - maksymalna liczba wierzcho�k�w bazowych


VI krazek[MAX_N+1];

int n, R, rozm = 0, t[MAX_N], odp[MAX_N], DP[2*MAX_R], V[MX], M;


/*

n - liczba akcji wykonywanych na wie�y ( 1 <= n <= MAX_N = 500000 )

t - tablica akcji wykonywanych na wie�y (i zapyta� jednocze�nie) (po wykonaniu i-tej (i = 0,1,...n-1) akcji mamy odpowiedzie� na zapytanie, czyli ile widocznych od g�ry kr��k�w po wykonaniu i-tej akcji)

krazek[i][j] - numer akcji w tablicy 't', kt�ry reprezentuje pojawienie si� j-tego kr��ka wielko�ci 'i', w aktualnym stanie wie�y

odp[i] - odpowied� na zapytanie po wykonaniu i-tej akcji

DP - drzewo przedzia�owe typu max, zbudowane nad przeskalowanymi rozmiarami kr��k�w - w li�ciach s� maksymalne numery akcji, w kt�rych dok�ada�em kr��ek danej wielko�ci i ten kr��ek (reprezentowany przez numer akcji) nadal jest na wie�y

R - liczba li�ci drzewa przedzia�owego 'DP' (liczba 'R' jest zale�na od liczby akcji)

V - tablica, w kt�rym trzymam wierzcho�ki drzewa przedzia�owego, reprezentu�ce podzia� danego przedzia�u wielko�ci (przeskalowanych) kr��k�w na przedzia�y bazowe

rozm - liczba element�w w tablicy 'V'

M - maksymalna wielko�� kr��ka po przeskalowaniu

*/


void wczytaj() // wczytanie danych wej�ciowych
{
	scanf( "%d", &n ); // wczytanie liczby akcji
	
	
	// Wczytujemy kolejne akcje
	
	REP(i,0,n-1)
	{
		scanf( "%d", &t[i] );
	}
}


void przeskaluj() // przeskalowanie ci�gu 't'
{
	PII pom[n]; // struktura pomocnicza ( tj. tablica par postaci ( wielko�� kr��ka, numer akcji odpowiadaj�cy pierwszemu elementowi pary ) ) do przeskalowania ci�gu 't'
	
	REP(i,0,n-1)
	{
		pom[i] = MP( t[i], i );
	}
	
	sort( pom, pom + n );
	
	
	// Przydzielanie elementom ci�gu 't' nowych warto�ci
	
	M = ( pom[0].val == 0 ) ? 0 : 1 ; // je�li kiedykolwiek b�d� usuwa� kr��ek ze szczytu wie�y, to musimy zachowa� po przeskalowaniu, w ci�gu 't', warto�� zero (bo przyj��em, �e warto�� zero przed i po przeskalowaniu ma mie� to samo znaczenie, czyli usuni�cie kr��ka ze szczytu wie�y)
	
	t[ pom[0].ind ] = M;
	
	REP(i,1,n-1)
	{
		if( pom[i].val > pom[ i - 1 ].val )
		{
			++M;
		}
		
		t[ pom[i].ind ] = M;
	}
}


int f(int x)
{
	int wyn = 1;
	
	while( wyn < x )
	{
		wyn *= 2;
	}
	
	return wyn;
}


void inicjuj() // Inicjacja drzewa przedzia�owego 
{
	R = f( n + 1 ); // wyznaczenie liczby li�ci drzewa przedzia�owego 'DP'
	
	REP(i,1,2*R-1)
	{
		DP[i] = -1;
	}
}


int max(int a, int b)
{
	return ( a > b ) ? a : b ;
}


void ins(int v, int val)
{
	v += R;
	
	DP[v] = val;
	
	v /= 2;
	
	while( v > 0 )
	{
		DP[v] = max( DP[ 2 * v ], DP[ 2 * v + 1 ] );
		
		v /= 2;
	}
}


void bazowe(int v, int L, int R, int a, int b)
{
	if ( L == a  &&  R == b ) 
	{
		V[ rozm ] = v;
		
		++rozm;
		
		return;
	}

	int sr = ( a + b ) / 2;
	
	if ( R <= sr )
	{
		bazowe( 2 * v, L, R, a, sr );
	}
	else
	{
		if ( L > sr )
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


int query(int a)
{
	if( a > M ) // je�li mamy niepoprawny przedzia�
	{
		return -1;
	}
	
	bazowe( 1, a, M, 0, R - 1 );
	
	
	// Wyznaczenie wyniku
	
	int wyn = -1;
	
	REP(i,0,rozm-1)
	{
		wyn = max( wyn, DP[ V[i] ] );
	}
	
	rozm = 0;
	
	return wyn;
}


void obsluz()
{
	int ind, pierwszy_wiekszy;
	
	REP(i,0,n-1) // przegl�damy kolejne akcje (od najwcze�niejszej do najp�niejszej)
	{
		if( t[i] == 0 ) // usuni�cie kr��ka ze szczytu wie�y
		{
			ind = query( 1 ); // szukam najwi�kszego numeru akcji odpowiadaj�cego dodaniu jakiego� kr��ka do wie�y 
			
			krazek[ t[ ind ] ].pop_back(); // usuwam znaleziony kr��ek z wie�y
			
			
			// Aktualizuj� drzewo nieco wcze�niejszym (ale mo�liwie najwi�kszym, o ile istnieje) wyst�pieniem odpowiedniej wielko�ci kr��ka
			
			if( !krazek[ t[ ind ] ].E() )
			{
				ins( t[ ind ], krazek[ t[ ind ] ].back() );
			}
			else
			{
				ins( t[ ind ], -1 );
			}
			
			
			// Ustalam, jaka powinna by� odpowied� (b�dzie ona taka sama, jak odpowied� na taki numer akcji, kt�ry odpowiada najp�niejszemu dodaniu na wie�� jakiego� kr��ka, albo zero, gdy aktualnie wie�a jest pusta)
			
			ind = query( 1 );
			
			if( ind == -1 )
			{
				odp[i] = 0;
			}
			else
			{
				odp[i] = odp[ ind ];
			}
		}
		else // t[i] > 0, czyli dodajemy kr��ek na szczyt wie�y
		{
			
			// Ustalenie odpowiedzi (b�dzie ona taka, jak powi�kszona o jeden odpowied� na taki numer akcji, kt�ry odpowiada najp�niejszemu dodaniu na wie�� jakiego� kr��ka wi�kszego ni� aktualnie dodany, albo jeden, gdy aktualnie dodany kr��ek jest na wie�y najwi�kszy)
			
			pierwszy_wiekszy = query( t[i] + 1 );
			
			if( pierwszy_wiekszy == -1 )
			{
				odp[i] = 1;
			}
			else
			{
				odp[i] = odp[ pierwszy_wiekszy ] + 1;
			}
			
			krazek[ t[i] ].PB( i );
			
			ins( t[i], i );
		}
	}
}


void wypisz() // wypisywanie odpowiedzi na zapytania
{
	REP(i,0,n-1)
	{
		printf( "%d\n", odp[i] );
	}
}


int main()
{
	wczytaj();
	
	przeskaluj();
	
	inicjuj();
	
	obsluz();
	
	wypisz();
	
	return 0;
}
