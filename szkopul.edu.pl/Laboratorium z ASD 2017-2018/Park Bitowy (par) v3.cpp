/*

W tym zadaniu, dla danego drzewa, mamy odpowiadać na wiele zapytań takiej postaci:
podać przykład wierzchołka oddalonego od zadanego wierzchołka "u" o zadaną odledłość "odl", bądź stwierdzić, że takowy wierzchołek w drzewie nie istnieje


Założenia:

1) W obliczeniach nie zakładałem, że drzewo jest binarne (tylko założenia zadania oraz format danych wejściowych to wymuszały)

2) W strukturze "syn" mam tylko listy synów (tzn. dla dowolnego wierzchołka drzewa "u", w wektorze "syn[u]" nie kryje się ojciec wierzchołka "u") - wynika to z tego, jak wyglądają dane wejściowe (nawiasem mówiąc, taki format danych wejściowych sprawił, że kod był nieco łatwiejszy - np. nie trzeba było się ciągle pilnować, czy oby na pewno rozważamy syna jakiegoś wierzchołka, czy nie)

3) W programie (tj. w strukturach danych, w procesie obliczeń) numeruję wierzchołki od zera - oczywiście, na wejściu i na wyjściu numeracja jest od jedynki, ale to nie problem dodać lub odjąć w danym momencie jedynkę


Definicje:

Def 1. Dla dowolnego, ustalonego wierzchołka "u" drzewa, najdłuższa ścieżka I rodzaju to najdłuższa ścieżka wychodząca z wierzchołka "u", znajdująca się w poddrzewie wierzchołka "u"

Def 2. Dla dowolnego, ustalonego wierzchołka "u" drzewa, najdłuższa ścieżka II rodzaju to najdłuższa ścieżka wychodząca z wierzchołka "u", idąca w górę drzewa (aż do pewnego wierzchołka "x", znajdującego się na ścieżce od wierzchołka "u" do korzenia), a następnie idąca od wierzchołka "x" w dół drzewa (oczywiście nie możemy iść w dół przez takiego syna wierzchołka "x", w którego poddrzewie jest wierzchołek "u")

*/


#include<cstdio> // 100 pkt
#include<vector>


using namespace std;


typedef pair < int, int > PII;

typedef vector < int > VI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back

#define S size

#define MP make_pair

#define ST first

#define ND second


const int MAX_N = 500000, MAX_K = 18; // MAX_N - maksymalna ilość wierzchołków w drzewie, MAX_K - maksymalne takie 'x' (całkowite nieujemne), że 2^x <= MAX_N


VI syn[MAX_N]; // dla każdego wierzchołka "u" w drzewie, trzymam wektor synów wierzchołka "u"


// Uwaga ( dla struktur "d1" oraz "d2" ). Jeśli dla wierzchołka "u" są co najmniej 2 najdłuższe ścieżki, to jedna z nich jest opisana przez d1[u], natomiast druga - przez d2[u]

PII d1[MAX_N]; // dla każdego wierzchołka drzewa "u", d1[u] oznacza parę postaci (długość najdłuższej ścieżki w poddrzewie wierzchołka "u", wychodzącej z wierzchołka "u" ; numer syna wierzchołka "u", przez którego ta ścieżka przechodzi)

int d2[MAX_N]; // dla każdego wierzchołka drzewa "u", d2[u] oznacza długość drugiej najdłuższej ścieżki w poddrzewie wierzchołka "u", wychodzącej z wierzchołka "u" ( oczywiście ta ścieżka musi przechodzić przez innego syna wierzchołka "u", niż ścieżka najdłuższa, czyli związana z wartością d1[u] )


PII d[MAX_N]; // dla każdego wierzchołka drzewa "u", d[u] oznacza parę postaci (długość najdłuższej ścieżki wychodzącej z wierzchołka "u", idącej w górę aż do jakiegoś wierzchołka "x", a potem schodzącej w dół (oczywiście to schodzenie musi przechodzić przez takiego syna wierzchołka "x", w którego poddrzewie nie ma wierzchołka "u") ; numer wierzchołka "x" z opisu pierwszego elementu tej pary)

int q, n, k, root = 0; // q - liczba zapytań;  n - liczba wierzchołków drzewa;  k = max x: { x - całkowite nieujemne oraz 2^x <= n };  root - korzeń drzewa

