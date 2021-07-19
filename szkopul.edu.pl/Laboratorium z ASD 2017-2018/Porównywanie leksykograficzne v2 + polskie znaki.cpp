/*

W tym programie, dla s�owa s[0..n-1] odpowiadam w kolejnych zapytaniach o to, kt�re jego pods�owo jest mniejsze leksykograficznie : pierwsze (o kra�cach l1, r1), czy drugie (o kra�cach l2, r2) (by� mo�e oba pods�owa s� sobie r�wne) 

Do rozwi�zania tego zadania u�ywam algorytmu KMR, dzia�aj�cego w czasie O(n log n)

Na ka�de zapytanie odpowiadam w czasie O(log log n)

Z�o�ono�� czasowa rozwi�zania to O(n log n + q log log n), pami�ciowa - O(n log n)

Uwaga. Kra�ce pods��w z zapyta� dotycz� s�owa "s", ale indeksowanego od jedynki

Uwaga. Zak�adam, �e alfabet, nad kt�rym wykonuj� ten algorytm, ma rozmiar O(1) 
       (ma to znaczenie przy szacowaniu z�o�ono�ci sortowania pozycyjnego)

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

s - s�owo wej�ciowe

T - tablica par, kt�rej u�ywam do wyznaczania identyfikator�w dla pods��w o d�ugo�ci 2^0 = 1

MAX_N - maksymalna d�ugo�� s�owa "s"

MAX_EXP - wyk�adnik (ca�kowity nieujemny) maksymalnej pot�gi dw�jki, nieprzekraczaj�cej maksymalnej mo�liwej 
          d�ugo�ci s�owa "s" (czyli MAX_N)

n - d�ugo�� s�owa "s"

EXP - wyk�adnik (ca�kowity nieujemny) maksymalnej pot�gi dw�jki, nieprzekraczaj�cej d�ugo�ci s�owa "s"

pot2 - tablica kolejnych pot�g dw�jki (o wyk�adniku ca�kowitym nieujemnym)

ID - tablica identyfikator�w

q - liczba zapyta�

l1, r1 - odpowiednio, pocz�tek i koniec, pierwszego pods�owa z pojedy�czego zapytania

l2, r2 - odpowiednio, pocz�tek i koniec, drugiego pods�owa z pojedy�czego zapytania

*/

const int MAX_N = 300000, MAX_EXP = 18;


VPII *G, *POM;

string s;

PII T[MAX_N];

int q, n, EXP, pot2[MAX_EXP+1], ID[MAX_EXP+1][MAX_N];


void preprocessing()
{
	// Spami�tanie pot�g dw�jki (o ca�kowitym i nieujemnym wyk�adniku)
	
	pot2[0] = 1;
	
	REP(i,1,MAX_EXP)
	{
		pot2[i] = pot2[ i - 1 ] * 2;
	}

	
	// Inicjowanie tablicy identyfikator�w
	
	REP(i,0,MAX_EXP)
	{
		REP(j,0,MAX_N-1)
		{
			ID[i][j] = -1; // nie istnieje (w pierwszym przybli�eniu) identyfikator dla pods�owa s�owa "s" d�ugo�ci "2^i", ko�cz�cego si� na pozycji "j"
		}
	}
	
	
	// Inicjowanie struktur danych do sortowania pozycyjnego
	
	G = new VPII [MAX_N]; // tablica wektor�w, kt�r� indeksujemy warto�ciami ID1 (w ka�dym wektorze s�, dla ustalonego ID1, pary postaci (ID2,kon) )
	
	POM = new VPII [MAX_N]; // tablica wektor�w, kt�r� indeksujemy warto�ciami ID2 (w ka�dym wektorze s�, dla ustalonego ID1, pary postaci (ID1,kon) )

}


int bin(int x) // szukam najwi�kszego takiego "sr", �e 2^sr <= x
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


void wczytaj_dane() // wczytanie danych + obliczenie niekt�rych parametr�w globalnych
{
	cin >> n >> q >> s;
	
	EXP = bin( n );
}


