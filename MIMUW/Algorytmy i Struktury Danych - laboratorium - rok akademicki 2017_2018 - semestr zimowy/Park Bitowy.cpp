/*

W tym zadaniu, dla danego drzewa, mamy odpowiadaæ na wiele zapytañ takiej postaci:
podaæ przyk³ad wierzcho³ka oddalonego od zadanego wierzcho³ka "u" o zadan¹ odled³oœæ "odl", b¹dŸ stwierdziæ, ¿e takowy wierzcho³ek w drzewie nie istnieje



Za³o¿enia:

1) W obliczeniach nie zak³ada³em, ¿e drzewo jest binarne (tylko za³o¿enia zadania oraz format danych wejœciowych to wymusza³y)

2) W strukturze "syn" mam tylko listy synów (tzn. dla dowolnego wierzcho³ka drzewa "u", w wektorze "syn[u]" nie kryje siê ojciec wierzcho³ka "u") - wynika to z tego, jak wygl¹daj¹ dane wejœciowe (nawiasem mówi¹c, taki format danych wejœciowych sprawi³, ¿e kod by³ nieco ³atwiejszy - np. nie trzeba by³o siê ci¹gle pilnowaæ, czy oby na pewno rozwa¿amy syna jakiegoœ wierzcho³ka, czy nie)

3) W programie (tj. w strukturach danych, w procesie obliczeñ) numerujê wierzcho³ki od zera - oczywiœcie, na wejœciu i na wyjœciu numeracja jest od jedynki, ale to nie problem dodaæ lub odj¹æ w danym momencie jedynkê

4) Drzewo jest nieskierowane (czyli krawêdziami drzewa mo¿na chodziæ w obie strony)

5) Pojêcie " wierzcho³ek o numerze "u" " znaczy to samo, co " wierzcho³ek "u" "



Definicje:

Def. 1. Dla dowolnego, ustalonego wierzcho³ka "u" drzewa, najd³u¿sza œcie¿ka I rodzaju to najd³u¿sza œcie¿ka wychodz¹ca z wierzcho³ka "u", znajduj¹ca siê w poddrzewie wierzcho³ka "u"

Def. 2. Dla dowolnego, ustalonego wierzcho³ka "u" drzewa, najd³u¿sza œcie¿ka II rodzaju to najd³u¿sza œcie¿ka wychodz¹ca z wierzcho³ka "u", id¹ca w górê drzewa (a¿ do pewnego wierzcho³ka "x", znajduj¹cego siê na œcie¿ce od wierzcho³ka "u" do korzenia), a nastêpnie id¹ca od wierzcho³ka "x" w dó³ drzewa (oczywiœcie nie mo¿emy iœæ w dó³ przez takiego syna wierzcho³ka "x", w którego poddrzewie jest wierzcho³ek "u")

Def. 3. Dla dowolnych, ustalonych wierzcho³ków "u", "v" drzewa, odleg³oœæ miêdzy tymi wierzcho³kami to liczba krawêdzi na œcie¿ce ³¹cz¹cej te wierzcho³ki

Def. 4. Dla wierzcho³ka "u" drzewa, przodek wierzcho³ka "u" to wierzcho³ek le¿¹cy na œcie¿ce od wierzcho³ka "u" do korzenia drzewa (nie licz¹c wierzcho³ka "u") - w szczególnoœci, gdy ruszamy z wierzcho³ka "u" w stronê korzenia, to pierwszy napotkany przodek to ojciec wierzcho³ka "u"

Def. 5. Dla wierzcho³ka "u" drzewa, poddrzewo wierzcho³ka "u" to wierzcho³ek "u" oraz wszystkie wierzcho³ki drzewa, dla których wierzho³ek "u" jest ich przodkiem

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


const int MAX_N = 500000, MAX_K = 18; // MAX_N - maksymalna iloœæ wierzcho³ków w drzewie, MAX_K - maksymalne takie 'x' (ca³kowite nieujemne), ¿e 2^x <= MAX_N


VI syn[MAX_N]; // dla ka¿dego wierzcho³ka "u" w drzewie, trzymam wektor synów wierzcho³ka "u"


// Uwaga ( dla struktur "d1" oraz "d2" ). Jeœli dla wierzcho³ka "u" s¹ co najmniej 2 najd³u¿sze œcie¿ki I rodzaju, to jedna z nich jest opisana przez d1[u], natomiast druga - przez d2[u];  dla wierzcho³ka u", jak co najmniej 2 œcie¿ki s¹ pod wzglêdem d³ugoœci na 2. miejscu, to pamiêtamy któr¹œ z nich (tylko jedn¹)
                                         
PII d1[MAX_N]; // dla ka¿dego wierzcho³ka "u" drzewa, d1[u] oznacza parê postaci (d³ugoœæ najd³u¿szej œcie¿ki w poddrzewie wierzcho³ka "u", wychodz¹cej z wierzcho³ka "u" ; numer syna wierzcho³ka "u", przez którego ta œcie¿ka przechodzi)

int d2[MAX_N]; // dla ka¿dego wierzcho³ka "u" drzewa, d2[u] oznacza d³ugoœæ drugiej najd³u¿szej œcie¿ki w poddrzewie wierzcho³ka "u", wychodz¹cej z wierzcho³ka "u" ( oczywiœcie ta œcie¿ka musi przechodziæ przez innego syna wierzcho³ka "u", ni¿ œcie¿ka najd³u¿sza, czyli zwi¹zana z wartoœci¹ d1[u] )


PII d[MAX_N]; // dla ka¿dego wierzcho³ka "u" drzewa, d[u] oznacza parê postaci (d³ugoœæ najd³u¿szej œcie¿ki wychodz¹cej z wierzcho³ka "u", id¹cej w górê a¿ do jakiegoœ wierzcho³ka "x", a potem (o ile to mo¿liwe) schodz¹cej w dó³ (oczywiœcie to schodzenie musi przechodziæ przez takiego syna wierzcho³ka "x", w którego poddrzewie nie ma wierzcho³ka "u") ; przyk³adowy numer wierzcho³ka "x" z opisu pierwszego elementu tej pary)

int w1[MAX_N], w2[MAX_N], w[MAX_N]; // dla ka¿dego wierzcho³ka "u" drzewa:  w1[u] - przyk³adowy numer wierzcho³ka koñcz¹cego œcie¿kê zwi¹zan¹ z wartoœci¹ d1[u];  w2[u] - przyk³adowy numer wierzcho³ka koñcz¹cego œcie¿kê zwi¹zan¹ z wartoœci¹ d2[u];  w[u] - przyk³adowy numer wierzcho³ka koñcz¹cego œcie¿kê zwi¹zan¹ z wartoœci¹ d[u] - oczywiœcie wartoœci d[u].ND oraz w[u] (o ile te wartoœci istniej¹) s¹ ze sob¹ zwi¹zane - w[u] ( o ile w[u] != d[u].ND ) le¿y w poddrzewie pewnego syna wierzcho³ka "d[u].ND", jednak wierzcho³ek "u" le¿y w poddrzewie pewnego innego syna wierzcho³ka "d[u].ND" 

int q, n, k, root = 0; // q - liczba zapytañ;  n - liczba wierzcho³ków drzewa;  k = max y: { y - ca³kowite nieujemne oraz 2^y <= n };  root - korzeñ drzewa ( numeracja z zakresu [0..n-1] )

int depth[MAX_N]; // dla ka¿dego wierzcho³ka "u" drzewa, depth[u] oznacza g³êbokoœæ wierzcho³ka "u" w drzewie (innymi s³owy, odleg³oœæ miêdzy wierzcho³kiem "u" oraz korzeniem)

int nr[MAX_N][MAX_K+1]; // dla ka¿dego wierzcho³ka "u" drzewa, nr[u][j] oznacza przodka wierzcho³ka "u", oddalonego od wierzcho³ka "u" o wartoœæ 2^j, lub "-1", gdy takowy wierzcho³ek nie istnieje - czyli, intuicyjnie, do jakiego wierzcho³ka dojdziemy, jeœli z wierzcho³ka "u" wykonamy w górê drzewa skok d³ugoœci 2^j


int max(int a, int b) // wiêksza z liczb ca³kowitych "a" oraz "b"
{
	return ( a > b ) ? a : b ; // jeœli warunek ( a > b ) jest prawdziwy ( czyli zachodzi a > b ), to zwracamy "a", w przeciwnym razie ( czyli zachodzi a <= b ) zwracamy "b"
}


int funkcja(int x) // x - liczba naturalna dodatnia;  wynikiem jest exp = max y: { y - ca³kowite nieujemne oraz 2^y <= x }
{
	// Niezmiennik pêtli "while": 2^exp = tmp (czyli tu¿ przed wejœciem do tej pêtli to zachodzi, pod sam koniec ka¿dego obrotu tej pêtli to zachodzi oraz tu¿ po wyjœciu z tej pêtli to zachodzi)
	
	int tmp = 1, exp = 0; // tmp - aktualna potêga dwójki;  exp - aktualny wyk³adnik, dla aktualnej potêgi dwójki "tmp"
	
	while( tmp <= x ) // dopóki aktualna potêga dwójki nie przekracza liczby "x"
	{
		tmp *= 2; // przechodzimy do kolejnej, wiêkszej potêgi dwójki
		
		++exp; // przejœcie do kolejnej, wiêkszej potêgi dwójki, oznacza zwiêkszenie wyk³adnika o jeden
	}
	
	return --exp; // odejmujê jedynkê od zmiennej "exp", bo po wyjœciu z pêtli "while", zmienna "exp" oznacza wyk³adnik najmniejszej potêgi dwójki, wiêkszej ni¿ "x" - tak wiêc odjêcie jedynki od zmiennej "exp" sprawia, ¿e mamy wyk³adnik dla potêgi dwójki niewiêkszej ni¿ "x", ale mo¿liwie najwiêkszej (samej potêgi dwójki "tmp" nie musimy dzieliæ przez 2, bo nie ma takiej potrzeby)
}


void inicjuj_struktury_danych() // dla ka¿dego wierzcho³ka drzewa "u", okreœlam wartoœci pocz¹tkowe pewnych struktur danych
{
	REP(u,0,MAX_N-1) // dla ka¿dego potencjalnego wierzcho³ka drzewa (wierzcho³ków mo¿e byæ nawet MAX_N)
	{
		d1[u] = MP( 0, -1 ); // pocz¹tkowo zak³adamy, ¿e œcie¿ki, okreœlone tablic¹ "d1", maj¹ zerow¹ d³ugoœæ (skoro tak, to nie przechodz¹ one przez ¿adnych synów)
		
		d2[u] = 0; // pocz¹tkowo zak³adamy, ¿e œcie¿ki, okreœlone tablic¹ "d2", maj¹ zerow¹ d³ugoœæ
		
		d[u] = MP( 0, -1 ); // pocz¹tkowo zak³adamy, ¿e œcie¿ki, okreœlone tablic¹ "d", maj¹ zerow¹ d³ugoœæ (skoro tak, to nie przechodz¹ one przez ¿adne wierzcho³ki po³o¿one wy¿ej w stosunku do konkretnych wierzcho³ków "u", dla których liczymy tablicê "d")
		
		w[u] = -1; // skoro pocz¹tkowe przybli¿enie d³ugoœci œcie¿ki ( zwi¹zanej z wartoœci¹ d[u] ) jest zerem, to ta œcie¿ka nie mo¿e koñczyæ siê w ¿adnym wierzcho³ku drzewa (no bo trzeba by pójœæ co najmniej jedn¹ krawêdzi¹ w górê, a potem (o ile to mo¿liwe) gdzieœ w dó³ drzewa - wynika to z tego, jakiego rodzaju œcie¿ki s¹ opisane w tablicy "d" - patrz opis tablicy "d")
		
		w1[u] = w2[u] = u; // skoro pocz¹tkowe przybli¿enia d³ugoœci œcie¿ek ( zwi¹zanych z wartoœciami d1[u] oraz d2[u] ) s¹ zerami, to te œcie¿ki koñcz¹ siê (jak równie¿ rozpoczynaj¹ siê) w wierzcho³ku "u" - w razie w¹tpliwoœci, patrz opis tablic "d1" oraz "d2"
		
		REP(j,0,MAX_K) // dla ka¿dej potencjalnej d³ugoœci skoku równej 2^j
		{
			nr[u][j] = -1; // pocz¹tkowo nie istnieje przodek oddalony od wierzcho³ka "u" o "2^j"
		}
	}
}


void wczytaj_dane() // wczytujê dane wejœciowe odnoœnie drzewa - zapytania wczytywane bêd¹ w procedurze "obsluz_zapytania"
{
	scanf( "%d", &n ); // wczytujemy liczbê wierzcho³ków drzewa
	
	int v1, v2; // zmienne pomocnicze - w tych zmiennych, dla ka¿dego wierzcho³ka drzewa "u", trzymam numery potencjalnych synów wierzcho³ka "u"
	
	REP(u,0,n-1) // dla ka¿dego wierzcho³ka drzewa "u"
	{
		scanf( "%d %d", &v1, &v2 ); // wczytujemy numery potencjalnych synów wierzcho³ka "u"
		
		if( v1 != -1 ) // jeœli, dla wierzcho³ka "u", istnieje syn o numerze "v1"
		{
			--v1; // odejmujê jedynkê, ¿eby byæ w zakresie [0..n-1] ( w danych wejœciowych wierzcho³ki maj¹ numery z zakresu [1..n] ) 
			
			syn[u].PB( v1 ); // dorzucam, do listy synów wierzcho³ka "u", wierzcho³ek "v1"
		}
		
		if( v2 != -1 ) // jeœli, dla wierzcho³ka "u", istnieje syn o numerze "v2"
		{
			--v2; // odejmujê jedynkê, ¿eby byæ w zakresie [0..n-1] ( w danych wejœciowych wierzcho³ki maj¹ numery z zakresu [1..n] )
			
			syn[u].PB( v2 ); // dorzucam, do listy synów wierzcho³ka "u", wierzcho³ek "v2"
		}
	}
}


void f1(int u) // ta procedura, dla ka¿dego wierzcho³ka "u" drzewa, oblicza tablice "nr", "d1", "d2", "w1", "w2", "depth" (pod warunkiem, ¿e wywo³amy j¹ dla korzenia, tzn. wywo³amy j¹ dla argumentu "root")
{
	int r = syn[u].S(), v, ww; // r - liczba synów wierzcho³ka "u";  v, ww - zmienne pomocnicze (bêd¹ one oznaczaæ numery wierzcho³ków; mo¿e lepiej by³oby daæ nazwê "w" zamiast "ww", jednak mamy ju¿ globaln¹ tablicê o nazwie "w")
	
	REP(i,0,r-1) // dla ka¿dego syna wierzcho³ka "u"
	{
		v = syn[u][i]; // wierzcho³ek "v" to i-ty syn na liœcie synów wierzcho³ka "u"
		
		depth[v] = depth[u] + 1; // znaj¹c g³êbokoœæ ojca (w naszym wypadku ojcem jest wierzcho³ek "u"), ³atwo liczymy g³êbokoœæ dla jego syna (w naszym wypadku synem jest wierzcho³ek "v") - g³êbokoœæ dla syna to g³êbokoœæ dla ojca, powiêkszona o jeden ( by dojœæ z korzenia do wierzcho³ka "v", napierw idziemy z korzenia do wierzcho³ka "u" (odleg³oœæ miêdzy wierzcho³kiem "u" oraz korzeniem to "depth[u]"), potem idziemy jeszcze krawêdzi¹ z ojca (w tym przypadku, wierzcho³ka "u") do syna (w tym przypadku, wierzcho³ka "v") (odleg³oœæ miêdzy wierzcho³kiem "u" oraz wierzcho³kiem "v" to jeden - wierzcho³ki "u" oraz "v" s¹ bezpoœrednio po³¹czone krawêdzi¹) ) 
		
		
		
		// Wyznaczanie, dla wierzcho³ka "v" drzewa, tablicy "nr"
		
		// Uwaga. Tablicê "nr" bêdziemy obliczali od góry do do³u drzewa, tzn. jeœli chcemy liczyæ tê tablicê dla jakiegoœ wierzcho³ka "v" drzewa, to wczeœniej musimy obliczyæ tablicê "nr" dla wszystkich przodków wierzcho³ka "v" (tj. wszystkich, poza wierzcho³kiem "v", wierzcho³ków na œcie¿ce od wierzcho³ka "v" do korzenia)
		
		nr[v][0] = u; // wierzcho³ek "u" to wierzcho³ek oddalony o 2^0 od wierzcho³ka "v" 
	
		REP(j,1,k) // dla ka¿dej, poza d³ugoœci¹ skoku równ¹ 2^0, mo¿liwej d³ugoœci skoku (tzn. d³ugoœci 2^j - d³ugoœæ skoku reprezentujê za pomoc¹ wyk³adnika dla potêgi dwójki równej 2^j)
		{
			// Tutaj skorzystamy z takiego faktu: ¿eby pójœæ z jakiegoœ wierzcho³ka "v" drzewa o "2^j" w górê drzewa, to mo¿emy najpierw pójœæ z wierzcho³ka "v" o "2^(j-1)" w górê drzewa (do wierzcho³ka, nazwijmy go, "ww"), a potem, z wierzcho³ka "ww" o "2^j-1" w górê drzewa
			
			ww = nr[v][ j - 1 ]; // wierzcho³ek "ww" jest oddalony od wierzcho³ka "v" o "2^(j-1)" (idziemy z wierzcho³ka "v" w górê drzewa, wiêc jeœli wierzcho³ek "ww" istnieje, to jest wyznaczony jednoznacznie - w górê drzewa mo¿emy iœæ tylko na jeden sposób)
	
			if( ww == -1 ) // jeœli ¿¹dany wierzcho³ek "ww" nie istnieje
			{
				nr[v][j] = -1; // mówimy, ¿e nie istnieje wierzcho³ek odleg³y o "2^j" od wierzcho³ka "v" (idziemy z wierzcho³ka "v" w górê drzewa)
			}
			else
			{
				nr[v][j] = nr[ ww ][ j - 1 ]; // wierzcho³ek odleg³y o "2^j" od wierzcho³ka "v" to wierzcho³ek odleg³y o "2^j-1" od wierzcho³ka "ww" (jeœli wierzcho³ek odleg³y o "2^j-1" od wierzcho³ka "ww" nie istnieje, to nie istnieje równie¿ wierzcho³ek odleg³y o "2^j" od wierzcho³ka "v";  w takim wypadku wartoœæ "nr[ ww ][ j - 1 ]" wynosi "-1" - skoro wiêc robimy przypisanie "nr[v][j] = nr[ ww ][ j - 1 ]", to wartoœæ "nr[v][j]" wynosi "-1", czyli to, co trzeba)
			}
		}
		
		// Koniec wyznaczania tablicy "nr"
		
		
		
		f1( v ); // wywo³ujemy siê rekurencyjnie dla wierzcho³ka "v" drzewa
		
		
		
		// Obliczanie, dla wierzcho³ka "u", tablic "d1", "d2", "w1", "w2"
		
		if( d1[v].ST + 1 > d1[u].ST ) // jeœli najd³u¿sza, dla wierzcho³ka "v", œcie¿ka I rodzaju, przed³u¿ona o krawêdŸ z wierzcho³ka "v" do wierzcho³ka "u", jest d³u¿sza ni¿ dotychczasowa najd³u¿sza, dla wierzcho³ka "u", œcie¿ka I rodzaju 
		{
			d2[u] = d1[u].ST; // dla wierzcho³ka "u", d³ugoœæ drugiej najd³u¿szej œcie¿ki I rodzaju to teraz dotychczasowa (dla wierzcho³ka "u") d³ugoœæ najd³u¿szej œcie¿ki I rodzaju
			
			w2[u] = w1[u]; // dla wierzcho³ka "u", przyk³adowy wierzcho³ek koñcz¹cy drug¹ najd³u¿sz¹ œcie¿kê I rodzaju to teraz dotychczasowy (dla wierzcho³ka "u") wierzcho³ek koñcz¹cy najd³u¿sz¹ œcie¿kê I rodzaju
			
			d1[u] = MP( d1[v].ST + 1, v ); // dla wierzcho³ka "u", d³ugoœæ najd³u¿szej œcie¿ki I rodzaju to teraz d³ugoœæ najd³u¿szej, dla wierzcho³ka "v", œcie¿ki I rodzaju, przed³u¿onej o krawêdŸ z wierzcho³ka "v" do wierzcho³ka "u";  dla wierzcho³ka "u", najd³u¿sza œcie¿ka I rodzaju przechodzi teraz przez wierzcho³ek "v" - syna wierzcho³ka "u"
			
			w1[u] = w1[v]; // dla wierzcho³ka "u", przyk³adowy wierzcho³ek koñcz¹cy najd³u¿sz¹ œcie¿kê I rodzaju to teraz przyk³adowy, dla wierzcho³ka "v", wierzcho³ek koñcz¹cy najd³u¿sz¹ œcie¿kê I rodzaju
		}
		else // najd³u¿sza, dla wierzcho³ka "v", œcie¿ka I rodzaju, przed³u¿ona o krawêdŸ z wierzcho³ka "v" do wierzcho³ka "u", nie jest d³u¿sza ni¿ dotychczasowa najd³u¿sza, dla wierzcho³ka "u", œcie¿ka I rodzaju 
		{
			if( d1[v].ST + 1 > d2[u] ) // jeœli najd³u¿sza, dla wierzcho³ka "v", œcie¿ka I rodzaju, przed³u¿ona o krawêdŸ z wierzcho³ka "v" do wierzcho³ka "u", jest d³u¿sza ni¿ dotychczasowa druga najd³u¿sza, dla wierzcho³ka "u", œcie¿ka I rodzaju  
			{
				d2[u] = d1[v].ST + 1; // dla wierzcho³ka "u", d³ugoœæ drugiej najd³u¿szej œcie¿ki I rodzaju to teraz najd³u¿sza, dla wierzcho³ka "v", œcie¿ka I rodzaju, przed³u¿ona o krawêdŸ z wierzcho³ka "v" do wierzcho³ka "u"
				
				w2[u] = w1[v]; // dla wierzcho³ka "u", przyk³adowy wierzcho³ek koñcz¹cy drug¹ najd³u¿sz¹ œcie¿kê I rodzaju to teraz przyk³adowy, dla wierzcho³ka "v", wierzcho³ek koñcz¹cy najd³u¿sz¹ œcie¿kê I rodzaju
			}
		}
		
		// Koniec obliczania, dla wierzcho³ka "u", tablic "d1", "d2", "w1", "w2"
	}
}


void f2(int u) // ta procedura, dla ka¿dego wierzcho³ka "u" drzewa, oblicza tablice "d", "w" (pod warunkiem, ¿e wywo³amy j¹ dla korzenia, tzn. wywo³amy j¹ dla argumentu "root")
{
	int r = syn[u].S(), v; // r - liczba synów wierzcho³ka "u";  v - zmienna pomocnicza (bêdzie oznaczaæ okreœlonego syna wierzcho³ka "u")
	
	REP(i,0,r-1) // dla ka¿dego syna wierzcho³ka "u"
	{
		v = syn[u][i]; // v - dla wierzcho³ka "u" drzewa, i-ty syn wierzcho³ka "u" 
		
		
		
		// Obliczanie, dla wierzcho³ka "v", tablic "d", "w"
		
		
		// Przypadek 1: idê z wierzcho³ka "v" do ojca wierzcho³ka "v" (czyli wierzcho³ka "u"), potem z wierzcho³ka "u" w dó³ drzewa (przez innego, ni¿ wierzcho³ek "v", syna wierzcho³ka "u")
			
		if( d1[u].ND != v ) // jeœli przyk³adowy numer syna wierzcho³ka "u", przez którego przechodzi, dla wierzcho³ka "u", najd³u¿sza œcie¿ka I rodzaju, jest inny ni¿ wierzcho³ek "v" - gdy tak rzeczywiœcie jest, to bierzemy do analizy najd³u¿sz¹, dla wierzcho³ka "u", œcie¿kê I rodzaju (przypadek, gdzie "d1[u].ND" wynosi "-1", nie stwarza problemów)
		{
			if( 1 + d1[u].ST > d[v].ST ) // jeœli najd³u¿sza, dla wierzcho³ka "u", œcie¿ka I rodzaju, przed³u¿ona o krawêdŸ z wierzcho³ka "v" do wierzcho³ka "u" (tak skonstruowana œcie¿ka jest œcie¿k¹ II rodzaju), jest d³u¿sza ni¿ dotychczasowa najd³u¿sza, dla wierzcho³ka "v", œcie¿ka II rodzaju  
			{
				d[v] = MP( 1 + d1[u].ST, u ); // dla wierzcho³ka "v", d³ugoœæ najd³u¿szej œcie¿ki II rodzaju to teraz najd³u¿sza, dla wierzcho³ka "u", œcie¿ka I rodzaju, przed³u¿ona o krawêdŸ z wierzcho³ka "v" do wierzcho³ka "u";  najwy¿ej po³o¿ony wierzcho³ek na najd³u¿szej (dla wierzcho³ka "v") œcie¿ce II rodzaju, to teraz wierzcho³ek "u" 
				
				w[v] = w1[u]; // dla wierzcho³ka "v", przyk³adowy wierzcho³ek koñcz¹cy najd³u¿sz¹ œcie¿kê II rodzaju to teraz przyk³adowy, dla wierzcho³ka "u", wierzcho³ek koñcz¹cy najd³u¿sz¹ œcie¿kê I rodzaju 
			}
		}
		else // jeœli przyk³adowy syn wierzcho³ka "u", przez którego przechodzi, dla wierzcho³ka "u", najd³u¿sza œcie¿ka I rodzaju, to dok³adnie wierzcho³ek "v" - w takim wypadku bierzemy do analizy drug¹ najd³u¿sz¹, dla wierzcho³ka "u", œcie¿kê I rodzaju
		{
			if( 1 + d2[u] > d[v].ST ) // jeœli druga najd³u¿sza, dla wierzcho³ka "u", œcie¿ka I rodzaju, przed³u¿ona o krawêdŸ z wierzcho³ka "v" do wierzcho³ka "u" (tak skonstruowana œcie¿ka jest œcie¿k¹ II rodzaju), jest d³u¿sza ni¿ dotychczasowa najd³u¿sza, dla wierzcho³ka "v", œcie¿ka II rodzaju   
			{
				d[v] = MP( 1 + d2[u], u ); // dla wierzcho³ka "v", d³ugoœæ najd³u¿szej œcie¿ki II rodzaju to teraz druga najd³u¿sza, dla wierzcho³ka "u", œcie¿ka I rodzaju, przed³u¿ona o krawêdŸ z wierzcho³ka "v" do wierzcho³ka "u";  najwy¿ej po³o¿ony wierzcho³ek na najd³u¿szej (dla wierzcho³ka "v") œcie¿ce II rodzaju, to teraz wierzcho³ek "u" 
				
				w[v] = w2[u]; // dla "v", przyk³adowy wierzcho³ek koñcz¹cy najd³u¿sz¹ œcie¿kê II rodzaju to teraz przyk³adowy, dla "u", wierzcho³ek koñcz¹cy drug¹ najd³u¿sz¹ œcie¿kê I rodzaju
			}
		}
		
		// Koniec analizy przypadku 1
		
		
		// Przypadek 2: biorê, przed³u¿on¹ o krawêdŸ z wierzcho³ka "v" do wierzcho³ka "u", najlepsz¹ œcie¿kê II rodzaju dla ojca wierzcho³ka "v" (czyli, w tym wypadku, wierzcho³ka "u")
		
		if( u != root  &&  1 + d[u].ST > d[v].ST ) // jeœli wierzcho³ek "u" nie jest korzeniem drzewa (dla korzenia nie istnieje œcie¿ka II rodzaju) oraz jeœli najd³u¿sza, dla wierzcho³ka "u", œcie¿ka II rodzaju, przed³u¿ona o krawêdŸ z wierzcho³ka "v" do wierzcho³ka "u" (tak skonstruowana œcie¿ka jest œcie¿k¹ II rodzaju), jest d³u¿sza ni¿ dotychczasowa najd³u¿sza, dla wierzcho³ka "v", œcie¿ka II rodzaju
		{
			d[v] = MP( 1 + d[u].ST, d[u].ND ); // najd³u¿sza œcie¿ka II rodzaju, dla wierzcho³ka "v", to teraz najd³u¿sza œcie¿ka II rodzaju dla wierzcho³ka "u", przed³u¿ona o krawêdŸ z wierzcho³ka "v" do wierzcho³ka "u";  najwy¿ej po³o¿ony wierzcho³ek na najd³u¿szej (dla wierzcho³ka "v") œcie¿ce II rodzaju, to teraz najwy¿ej po³o¿ony wierzcho³ek na najd³u¿szej (dla wierzcho³ka "u") œcie¿ce II rodzaju  
			
			w[v] = w[u]; // dla wierzcho³ka "v", przyk³adowy, ostatni wierzcho³ek na najd³u¿szej œcie¿ce II rodzaju to teraz, przyk³adowy, ostatni wierzcho³ek na najd³u¿szej œcie¿ce II rodzaju, dla wierzcho³ka "u"
		}
		
		// Koniec analizy przypadku 2
		
		
		// Koniec obliczania, dla "v", tablic "d", "w"
		
		
		
		f2( v ); // wywo³ujemy siê rekurencyjnie dla wierzcho³ka "v"
	}
}


void obliczenia_wstepne() // ta procedura oblicza wszystkie niezbêdne wielkoœci
{
	k = funkcja( n ); // obliczamy wyk³adnik najwiêkszej potêgi dwójki, niewiêkszej ni¿ "n" (po obliczeniu wartoœci tej zmiennej wiemy, ¿e warto rozwa¿aæ tylko skoki d³ugoœci 2^0, 2^1, ... , 2^k)
	
	f1( root ); // wywo³ujemy procedurê "f1" dla korzenia (dziêki takiemu argumentowi dla tej procedury obliczymy to, o czym powiedzia³em w opisie tej funkcji)
	
	f2( root ); // wywo³ujemy procedurê "f2" dla korzenia (dziêki takiemu argumentowi dla tej procedury obliczymy to, o czym powiedzia³em w opisie tej funkcji) 
}


int znajdz(int u, int odl) // znajdujê wierzcho³ek po³o¿ony w odleg³oœci "odl" od wierzcho³ka "u" (przy czym szukany wierzcho³ek ma byæ po³o¿ony na œcie¿ce od wierzcho³ka "u" do korzenia drzewa, oraz ma istnieæ)
{
	/* Funkcja ta oprze siê na zapisie binarnym liczby "odl" (czyli zapisie liczby "odl" jako suma potêg dwójki o parami ró¿nych, nieujemnych, ca³kowitych wyk³adnikach)
	   Liczbê "odl" bêdziemy w kó³ko dzieliæ ca³kowitoliczbowo przez dwa (dziêki temu wyrzucamy za ka¿dym razem najm³odszy bit "odl"), a wczeœniej - sprawdzaæ, czy aktualnie najm³odszy bit liczby "odl" jest jeden
	   Jeœli aktualna potêga dwójki ( reprezentowana przez wykladnik "ind" ) pojawia siê w zapisie binarnym liczby "odl" (czyli aktualnie najm³odszy bit liczby "odl" jest jeden), to bêdziemy aktualizowaæ odpowiednio nasz wynik
	*/
	
	int ind = 0, wyn = u; // ind - identyfikator/wyk³adnik zwi¹zany z aktualn¹ d³ugoœci¹ skoku ( pod pojêciem "aktualna d³ugoœæ skoku" rozumiem wartoœæ "2^ind" );  wyn - wynik dzia³ania funkcji "znajdz" - przybli¿eniem pocz¹tkowym rozwi¹zania jest wierzcho³ek "u" (bo na pocz¹tku nigdzie siê z wierzcho³ka "u" nie ruszyliœmy; jak oka¿e siê, ¿e "odl" == 0, to po prostu zwrócimy "u")
	
	while( odl > 0 ) // dopóki liczba "odl" ma jeszcze jakieœ bity do przeanalizowania (tutaj wygodnie jest przyj¹æ, ¿e liczba zero ma zero cyfr bitowych)
	{
		if( odl % 2 == 1 ) // jeœli aktualnie najm³odszy bit liczby "odl" jest jeden
		{
			wyn = nr[ wyn ][ ind ]; // nowe przybli¿enie wyniku to wierzcho³ek, do jakiego dojdziemy, "skacz¹c" w górê o "2^ind" z dotychczasowego wierzcho³ka - starego przybli¿enia wyniku
		}
		
		++ind; // przechodzimy do kolejnej potegi dwójki
		
		odl /= 2; // pozbywamy sie aktualnie najm³odszego bitu liczby "odl"
	}
	
	return wyn;
}


