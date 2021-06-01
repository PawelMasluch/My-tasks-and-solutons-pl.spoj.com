/* 

W tym programie obliczam 
liczb� wszystkich niepustych 
(w sensie liczby kraw�dzi) 
�cie�ek w zadanym drzewie 

*/


#include<cstdio>
#include<vector>


using namespace std;


typedef long long LL;

typedef vector < int > VI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back

#define S size


const int MAX_N = 1000000; // maksymalna liczba wierzcho�k�w drzewa (ten zabieg upraszcza mi kod)


VI G[MAX_N]; // w tej strukture danych utrzymuj� reprezentacj� drzewa jako listy (tak naprawd� to wektory, ale idea jest podobna - dla ka�dego wierzcho�ka drzewa pami�tam jego s�siad�w) s�siedztwa 

LL ile[MAX_N], wyn = 0; // w zmiennej 'wyn' pami�tam wynik dla ca�ego zadania ; ile[u] - liczba wszystkich niepustych i 'pojedy�czych' �cie�ek w poddrzewie wierzcho�ka 'u', ko�cz�cych si� dok�adnie w wierzcho�ku 'u'

int n; // liczba wierzcho�k�w drzewa


void wczytaj()
{
	scanf( "%d", &n );
	
	int u, v;
	
	REP(i,1,n-1)
	{
		scanf( "%d %d", &u, &v );
		
		--u;    --v;
		
		G[u].PB( v );
		
		G[v].PB( u );
	}
}


void oblicz(int u, int ojciec)
{
	int r = G[u].S(), v;
	
	REP(i,0,r-1)
	{
		v = G[u][i];
		
		if( v != ojciec )
		{
			oblicz( v, u );
			
			wyn += ( ile[v] + 1 ) * ile[u];
			
			ile[u] += ile[v] + 1;
		}
	}
	
	wyn += ile[u];
}


void wypisz()
{
	printf( "%lld\n", wyn );
}


int main()
{
	wczytaj();
	
	oblicz( 0, -1 );
	
	wypisz();
	
	return 0;
}
