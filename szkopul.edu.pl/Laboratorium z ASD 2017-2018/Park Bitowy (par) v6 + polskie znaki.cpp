/*

W tym zadaniu, dla danego drzewa, mamy odpowiada� na wiele zapyta� takiej postaci:
poda� przyk�ad wierzcho�ka oddalonego od zadanego wierzcho�ka "u" o zadan� odled�o�� "odl", b�d� stwierdzi�, �e takowy wierzcho�ek w drzewie nie istnieje



Za�o�enia:

1) W obliczeniach nie zak�ada�em, �e drzewo jest binarne (tylko za�o�enia zadania oraz format danych wej�ciowych to wymusza�y)

2) W strukturze "syn" mam tylko listy syn�w (tzn. dla dowolnego wierzcho�ka drzewa "u", w wektorze "syn[u]" nie kryje si� ojciec wierzcho�ka "u") - wynika to z tego, jak wygl�daj� dane wej�ciowe (nawiasem m�wi�c, taki format danych wej�ciowych sprawi�, �e kod by� nieco �atwiejszy - np. nie trzeba by�o si� ci�gle pilnowa�, czy oby na pewno rozwa�amy syna jakiego� wierzcho�ka, czy nie)

3) W programie (tj. w strukturach danych, w procesie oblicze�) numeruj� wierzcho�ki od zera - oczywi�cie, na wej�ciu i na wyj�ciu numeracja jest od jedynki, ale to nie problem doda� lub odj�� w danym momencie jedynk�

4) Drzewo jest nieskierowane (czyli kraw�dziami drzewa mo�na chodzi� w obie strony)

5) Poj�cie " wierzcho�ek o numerze "u" " znaczy to samo, co " wierzcho�ek "u" "



Definicje:

Def. 1. Dla dowolnego, ustalonego wierzcho�ka "u" drzewa, najd�u�sza �cie�ka I rodzaju to najd�u�sza �cie�ka wychodz�ca z wierzcho�ka "u", znajduj�ca si� w poddrzewie wierzcho�ka "u"

Def. 2. Dla dowolnego, ustalonego wierzcho�ka "u" drzewa, najd�u�sza �cie�ka II rodzaju to najd�u�sza �cie�ka wychodz�ca z wierzcho�ka "u", id�ca w g�r� drzewa (a� do pewnego wierzcho�ka "x", znajduj�cego si� na �cie�ce od wierzcho�ka "u" do korzenia), a nast�pnie id�ca od wierzcho�ka "x" w d� drzewa (oczywi�cie nie mo�emy i�� w d� przez takiego syna wierzcho�ka "x", w kt�rego poddrzewie jest wierzcho�ek "u")

Def. 3. Dla dowolnych, ustalonych wierzcho�k�w "u", "v" drzewa, odleg�o�� mi�dzy tymi wierzcho�kami to liczba kraw�dzi na �cie�ce ��cz�cej te wierzcho�ki

Def. 4. Dla wierzcho�ka "u" drzewa, przodek wierzcho�ka "u" to wierzcho�ek le��cy na �cie�ce od wierzcho�ka "u" do korzenia drzewa (nie licz�c wierzcho�ka "u") - w szczeg�lno�ci, gdy ruszamy z wierzcho�ka "u" w stron� korzenia, to pierwszy napotkany przodek to ojciec wierzcho�ka "u"

Def. 5. Dla wierzcho�ka "u" drzewa, poddrzewo wierzcho�ka "u" to wierzcho�ek "u" oraz wszystkie wierzcho�ki drzewa, dla kt�rych wierzho�ek "u" jest ich przodkiem

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


const int MAX_N = 500000, MAX_K = 18; // MAX_N - maksymalna ilo�� wierzcho�k�w w drzewie, MAX_K - maksymalne takie 'x' (ca�kowite nieujemne), �e 2^x <= MAX_N


VI syn[MAX_N]; // dla ka�dego wierzcho�ka "u" w drzewie, trzymam wektor syn�w wierzcho�ka "u"


// Uwaga ( dla struktur "d1" oraz "d2" ). Je�li dla wierzcho�ka "u" s� co najmniej 2 najd�u�sze �cie�ki I rodzaju, to jedna z nich jest opisana przez d1[u], natomiast druga - przez d2[u];  dla wierzcho�ka u", jak co najmniej 2 �cie�ki s� pod wzgl�dem d�ugo�ci na 2. miejscu, to pami�tamy kt�r�� z nich (tylko jedn�)
                                         
PII d1[MAX_N]; // dla ka�dego wierzcho�ka "u" drzewa, d1[u] oznacza par� postaci (d�ugo�� najd�u�szej �cie�ki w poddrzewie wierzcho�ka "u", wychodz�cej z wierzcho�ka "u" ; numer syna wierzcho�ka "u", przez kt�rego ta �cie�ka przechodzi)

int d2[MAX_N]; // dla ka�dego wierzcho�ka "u" drzewa, d2[u] oznacza d�ugo�� drugiej najd�u�szej �cie�ki w poddrzewie wierzcho�ka "u", wychodz�cej z wierzcho�ka "u" ( oczywi�cie ta �cie�ka musi przechodzi� przez innego syna wierzcho�ka "u", ni� �cie�ka najd�u�sza, czyli zwi�zana z warto�ci� d1[u] )


PII d[MAX_N]; // dla ka�dego wierzcho�ka "u" drzewa, d[u] oznacza par� postaci (d�ugo�� najd�u�szej �cie�ki wychodz�cej z wierzcho�ka "u", id�cej w g�r� a� do jakiego� wierzcho�ka "x", a potem (o ile to mo�liwe) schodz�cej w d� (oczywi�cie to schodzenie musi przechodzi� przez takiego syna wierzcho�ka "x", w kt�rego poddrzewie nie ma wierzcho�ka "u") ; przyk�adowy numer wierzcho�ka "x" z opisu pierwszego elementu tej pary)

int w1[MAX_N], w2[MAX_N], w[MAX_N]; // dla ka�dego wierzcho�ka "u" drzewa:  w1[u] - przyk�adowy numer wierzcho�ka ko�cz�cego �cie�k� zwi�zan� z warto�ci� d1[u];  w2[u] - przyk�adowy numer wierzcho�ka ko�cz�cego �cie�k� zwi�zan� z warto�ci� d2[u];  w[u] - przyk�adowy numer wierzcho�ka ko�cz�cego �cie�k� zwi�zan� z warto�ci� d[u] - oczywi�cie warto�ci d[u].ND oraz w[u] (o ile te warto�ci istniej�) s� ze sob� zwi�zane - w[u] ( o ile w[u] != d[u].ND ) le�y w poddrzewie pewnego syna wierzcho�ka "d[u].ND", jednak wierzcho�ek "u" le�y w poddrzewie pewnego innego syna wierzcho�ka "d[u].ND" 

int q, n, k, root = 0; // q - liczba zapyta�;  n - liczba wierzcho�k�w drzewa;  k = max y: { y - ca�kowite nieujemne oraz 2^y <= n };  root - korze� drzewa ( numeracja z zakresu [0..n-1] )

int depth[MAX_N]; // dla ka�dego wierzcho�ka "u" drzewa, depth[u] oznacza g��boko�� wierzcho�ka "u" w drzewie (innymi s�owy, odleg�o�� mi�dzy wierzcho�kiem "u" oraz korzeniem)

int nr[MAX_N][MAX_K+1]; // dla ka�dego wierzcho�ka "u" drzewa, nr[u][j] oznacza przodka wierzcho�ka "u", oddalonego od wierzcho�ka "u" o warto�� 2^j, lub "-1", gdy takowy wierzcho�ek nie istnieje - czyli, intuicyjnie, do jakiego wierzcho�ka dojdziemy, je�li z wierzcho�ka "u" wykonamy w g�r� drzewa skok d�ugo�ci 2^j


int max(int a, int b) // wi�ksza z liczb ca�kowitych "a" oraz "b"
{
	return ( a > b ) ? a : b ; // je�li warunek ( a > b ) jest prawdziwy ( czyli zachodzi a > b ), to zwracamy "a", w przeciwnym razie ( czyli zachodzi a <= b ) zwracamy "b"
}


int funkcja(int x) // x - liczba naturalna dodatnia;  wynikiem jest exp = max y: { y - ca�kowite nieujemne oraz 2^y <= x }
{
	// Niezmiennik p�tli "while": 2^exp = tmp (czyli tu� przed wej�ciem do tej p�tli to zachodzi, pod sam koniec ka�dego obrotu tej p�tli to zachodzi oraz tu� po wyj�ciu z tej p�tli to zachodzi)
	
	int tmp = 1, exp = 0; // tmp - aktualna pot�ga dw�jki;  exp - aktualny wyk�adnik, dla aktualnej pot�gi dw�jki "tmp"
	
	while( tmp <= x ) // dop�ki aktualna pot�ga dw�jki nie przekracza liczby "x"
	{
		tmp *= 2; // przechodzimy do kolejnej, wi�kszej pot�gi dw�jki
		
		++exp; // przej�cie do kolejnej, wi�kszej pot�gi dw�jki, oznacza zwi�kszenie wyk�adnika o jeden
	}
	
	return --exp; // odejmuj� jedynk� od zmiennej "exp", bo po wyj�ciu z p�tli "while", zmienna "exp" oznacza wyk�adnik najmniejszej pot�gi dw�jki, wi�kszej ni� "x" - tak wi�c odj�cie jedynki od zmiennej "exp" sprawia, �e mamy wyk�adnik dla pot�gi dw�jki niewi�kszej ni� "x", ale mo�liwie najwi�kszej (samej pot�gi dw�jki "tmp" nie musimy dzieli� przez 2, bo nie ma takiej potrzeby)
}


void inicjuj_struktury_danych() // dla ka�dego wierzcho�ka drzewa "u", okre�lam warto�ci pocz�tkowe pewnych struktur danych
{
	REP(u,0,MAX_N-1) // dla ka�dego potencjalnego wierzcho�ka drzewa (wierzcho�k�w mo�e by� nawet MAX_N)
	{
		d1[u] = MP( 0, -1 ); // pocz�tkowo zak�adamy, �e �cie�ki, okre�lone tablic� "d1", maj� zerow� d�ugo�� (skoro tak, to nie przechodz� one przez �adnych syn�w)
		
		d2[u] = 0; // pocz�tkowo zak�adamy, �e �cie�ki, okre�lone tablic� "d2", maj� zerow� d�ugo��
		
		d[u] = MP( 0, -1 ); // pocz�tkowo zak�adamy, �e �cie�ki, okre�lone tablic� "d", maj� zerow� d�ugo�� (skoro tak, to nie przechodz� one przez �adne wierzcho�ki po�o�one wy�ej w stosunku do konkretnych wierzcho�k�w "u", dla kt�rych liczymy tablic� "d")
		
		w[u] = -1; // skoro pocz�tkowe przybli�enie d�ugo�ci �cie�ki ( zwi�zanej z warto�ci� d[u] ) jest zerem, to ta �cie�ka nie mo�e ko�czy� si� w �adnym wierzcho�ku drzewa (no bo trzeba by p�j�� co najmniej jedn� kraw�dzi� w g�r�, a potem (o ile to mo�liwe) gdzie� w d� drzewa - wynika to z tego, jakiego rodzaju �cie�ki s� opisane w tablicy "d" - patrz opis tablicy "d")
		
		w1[u] = w2[u] = u; // skoro pocz�tkowe przybli�enia d�ugo�ci �cie�ek ( zwi�zanych z warto�ciami d1[u] oraz d2[u] ) s� zerami, to te �cie�ki ko�cz� si� (jak r�wnie� rozpoczynaj� si�) w wierzcho�ku "u" - w razie w�tpliwo�ci, patrz opis tablic "d1" oraz "d2"
		
		REP(j,0,MAX_K) // dla ka�dej potencjalnej d�ugo�ci skoku r�wnej 2^j
		{
			nr[u][j] = -1; // pocz�tkowo nie istnieje przodek oddalony od wierzcho�ka "u" o "2^j"
		}
	}
}


void wczytaj_dane() // wczytuj� dane wej�ciowe odno�nie drzewa - zapytania wczytywane b�d� w procedurze "obsluz_zapytania"
{
	scanf( "%d", &n ); // wczytujemy liczb� wierzcho�k�w drzewa
	
	int v1, v2; // zmienne pomocnicze - w tych zmiennych, dla ka�dego wierzcho�ka drzewa "u", trzymam numery potencjalnych syn�w wierzcho�ka "u"
	
	REP(u,0,n-1) // dla ka�dego wierzcho�ka drzewa "u"
	{
		scanf( "%d %d", &v1, &v2 ); // wczytujemy numery potencjalnych syn�w wierzcho�ka "u"
		
		if( v1 != -1 ) // je�li, dla wierzcho�ka "u", istnieje syn o numerze "v1"
		{
			--v1; // odejmuj� jedynk�, �eby by� w zakresie [0..n-1] ( w danych wej�ciowych wierzcho�ki maj� numery z zakresu [1..n] ) 
			
			syn[u].PB( v1 ); // dorzucam, do listy syn�w wierzcho�ka "u", wierzcho�ek "v1"
		}
		
		if( v2 != -1 ) // je�li, dla wierzcho�ka "u", istnieje syn o numerze "v2"
		{
			--v2; // odejmuj� jedynk�, �eby by� w zakresie [0..n-1] ( w danych wej�ciowych wierzcho�ki maj� numery z zakresu [1..n] )
			
			syn[u].PB( v2 ); // dorzucam, do listy syn�w wierzcho�ka "u", wierzcho�ek "v2"
		}
	}
}


void f1(int u) // ta procedura, dla ka�dego wierzcho�ka "u" drzewa, oblicza tablice "nr", "d1", "d2", "w1", "w2", "depth" (pod warunkiem, �e wywo�amy j� dla korzenia, tzn. wywo�amy j� dla argumentu "root")
{
	int r = syn[u].S(), v, ww; // r - liczba syn�w wierzcho�ka "u";  v, ww - zmienne pomocnicze (b�d� one oznacza� numery wierzcho�k�w; mo�e lepiej by�oby da� nazw� "w" zamiast "ww", jednak mamy ju� globaln� tablic� o nazwie "w")
	
	REP(i,0,r-1) // dla ka�dego syna wierzcho�ka "u"
	{
		v = syn[u][i]; // wierzcho�ek "v" to i-ty syn na li�cie syn�w wierzcho�ka "u"
		
		depth[v] = depth[u] + 1; // znaj�c g��boko�� ojca (w naszym wypadku ojcem jest wierzcho�ek "u"), �atwo liczymy g��boko�� dla jego syna (w naszym wypadku synem jest wierzcho�ek "v") - g��boko�� dla syna to g��boko�� dla ojca, powi�kszona o jeden ( by doj�� z korzenia do wierzcho�ka "v", napierw idziemy z korzenia do wierzcho�ka "u" (odleg�o�� mi�dzy wierzcho�kiem "u" oraz korzeniem to "depth[u]"), potem idziemy jeszcze kraw�dzi� z ojca (w tym przypadku, wierzcho�ka "u") do syna (w tym przypadku, wierzcho�ka "v") (odleg�o�� mi�dzy wierzcho�kiem "u" oraz wierzcho�kiem "v" to jeden - wierzcho�ki "u" oraz "v" s� bezpo�rednio po��czone kraw�dzi�) ) 
		
		
		
		// Wyznaczanie, dla wierzcho�ka "v" drzewa, tablicy "nr"
		
		// Uwaga. Tablic� "nr" b�dziemy obliczali od g�ry do do�u drzewa, tzn. je�li chcemy liczy� t� tablic� dla jakiego� wierzcho�ka "v" drzewa, to wcze�niej musimy obliczy� tablic� "nr" dla wszystkich przodk�w wierzcho�ka "v" (tj. wszystkich, poza wierzcho�kiem "v", wierzcho�k�w na �cie�ce od wierzcho�ka "v" do korzenia)
		
		nr[v][0] = u; // wierzcho�ek "u" to wierzcho�ek oddalony o 2^0 od wierzcho�ka "v" 
	
		REP(j,1,k) // dla ka�dej, poza d�ugo�ci� skoku r�wn� 2^0, mo�liwej d�ugo�ci skoku (tzn. d�ugo�ci 2^j - d�ugo�� skoku reprezentuj� za pomoc� wyk�adnika dla pot�gi dw�jki r�wnej 2^j)
		{
			// Tutaj skorzystamy z takiego faktu: �eby p�j�� z jakiego� wierzcho�ka "v" drzewa o "2^j" w g�r� drzewa, to mo�emy najpierw p�j�� z wierzcho�ka "v" o "2^(j-1)" w g�r� drzewa (do wierzcho�ka, nazwijmy go, "ww"), a potem, z wierzcho�ka "ww" o "2^j-1" w g�r� drzewa
			
			ww = nr[v][ j - 1 ]; // wierzcho�ek "ww" jest oddalony od wierzcho�ka "v" o "2^(j-1)" (idziemy z wierzcho�ka "v" w g�r� drzewa, wi�c je�li wierzcho�ek "ww" istnieje, to jest wyznaczony jednoznacznie - w g�r� drzewa mo�emy i�� tylko na jeden spos�b)
	
			if( ww == -1 ) // je�li ��dany wierzcho�ek "ww" nie istnieje
			{
				nr[v][j] = -1; // m�wimy, �e nie istnieje wierzcho�ek odleg�y o "2^j" od wierzcho�ka "v" (idziemy z wierzcho�ka "v" w g�r� drzewa)
			}
			else
			{
				nr[v][j] = nr[ ww ][ j - 1 ]; // wierzcho�ek odleg�y o "2^j" od wierzcho�ka "v" to wierzcho�ek odleg�y o "2^j-1" od wierzcho�ka "ww" (je�li wierzcho�ek odleg�y o "2^j-1" od wierzcho�ka "ww" nie istnieje, to nie istnieje r�wnie� wierzcho�ek odleg�y o "2^j" od wierzcho�ka "v";  w takim wypadku warto�� "nr[ ww ][ j - 1 ]" wynosi "-1" - skoro wi�c robimy przypisanie "nr[v][j] = nr[ ww ][ j - 1 ]", to warto�� "nr[v][j]" wynosi "-1", czyli to, co trzeba)
			}
		}
		
		// Koniec wyznaczania tablicy "nr"
		
		
		
		f1( v ); // wywo�ujemy si� rekurencyjnie dla wierzcho�ka "v" drzewa
		
		
		
		// Obliczanie, dla wierzcho�ka "u", tablic "d1", "d2", "w1", "w2"
		
		if( d1[v].ST + 1 > d1[u].ST ) // je�li najd�u�sza, dla wierzcho�ka "v", �cie�ka I rodzaju, przed�u�ona o kraw�d� z wierzcho�ka "v" do wierzcho�ka "u", jest d�u�sza ni� dotychczasowa najd�u�sza, dla wierzcho�ka "u", �cie�ka I rodzaju 
		{
			d2[u] = d1[u].ST; // dla wierzcho�ka "u", d�ugo�� drugiej najd�u�szej �cie�ki I rodzaju to teraz dotychczasowa (dla wierzcho�ka "u") d�ugo�� najd�u�szej �cie�ki I rodzaju
			
			w2[u] = w1[u]; // dla wierzcho�ka "u", przyk�adowy wierzcho�ek ko�cz�cy drug� najd�u�sz� �cie�k� I rodzaju to teraz dotychczasowy (dla wierzcho�ka "u") wierzcho�ek ko�cz�cy najd�u�sz� �cie�k� I rodzaju
			
			d1[u] = MP( d1[v].ST + 1, v ); // dla wierzcho�ka "u", d�ugo�� najd�u�szej �cie�ki I rodzaju to teraz d�ugo�� najd�u�szej, dla wierzcho�ka "v", �cie�ki I rodzaju, przed�u�onej o kraw�d� z wierzcho�ka "v" do wierzcho�ka "u";  dla wierzcho�ka "u", najd�u�sza �cie�ka I rodzaju przechodzi teraz przez wierzcho�ek "v" - syna wierzcho�ka "u"
			
			w1[u] = w1[v]; // dla wierzcho�ka "u", przyk�adowy wierzcho�ek ko�cz�cy najd�u�sz� �cie�k� I rodzaju to teraz przyk�adowy, dla wierzcho�ka "v", wierzcho�ek ko�cz�cy najd�u�sz� �cie�k� I rodzaju
		}
		else // najd�u�sza, dla wierzcho�ka "v", �cie�ka I rodzaju, przed�u�ona o kraw�d� z wierzcho�ka "v" do wierzcho�ka "u", nie jest d�u�sza ni� dotychczasowa najd�u�sza, dla wierzcho�ka "u", �cie�ka I rodzaju 
		{
			if( d1[v].ST + 1 > d2[u] ) // je�li najd�u�sza, dla wierzcho�ka "v", �cie�ka I rodzaju, przed�u�ona o kraw�d� z wierzcho�ka "v" do wierzcho�ka "u", jest d�u�sza ni� dotychczasowa druga najd�u�sza, dla wierzcho�ka "u", �cie�ka I rodzaju  
			{
				d2[u] = d1[v].ST + 1; // dla wierzcho�ka "u", d�ugo�� drugiej najd�u�szej �cie�ki I rodzaju to teraz najd�u�sza, dla wierzcho�ka "v", �cie�ka I rodzaju, przed�u�ona o kraw�d� z wierzcho�ka "v" do wierzcho�ka "u"
				
				w2[u] = w1[v]; // dla wierzcho�ka "u", przyk�adowy wierzcho�ek ko�cz�cy drug� najd�u�sz� �cie�k� I rodzaju to teraz przyk�adowy, dla wierzcho�ka "v", wierzcho�ek ko�cz�cy najd�u�sz� �cie�k� I rodzaju
			}
		}
		
		// Koniec obliczania, dla wierzcho�ka "u", tablic "d1", "d2", "w1", "w2"
	}
}


void f2(int u) // ta procedura, dla ka�dego wierzcho�ka "u" drzewa, oblicza tablice "d", "w" (pod warunkiem, �e wywo�amy j� dla korzenia, tzn. wywo�amy j� dla argumentu "root")
{
	int r = syn[u].S(), v; // r - liczba syn�w wierzcho�ka "u";  v - zmienna pomocnicza (b�dzie oznacza� okre�lonego syna wierzcho�ka "u")
	
	REP(i,0,r-1) // dla ka�dego syna wierzcho�ka "u"
	{
		v = syn[u][i]; // v - dla wierzcho�ka "u" drzewa, i-ty syn wierzcho�ka "u" 
		
		
		
		// Obliczanie, dla wierzcho�ka "v", tablic "d", "w"
		
		
		// Przypadek 1: id� z wierzcho�ka "v" do ojca wierzcho�ka "v" (czyli wierzcho�ka "u"), potem z wierzcho�ka "u" w d� drzewa (przez innego, ni� wierzcho�ek "v", syna wierzcho�ka "u")
			
		if( d1[u].ND != v ) // je�li przyk�adowy numer syna wierzcho�ka "u", przez kt�rego przechodzi, dla wierzcho�ka "u", najd�u�sza �cie�ka I rodzaju, jest inny ni� wierzcho�ek "v" - gdy tak rzeczywi�cie jest, to bierzemy do analizy najd�u�sz�, dla wierzcho�ka "u", �cie�k� I rodzaju (przypadek, gdzie "d1[u].ND" wynosi "-1", nie stwarza problem�w)
		{
			if( 1 + d1[u].ST > d[v].ST ) // je�li najd�u�sza, dla wierzcho�ka "u", �cie�ka I rodzaju, przed�u�ona o kraw�d� z wierzcho�ka "v" do wierzcho�ka "u" (tak skonstruowana �cie�ka jest �cie�k� II rodzaju), jest d�u�sza ni� dotychczasowa najd�u�sza, dla wierzcho�ka "v", �cie�ka II rodzaju  
			{
				d[v] = MP( 1 + d1[u].ST, u ); // dla wierzcho�ka "v", d�ugo�� najd�u�szej �cie�ki II rodzaju to teraz najd�u�sza, dla wierzcho�ka "u", �cie�ka I rodzaju, przed�u�ona o kraw�d� z wierzcho�ka "v" do wierzcho�ka "u";  najwy�ej po�o�ony wierzcho�ek na najd�u�szej (dla wierzcho�ka "v") �cie�ce II rodzaju, to teraz wierzcho�ek "u" 
				
				w[v] = w1[u]; // dla wierzcho�ka "v", przyk�adowy wierzcho�ek ko�cz�cy najd�u�sz� �cie�k� II rodzaju to teraz przyk�adowy, dla wierzcho�ka "u", wierzcho�ek ko�cz�cy najd�u�sz� �cie�k� I rodzaju 
			}
		}
		else // je�li przyk�adowy syn wierzcho�ka "u", przez kt�rego przechodzi, dla wierzcho�ka "u", najd�u�sza �cie�ka I rodzaju, to dok�adnie wierzcho�ek "v" - w takim wypadku bierzemy do analizy drug� najd�u�sz�, dla wierzcho�ka "u", �cie�k� I rodzaju
		{
			if( 1 + d2[u] > d[v].ST ) // je�li druga najd�u�sza, dla wierzcho�ka "u", �cie�ka I rodzaju, przed�u�ona o kraw�d� z wierzcho�ka "v" do wierzcho�ka "u" (tak skonstruowana �cie�ka jest �cie�k� II rodzaju), jest d�u�sza ni� dotychczasowa najd�u�sza, dla wierzcho�ka "v", �cie�ka II rodzaju   
			{
				d[v] = MP( 1 + d2[u], u ); // dla wierzcho�ka "v", d�ugo�� najd�u�szej �cie�ki II rodzaju to teraz druga najd�u�sza, dla wierzcho�ka "u", �cie�ka I rodzaju, przed�u�ona o kraw�d� z wierzcho�ka "v" do wierzcho�ka "u";  najwy�ej po�o�ony wierzcho�ek na najd�u�szej (dla wierzcho�ka "v") �cie�ce II rodzaju, to teraz wierzcho�ek "u" 
				
				w[v] = w2[u]; // dla "v", przyk�adowy wierzcho�ek ko�cz�cy najd�u�sz� �cie�k� II rodzaju to teraz przyk�adowy, dla "u", wierzcho�ek ko�cz�cy drug� najd�u�sz� �cie�k� I rodzaju
			}
		}
		
		// Koniec analizy przypadku 1
		
		
		// Przypadek 2: bior�, przed�u�on� o kraw�d� z wierzcho�ka "v" do wierzcho�ka "u", najlepsz� �cie�k� II rodzaju dla ojca wierzcho�ka "v" (czyli, w tym wypadku, wierzcho�ka "u")
		
		if( u != root  &&  1 + d[u].ST > d[v].ST ) // je�li wierzcho�ek "u" nie jest korzeniem drzewa (dla korzenia nie istnieje �cie�ka II rodzaju) oraz je�li najd�u�sza, dla wierzcho�ka "u", �cie�ka II rodzaju, przed�u�ona o kraw�d� z wierzcho�ka "v" do wierzcho�ka "u" (tak skonstruowana �cie�ka jest �cie�k� II rodzaju), jest d�u�sza ni� dotychczasowa najd�u�sza, dla wierzcho�ka "v", �cie�ka II rodzaju
		{
			d[v] = MP( 1 + d[u].ST, d[u].ND ); // najd�u�sza �cie�ka II rodzaju, dla wierzcho�ka "v", to teraz najd�u�sza �cie�ka II rodzaju dla wierzcho�ka "u", przed�u�ona o kraw�d� z wierzcho�ka "v" do wierzcho�ka "u";  najwy�ej po�o�ony wierzcho�ek na najd�u�szej (dla wierzcho�ka "v") �cie�ce II rodzaju, to teraz najwy�ej po�o�ony wierzcho�ek na najd�u�szej (dla wierzcho�ka "u") �cie�ce II rodzaju  
			
			w[v] = w[u]; // dla wierzcho�ka "v", przyk�adowy, ostatni wierzcho�ek na najd�u�szej �cie�ce II rodzaju to teraz, przyk�adowy, ostatni wierzcho�ek na najd�u�szej �cie�ce II rodzaju, dla wierzcho�ka "u"
		}
		
		// Koniec analizy przypadku 2
		
		
		// Koniec obliczania, dla "v", tablic "d", "w"
		
		
		
		f2( v ); // wywo�ujemy si� rekurencyjnie dla wierzcho�ka "v"
	}
}


void obliczenia_wstepne() // ta procedura oblicza wszystkie niezb�dne wielko�ci
{
	k = funkcja( n ); // obliczamy wyk�adnik najwi�kszej pot�gi dw�jki, niewi�kszej ni� "n" (po obliczeniu warto�ci tej zmiennej wiemy, �e warto rozwa�a� tylko skoki d�ugo�ci 2^0, 2^1, ... , 2^k)
	
	f1( root ); // wywo�ujemy procedur� "f1" dla korzenia (dzi�ki takiemu argumentowi dla tej procedury obliczymy to, o czym powiedzia�em w opisie tej funkcji)
	
	f2( root ); // wywo�ujemy procedur� "f2" dla korzenia (dzi�ki takiemu argumentowi dla tej procedury obliczymy to, o czym powiedzia�em w opisie tej funkcji) 
}


int znajdz(int u, int odl) // znajduj� wierzcho�ek po�o�ony w odleg�o�ci "odl" od wierzcho�ka "u" (przy czym szukany wierzcho�ek ma by� po�o�ony na �cie�ce od wierzcho�ka "u" do korzenia drzewa, oraz ma istnie�)
{
	/* Funkcja ta oprze si� na zapisie binarnym liczby "odl" (czyli zapisie liczby "odl" jako suma pot�g dw�jki o parami r�nych, nieujemnych, ca�kowitych wyk�adnikach)
	   Liczb� "odl" b�dziemy w k�ko dzieli� ca�kowitoliczbowo przez dwa (dzi�ki temu wyrzucamy za ka�dym razem najm�odszy bit "odl"), a wcze�niej - sprawdza�, czy aktualnie najm�odszy bit liczby "odl" jest jeden
	   Je�li aktualna pot�ga dw�jki ( reprezentowana przez wykladnik "ind" ) pojawia si� w zapisie binarnym liczby "odl" (czyli aktualnie najm�odszy bit liczby "odl" jest jeden), to b�dziemy aktualizowa� odpowiednio nasz wynik
	*/
	
	int ind = 0, wyn = u; // ind - identyfikator/wyk�adnik zwi�zany z aktualn� d�ugo�ci� skoku ( pod poj�ciem "aktualna d�ugo�� skoku" rozumiem warto�� "2^ind" );  wyn - wynik dzia�ania funkcji "znajdz" - przybli�eniem pocz�tkowym rozwi�zania jest wierzcho�ek "u" (bo na pocz�tku nigdzie si� z wierzcho�ka "u" nie ruszyli�my; jak oka�e si�, �e "odl" == 0, to po prostu zwr�cimy "u")
	
	while( odl > 0 ) // dop�ki liczba "odl" ma jeszcze jakie� bity do przeanalizowania (tutaj wygodnie jest przyj��, �e liczba zero ma zero cyfr bitowych)
	{
		if( odl % 2 == 1 ) // je�li aktualnie najm�odszy bit liczby "odl" jest jeden
		{
			wyn = nr[ wyn ][ ind ]; // nowe przybli�enie wyniku to wierzcho�ek, do jakiego dojdziemy, "skacz�c" w g�r� o "2^ind" z dotychczasowego wierzcho�ka - starego przybli�enia wyniku
		}
		
		++ind; // przechodzimy do kolejnej potegi dw�jki
		
		odl /= 2; // pozbywamy sie aktualnie najm�odszego bitu liczby "odl"
	}
	
	return wyn;
}


