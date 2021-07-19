/*

W tym zadaniu, dla danego drzewa, mamy odpowiadać na wiele zapytań takiej postaci:
podać przykład wierzchołka oddalonego od zadanego wierzchołka "u" o zadaną odledłość "odl", bądź stwierdzić, że takowy wierzchołek w drzewie nie istnieje



Założenia:

1) W obliczeniach nie zakładałem, że drzewo jest binarne (tylko założenia zadania oraz format danych wejściowych to wymuszały)

2) W strukturze "syn" mam tylko listy synów (tzn. dla dowolnego wierzchołka drzewa "u", w wektorze "syn[u]" nie kryje się ojciec wierzchołka "u") - wynika to z tego, jak wyglądają dane wejściowe (nawiasem mówiąc, taki format danych wejściowych sprawił, że kod był nieco łatwiejszy - np. nie trzeba było się ciągle pilnować, czy oby na pewno rozważamy syna jakiegoś wierzchołka, czy nie)

3) W programie (tj. w strukturach danych, w procesie obliczeń) numeruję wierzchołki od zera - oczywiście, na wejściu i na wyjściu numeracja jest od jedynki, ale to nie problem dodać lub odjąć w danym momencie jedynkę

4) Drzewo jest nieskierowane (czyli krawędziami drzewa można chodzić w obie strony)

5) Pojęcie " wierzchołek o numerze "u" " znaczy to samo, co " wierzchołek "u" "



Definicje:

Def. 1. Dla dowolnego, ustalonego wierzchołka "u" drzewa, najdłuższa ścieżka I rodzaju to najdłuższa ścieżka wychodząca z wierzchołka "u", znajdująca się w poddrzewie wierzchołka "u"

Def. 2. Dla dowolnego, ustalonego wierzchołka "u" drzewa, najdłuższa ścieżka II rodzaju to najdłuższa ścieżka wychodząca z wierzchołka "u", idąca w górę drzewa (aż do pewnego wierzchołka "x", znajdującego się na ścieżce od wierzchołka "u" do korzenia), a następnie idąca od wierzchołka "x" w dół drzewa (oczywiście nie możemy iść w dół przez takiego syna wierzchołka "x", w którego poddrzewie jest wierzchołek "u")

Def. 3. Dla dowolnych, ustalonych wierzchołków "u", "v" drzewa, odległość między tymi wierzchołkami to liczba krawędzi na ścieżce łączącej te wierzchołki

Def. 4. Dla wierzchołka "u" drzewa, przodek wierzchołka "u" to wierzchołek leżący na ścieżce od wierzchołka "u" do korzenia drzewa (nie licząc wierzchołka "u") - w szczególności, gdy ruszamy z wierzchołka "u" w stronę korzenia, to pierwszy napotkany przodek to ojciec wierzchołka "u"

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


// Uwaga ( dla struktur "d1" oraz "d2" ). Jeśli dla wierzchołka "u" są co najmniej 2 najdłuższe ścieżki I rodzaju, to jedna z nich jest opisana przez d1[u], natomiast druga - przez d2[u];  dla wierzchołka u", jak co najmniej 2 ścieżki są pod względem długości na 2. miejscu, to pamiętamy którąś z nich (tylko jedną)
                                         
PII d1[MAX_N]; // dla każdego wierzchołka "u" drzewa, d1[u] oznacza parę postaci (długość najdłuższej ścieżki w poddrzewie wierzchołka "u", wychodzącej z wierzchołka "u" ; numer syna wierzchołka "u", przez którego ta ścieżka przechodzi)

int d2[MAX_N]; // dla każdego wierzchołka "u" drzewa, d2[u] oznacza długość drugiej najdłuższej ścieżki w poddrzewie wierzchołka "u", wychodzącej z wierzchołka "u" ( oczywiście ta ścieżka musi przechodzić przez innego syna wierzchołka "u", niż ścieżka najdłuższa, czyli związana z wartością d1[u] )


PII d[MAX_N]; // dla każdego wierzchołka "u" drzewa, d[u] oznacza parę postaci (długość najdłuższej ścieżki wychodzącej z wierzchołka "u", idącej w górę aż do jakiegoś wierzchołka "x", a potem schodzącej w dół (oczywiście to schodzenie musi przechodzić przez takiego syna wierzchołka "x", w którego poddrzewie nie ma wierzchołka "u") ; przykładowy numer wierzchołka "x" z opisu pierwszego elementu tej pary)

int w1[MAX_N], w2[MAX_N], w[MAX_N]; // dla każdego wierzchołka "u" drzewa:  w1[u] - przykładowy numer wierzchołka kończącego ścieżkę związaną z wartością d1[u];  w2[u] - przykładowy numer wierzchołka kończącego ścieżkę związaną z wartością d2[u];  w[u] - przykładowy numer wierzchołka kończącego ścieżkę związaną z wartością d[u] - oczywiście wartości d[u].ND oraz w[u] (o ile te wartości istnieją) są ze sobą związane - w[u] leży w poddrzewie pewnego syna wierzchołka "d[u].ND", jednak ten syn jest inny, niż dla wierzchołka "u"

int q, n, k, root = 0; // q - liczba zapytań;  n - liczba wierzchołków drzewa;  k = max y: { y - całkowite nieujemne oraz 2^y <= n };  root - korzeń drzewa ( numeracja z zakresu [0..n-1] )

int depth[MAX_N]; // dla każdego wierzchołka "u" drzewa, depth[u] oznacza głębokość wierzchołka "u" w drzewie (innymi słowy, odległość między wierzchołkiem "u" oraz korzeniem)

int nr[MAX_N][MAX_K+1]; // dla każdego wierzchołka "u" drzewa, nr[u][j] oznacza przodka wierzchołka "u", oddalonego od wierzchołka "u" o wartość 2^j, lub "-1", gdy takowy wierzchołek nie istnieje - czyli, intuicyjnie, do jakiego wierzchołka dojdziemy, jeśli z wierzchołka "u" wykonamy w górę drzewa skok długości 2^j


int max(int a, int b) // większa z liczb całkowitych "a" oraz "b"
{
	return ( a > b ) ? a : b ; // jeśli warunek ( a > b ) jest prawdziwy ( czyli zachodzi a > b ), to zwracamy "a", w przeciwnym razie ( czyli zachodzi a <= b ) zwracamy "b"
}


int funkcja(int x) // x - liczba naturalna dodatnia;  wynikiem jest exp = max y: { y - całkowite nieujemne oraz 2^y <= x }
{
	// Niezmiennik pętli "while": 2^exp = tmp (czyli tuż przed wejściem do tej pętli to zachodzi, pod sam koniec każdego obrotu tej pętli to zachodzi oraz tuż po wyjściu z tej pętli to zachodzi)
	
	int tmp = 1, exp = 0; // tmp - aktualna potęga dwójki;  exp - aktualny wykładnik, dla aktualnej potęgi dwójki "tmp"
	
	while( tmp <= x ) // dopóki aktualna potęga dwójki nie przekracza liczby "x"
	{
		tmp *= 2; // przechodzimy do kolejnej, większej potęgi dwójki
		
		++exp; // przejście do kolejnej, większej potęgi dwójki, oznacza zwiększenie wykładnika o jeden
	}
	
	return --exp; // odejmuję jedynkę od zmiennej "exp", bo po wyjściu z pętli "while", zmienna "exp" oznacza wykładnik najmniejszej potęgi dwójki, większej niż "x" - tak więc odjęcie jedynki od zmiennej "exp" sprawia, że mamy wykładnik dla potęgi dwójki niewiększej niż "x", ale możliwie największej (samej potęgi dwójki "tmp" nie musimy dzielić przez 2, bo nie ma takiej potrzeby)
}


void inicjuj_struktury_danych() // dla każdego wierzchołka drzewa "u", określam wartości początkowe pewnych struktur danych
{
	REP(u,0,MAX_N-1) // dla każdego potencjalnego wierzchołka drzewa (wierzchołków może być nawet MAX_N)
	{
		d1[u] = MP( 0, -1 ); // początkowo zakładamy, że ścieżki, określone tablicą "d1", mają zerową długość (skoro tak, to nie przechodzą one przez żadnych synów)
		
		d2[u] = 0; // początkowo zakładamy, że ścieżki, określone tablicą "d2", mają zerową długość
		
		d[u] = MP( 0, -1 ); // początkowo zakładamy, że ścieżki, określone tablicą "d", mają zerową długość (skoro tak, to nie przechodzą one przez żadne wierzchołki położone wyżej w stosunku do konkretnych wierzchołków "u", dla których liczymy tablicę "d")
		
		w[u] = -1; // skoro początkowe przybliżenie długości ścieżki ( związanej z wartością d[u] ) jest zerem, to ta ścieżka nie może kończyć się w żadnym wierzchołku drzewa (no bo trzeba by pójść co najmniej jedną krawędzią w górę, a potem co najmniej jedną krawędzią w dół - wynika to z tego, jakiego rodzaju ścieżki są opisane w tablicy "d" - patrz opis tablicy "d")
		
		w1[u] = w2[u] = u; // skoro początkowe przybliżenia długości ścieżek ( związanych z wartościami d1[u] oraz d2[u] ) są zerami, to te ścieżki kończą się (jak również rozpoczynają się) w wierzchołku "u" - w razie wątpliwości, patrz opis tablic "d1" oraz "d2"
		
		REP(j,0,MAX_K) // dla każdej potencjalnej długości skoku równej 2^j
		{
			nr[u][j] = -1; // początkowo nie istnieje przodek oddalony od wierzchołka "u" o "2^j"
		}
	}
}


void wczytaj_dane() // wczytuję dane wejściowe odnośnie drzewa - zapytania wczytywane będą w procedurze "obsluz_zapytania"
{
	scanf( "%d", &n ); // wczytujemy liczbę wierzchołków drzewa
	
	int v1, v2; // zmienne pomocnicze - w tych zmiennych, dla każdego wierzchołka drzewa "u", trzymam numery potencjalnych synów wierzchołka "u"
	
	REP(u,0,n-1) // dla każdego wierzchołka drzewa "u"
	{
		scanf( "%d %d", &v1, &v2 ); // wczytujemy numery potencjalnych synów wierzchołka "u"
		
		if( v1 != -1 ) // jeśli, dla wierzchołka "u", istnieje syn o numerze "v1"
		{
			--v1; // odejmuję jedynkę, żeby być w zakresie [0..n-1] ( w danych wejściowych wierzchołki mają numery z zakresu [1..n] ) 
			
			syn[u].PB( v1 ); // dorzucam, do listy synów wierzchołka "u", wierzchołek "v1"
		}
		
		if( v2 != -1 ) // jeśli, dla wierzchołka "u", istnieje syn o numerze "v2"
		{
			--v2; // odejmuję jedynkę, żeby być w zakresie [0..n-1] ( w danych wejściowych wierzchołki mają numery z zakresu [1..n] )
			
			syn[u].PB( v2 ); // dorzucam, do listy synów wierzchołka "u", wierzchołek "v2"
		}
	}
}


void f1(int u) // ta procedura, dla każdego wierzchołka "u" drzewa, oblicza tablice "nr", "d1", "d2", "w1", "w2", "depth" (pod warunkiem, że wywołamy ją dla korzenia, tzn. wywołamy ją dla argumentu "root")
{
	int r = syn[u].S(), v, ww; // r - liczba synów wierzchołka "u";  v, ww - zmienne pomocnicze (będą one oznaczać numery wierzchołków; może lepiej byłoby dać nazwę "w" zamiast "ww", jednak mamy już globalną tablicę o nazwie "w")
	
	REP(i,0,r-1) // dla każdego syna wierzchołka "u"
	{
		v = syn[u][i]; // wierzchołek "v" to i-ty syn na liście synów wierzchołka "u"
		
		depth[v] = depth[u] + 1; // znając głębokość ojca (w naszym wypadku ojcem jest wierzchołek "u"), łatwo liczymy głębokość dla jego syna (w naszym wypadku synem jest wierzchołek "v") - głębokość dla syna to głębokość dla ojca, powiększona o jeden ( by dojść z korzenia do wierzchołka "v", napierw idziemy z korzenia do wierzchołka "u" (odległość między wierzchołkiem "u" oraz korzeniem to "depth[u]"), potem idziemy jeszcze krawędzią z ojca (w tym przypadku, wierzchołka "u") do syna (w tym przypadku, wierzchołka "v") (odległość między wierzchołkiem "u" oraz wierzchołkiem "v" to jeden - wierzchołki "u" oraz "v" są bezpośrednio połączone krawędzią) ) 
		
		
		
		// Wyznaczanie, dla wierzchołka "v" drzewa, tablicy "nr"
		
		// Uwaga. Tablicę "nr" będziemy obliczali od góry do dołu drzewa, tzn. jeśli chcemy liczyć tę tablicę dla jakiegoś wierzchołka "v" drzewa, to wcześniej musimy obliczyć tablicę "nr" dla wszystkich przodków wierzchołka "v" (tj. wszystkich, poza wierzchołkiem "v", wierzchołków na ścieżce od wierzchołka "v" do korzenia)
		
		nr[v][0] = u; // wierzchołek "u" to wierzchołek oddalony o 2^0 od wierzchołka "v" 
	
		REP(j,1,k) // dla każdej, poza długością skoku równą 2^0, możliwej długości skoku (tzn. długości 2^j - długość skoku reprezentuję za pomocą wykładnika dla potęgi dwójki równej 2^j)
		{
			// Tutaj skorzystamy z takiego faktu: żeby pójść z jakiegoś wierzchołka "v" drzewa o "2^j" w górę drzewa, to możemy najpierw pójść z wierzchołka "v" o "2^(j-1)" w górę drzewa (do wierzchołka, nazwijmy go, "ww"), a potem, z wierzchołka "ww" o "2^j-1" w górę drzewa
			
			ww = nr[v][ j - 1 ]; // wierzchołek "ww" jest oddalony od wierzchołka "v" o "2^(j-1)" (idziemy z wierzchołka "v" w górę drzewa, więc jeśli wierzchołek "ww" istnieje, to jest wyznaczony jednoznacznie - w górę drzewa możemy iść tylko na jeden sposób)
	
			if( ww == -1 ) // jeśli żądany wierzchołek "ww" nie istnieje
			{
				nr[v][j] = -1; // mówimy, że nie istnieje wierzchołek odległy o "2^j" od wierzchołka "v" (idziemy z wierzchołka "v" w górę drzewa)
			}
			else
			{
				nr[v][j] = nr[ ww ][ j - 1 ]; // wierzchołek odległy o "2^j" od wierzchołka "v" to wierzchołek odległy o "2^j-1" od wierzchołka "ww" (jeśli wierzchołek odległy o "2^j-1" od wierzchołka "ww" nie istnieje, to nie istnieje również wierzchołek odległy o "2^j" od wierzchołka "v";  w takim wypadku wartość "nr[ ww ][ j - 1 ]" wynosi "-1" - skoro więc robimy przypisanie "nr[v][j] = nr[ ww ][ j - 1 ]", to wartość "nr[v][j]" wynosi "-1", czyli to, co trzeba)
			}
		}
		
		// Koniec wyznaczania tablicy "nr"
		
		
		
		f1( v ); // wywołujemy się rekurencyjnie dla wierzchołka "v" drzewa
		
		
		
		// Obliczanie, dla wierzchołka "u", tablic "d1", "d2", "w1", "w2"
		
		if( d1[v].ST + 1 > d1[u].ST ) // jeśli najdłuższa, dla wierzchołka "v", ścieżka I rodzaju, przedłużona o krawędź z wierzchołka "v" do wierzchołka "u", jest dłuższa niż dotychczasowa najdłuższa, dla wierzchołka "u", ścieżka I rodzaju 
		{
			d2[u] = d1[u].ST; // dla wierzchołka "u", długość drugiej najdłuższej ścieżki I rodzaju to teraz dotychczasowa (dla wierzchołka "u") długość najdłuższej ścieżki I rodzaju
			
			w2[u] = w1[u]; // dla wierzchołka "u", przykładowy wierzchołek kończący drugą najdłuższą ścieżkę I rodzaju to teraz dotychczasowy (dla wierzchołka "u") wierzchołek kończący najdłuższą ścieżkę I rodzaju
			
			d1[u] = MP( d1[v].ST + 1, v ); // dla wierzchołka "u", długość najdłuższej ścieżki I rodzaju to teraz długość najdłuższej, dla wierzchołka "v", ścieżki I rodzaju, przedłużonej o krawędź z wierzchołka "v" do wierzchołka "u";  dla wierzchołka "u", najdłuższa ścieżka I rodzaju przechodzi teraz przez wierzchołek "v" - syna wierzchołka "u"
			
			w1[u] = w1[v]; // dla wierzchołka "u", przykładowy wierzchołek kończący najdłuższą ścieżkę I rodzaju to teraz przykładowy, dla wierzchołka "v", wierzchołek kończący najdłuższą ścieżkę I rodzaju
		}
		else // najdłuższa, dla wierzchołka "v", ścieżka I rodzaju, przedłużona o krawędź z wierzchołka "v" do wierzchołka "u", nie jest dłuższa niż dotychczasowa najdłuższa, dla wierzchołka "u", ścieżka I rodzaju 
		{
			if( d1[v].ST + 1 > d2[u] ) // jeśli najdłuższa, dla wierzchołka "v", ścieżka I rodzaju, przedłużona o krawędź z wierzchołka "v" do wierzchołka "u", jest dłuższa niż dotychczasowa druga najdłuższa, dla wierzchołka "u", ścieżka I rodzaju  
			{
				d2[u] = d1[v].ST + 1; // dla wierzchołka "u", długość drugiej najdłuższej ścieżki I rodzaju to teraz najdłuższa, dla wierzchołka "v", ścieżka I rodzaju, przedłużona o krawędź z wierzchołka "v" do wierzchołka "u"
				
				w2[u] = w1[v]; // dla wierzchołka "u", przykładowy wierzchołek kończący drugą najdłuższą ścieżkę I rodzaju to teraz przykładowy, dla wierzchołka "v", wierzchołek kończący najdłuższą ścieżkę I rodzaju
			}
		}
		
		// Koniec obliczania, dla wierzchołka "u", tablic "d1", "d2", "w1", "w2"
	}
}


void f2(int u) // ta procedura, dla każdego wierzchołka "u" drzewa, oblicza tablice "d", "w" (pod warunkiem, że wywołamy ją dla korzenia, tzn. wywołamy ją dla argumentu "root")
{
	int r = syn[u].S(), v; // r - liczba synów wierzchołka "u";  v - zmienna pomocnicza (będzie oznaczać określonego syna wierzchołka "u")
	
	REP(i,0,r-1) // dla każdego syna wierzchołka "u"
	{
		v = syn[u][i]; // v - dla wierzchołka "u" drzewa, i-ty syn wierzchołka "u" 
		
		
		
		// Obliczanie, dla wierzchołka "v", tablic "d", "w"
		
		
		// Przypadek 1: idę z wierzchołka "v" do ojca wierzchołka "v" (czyli wierzchołka "u"), potem z wierzchołka "u" w dół drzewa (przez innego, niż wierzchołek "v", syna wierzchołka "u")
			
		if( d1[u].ND != v ) // jeśli przykładowy numer syna wierzchołka "u", przez którego przechodzi, dla wierzchołka "u", najdłuższa ścieżka I rodzaju, jest inny niż wierzchołek "v" - gdy tak rzeczywiście jest, to bierzemy do analizy najdłuższą, dla wierzchołka "u", ścieżkę I rodzaju
		{
			if( 1 + d1[u].ST > d[v].ST ) // jeśli najdłuższa, dla wierzchołka "u", ścieżka I rodzaju, przedłużona o krawędź z wierzchołka "v" do wierzchołka "u" (tak skonstruowana ścieżka jest ścieżką II rodzaju), jest dłuższa niż dotychczasowa najdłuższa, dla wierzchołka "v", ścieżka II rodzaju  
			{
				d[v] = MP( 1 + d1[u].ST, u ); // dla wierzchołka "v", długość najdłuższej ścieżki II rodzaju to teraz najdłuższa, dla wierzchołka "u", ścieżka I rodzaju, przedłużona o krawędź z wierzchołka "v" do wierzchołka "u";  najwyżej położony wierzchołek na najdłuższej (dla wierzchołka "v") ścieżce II rodzaju, to teraz wierzchołek "u" 
				
				w[v] = w1[u]; // dla wierzchołka "v", przykładowy wierzchołek kończący najdłuższą ścieżkę II rodzaju to teraz przykładowy, dla wierzchołka "u", wierzchołek kończący najdłuższą ścieżkę I rodzaju 
			}
		}
		else // jeśli przykładowy syn wierzchołka "u", przez którego przechodzi, dla wierzchołka "u", najdłuższa ścieżka I rodzaju, to dokładnie wierzchołek "v" - w takim wypadku bierzemy do analizy drugą najdłuższą, dla wierzchołka "u", ścieżkę I rodzaju
		{
			if( 1 + d2[u] > d[v].ST ) // jeśli druga najdłuższa, dla wierzchołka "u", ścieżka I rodzaju, przedłużona o krawędź z wierzchołka "v" do wierzchołka "u" (tak skonstruowana ścieżka jest ścieżką II rodzaju), jest dłuższa niż dotychczasowa najdłuższa, dla wierzchołka "v", ścieżka II rodzaju   
			{
				d[v] = MP( 1 + d2[u], u ); // dla wierzchołka "v", długość najdłuższej ścieżki II rodzaju to teraz druga najdłuższa, dla wierzchołka "u", ścieżka I rodzaju, przedłużona o krawędź z wierzchołka "v" do wierzchołka "u";  najwyżej położony wierzchołek na najdłuższej (dla wierzchołka "v") ścieżce II rodzaju, to teraz wierzchołek "u" 
				
				w[v] = w2[u]; // dla "v", przykładowy wierzchołek kończący najdłuższą ścieżkę II rodzaju to teraz przykładowy, dla "u", wierzchołek kończący drugą najdłuższą ścieżkę I rodzaju
			}
		}
		
		// Koniec analizy przypadku 1
		
		
		// Przypadek 2: biorę, przedłużoną o krawędź z wierzchołka "v" do wierzchołka "u", najlepszą ścieżkę II rodzaju dla ojca wierzchołka "v" (czyli, w tym wypadku, wierzchołka "u")
		
		if( u != root  &&  1 + d[u].ST > d[v].ST ) // jeśli wierzchołek "u" nie jest korzeniem drzewa (dla korzenia nie istnieje ścieżka II rodzaju) oraz jeśli najdłuższa, dla wierzchołka "u", ścieżka II rodzaju, przedłużona o krawędź z wierzchołka "v" do wierzchołka "u" (tak skonstruowana ścieżka jest ścieżką II rodzaju), jest dłuższa niż dotychczasowa najdłuższa, dla wierzchołka "v", ścieżka II rodzaju
		{
			d[v] = MP( 1 + d[u].ST, d[u].ND ); // najdłuższa ścieżka II rodzaju, dla wierzchołka "v", to teraz najdłuższa ścieżka II rodzaju dla wierzchołka "u", przedłużona o krawędź z wierzchołka "v" do wierzchołka "u";  najwyżej położony wierzchołek na najdłuższej (dla wierzchołka "v") ścieżce II rodzaju, to teraz najwyżej położony wierzchołek na najdłuższej (dla wierzchołka "u") ścieżce II rodzaju  
			
			w[v] = w[u]; // dla wierzchołka "v", przykładowy, ostatni wierzchołek na najdłuższej ścieżce II rodzaju to teraz, przykładowy, ostatni wierzchołek na najdłuższej ścieżce II rodzaju, dla wierzchołka "u"
		}
		
		// Koniec analizy przypadku 2
		
		
		// Koniec obliczania, dla "v", tablic "d", "w"
		
		
		
		f2( v ); // wywołujemy się rekurencyjnie dla wierzchołka "v"
	}
}


void obliczenia_wstepne() // ta procedura oblicza wszystkie niezbędne wielkości
{
	k = funkcja( n ); // obliczamy wykładnik największej potęgi dwójki, niewiększej niż "n" (po obliczeniu wartości tej zmiennej wiemy, że warto rozważać tylko skoki długości 2^0, 2^1, ... , 2^k)
	
	f1( root ); // wywołujemy procedurę "f1" dla korzenia (dzięki takiemu argumentowi dla tej procedury obliczymy to, o czym powiedziałem w opisie tej funkcji)
	
	f2( root ); // wywołujemy procedurę "f2" dla korzenia (dzięki takiemu argumentowi dla tej procedury obliczymy to, o czym powiedziałem w opisie tej funkcji) 
}


int znajdz(int u, int odl) // znajduję wierzchołek położony w odległości "odl" od wierzchołka "u" (przy czym szukany wierzchołek ma być położony na ścieżce od wierzchołka "u" do korzenia drzewa, oraz ma istnieć)
{
	/* Funkcja ta oprze się na zapisie binarnym liczby "odl" (czyli zapisie liczby "odl" jako suma potęg dwójki o parami różnych, nieujemnych, całkowitych wykładnikach)
	   Liczbę "odl" będziemy w kółko dzielić całkowitoliczbowo przez dwa (dzięki temu wyrzucamy za każdym razem najmłodszy bit "odl"), a wcześniej - sprawdzać, czy aktualnie najmłodszy bit liczby "odl" jest jeden
	   Jeśli aktualna potęga dwójki ( reprezentowana przez wykladnik "ind" ) pojawia się w zapisie binarnym liczby "odl" (czyli aktualnie najmłodszy bit liczby "odl" jest jeden), to będziemy aktualizować odpowiednio nasz wynik
	*/
	
	int ind = 0, wyn = u; // ind - identyfikator/wykładnik związany z aktualną długością skoku ( pod pojęciem "aktualna długość skoku" rozumiem wartość "2^ind" );  wyn - wynik działania funkcji "znajdz" - przybliżeniem początkowym rozwiązania jest wierzchołek "u" (bo na początku nigdzie się z wierzchołka "u" nie ruszyliśmy; jak okaże się, że "odl" == 0, to po prostu zwrócimy "u")
	
	while( odl > 0 ) // dopóki liczba "odl" ma jeszcze jakieś bity do przeanalizowania (tutaj wygodnie jest przyjąć, że liczba zero ma zero cyfr bitowych)
	{
		if( odl % 2 == 1 ) // jeśli aktualnie najmłodszy bit liczby "odl" jest jeden
		{
			wyn = nr[ wyn ][ ind ]; // nowe przybliżenie wyniku to wierzchołek, do jakiego dojdziemy, "skacząc" w górę o "2^ind" z dotychczasowego wierzchołka - starego przybliżenia wyniku
		}
		
		++ind; // przechodzimy do kolejnej potegi dwójki
		
		odl /= 2; // pozbywamy sie aktualnie najmłodszego bitu liczby "odl"
	}
	
	return wyn;
}


