#include<cstdio> // 100 pkt
#include<new>
#include<vector>


using namespace std;


typedef pair < int, int > pII;

typedef vector < int > VII;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)

#define PB push_back

#define C clear

#define MP make_pair

#define ST first

#define ND second


const int UNDEF = -1;


int main()
{
	int N;
	
	scanf( "%d", &N );
	
	if( N == 1 ) // przypadek brzegowy
	{
		printf( "1\n" );
		
		return 0;
	}
	
	
	pII *last; // tablica par (poprzednik, ostatnia potęga dziesiątki - pamiętam tylko wykładnik)
	
	VII v, pom, wyn; // v - aktualne wierzchołki, z których kontynuujemy przeszukiwanie ; pom - wierzchołki odwiedzone po raz pierwszy ; wyn - potęgi dziesiątki wchodzące w skład szukanej liczby
	
	int rv = 0, skok = 1, ind, faza = 1, rwyn = 0; // skok - o ile skaczemy w danej fazie, czyli danej potędze dziesiątki
	
	last = new pII [N];
	
	REP(i,0,N-1)
	{
		last[i] = MP( UNDEF, UNDEF );	
	}
	
	
	/*** Ręczne wykonanie fazy "0" ***/
	
	last[1] = MP( 0, 0 ); 
	
	v.PB( 0 );  v.PB( 1 );  rv += 2;
	
	
	/*** Pozostałe fazy ***/
	
	while( last[0].ST == UNDEF ) // dopóki wierzchołek "0" nie ma poprzednika
	{
		skok = ( skok * 10 ) % N; // ustal skok dla aktualnej fazy
		
		REP(i,0,rv-1) // dla wszystkich wcześniej odwiedzonych wierzchołków
		{
			ind = ( v[i] + skok ) % N; // ustal, dokąd pójdzie potencjalna krawędź
			
			if( last[ ind ].ST == UNDEF ) // jeśli wierzchołek docelowy nie był odwiedzony
			{
				last[ ind ] = MP( v[i], faza ); // zapisz poprzednika i aktualną potęgę dziesiątki dla wierzchołka "ind"
				
				pom.PB( ind ); // zapisz w pomocniczym wektorze wierzchołek "ind" (dopiero od kolejnej fazy będę mógł ruszyć z wierzchołka "ind" do innych wierzchołków)
			}
		}
		
		
		/*** Wrzucam nowo odwiedzone wierzchołki do listy wcześniej odwiedzonych oraz czyszczę wektor "pom", by dla kolejnej fazy wszystko było aktualne ***/
		
		while( !pom.empty() )
		{
			v.PB( pom.back() );
			
			++rv;
			
			pom.pop_back();
		}
		
		++faza;
	}
	
	
	/*** Zapamiętuję potęgi dziesiątki wchodzące w skład wyniku ***/
	
	ind = 0;
	
	while( last[ ind ].ST != 0 )
	{
		wyn.PB( last[ ind ].ND );
		
		++rwyn;
		
		ind = last[ ind ].ST;
	}
	
	wyn.PB( last[ ind ].ND ); // muszę dopisać jeszcze jedną potęgę, bo pętla "while" jej nie rozważyła
		
	++rwyn;
	
	
	wyn.PB( -1 ); // wartownik, by łatwiej wypisywać wynik
		
	++rwyn;
	
	
	REP(i,0,rwyn-2) // dla wszystkich potęg dziesiątki z wektora "wyn", poza wartownikiem
	{
		printf( "1" ); // najpierw wypisujemy jedynkę
		
		FORD(j,wyn[i]-1,wyn[i+1]+1) // potem wypisujemy odpowiednią liczbę zer
		{
			printf( "0" );
		}
	}
	
	printf( "\n" );
	
	return 0;
}
