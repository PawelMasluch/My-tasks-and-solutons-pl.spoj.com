/*

Założenia:

1) W obliczeniach nie zakładałem, że drzewo jest binarne (tylko założenia zadania oraz format danych wejściowych to wymuszały)

2) W strukturze G mam tylko listy synów (tzn. dla dowolnego wierzchołka drzewa "u", w wektorze "G[u]" nie kryje się ojciec wierzchołka "u") - wynika to z tego, jak wyglądają dane wejściowe (nawiasem mówiąc, taki format danych wejściowych sprawił, że kod był nieco łatwiejszy - np. nie trzeba było się ciągle pilnować, czy oby na pewno rozważamy syna jakiegoś wierzchołka, czy nie)

*/


#include<cstdio>
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


const int MAX_N = 500000, MAX_K = 18;


VI syn[MAX_N]; // dla każdego wierzchołka "u" w drzewie, trzymam wektor synów wierzchołka "u"

PII d1[MAX_N], d2[MAX_N], d[MAX_N], best[MAX_N];

int czy[MAX_N]; // czy pojedyńcza gałąź (0-nie, 1-tak)

int q, n, k, root = 0, depth[MAX_N], w1[MAX_N], w2[MAX_N], w[MAX_N], nr[MAX_N][MAX_K+1];


int max(int a, int b) // większa z liczb całkowitych "a" oraz "b"
{
	return ( a > b ) ? a : b ; // jeśli warunek ( a > b ) jest prawdziwy ( czyli zachodzi a > b ), to zwracamy "a", w przeciwnym razie ( czyli zachodzi a <= b ) zwracamy "b"
}


int funkcja(int x) // wynikiem jest wyn = max k: { k - całkowite nieujemne oraz 2^k < x } (maksymalna długość ścieżki w drzewie o "n" wierzchołkach ma długosć n-1, więc potencjalnie najdłuższy możliwy "skok" z jakiegoś wierzchołka w drzewie do jakiegoś innego, długości równej potędze dwójki, to 2^wyn )
{
	int wyn = 0, tmp = 1;
	
	while( tmp < x )
	{
		tmp *= 2;
		
		++wyn;
	}
	
	return --wyn;
}


void inicjuj_struktury_danych()
{
	REP(u,0,MAX_N-1) // dla każdego wierzchołka drzewa "u"
	{
		d1[u] = d2[u] = d[u] = MP( 0, -1 );
		
		w[u] = -1;
		
		w1[u] = w2[u] = u;
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
		
		f1( v );
				
		if( d1[v].ST + 1 > d1[u].ST )
		{
			d2[u] = d1[u];
			
			w2[u] = w1[u];
			
			d1[u] = MP( d1[v].ST + 1, v );
			
			w1[u] = w1[v];
		}
		else
		{
			if( d2[v].ST + 1 > d2[u].ST )
			{
				d2[u] = MP( d1[v].ST + 1, v );
				
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
			if( 1 + d2[u].ST > d[v].ST )
			{
				d[v] = MP( 1 + d2[u].ST, u );
				
				w[v] = w2[u];
			}
		}
		
		
		// Przypadek 2: biorę przedłużoną najlepszą ścieżkę dla ojca
		
		if( u != root  &&  1 + d[u].ST > d[v].ST )
		{
			d[v] = MP( 1 + d[u].ST, d[u].ND );
			
			w[v] = w[u];
		}
		
		f2( v );
	}
}


void najdalsze()
{
	REP(u,0,n-1)
	{
		if( d1[u].ST > d[u].ST )
		{
			best[u] = MP( d1[u].ST, w1[u] );
			
			czy[u] = 1;
		}
		else
		{
			best[u] = MP( d[u].ST, w[u] );
		}
	}
}


void obliczenia_wstepne()
{
	k = funkcja( n );
	
	f1( root );
	
	f2( root );
	
	najdalsze();
}


int znajdz(int u, int odl) // znajduję wierzchołek położony w odległości "odl" od wierzchołka "u" (przy czym szukany wierzchołek ma być położony na wyższym poziomie drzewa niż wierzchołek "u")
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


int zapytanie(int u, int odl)
{
	int v = best[u].ND, dmax = best[u].ST;
	
	if( dmax >= odl ) // jeśli wierzchołek "v" (czyli wierzchołek najbardziej oddalony od wierzchołka "u") jest wystarczająco odległy od wierzchołka "u"
	{
		if( czy[u] == 1 ) // jeśli wierzchołki "u" oraz "v" łączy pojedyńcza gałąź
		{
			return znajdz( v, dmax - odl ) + 1;
		}
		else // jeśli wierzchołki "u" oraz "v" łączy ścieżka w postaci 2 połączonych gałęzi
		{
			int LCA = d[u].ND, D = depth[u] - depth[ LCA ];
			
			if( D >= odl )
			{
				return znajdz( u, odl ) + 1;
			}
			else
			{
				return znajdz( v, dmax - odl ) + 1;
			}
		}
	}
	else // jeśli wierzchołki "u" oraz "v" są za mało oddalone
	{
		return -1; // wypisujemy komunikat, że odpowiednio oddalony wierzchołek (tj. w odległości dokładnie "d" od wierzchołka "u") od wierzchołka "u" nie istnieje		
	}
}


void obsluz_zapytania()
{
	scanf( "%d", &q );
	
	int u, odl;
	
	while( q )
	{
		scanf( "%d %d", &u, &odl );
		
		printf( "%d\n", zapytanie( --u, odl ) );
		
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