int zapytanie(int u, int odl) // dla wierzchołka "u" drzewa, znajduję wierzchołek odległy o "odl" od wierzchołka "u" (jeśli istnieje, to wypisuję jego numer (jak ich jest więcej - wypisuję numer któregokolwiek z nich), ale z zakresu [1..n]), bądź stwierdzam, że takiego w drzewie nie ma
{
	// Przypadek 1 - szukamy wierzchołka w ramach najdłuższej ścieżki I rodzaju
	
	int dmax_I = d1[u].ST; // dmax_I - dla wierzchołka "u", długość najdłuższej ścieżki I rodzaju 
	
	if( dmax_I >= odl ) // jeśli wierzchołek najbardziej oddalony od wierzchołka "u", jest wystarczająco odległy od wierzchołka "u" (równoważnie: jeśli odległość od wierzchołka "u" do wierzchołka najbardziej oddalonego od wierzchołka "u" jest niemniejsza niż wymagana odległość między wierzchołkiem "u" oraz jakimś wierzchołkiem drzewa)
	{
		int v = w1[u]; // wierzchołek "v" jest tym najbardziej oddalonym od wierzchołka "u" wierzchołkiem (jak jest takich wierzchołków więcej, to wierzchołek "v" jest przykładowym takim wierzchołkiem)
		
		return znajdz( v, dmax_I - odl ) + 1; // wierzchołki "u" oraz "v" są odległe o "dmax_I" - zatem jeśli pójdziemy z wierzchołka "v" w górę o 'dmax_I - odl', to osiągniemy żądany wierzchołek;  funkcja "znajdz" zwraca numer wierzchołka z zakresu [0..n-1], natomiast potrzebujemy numeru wierzchołka z zakresu [1..n] - wystarczy więc tylko dodać jedynkę
	}
	
	
	// Przypadek 2 - szukamy wierzchołka w ramach najdłuższej ścieżki II rodzaju
	
	int dmax_II = d[u].ST; // dmax_II - dla wierzchołka "u", długość najdłuższej ścieżki II rodzaju
	
	if( dmax_II >= odl ) // jeśli wierzchołek najbardziej oddalony od wierzchołka "u" jest wystarczająco odległy od wierzchołka "u" (równoważnie: jeśli odległość od wierzchołka "u" do wierzchołka najbardziej oddalonego od wierzchołka "u" jest niemniejsza niż wymagana odległość między wierzchołkiem "u" oraz jakimś wierzchołkiem drzewa)
	{
		int LCA = d[u].ND,    D = depth[u] - depth[ LCA ]; // LCA - wierzchołek (o najmniejszej możliwej głębokości, czyli możliwie najwyżej położony), leżący na najdłuższej ścieżce (II rodzaju) z wierzchołka "u" do jakiegoś wierzchołka ( konkretniej, wierzchołka "w[u]" - wierzchołek "LCA" to najniższy wspólny przodek wierzchołków "u" oraz "w[u]" ( "w[u]" oznacza przykładowy najbardziej oddalony wierzchołek od wierzchołka "u" )  ) drzewa;  D - odległość między wierzchołkami "u" oraz "LCA" (która równa jest głębokości wierzchołka "u", pomniejszonej o głębokość wierzchołka "LCA")
			
		if( D >= odl ) // jeśli odległość między wierzchołkami "u" oraz "LCA" jest niemniejsza niż "odl", czyli żądany wierzchołek jest na ścieżce łączącej wierzchołki "u" oraz "LCA"
		{
			return znajdz( u, odl ) + 1; // żądany wierzchołek jest odległy o "odl" od wierzchołka "u" (z wierzchołka "u" idziemy w górę drzewa);  funkcja "znajdz" zwraca numer wierzchołka z zakresu [0..n-1], natomiast potrzebujemy numeru wierzchołka z zakresu [1..n] - wystarczy więc tylko dodać jedynkę
		}
		else // w takim razie żądany wierzchołek jest na ścieżce łączącej wierzchołek "LCA" oraz wierzchołek najbardziej oddalony od wierzchołka "u"
		{
			int v = w[u]; // przykładowy wierzchołek najbardziej oddalony od wierzchołka "u"
			
			return znajdz( v, dmax_II - odl ) + 1; // idziemy z wierzchołka "u" w górę drzewa na odległość "D" (aż do wierzchołka "LCA"), odległość między wierzchołkami "LCA" oraz "v" to "dmax_II - D", szukany wierzchołek (nazwijmy go "wyn" - nawiasem mówiąc, wierzchołek "wyn" leży na ścieżce łączącej wierzchołki "LCA" oraz "v") ma to do siebie, że odległość między wierzchołkami "wyn" oraz "LCA" to "odl-D" (wtedy odległość między wierzchołkami "u" oraz wyn" to suma odległości między wierzchołkami "u" oraz "LCA" oraz między wierzchołkami "LCA" oraz "wyn", czyli D + (odl-D) = odl), tak więc z wierzchołka "v" do wierzchołka "wyn" idziemy w górę o (dmax_II-D)-(odl-D) = dmax_II-odl (od odległości między wierzchołkami "v" oraz "LCA", odjąłem odległość między wierzchołkami "wyn" oraz "LCA)
		}
	}
	
	
	// Nie istnieje wierzchołek odległy o "odl" od wierzchołka "u"
	
	return -1;
}