int depth[MAX_N]; // dla każdego wierzchołka drzewa "u", depth[u] oznacza głębokość wierzchołka "u" w drzewie

int w1[MAX_N], w2[MAX_N], w[MAX_N]; // dla każdego wierzchołka drzewa "u":  w1[u] - numer wierzchołka kończącego ścieżkę związaną z wartością d1[u];  w2[u] - numer wierzchołka kończącego ścieżkę związaną z wartością d2[u];  w[u] - numer wierzchołka kończącego ścieżkę związaną z wartością d[u]

int nr[MAX_N][MAX_K+1]; // dla każdego wierzchołka drzewa "u", nr[u][j] oznacza numer wierzchołka, oddalonego od wierzchołka "u" o wartość 2^j (przy czym z wierzchołka "u" idziemy tylko w górę drzewa)


int max(int a, int b) // większa z liczb całkowitych "a" oraz "b"
{
	return ( a > b ) ? a : b ; // jeśli warunek ( a > b ) jest prawdziwy ( czyli zachodzi a > b ), to zwracamy "a", w przeciwnym razie ( czyli zachodzi a <= b ) zwracamy "b"
}


int funkcja(int x) // wynikiem jest exp = max y: { y - całkowite nieujemne oraz 2^y <= x }
{
	// Niezmiennik pętli "while": 2^exp = tmp (czyli przed wejściem do tej pętli to zachodzi, pod sam koniec każdego obrotu tej pętli to zachodzi oraz tuż po wyjściu z tej pętli to zachodzi)
	
	int exp = 0, tmp = 1;
	
	while( tmp <= x )
	{
		tmp *= 2;
		
		++exp;
	}
	
	return --exp; // odejmuję jedynkę od zmiennej "exp", bo po wyjściu z pętli "while", zmienna "exp" oznacza wykładnik najmniejszej potęgi dwójki, większej niż "x" - tak więc odjęcie jedynki od zmiennej "exp" sprawia, że mamy potęgę dwójki niewiększą niż "x", ale możliwie dużą 
}


void inicjuj_struktury_danych() // dla każdego wierzchołka drzewa "u", określam wartości początkowe pewnych struktur danych
{
	REP(u,0,MAX_N-1)
	{
		d1[u] = MP( 0, -1 ); // początkowo zakładamy, że ścieżki, określone tablicą "d1", mają zerową długość (skoro tak, to nie przechodzą one przez żadnych synów)
		
		d2[u] = 0; // początkowo zakładamy, że ścieżki, określone tablicą "d2", mają zerową długość
		
		d[u] = MP( 0, -1 ); // początkowo zakładamy, że ścieżki, określone tablicą "d", mają zerową długość (skoro tak, to nie przechodzą one przez żadne wierzchołki położone wyżej w stosunku do konkretnych wierzchołków, dla których liczymy tablicę "d")
		
		w[u] = -1; // skoro początkowe przybliżenie długości ścieżki ( związanej z wartością d[u] ) jest zerem, to ta ścieżka nie może kończyć się w żadnym wierzchołku drzewa (no bo trzeba by pójść co najmniej jedną krawędzią w górę, a potem co najmniej jedną krawędzią w dół - wynika to z tego, jakiego rodzaju ścieżki są opisane w tablicy "d" - patrz opis tablicy "d")
		
		w1[u] = w2[u] = u; // skoro początkowe przybliżenia długości ścieżek ( związanych z wartościami d1[u] oraz d2[u] ) są zerami, to te ścieżki kończą się (jak również rozpoczynają się) w wierzchołku "u" - w razie wątpliwości, patrz opis tablic "d1" oraz "d2"
	}
}


void wczytaj_dane()
{
	scanf( "%d", &n );
	
	int v1, v2;
	
	REP(u,0,n-1)
	{
		scanf( "%d %d", &v1, &v2 );
		
		if( v1 != -1 )
		{
			--v1;
			
			syn[u].PB( v1 );
		}
		
		if( v2 != -1 )
		{
			--v2;
			
			syn[u].PB( v2 );
		}
	}
}


