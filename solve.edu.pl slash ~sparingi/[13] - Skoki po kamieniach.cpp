#include<cstdio> // 100 pkt
#include<vector>


using namespace std;


typedef vector < int > VI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back

#define S size


const int MAX_N = 500000; // maksymalna d�ugo�� ci�gu wej�ciowego 't'


VI skok[MAX_N];

int n, wyn = 1, t[MAX_N], kolejnosc[MAX_N], repr[MAX_N], pocz[MAX_N], kon[MAX_N];


/*

n - d�ugo�� ci�gu wej�ciowego 't'

t[i] - numer chwili czasu, w kt�rej odwiedzony zostanie kamie� o numerze 'i' ( pocz�tkowo 1 <= t[i] <= n, ale potem zmniejszam t[i] o 1  ;  0 <= i <= n - 1 )

kolejnosc[i] - numer kamienia odwiedzonego w chwili czasu o numerze 'i' ( 0 <= kolejnosc[i] <= n - 1  ;  0 <= i <= n - 1 )

repr[i] - reprezentant zbioru, w kt�rym jest element (czyli w naszym wypadku chwila czasu) o numerze 'i' ( 0 <= repr[i] <= n - 1  ;  0 <= i <= n - 1 )

pocz[i] - pocz�tek przedzia�u dla zbioru, w kt�rym jest chwila czasu o numerze 'i' ( 0 <= pocz[i] <= n - 1  ;  0 <= i <= n - 1 )

kon[i] - koniec przedzia�u dla zbioru, w kt�rym jest chwila czasu o numerze 'i' ( 0 <= pocz[i] <= n - 1  ;  0 <= i <= n - 1 )

skok[i][j] - numer chwili czasu, w kt�rej wykonujemy po raz j-ty (id�c od najwcze�niejszych chwil czasu do najp�niejszych) skok o d�ugo�ci 'i' ( 0 <= i <= n - 1  ;  0 <= j <= n - 2  dla n >= 2, bo dla n = 1 nie wykonam nigdy skoku ;  j = 0 oznacza tak naprawd�, �e po raz pierwszy wykonuj� skok danej d�ugo�ci, dla j = 1 - po raz drugi, itd.  ;  je�eli ani razu nie wykonuj� skoku d�ugo�ci 'x', to wektor skok[x] jest pusty  ;  wiadomo te�, �e ��czna liczba wszystkich skok�w to n-1 )

wyn - maksymalna d�ugo�� sp�jnego przedzia�u numer�w chwil czasu, w kt�rym mog� skaka� mi�dzy kamieniami ( numery kamieni, na kt�rych w danej chwili czasu mog� si� znajdowa�, s� wyznaczone przez ci�g 'kolejnosc')


Uwagi:

1. W dowolnej chwili dzia�ania tego algorytmu, wszystkie zbiory s� zawsze sp�jnymi fragmentami tablicy 'kolejnosc'

2. Tablica 't' to permutacja liczb od 1 do n ( ale tylko pocz�tkowo, bo potem od ka�dego elementu tablicy 't' odejmuj� jedynk�, tak wi�c po tym zabiegu tablica 't' b�dzie permutacj� liczb od 0 do n-1 )

3. Tablica 'kolejnosc' przechowuje permutacj� odwrotn� dla permutacji przechowywanej w tablicy 't' ( chodzi mi tu o tablic� 't' po fazie odejmowania jedynki od ka�dego elementu tablicy 't' )

*/


int abs(int x) // warto�� bezwzgl�dna liczby ca�kowitej 'x'
{
	return ( x >= 0 ) ? x : -x ;
}


int max(int a, int b) // wi�ksza z liczb 'a' oraz 'b'
{
	return ( a > b ) ? a : b ;
}


int dl(int x) // d�ugo�� skoku z x-tego do x+1-szego kamienia w kolejno�ci
{
	return abs( kolejnosc[ x ] - kolejnosc[ x + 1 ] );
}


int ile(int x) // liczba element�w (tj. chwil czasu) w zbiorze zawieraj�cym element (tj. chwil� czasu) 'x'
{
	return kon[ x ] - pocz[ x ] + 1;
}


void wczytaj()
{
	scanf( "%d", &n ); // wczytanie d�ugo�ci ci�gu wej�ciowego 't'
	
	
	// Wczytanie ci�gu wej�ciowego 't' + obliczenie tablicy 'kolejnosc' z jednoczesn� zmian� warto�ci element�w tablicy 't'
	
	REP(i,0,n-1)
	{
		scanf( "%d", &t[i] );
		
		kolejnosc[ --t[i] ] = i;
	}
	
	
	// Obliczenie tablicy wektor�w 'skok'
	
	REP(i,0,n-2)
	{
		skok[ dl( i ) ].PB( i );
	}
	
	
	// Zainicjowanie strktur zwi�zanych z Find-Union
	
	REP(i,0,n-1)
	{
		repr[i] = i; // na pocz�tku ka�dy element 'i' (tj. chwila czasu o numerze 'i' ) jest reprezentantem zbioru, w kt�rym si� znajduje (bo pocz�tkowo te zbiory s� 1-elementowe)
		
		pocz[i] = kon[i] = i; // ka�dy zbi�r jest pocz�tkowo 1-elementowy, czyli kra�ce zbioru z chwil� czasu o numerze 'i' wynosz� po prostu 'i'
	}
}


int Find(int x) // znalezienie reprezentanta zbioru z elementem (w naszym wypadku chwil� czasu) 'x'
{
	if( repr[x] == x )
	{
		return x;	
	}
	
	int wyn = Find( repr[x] );
	
	repr[x] = wyn;
	
	return wyn;
}


void Union(int a, int b) // po��czenie zbior�w zawieraj�cych elementy (tj. chwile czasu) 'a' oraz 'b' (w naszym wypadku 'a' oraz 'b' b�d� zawsze w r�nych zbiorach, kt�re w dodatku ze sob� s�siaduj� w ci�gu 'kolejnosc')
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
		
		printf( "%d\n", wyn - 1 ); // musz� wypisywa� maksymaln� mo�liw� liczb� kolejnych skok�w d�ugo�ci <= i, st�d odejmuj� od wyniku jedynk� ( bo 'wyn' oznacza tak naprawd� maksymaln� liczb� kolejnych - w kolejno�ci - kamieni, mi�dzy kt�rymi mog� skaka� (skoki s� mo�liwe tylko z kamienia poprzedniego do nast�pnego, czyli z kamienia x-tego w kolejno�ci do x+1-szego w kolejno�ci) zatem skok�w b�dzie wyn-1 )
	}
}


int main()
{
	wczytaj();
	
	obsluz();
	
	return 0;
}