void obsluz_zapytania() // ta procedura odpowiada za obsługę zapytań (czyli ta procedura odpowiada za odpowiadanie na kolejne zapytania) 
{
	scanf( "%d", &q ); // wczytujemy liczbę zapytań "q"
	
	int u, odl; // zmienne pomocnicze: u - wierzchołek, z którego ruszamy;  odl - wymagana odległość z wierzchołka "u" do pewnego wierzchołka drzewa (tego pewnego wierzchołka drzewa szukamy) (odległość jest liczona w liczbie krawędzi na ścieżce między wierzchołkami)
		
	while( q > 0 ) // dopóki mamy jeszcze do obsłużenia jakieś zapytania (czyli dopóki liczba pozostałych do obsłużenia zapytań jest dodatnia)
	{
		scanf( "%d %d", &u, &odl ); // wczytujemy zmienne "u", "odl"
		
		printf( "%d\n", zapytanie( --u, odl ) ); // wypisujemy przykładowy wierzchołek oddalony od wierzchołka "u" o "odl" (lub -1, jeśli takowy wierzchołek nie istnieje);  zapisałem --u (czyli odjąłem jedynkę od "u"), bo funkcja "zapytanie" potrzebuje numeru wierzchołka z zakresu [0..n-1] ( w zapytaniach dostajemy numer wierzchołka z zakresu [1..n] )
		
		--q; // obsłużyliśmy właśnie kolejne zapytanie, więc liczba zapytań pozostałych do obsłużenia zmalała o jeden
	}
}


int main() // funkcja głowna całego programu - tutaj wykonywane jest całe zadanie
{
	inicjuj_struktury_danych(); // nasze struktury danych inicjujemy odpowiednimi wielkościami (tj. przypisujemy tym strukturom danych odpowiednie wartości początkowe)
	
	wczytaj_dane(); // wczytujemy opis drzewa
	
	obliczenia_wstepne(); // obliczamy niezbędne wielkości
	
	obsluz_zapytania(); // odpowiadamy na zapytania
	
	return 0;
}