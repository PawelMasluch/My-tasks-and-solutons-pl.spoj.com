/*

W tym programie, dla s³owa s[0..n-1] odpowiadam w kolejnych zapytaniach o to, które jego pods³owo jest mniejsze leksykograficznie : pierwsze (o krañcach l1, r1), czy drugie (o krañcach l2, r2) (byæ mo¿e oba pods³owa s¹ sobie równe) 

Do rozwi¹zania tego zadania u¿ywam algorytmu KMR, dzia³aj¹cego w czasie O(n log n)

Na ka¿de zapytanie odpowiadam w czasie O(log log n)

Z³o¿onoœæ czasowa rozwi¹zania to O(n log n + q log log n), pamiêciowa - O(n log n)

Uwaga. Krañce pods³ów z zapytañ dotycz¹ s³owa "s", ale indeksowanego od jedynki

Uwaga. Zak³adam, ¿e alfabet, nad którym wykonujê ten algorytm, ma rozmiar O(1) 
       (ma to znaczenie przy szacowaniu z³o¿onoœci sortowania pozycyjnego)

*/


#include<iostream> // 53/100 pkt (przekroczono limit pamieci)
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<new>


using namespace std;


typedef pair < int, int > PII;

typedef pair < PII, int > PIII;

typedef vector < PII > VPII;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back

#define S size

#define C clear

#define MP make_pair

#define ST first

#define ND second



/*

Oznaczenia zmiennych globalnych:

s - s³owo wejœciowe

T - tablica par, której u¿ywam do wyznaczania identyfikatorów dla pods³ów o d³ugoœci 2^0 = 1

MAX_N - maksymalna d³ugoœæ s³owa "s"

MAX_EXP - wyk³adnik (ca³kowity nieujemny) maksymalnej potêgi dwójki, nieprzekraczaj¹cej maksymalnej mo¿liwej 
          d³ugoœci s³owa "s" (czyli MAX_N)

n - d³ugoœæ s³owa "s"

EXP - wyk³adnik (ca³kowity nieujemny) maksymalnej potêgi dwójki, nieprzekraczaj¹cej d³ugoœci s³owa "s"

pot2 - tablica kolejnych potêg dwójki (o wyk³adniku ca³kowitym nieujemnym)

ID - tablica identyfikatorów

q - liczba zapytañ

l1, r1 - odpowiednio, pocz¹tek i koniec, pierwszego pods³owa z pojedyñczego zapytania

l2, r2 - odpowiednio, pocz¹tek i koniec, drugiego pods³owa z pojedyñczego zapytania

*/

const int MAX_N = 300000, MAX_EXP = 18;


VPII *G, *POM;

string s;

PII T[MAX_N];

int q, n, EXP, pot2[MAX_EXP+1], ID[MAX_EXP+1][MAX_N];


void preprocessing()
{
	// Spamiêtanie potêg dwójki (o ca³kowitym i nieujemnym wyk³adniku)
	
	pot2[0] = 1;
	
	REP(i,1,MAX_EXP)
	{
		pot2[i] = pot2[ i - 1 ] * 2;
	}

	
	// Inicjowanie tablicy identyfikatorów
	
	REP(i,0,MAX_EXP)
	{
		REP(j,0,MAX_N-1)
		{
			ID[i][j] = -1; // nie istnieje (w pierwszym przybli¿eniu) identyfikator dla pods³owa s³owa "s" d³ugoœci "2^i", koñcz¹cego siê na pozycji "j"
		}
	}
	
	
	// Inicjowanie struktur danych do sortowania pozycyjnego
	
	G = new VPII [MAX_N]; // tablica wektorów, któr¹ indeksujemy wartoœciami ID1 (w ka¿dym wektorze s¹, dla ustalonego ID1, pary postaci (ID2,kon) )
	
	POM = new VPII [MAX_N]; // tablica wektorów, któr¹ indeksujemy wartoœciami ID2 (w ka¿dym wektorze s¹, dla ustalonego ID1, pary postaci (ID1,kon) )

}


int bin(int x) // szukam najwiêkszego takiego "sr", ¿e 2^sr <= x
{
	int pocz = 0, kon = MAX_EXP, wyn, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( pot2[ sr ] <= x )
		{
			wyn = sr;
			
			pocz = sr + 1;
		}
		else
		{
			kon = sr - 1;
		}
	}
	
	return wyn;
}


void wczytaj_dane() // wczytanie danych + obliczenie niektórych parametrów globalnych
{
	cin >> n >> q >> s;
	
	EXP = bin( n );
}


// Teraz czêœæ kodu odpowiedzialna za sortowanie pozycyjne


void fun(VPII *AA, VPII *BB)
{
	int tmp, kon, r;
	
	REP(i,0,n-1)
	{
		r = AA[i].S(); // iloœæ elementów i-tego wektora struktury A
		
		REP(j,0,r-1)
		{
			tmp = AA[i][j].ST; // wartoœæ j-tego identyfikatora w i-tym wektorze struktury A
			
			kon = AA[i][j].ND;
			
			BB[ tmp ].PB( MP( i, kon ) );
		}
		
		AA[i].C();
	}
}


void sortowanie_pozycyjne()
{
	fun( G, POM );
	
	fun( POM, G );
}


// Teraz algorytm KMR


