#include<cstdio> // 100 pkt
#include<vector>


using namespace std;


typedef vector < int > VI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back

#define S size


const int MAX_N = 500000; // maksymalna d³ugoœæ ci¹gu wejœciowego 't'


VI skok[MAX_N];

int n, wyn = 1, t[MAX_N], kolejnosc[MAX_N], repr[MAX_N], pocz[MAX_N], kon[MAX_N];


/*

n - d³ugoœæ ci¹gu wejœciowego 't'

t[i] - numer chwili czasu, w której odwiedzony zostanie kamieñ o numerze 'i' ( pocz¹tkowo 1 <= t[i] <= n, ale potem zmniejszam t[i] o 1  ;  0 <= i <= n - 1 )

kolejnosc[i] - numer kamienia odwiedzonego w chwili czasu o numerze 'i' ( 0 <= kolejnosc[i] <= n - 1  ;  0 <= i <= n - 1 )

repr[i] - reprezentant zbioru, w którym jest element (czyli w naszym wypadku chwila czasu) o numerze 'i' ( 0 <= repr[i] <= n - 1  ;  0 <= i <= n - 1 )

pocz[i] - pocz¹tek przedzia³u dla zbioru, w którym jest chwila czasu o numerze 'i' ( 0 <= pocz[i] <= n - 1  ;  0 <= i <= n - 1 )

kon[i] - koniec przedzia³u dla zbioru, w którym jest chwila czasu o numerze 'i' ( 0 <= pocz[i] <= n - 1  ;  0 <= i <= n - 1 )

skok[i][j] - numer chwili czasu, w której wykonujemy po raz j-ty (id¹c od najwczeœniejszych chwil czasu do najpóŸniejszych) skok o d³ugoœci 'i' ( 0 <= i <= n - 1  ;  0 <= j <= n - 2  dla n >= 2, bo dla n = 1 nie wykonam nigdy skoku ;  j = 0 oznacza tak naprawdê, ¿e po raz pierwszy wykonujê skok danej d³ugoœci, dla j = 1 - po raz drugi, itd.  ;  je¿eli ani razu nie wykonujê skoku d³ugoœci 'x', to wektor skok[x] jest pusty  ;  wiadomo te¿, ¿e ³¹czna liczba wszystkich skoków to n-1 )

wyn - maksymalna d³ugoœæ spójnego przedzia³u numerów chwil czasu, w którym mogê skakaæ miêdzy kamieniami ( numery kamieni, na których w danej chwili czasu mogê siê znajdowaæ, s¹ wyznaczone przez ci¹g 'kolejnosc')


Uwagi:

1. W dowolnej chwili dzia³ania tego algorytmu, wszystkie zbiory s¹ zawsze spójnymi fragmentami tablicy 'kolejnosc'

2. Tablica 't' to permutacja liczb od 1 do n ( ale tylko pocz¹tkowo, bo potem od ka¿dego elementu tablicy 't' odejmujê jedynkê, tak wiêc po tym zabiegu tablica 't' bêdzie permutacj¹ liczb od 0 do n-1 )

3. Tablica 'kolejnosc' przechowuje permutacjê odwrotn¹ dla permutacji przechowywanej w tablicy 't' ( chodzi mi tu o tablicê 't' po fazie odejmowania jedynki od ka¿dego elementu tablicy 't' )

*/


int abs(int x) // wartoœæ bezwzglêdna liczby ca³kowitej 'x'
{
	return ( x >= 0 ) ? x : -x ;
}


int max(int a, int b) // wiêksza z liczb 'a' oraz 'b'
{
	return ( a > b ) ? a : b ;
}


int dl(int x) // d³ugoœæ skoku z x-tego do x+1-szego kamienia w kolejnoœci
{
	return abs( kolejnosc[ x ] - kolejnosc[ x + 1 ] );
}


int ile(int x) // liczba elementów (tj. chwil czasu) w zbiorze zawieraj¹cym element (tj. chwilê czasu) 'x'
{
	return kon[ x ] - pocz[ x ] + 1;
}


void wczytaj()
{
	scanf( "%d", &n ); // wczytanie d³ugoœci ci¹gu wejœciowego 't'
	
	
	// Wczytanie ci¹gu wejœciowego 't' + obliczenie tablicy 'kolejnosc' z jednoczesn¹ zmian¹ wartoœci elementów tablicy 't'
	
	REP(i,0,n-1)
	{
		scanf( "%d", &t[i] );
		
		kolejnosc[ --t[i] ] = i;
	}
	
	
	// Obliczenie tablicy wektorów 'skok'
	
	REP(i,0,n-2)
	{
		skok[ dl( i ) ].PB( i );
	}
	
	
	// Zainicjowanie strktur zwi¹zanych z Find-Union
	
	REP(i,0,n-1)
	{
		repr[i] = i; // na pocz¹tku ka¿dy element 'i' (tj. chwila czasu o numerze 'i' ) jest reprezentantem zbioru, w którym siê znajduje (bo pocz¹tkowo te zbiory s¹ 1-elementowe)
		
		pocz[i] = kon[i] = i; // ka¿dy zbiór jest pocz¹tkowo 1-elementowy, czyli krañce zbioru z chwil¹ czasu o numerze 'i' wynosz¹ po prostu 'i'
	}
}


int Find(int x) // znalezienie reprezentanta zbioru z elementem (w naszym wypadku chwil¹ czasu) 'x'
{
	if( repr[x] == x )
	{
		return x;	
	}
	
	int wyn = Find( repr[x] );
	
	repr[x] = wyn;
	
	return wyn;
}


void Union(int a, int b) // po³¹czenie zbiorów zawieraj¹cych elementy (tj. chwile czasu) 'a' oraz 'b' (w naszym wypadku 'a' oraz 'b' bêd¹ zawsze w ró¿nych zbiorach, które w dodatku ze sob¹ s¹siaduj¹ w ci¹gu 'kolejnosc')
{
	int repr_a = Find( a ), repr_b = Find( b );
	
	if( ile( repr_a ) <= ile( repr_b ) )
	{
		repr[ repr_a ] = repr_b;
		
		pocz[ repr_b ] = pocz[ repr_a ];
		
		wyn = max( wyn, ile( repr_b ) );
	}
	else
	{
		repr[ repr_b ] = repr_a;
		
		kon[ repr_a ] = kon[ repr_b ];
		
		wyn = max( wyn, ile( repr_a ) );
	}
}


void obsluz()
{
	int r, ind;
	
	REP(i,1,n-1)
	{
		r = skok[i].S();
		
		REP(j,0,r-1)
		{
			ind = skok[i][j];
			
			Union( ind, ind + 1 );
		}
		
		printf( "%d\n", wyn - 1 ); // muszê wypisywaæ maksymaln¹ mo¿liw¹ liczbê kolejnych skoków d³ugoœci <= i, st¹d odejmujê od wyniku jedynkê ( bo 'wyn' oznacza tak naprawdê maksymaln¹ liczbê kolejnych - w kolejnoœci - kamieni, miêdzy którymi mogê skakaæ (skoki s¹ mo¿liwe tylko z kamienia poprzedniego do nastêpnego, czyli z kamienia x-tego w kolejnoœci do x+1-szego w kolejnoœci) zatem skoków bêdzie wyn-1 )
	}
}


int main()
{
	wczytaj();
	
	obsluz();
	
	return 0;
}