// Teraz cz�� kodu odpowiedzialna za sortowanie pozycyjne


void fun(VPII *AA, VPII *BB)
{
	int tmp, kon, r;
	
	REP(i,0,n-1)
	{
		r = AA[i].S(); // ilo�� element�w i-tego wektora struktury A
		
		REP(j,0,r-1)
		{
			tmp = AA[i][j].ST; // warto�� j-tego identyfikatora w i-tym wektorze struktury A
			
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


// Wype�niam struktur� "G" (dla pods��w s�owa "s", d�ugo�ci "2^exp")

void wypelnij(int exp)
{
	int pocz, kon, sr, ID1, ID2, min_kon = pot2[ exp ] - 1; // min_kon - minimalny indeks ko�ca pods�owa s�owa "s", d�ugo�ci "2^exp"
		
	REP(i,min_kon,n-1)
	{
		// Ustalenie kra�c�w rozwa�anego pods�owa oraz jego �rodka (tj. indeksu ostatniej litery w pierwszej po��wki rozwa�anego aktualnie pods�owa)
		
		kon = i; // kon - indeks ko�ca aktualnego pods�owa 
		
		pocz = kon - min_kon; // pocz - indeks pocz�tku aktualnego pods�owa
		
		sr = ( pocz + kon ) / 2; // indeks �rodka aktualnego pods�owa
		
		
		// Wyznaczenie identyfiktor�w pierwszej oraz drugiej po��wki aktualnie rozwa�anego pods�owa 
		
		ID1 = ID[ exp - 1 ][ sr ]; // ID1 - identyfikator dla pierwszej po�owy aktualnego pods�owa
		
		ID2 = ID[ exp - 1 ][ kon ]; // ID2 - identyfikator dla drugiej po�owy aktualnego pods�owa
		
		
		// Wstawienie do struktury "G" danych na temat aktualnego pods�owa s�owa "s", d�ugo�ci "2^exp"
		
		G[ ID1 ].PB( MP( ID2, kon ) );
	}
}


// Aktualizuj� tablic� "ID" (odpowiedni wiersz) elementami ze stuktury "G"

void aktualizuj(int exp) // "exp" - oznacza, �e przydzielamy identyfikatory dla pods��w s�owa "s", d�ugo�ci "2^exp"
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
				if( G[i][ j - 1 ].ST < G[i][j].ST ) // je�li aktualne pods�owo jest r�ne od poprzedniego
				{
					++id; // to z faktu, i� identyfikatory dla pods��w s�owa "s" (d�ugo�ci "2^exp") by�y posortowane rosn�co wiemy, �e aktualnie rozwa�ane pods�owo jest kolejnym w porz�dku leksykograficznym (w ramach pods��w s�owa "s", d�ugo�ci "2^exp") 
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
	REP(exp,1,EXP) // dla wyk�adnika exp = 1,2,...,EXP (rozwa�am pods�owa s�owa "s", d�ugo�ci "2^exp")
	{
		wypelnij( exp );
		
		sortowanie_pozycyjne(); // sortujemy informacje o wszystkich pods�owach s�owa "s", d�ugo�ci "2^exp"
		
		aktualizuj( exp );
	}
}


void KMR() // tworzenie s�ownika pods��w bazowych dla s�owa "s"
{
	// 1. faza - pods�owa d�ugo�ci 2^0 = 1
	
	KMR_1_faza();
	
	
	// 2. faza - pods�owa d�ugo�ci 2^exp (exp = 1,2,...,EXP)
	
	KMR_2_faza();
}


void zapytanie(int l1, int r1, int l2, int r2)
{
	PII P1, P2; // P1, P2 - pary identyfikator�w dla, odpowiednio, pierwszego oraz drugiego pods�owa
	
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
		
		zapytanie( l1, r1, l2, r2 ); // je�li pierwsze pods�owo jest mniejsze, to wynikiem jest 1; je�li drugie pods�owo jest mniejsze, to wynikiem jest 2; je�li pods�owa s� sobie r�wne, wynikiem jest 0
		
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