void KMR_1_faza()
{
	int id = 0;
	
	REP(i,0,n-1)
	{
		T[i] = MP( s[i] - 'a', i );
	}
	
	sort( T, T + n );
	
	ID[0][ T[0].ND ] = id;
	
	REP(i,1,n-1)
	{
		if( T[ i - 1 ].ST < T[i].ST )
		{
			++id;
		}
		
		ID[0][ T[i].ND ] = id;
	}
}


// Wype³niam strukturê "G" (dla pods³ów s³owa "s", d³ugoœci "2^exp")

void wypelnij(int exp)
{
	int pocz, kon, sr, ID1, ID2, min_kon = pot2[ exp ] - 1; // min_kon - minimalny indeks koñca pods³owa s³owa "s", d³ugoœci "2^exp"
		
	REP(i,min_kon,n-1)
	{
		// Ustalenie krañców rozwa¿anego pods³owa oraz jego œrodka (tj. indeksu ostatniej litery w pierwszej po³ówki rozwa¿anego aktualnie pods³owa)
		
		kon = i; // kon - indeks koñca aktualnego pods³owa 
		
		pocz = kon - min_kon; // pocz - indeks pocz¹tku aktualnego pods³owa
		
		sr = ( pocz + kon ) / 2; // indeks œrodka aktualnego pods³owa
		
		
		// Wyznaczenie identyfiktorów pierwszej oraz drugiej po³ówki aktualnie rozwa¿anego pods³owa 
		
		ID1 = ID[ exp - 1 ][ sr ]; // ID1 - identyfikator dla pierwszej po³owy aktualnego pods³owa
		
		ID2 = ID[ exp - 1 ][ kon ]; // ID2 - identyfikator dla drugiej po³owy aktualnego pods³owa
		
		
		// Wstawienie do struktury "G" danych na temat aktualnego pods³owa s³owa "s", d³ugoœci "2^exp"
		
		G[ ID1 ].PB( MP( ID2, kon ) );
	}
}


// Aktualizujê tablicê "ID" (odpowiedni wiersz) elementami ze stuktury "G"

void aktualizuj(int exp) // "exp" - oznacza, ¿e przydzielamy identyfikatory dla pods³ów s³owa "s", d³ugoœci "2^exp"
{
	int r, id = 0;
	
	REP(i,0,n-1)
	{
		r = G[i].S();
		
		if( r > 0 )
		{
			ID[ exp ][ G[i][0].ND ] = id;
			
			REP(j,1,r-1)
			{
				if( G[i][ j - 1 ].ST < G[i][j].ST ) // jeœli aktualne pods³owo jest ró¿ne od poprzedniego
				{
					++id; // to z faktu, i¿ identyfikatory dla pods³ów s³owa "s" (d³ugoœci "2^exp") by³y posortowane rosn¹co wiemy, ¿e aktualnie rozwa¿ane pods³owo jest kolejnym w porz¹dku leksykograficznym (w ramach pods³ów s³owa "s", d³ugoœci "2^exp") 
				}
				
				ID[ exp ][ G[i][j].ND ] = id;
			}
			
			++id;
		}
		
		G[i].C();
	}
}


void KMR_2_faza()
{
	REP(exp,1,EXP) // dla wyk³adnika exp = 1,2,...,EXP (rozwa¿am pods³owa s³owa "s", d³ugoœci "2^exp")
	{
		wypelnij( exp );
		
		sortowanie_pozycyjne(); // sortujemy informacje o wszystkich pods³owach s³owa "s", d³ugoœci "2^exp"
		
		aktualizuj( exp );
	}
}


void KMR() // tworzenie s³ownika pods³ów bazowych dla s³owa "s"
{
	// 1. faza - pods³owa d³ugoœci 2^0 = 1
	
	KMR_1_faza();
	
	
	// 2. faza - pods³owa d³ugoœci 2^exp (exp = 1,2,...,EXP)
	
	KMR_2_faza();
}


void zapytanie(int l1, int r1, int l2, int r2)
{
	PII P1, P2; // P1, P2 - pary identyfikatorów dla, odpowiednio, pierwszego oraz drugiego pods³owa
	
	int dl1 = r1 - l1 + 1, dl2 = r2 - l2 + 1, dl = min( dl1, dl2 ), exp;
	
	exp = bin( dl );
	
	P1 = MP( ID[ exp ][ l1 + pot2[ exp ] - 1 ], ID[ exp ][ l1 + dl - 1 ] );
	
	P2 = MP( ID[ exp ][ l2 + pot2[ exp ] - 1 ], ID[ exp ][ l2 + dl - 1 ] );
	
	if( P1 < P2 )
	{
		cout << "<\n";
		
		return;
	}
	
	if( P1 > P2 )
	{
		cout << ">\n";
		
		return;
	}
	
	if( dl1 < dl2 )
	{
		cout << "<\n";
		
		return;
	}
	
	if( dl1 > dl2 )
	{
		cout << ">\n";
		
		return;
	}
	
	cout << "=\n";
}


void obsluz_zapytania()
{
	int l1, r1, l2, r2;
	
	while( q )
	{
		cin >> l1 >> r1 >> l2 >> r2;
		
		--l1;  --r1;  --l2;  --r2;
		
		zapytanie( l1, r1, l2, r2 ); // jeœli pierwsze pods³owo jest mniejsze, to wynikiem jest 1; jeœli drugie pods³owo jest mniejsze, to wynikiem jest 2; jeœli pods³owa s¹ sobie równe, wynikiem jest 0
		
		--q;
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	preprocessing();
	
	wczytaj_dane();
	
	KMR();
	
	obsluz_zapytania();
	
	return 0;
}