void f1(int u)
{
	int r = syn[u].S(), v, ww;
	
	REP(i,0,r-1)
	{
		v = syn[u][i];
		
		depth[v] = depth[u] + 1;
			
		nr[v][0] = u;
	
		REP(j,1,k)
		{
			ww = nr[v][ j - 1 ];
	
			if( ww == -1 )
			{
				nr[v][j] = -1;
			}
			else
			{
				nr[v][j] = nr[ ww ][ j - 1 ];
			}
		}
		
		f1( v ); // wywołujemy się rekurencyjnie dla wierzchołka "v"
				
		if( d1[v].ST + 1 > d1[u].ST )
		{
			d2[u] = d1[u].ST;
			
			w2[u] = w1[u];
			
			d1[u] = MP( d1[v].ST + 1, v );
			
			w1[u] = w1[v];
		}
		else
		{
			if( d1[v].ST + 1 > d2[u] )
			{
				d2[u] = d1[v].ST + 1;
				
				w2[u] = w1[v];
			}
		}
	}
}


void f2(int u)
{
	int r = syn[u].S(), v;
	
	REP(i,0,r-1)
	{
		v = syn[u][i];
		
		
		// Przypadek 1: idę do ojca, potem w dół
			
		if( d1[u].ND != v )
		{
			if( 1 + d1[u].ST > d[v].ST )
			{
				d[v] = MP( 1 + d1[u].ST, u );
				
				w[v] = w1[u];
			}
		}
		else
		{
			if( 1 + d2[u] > d[v].ST )
			{
				d[v] = MP( 1 + d2[u], u );
				
				w[v] = w2[u];
			}
		}
		
		
		// Przypadek 2: biorę przedłużoną najlepszą ścieżkę dla ojca
		
		if( u != root  &&  1 + d[u].ST > d[v].ST )
		{
			d[v] = MP( 1 + d[u].ST, d[u].ND );
			
			w[v] = w[u];
		}
		
		f2( v ); // wywołujemy się rekurencyjnie dla wierzchołka "v"
	}
}


void obliczenia_wstepne()
{
	k = funkcja( n );
	
	f1( root );
	
	f2( root );
}


int znajdz(int u, int odl) // znajduję wierzchołek położony w odległości "odl" od wierzchołka "u" (przy czym szukany wierzchołek ma być położony na ścieżce od wierzchołka "u" do korzenia drzewa)
{
	int ind = 0, wyn = u;
		
	while( odl > 0 )
	{
		if( odl % 2 == 1 )
		{
			wyn = nr[ wyn ][ ind ];
		}
		
		++ind;
		
		odl /= 2;
	}
	
	return wyn;
}


int zapytanie(int u, int odl) // dla wierzchołka "u" drzewa, znajduję wierzchołek odległy o "odl" od wierzchołka "u" (jeśli istnieje, to wypisuję jego numer, ale z zakresu [1..n]), bądź stwierdzam, że takiego w drzewie nie ma
{
	// Przypadek 1 - szukamy wierzchołka w ramach najdłuższej ścieżki I rodzaju
	
	int dmax_I = d1[u].ST;
	
	if( dmax_I >= odl ) // jeśli wierzchołek "v" (czyli wierzchołek najbardziej oddalony od wierzchołka "u") jest wystarczająco odległy od wierzchołka "u"
	{
		int v = w1[u];
		
		return znajdz( v, dmax_I - odl ) + 1;
	}
	
	
	// Przypadek 2 - szukamy wierzchołka w ramach najdłuższej ścieżki II rodzaju
	
	int dmax_II = d[u].ST;
	
	if( dmax_II >= odl )
	{
		int LCA = d[u].ND,    D = depth[u] - depth[ LCA ];
			
		if( D >= odl )
		{
			return znajdz( u, odl ) + 1;
		}
		else
		{
			int v = w[u];
			
			return znajdz( v, dmax_II - odl ) + 1;
		}
	}
	
	
	// Nie istnieje odpowiedni wierzchołek
	
	return -1;
}


void obsluz_zapytania()
{
	scanf( "%d", &q );
	
	int u, odl;
	
	while( q )
	{
		scanf( "%d %d", &u, &odl );
		
		printf( "%d\n", zapytanie( --u, odl ) ); // zapisałem --u (czyli odjąłem jedynkę od "u"), bo funkcja "zapytanie" potrzebuje numeru wierzchołka z zakresu [0..n-1] ( w zapytaniach dostajemy numer wierzchołka z zakresu [1..n] )
		
		--q;
	}
}


int main()
{
	inicjuj_struktury_danych();
	
	wczytaj_dane();
	
	obliczenia_wstepne();
	
	obsluz_zapytania();
	
	return 0;
}