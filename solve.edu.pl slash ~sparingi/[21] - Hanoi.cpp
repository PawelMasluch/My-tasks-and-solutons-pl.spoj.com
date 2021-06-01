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

Def.  Akcja to dodanie kr¹¿ka na szczyt wie¿y lub zdjêcie kr¹¿ka ze szczytu wie¿y

Za³o¿enie.  Przed wykonywaniem pierwszej akcji wie¿a jest bez kr¹¿ków oraz nie bêdziemy usuwaæ kr¹¿ka ze szczytu wie¿y, podczas gdy wie¿a jest pusta

*/


const int MAX_N = 500000, MAX_R = 524288, MX = 30; // MAX_N - maksymalna liczba akcji wykonywanych na wie¿y, MAX_R - maksymalna liczba liœci w drzewie przedzia³owym 'DP', MX - maksymalna liczba wierzcho³ków bazowych


VI krazek[MAX_N+1];

int n, R, rozm = 0, t[MAX_N], odp[MAX_N], DP[2*MAX_R], V[MX], M;


/*

n - liczba akcji wykonywanych na wie¿y ( 1 <= n <= MAX_N = 500000 )

t - tablica akcji wykonywanych na wie¿y (i zapytañ jednoczeœnie) (po wykonaniu i-tej (i = 0,1,...n-1) akcji mamy odpowiedzieæ na zapytanie, czyli ile widocznych od góry kr¹¿ków po wykonaniu i-tej akcji)

krazek[i][j] - numer akcji w tablicy 't', który reprezentuje pojawienie siê j-tego kr¹¿ka wielkoœci 'i', w aktualnym stanie wie¿y

odp[i] - odpowiedŸ na zapytanie po wykonaniu i-tej akcji

DP - drzewo przedzia³owe typu max, zbudowane nad przeskalowanymi rozmiarami kr¹¿ków - w liœciach s¹ maksymalne numery akcji, w których dok³ada³em kr¹¿ek danej wielkoœci i ten kr¹¿ek (reprezentowany przez numer akcji) nadal jest na wie¿y

R - liczba liœci drzewa przedzia³owego 'DP' (liczba 'R' jest zale¿na od liczby akcji)

V - tablica, w którym trzymam wierzcho³ki drzewa przedzia³owego, reprezentu¹ce podzia³ danego przedzia³u wielkoœci (przeskalowanych) kr¹¿ków na przedzia³y bazowe

rozm - liczba elementów w tablicy 'V'

M - maksymalna wielkoœæ kr¹¿ka po przeskalowaniu

*/


void wczytaj() // wczytanie danych wejœciowych
{
	scanf( "%d", &n ); // wczytanie liczby akcji
	
	
	// Wczytujemy kolejne akcje
	
	REP(i,0,n-1)
	{
		scanf( "%d", &t[i] );
	}
}


void przeskaluj() // przeskalowanie ci¹gu 't'
{
	PII pom[n]; // struktura pomocnicza ( tj. tablica par postaci ( wielkoœæ kr¹¿ka, numer akcji odpowiadaj¹cy pierwszemu elementowi pary ) ) do przeskalowania ci¹gu 't'
	
	REP(i,0,n-1)
	{
		pom[i] = MP( t[i], i );
	}
	
	sort( pom, pom + n );
	
	
	// Przydzielanie elementom ci¹gu 't' nowych wartoœci
	
	M = ( pom[0].val == 0 ) ? 0 : 1 ; // jeœli kiedykolwiek bêdê usuwa³ kr¹¿ek ze szczytu wie¿y, to musimy zachowaæ po przeskalowaniu, w ci¹gu 't', wartoœæ zero (bo przyj¹³em, ¿e wartoœæ zero przed i po przeskalowaniu ma mieæ to samo znaczenie, czyli usuniêcie kr¹¿ka ze szczytu wie¿y)
	
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


void inicjuj() // Inicjacja drzewa przedzia³owego 
{
	R = f( n + 1 ); // wyznaczenie liczby liœci drzewa przedzia³owego 'DP'
	
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
	if( a > M ) // jeœli mamy niepoprawny przedzia³
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
	
	REP(i,0,n-1) // przegl¹damy kolejne akcje (od najwczeœniejszej do najpóŸniejszej)
	{
		if( t[i] == 0 ) // usuniêcie kr¹¿ka ze szczytu wie¿y
		{
			ind = query( 1 ); // szukam najwiêkszego numeru akcji odpowiadaj¹cego dodaniu jakiegoœ kr¹¿ka do wie¿y 
			
			krazek[ t[ ind ] ].pop_back(); // usuwam znaleziony kr¹¿ek z wie¿y
			
			
			// Aktualizujê drzewo nieco wczeœniejszym (ale mo¿liwie najwiêkszym, o ile istnieje) wyst¹pieniem odpowiedniej wielkoœci kr¹¿ka
			
			if( !krazek[ t[ ind ] ].E() )
			{
				ins( t[ ind ], krazek[ t[ ind ] ].back() );
			}
			else
			{
				ins( t[ ind ], -1 );
			}
			
			
			// Ustalam, jaka powinna byæ odpowiedŸ (bêdzie ona taka sama, jak odpowiedŸ na taki numer akcji, który odpowiada najpóŸniejszemu dodaniu na wie¿ê jakiegoœ kr¹¿ka, albo zero, gdy aktualnie wie¿a jest pusta)
			
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
		else // t[i] > 0, czyli dodajemy kr¹¿ek na szczyt wie¿y
		{
			
			// Ustalenie odpowiedzi (bêdzie ona taka, jak powiêkszona o jeden odpowiedŸ na taki numer akcji, który odpowiada najpóŸniejszemu dodaniu na wie¿ê jakiegoœ kr¹¿ka wiêkszego ni¿ aktualnie dodany, albo jeden, gdy aktualnie dodany kr¹¿ek jest na wie¿y najwiêkszy)
			
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