int zapytanie(int u, int odl) // dla wierzcho³ka "u" drzewa, znajdujê wierzcho³ek odleg³y o "odl" od wierzcho³ka "u" (jeœli istnieje, to wypisujê jego numer (jak ich jest wiêcej - wypisujê numer któregokolwiek z nich), ale z zakresu [1..n]), b¹dŸ stwierdzam, ¿e takiego w drzewie nie ma
{
	// Przypadek 1 - szukamy wierzcho³ka w ramach najd³u¿szej œcie¿ki I rodzaju
	
	int dmax_I = d1[u].ST; // dmax_I - dla wierzcho³ka "u", d³ugoœæ najd³u¿szej œcie¿ki I rodzaju 
	
	if( dmax_I >= odl ) // jeœli wierzcho³ek najbardziej oddalony od wierzcho³ka "u", jest wystarczaj¹co odleg³y od wierzcho³ka "u" (równowa¿nie: jeœli odleg³oœæ od wierzcho³ka "u" do wierzcho³ka najbardziej oddalonego od wierzcho³ka "u" jest niemniejsza ni¿ wymagana odleg³oœæ miêdzy wierzcho³kiem "u" oraz jakimœ wierzcho³kiem drzewa)
	{
		int v = w1[u]; // wierzcho³ek "v" jest tym najbardziej oddalonym od wierzcho³ka "u" wierzcho³kiem (jak jest takich wierzcho³ków wiêcej, to wierzcho³ek "v" jest przyk³adowym takim wierzcho³kiem)
		
		return znajdz( v, dmax_I - odl ) + 1; // wierzcho³ki "u" oraz "v" s¹ odleg³e o "dmax_I" - zatem jeœli pójdziemy z wierzcho³ka "v" w górê o 'dmax_I - odl', to osi¹gniemy ¿¹dany wierzcho³ek;  funkcja "znajdz" zwraca numer wierzcho³ka z zakresu [0..n-1], natomiast potrzebujemy numeru wierzcho³ka z zakresu [1..n] - wystarczy wiêc tylko dodaæ jedynkê
	}
	
	
	// Przypadek 2 - szukamy wierzcho³ka w ramach najd³u¿szej œcie¿ki II rodzaju
	
	int dmax_II = d[u].ST; // dmax_II - dla wierzcho³ka "u", d³ugoœæ najd³u¿szej œcie¿ki II rodzaju
	
	
	// Uwaga. Warunek w poni¿szym "if-ie" nigdy siê nie wykona, gdy u - korzeñ drzewa (wartoœæ "dmax_II" wynosi wtedy zero, wiêc ¿eby warunek tego "if-a" by³ spe³niony, to musi byæ "odl" równe zero (bo zawsze zadajemy nieujemn¹ wartoœæ "odl") - skoro tak, to wiedz¹c, ¿e wartoœæ "dmax_I" jest zawsze nieujemna, to wykona siê "if" z Przypadku 1 tej funkcji) - skoro tak, to unikniemy sytuacji, ¿e bêdziemy mieæ wartoœæ "LCA" równ¹ "-1", a potem bedziemy chcieli mieæ wartoœæ "depth[ LCA ]" ( odwo³anie siê do nieistniej¹cego indeksu w tablicy "depth" )
	
	if( dmax_II >= odl ) // jeœli wierzcho³ek najbardziej oddalony od wierzcho³ka "u" jest wystarczaj¹co odleg³y od wierzcho³ka "u" (równowa¿nie: jeœli odleg³oœæ od wierzcho³ka "u" do wierzcho³ka najbardziej oddalonego od wierzcho³ka "u" jest niemniejsza ni¿ wymagana odleg³oœæ miêdzy wierzcho³kiem "u" oraz jakimœ wierzcho³kiem drzewa)
	{
		int LCA = d[u].ND,    D = depth[u] - depth[ LCA ]; // LCA - wierzcho³ek (o najmniejszej mo¿liwej g³êbokoœci, czyli mo¿liwie najwy¿ej po³o¿ony), le¿¹cy na najd³u¿szej œcie¿ce (II rodzaju) z wierzcho³ka "u" do jakiegoœ wierzcho³ka ( konkretniej, wierzcho³ka "w[u]" - wierzcho³ek "LCA" to najni¿szy wspólny przodek wierzcho³ków "u" oraz "w[u]" ( "w[u]" oznacza przyk³adowy najbardziej oddalony wierzcho³ek od wierzcho³ka "u" )  ) drzewa;  D - odleg³oœæ miêdzy wierzcho³kami "u" oraz "LCA" (która równa jest g³êbokoœci wierzcho³ka "u", pomniejszonej o g³êbokoœæ wierzcho³ka "LCA")
			
		if( D >= odl ) // jeœli odleg³oœæ miêdzy wierzcho³kami "u" oraz "LCA" jest niemniejsza ni¿ "odl", czyli ¿¹dany wierzcho³ek jest na œcie¿ce ³¹cz¹cej wierzcho³ki "u" oraz "LCA"
		{
			return znajdz( u, odl ) + 1; // ¿¹dany wierzcho³ek jest odleg³y o "odl" od wierzcho³ka "u" (z wierzcho³ka "u" idziemy w górê drzewa);  funkcja "znajdz" zwraca numer wierzcho³ka z zakresu [0..n-1], natomiast potrzebujemy numeru wierzcho³ka z zakresu [1..n] - wystarczy wiêc tylko dodaæ jedynkê
		}
		else // w takim razie ¿¹dany wierzcho³ek jest na œcie¿ce ³¹cz¹cej wierzcho³ek "LCA" oraz wierzcho³ek najbardziej oddalony od wierzcho³ka "u"
		{
			int v = w[u]; // przyk³adowy wierzcho³ek najbardziej oddalony od wierzcho³ka "u"
			
			return znajdz( v, dmax_II - odl ) + 1; // idziemy z wierzcho³ka "u" w górê drzewa na odleg³oœæ "D" (a¿ do wierzcho³ka "LCA"), odleg³oœæ miêdzy wierzcho³kami "LCA" oraz "v" to "dmax_II - D", szukany wierzcho³ek (nazwijmy go "wyn" - nawiasem mówi¹c, wierzcho³ek "wyn" le¿y na œcie¿ce ³¹cz¹cej wierzcho³ki "LCA" oraz "v") ma to do siebie, ¿e odleg³oœæ miêdzy wierzcho³kami "wyn" oraz "LCA" to "odl-D" (wtedy odleg³oœæ miêdzy wierzcho³kami "u" oraz wyn" to suma odleg³oœci miêdzy wierzcho³kami "u" oraz "LCA" oraz miêdzy wierzcho³kami "LCA" oraz "wyn", czyli D + (odl-D) = odl), tak wiêc z wierzcho³ka "v" do wierzcho³ka "wyn" idziemy w górê o (dmax_II-D)-(odl-D) = dmax_II-odl (od odleg³oœci miêdzy wierzcho³kami "v" oraz "LCA", odj¹³em odleg³oœæ miêdzy wierzcho³kami "wyn" oraz "LCA)
		}
	}
	
	
	// Nie istnieje wierzcho³ek odleg³y o "odl" od wierzcho³ka "u"
	
	return -1;
}