int zapytanie(int u, int odl) // dla wierzcho�ka "u" drzewa, znajduj� wierzcho�ek odleg�y o "odl" od wierzcho�ka "u" (je�li istnieje, to wypisuj� jego numer (jak ich jest wi�cej - wypisuj� numer kt�regokolwiek z nich), ale z zakresu [1..n]), b�d� stwierdzam, �e takiego w drzewie nie ma
{
	// Przypadek 1 - szukamy wierzcho�ka w ramach najd�u�szej �cie�ki I rodzaju
	
	int dmax_I = d1[u].ST; // dmax_I - dla wierzcho�ka "u", d�ugo�� najd�u�szej �cie�ki I rodzaju 
	
	if( dmax_I >= odl ) // je�li wierzcho�ek najbardziej oddalony od wierzcho�ka "u", jest wystarczaj�co odleg�y od wierzcho�ka "u" (r�wnowa�nie: je�li odleg�o�� od wierzcho�ka "u" do wierzcho�ka najbardziej oddalonego od wierzcho�ka "u" jest niemniejsza ni� wymagana odleg�o�� mi�dzy wierzcho�kiem "u" oraz jakim� wierzcho�kiem drzewa)
	{
		int v = w1[u]; // wierzcho�ek "v" jest tym najbardziej oddalonym od wierzcho�ka "u" wierzcho�kiem (jak jest takich wierzcho�k�w wi�cej, to wierzcho�ek "v" jest przyk�adowym takim wierzcho�kiem)
		
		return znajdz( v, dmax_I - odl ) + 1; // wierzcho�ki "u" oraz "v" s� odleg�e o "dmax_I" - zatem je�li p�jdziemy z wierzcho�ka "v" w g�r� o 'dmax_I - odl', to osi�gniemy ��dany wierzcho�ek;  funkcja "znajdz" zwraca numer wierzcho�ka z zakresu [0..n-1], natomiast potrzebujemy numeru wierzcho�ka z zakresu [1..n] - wystarczy wi�c tylko doda� jedynk�
	}
	
	
	// Przypadek 2 - szukamy wierzcho�ka w ramach najd�u�szej �cie�ki II rodzaju
	
	int dmax_II = d[u].ST; // dmax_II - dla wierzcho�ka "u", d�ugo�� najd�u�szej �cie�ki II rodzaju
	
	
	// Uwaga. Warunek w poni�szym "if-ie" nigdy si� nie wykona, gdy u - korze� drzewa (warto�� "dmax_II" wynosi wtedy zero, wi�c �eby warunek tego "if-a" by� spe�niony, to musi by� "odl" r�wne zero (bo zawsze zadajemy nieujemn� warto�� "odl") - skoro tak, to wiedz�c, �e warto�� "dmax_I" jest zawsze nieujemna, to wykona si� "if" z Przypadku 1 tej funkcji) - skoro tak, to unikniemy sytuacji, �e b�dziemy mie� warto�� "LCA" r�wn� "-1", a potem bedziemy chcieli mie� warto�� "depth[ LCA ]" ( odwo�anie si� do nieistniej�cego indeksu w tablicy "depth" )
	
	if( dmax_II >= odl ) // je�li wierzcho�ek najbardziej oddalony od wierzcho�ka "u" jest wystarczaj�co odleg�y od wierzcho�ka "u" (r�wnowa�nie: je�li odleg�o�� od wierzcho�ka "u" do wierzcho�ka najbardziej oddalonego od wierzcho�ka "u" jest niemniejsza ni� wymagana odleg�o�� mi�dzy wierzcho�kiem "u" oraz jakim� wierzcho�kiem drzewa)
	{
		int LCA = d[u].ND,    D = depth[u] - depth[ LCA ]; // LCA - wierzcho�ek (o najmniejszej mo�liwej g��boko�ci, czyli mo�liwie najwy�ej po�o�ony), le��cy na najd�u�szej �cie�ce (II rodzaju) z wierzcho�ka "u" do jakiego� wierzcho�ka ( konkretniej, wierzcho�ka "w[u]" - wierzcho�ek "LCA" to najni�szy wsp�lny przodek wierzcho�k�w "u" oraz "w[u]" ( "w[u]" oznacza przyk�adowy najbardziej oddalony wierzcho�ek od wierzcho�ka "u" )  ) drzewa;  D - odleg�o�� mi�dzy wierzcho�kami "u" oraz "LCA" (kt�ra r�wna jest g��boko�ci wierzcho�ka "u", pomniejszonej o g��boko�� wierzcho�ka "LCA")
			
		if( D >= odl ) // je�li odleg�o�� mi�dzy wierzcho�kami "u" oraz "LCA" jest niemniejsza ni� "odl", czyli ��dany wierzcho�ek jest na �cie�ce ��cz�cej wierzcho�ki "u" oraz "LCA"
		{
			return znajdz( u, odl ) + 1; // ��dany wierzcho�ek jest odleg�y o "odl" od wierzcho�ka "u" (z wierzcho�ka "u" idziemy w g�r� drzewa);  funkcja "znajdz" zwraca numer wierzcho�ka z zakresu [0..n-1], natomiast potrzebujemy numeru wierzcho�ka z zakresu [1..n] - wystarczy wi�c tylko doda� jedynk�
		}
		else // w takim razie ��dany wierzcho�ek jest na �cie�ce ��cz�cej wierzcho�ek "LCA" oraz wierzcho�ek najbardziej oddalony od wierzcho�ka "u"
		{
			int v = w[u]; // przyk�adowy wierzcho�ek najbardziej oddalony od wierzcho�ka "u"
			
			return znajdz( v, dmax_II - odl ) + 1; // idziemy z wierzcho�ka "u" w g�r� drzewa na odleg�o�� "D" (a� do wierzcho�ka "LCA"), odleg�o�� mi�dzy wierzcho�kami "LCA" oraz "v" to "dmax_II - D", szukany wierzcho�ek (nazwijmy go "wyn" - nawiasem m�wi�c, wierzcho�ek "wyn" le�y na �cie�ce ��cz�cej wierzcho�ki "LCA" oraz "v") ma to do siebie, �e odleg�o�� mi�dzy wierzcho�kami "wyn" oraz "LCA" to "odl-D" (wtedy odleg�o�� mi�dzy wierzcho�kami "u" oraz wyn" to suma odleg�o�ci mi�dzy wierzcho�kami "u" oraz "LCA" oraz mi�dzy wierzcho�kami "LCA" oraz "wyn", czyli D + (odl-D) = odl), tak wi�c z wierzcho�ka "v" do wierzcho�ka "wyn" idziemy w g�r� o (dmax_II-D)-(odl-D) = dmax_II-odl (od odleg�o�ci mi�dzy wierzcho�kami "v" oraz "LCA", odj��em odleg�o�� mi�dzy wierzcho�kami "wyn" oraz "LCA)
		}
	}
	
	
	// Nie istnieje wierzcho�ek odleg�y o "odl" od wierzcho�ka "u"
	
	return -1;
}


