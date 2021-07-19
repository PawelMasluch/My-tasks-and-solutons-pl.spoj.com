/*

W tym programie, dla słowa s[0..n-1] odpowiadam w kolejnych zapytaniach o to, które jego podsłowo jest mniejsze leksykograficznie : pierwsze (o krańcach l1, r1), czy drugie (o krańcach l2, r2) (być może oba podsłowa są sobie równe) 

Do rozwiązania tego zadania używam algorytmu KMR, działającego w czasie O(n log n)

Na każde zapytanie odpowiadam w czasie O(log log n)

Złożoność czasowa rozwiązania to O(n log n + q log log n), pamięciowa - O(n log n)

Uwaga. Krańce podsłów z zapytań dotyczą słowa "s", ale indeksowanego od jedynki

Uwaga. Zakładam, że alfabet, nad którym wykonuję ten algorytm, ma rozmiar O(1) 
       (ma to znaczenie przy szacowaniu złożoności sortowania pozycyjnego)

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

s - słowo wejściowe

T - tablica par, której używam do wyznaczania identyfikatorów dla podsłów o długości 2^0 = 1

MAX_N - maksymalna długość słowa "s"

MAX_EXP - wykładnik (całkowity nieujemny) maksymalnej potęgi dwójki, nieprzekraczającej maksymalnej możliwej 
          długości słowa "s" (czyli MAX_N)

n - długość słowa "s"

EXP - wykładnik (całkowity nieujemny) maksymalnej potęgi dwójki, nieprzekraczającej długości słowa "s"

pot2 - tablica kolejnych potęg dwójki (o wykładniku całkowitym nieujemnym)

ID - tablica identyfikatorów

q - liczba zapytań

l1, r1 - odpowiednio, początek i koniec, pierwszego podsłowa z pojedyńczego zapytania

l2, r2 - odpowiednio, początek i koniec, drugiego podsłowa z pojedyńczego zapytania

*/

const int MAX_N = 300000, MAX_EXP = 18;


VPII *G, *POM;

string s;

PII T[MAX_N];

int q, n, EXP, pot2[MAX_EXP+1], ID[MAX_EXP+1][MAX_N];


void preprocessing()
{
	// Spamiętanie potęg dwójki (o całkowitym i nieujemnym wykładniku)
	
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
			ID[i][j] = -1; // nie istnieje (w pierwszym przybliżeniu) identyfikator dla podsłowa słowa "s" długości "2^i", kończącego się na pozycji "j"
		}
	}
	
	
	// Inicjowanie struktur danych do sortowania pozycyjnego
	
	G = new VPII [MAX_N]; // tablica wektorów, którą indeksujemy wartościami ID1 (w każdym wektorze są, dla ustalonego ID1, pary postaci (ID2,kon) )
	
	POM = new VPII [MAX_N]; // tablica wektorów, którą indeksujemy wartościami ID2 (w każdym wektorze są, dla ustalonego ID1, pary postaci (ID1,kon) )

}


int bin(int x) // szukam największego takiego "sr", że 2^sr <= x
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


// Teraz część kodu odpowiedzialna za sortowanie pozycyjne


void fun(VPII *AA, VPII *BB)
{
	int tmp, kon, r;
	
	REP(i,0,n-1)
	{
		r = AA[i].S(); // ilość elementów i-tego wektora struktury A
		
		REP(j,0,r-1)
		{
			tmp = AA[i][j].ST; // wartość j-tego identyfikatora w i-tym wektorze struktury A
			
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


// Wypełniam strukturę "G" (dla podsłów słowa "s", długości "2^exp")

void wypelnij(int exp)
{
	int pocz, kon, sr, ID1, ID2, min_kon = pot2[ exp ] - 1; // min_kon - minimalny indeks końca podsłowa słowa "s", długości "2^exp"
		
	REP(i,min_kon,n-1)
	{
		// Ustalenie krańców rozważanego podsłowa oraz jego środka (tj. indeksu ostatniej litery w pierwszej połówki rozważanego aktualnie podsłowa)
		
		kon = i; // kon - indeks końca aktualnego podsłowa 
		
		pocz = kon - min_kon; // pocz - indeks początku aktualnego podsłowa
		
		sr = ( pocz + kon ) / 2; // indeks środka aktualnego podsłowa
		
		
		// Wyznaczenie identyfiktorów pierwszej oraz drugiej połówki aktualnie rozważanego podsłowa 
		
		ID1 = ID[ exp - 1 ][ sr ]; // ID1 - identyfikator dla pierwszej połowy aktualnego podsłowa
		
		ID2 = ID[ exp - 1 ][ kon ]; // ID2 - identyfikator dla drugiej połowy aktualnego podsłowa
		
		
		// Wstawienie do struktury "G" danych na temat aktualnego podsłowa słowa "s", długości "2^exp"
		
		G[ ID1 ].PB( MP( ID2, kon ) );
	}
}


// Aktualizuję tablicę "ID" (odpowiedni wiersz) elementami ze stuktury "G"

void aktualizuj(int exp) // "exp" - oznacza, że przydzielamy identyfikatory dla podsłów słowa "s", długości "2^exp"
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
				if( G[i][ j - 1 ].ST < G[i][j].ST ) // jeśli aktualne podsłowo jest różne od poprzedniego
				{
					++id; // to z faktu, iż identyfikatory dla podsłów słowa "s" (długości "2^exp") były posortowane rosnąco wiemy, że aktualnie rozważane podsłowo jest kolejnym w porządku leksykograficznym (w ramach podsłów słowa "s", długości "2^exp") 
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
	REP(exp,1,EXP) // dla wykładnika exp = 1,2,...,EXP (rozważam podsłowa słowa "s", długości "2^exp")
	{
		wypelnij( exp );
		
		sortowanie_pozycyjne(); // sortujemy informacje o wszystkich podsłowach słowa "s", długości "2^exp"
		
		aktualizuj( exp );
	}
}


void KMR() // tworzenie słownika podsłów bazowych dla słowa "s"
{
	// 1. faza - podsłowa długości 2^0 = 1
	
	KMR_1_faza();
	
	
	// 2. faza - podsłowa długości 2^exp (exp = 1,2,...,EXP)
	
	KMR_2_faza();
}


void zapytanie(int l1, int r1, int l2, int r2)
{
	PII P1, P2; // P1, P2 - pary identyfikatorów dla, odpowiednio, pierwszego oraz drugiego podsłowa
	
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
		
		zapytanie( l1, r1, l2, r2 ); // jeśli pierwsze podsłowo jest mniejsze, to wynikiem jest 1; jeśli drugie podsłowo jest mniejsze, to wynikiem jest 2; jeśli podsłowa są sobie równe, wynikiem jest 0
		
		--q;
	}
}


int main()
{
	preprocessing();
	
	wczytaj_dane();
	
	KMR();
	
	obsluz_zapytania();
	
	return 0;
}