void obsluz_zapytania() // ta procedura odpowiada za obs³ugê zapytañ (czyli ta procedura odpowiada za odpowiadanie na kolejne zapytania) 
{
	scanf( "%d", &q ); // wczytujemy liczbê zapytañ "q"
	
	int u, odl; // zmienne pomocnicze: u - wierzcho³ek, z którego ruszamy;  odl - wymagana odleg³oœæ z wierzcho³ka "u" do pewnego wierzcho³ka drzewa (tego pewnego wierzcho³ka drzewa szukamy) (odleg³oœæ jest liczona w liczbie krawêdzi na œcie¿ce miêdzy wierzcho³kami)
		
	while( q > 0 ) // dopóki mamy jeszcze do obs³u¿enia jakieœ zapytania (czyli dopóki liczba pozosta³ych do obs³u¿enia zapytañ jest dodatnia)
	{
		scanf( "%d %d", &u, &odl ); // wczytujemy zmienne "u", "odl"
		
		printf( "%d\n", zapytanie( --u, odl ) ); // wypisujemy przyk³adowy wierzcho³ek oddalony od wierzcho³ka "u" o "odl" (lub -1, jeœli takowy wierzcho³ek nie istnieje);  zapisa³em --u (czyli odj¹³em jedynkê od "u"), bo funkcja "zapytanie" potrzebuje numeru wierzcho³ka z zakresu [0..n-1] ( w zapytaniach dostajemy numer wierzcho³ka z zakresu [1..n] )
		
		--q; // obs³u¿yliœmy w³aœnie kolejne zapytanie, wiêc liczba zapytañ pozosta³ych do obs³u¿enia zmala³a o jeden
	}
}


int main() // funkcja g³owna ca³ego programu - tutaj wykonywane jest ca³e zadanie
{
	inicjuj_struktury_danych(); // nasze struktury danych inicjujemy odpowiednimi wielkoœciami (tj. przypisujemy tym strukturom danych odpowiednie wartoœci pocz¹tkowe)
	
	wczytaj_dane(); // wczytujemy opis drzewa
	
	obliczenia_wstepne(); // obliczamy niezbêdne wielkoœci
	
	obsluz_zapytania(); // odpowiadamy na zapytania
	
	return 0;
}