void obsluz_zapytania() // ta procedura odpowiada za obs�ug� zapyta� (czyli ta procedura odpowiada za odpowiadanie na kolejne zapytania) 
{
	scanf( "%d", &q ); // wczytujemy liczb� zapyta� "q"
	
	int u, odl; // zmienne pomocnicze: u - wierzcho�ek, z kt�rego ruszamy;  odl - wymagana odleg�o�� z wierzcho�ka "u" do pewnego wierzcho�ka drzewa (tego pewnego wierzcho�ka drzewa szukamy) (odleg�o�� jest liczona w liczbie kraw�dzi na �cie�ce mi�dzy wierzcho�kami)
		
	while( q > 0 ) // dop�ki mamy jeszcze do obs�u�enia jakie� zapytania (czyli dop�ki liczba pozosta�ych do obs�u�enia zapyta� jest dodatnia)
	{
		scanf( "%d %d", &u, &odl ); // wczytujemy zmienne "u", "odl"
		
		printf( "%d\n", zapytanie( --u, odl ) ); // wypisujemy przyk�adowy wierzcho�ek oddalony od wierzcho�ka "u" o "odl" (lub -1, je�li takowy wierzcho�ek nie istnieje);  zapisa�em --u (czyli odj��em jedynk� od "u"), bo funkcja "zapytanie" potrzebuje numeru wierzcho�ka z zakresu [0..n-1] ( w zapytaniach dostajemy numer wierzcho�ka z zakresu [1..n] )
		
		--q; // obs�u�yli�my w�a�nie kolejne zapytanie, wi�c liczba zapyta� pozosta�ych do obs�u�enia zmala�a o jeden
	}
}


int main() // funkcja g�owna ca�ego programu - tutaj wykonywane jest ca�e zadanie
{
	inicjuj_struktury_danych(); // nasze struktury danych inicjujemy odpowiednimi wielko�ciami (tj. przypisujemy tym strukturom danych odpowiednie warto�ci pocz�tkowe)
	
	wczytaj_dane(); // wczytujemy opis drzewa
	
	obliczenia_wstepne(); // obliczamy niezb�dne wielko�ci
	
	obsluz_zapytania(); // odpowiadamy na zapytania
	
	return 0;
}
