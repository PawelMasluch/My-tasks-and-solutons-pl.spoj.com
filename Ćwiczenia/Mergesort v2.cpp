#include<cstdio>
#include<new>


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


int *pom; // pomocnicza tablica do algorytmu Mergesort

int *t; // tablica liczb calkowitych

int n; // liczba elementow w tablicy "t"


void wczytaj() // wczytanie danych wejsciowych
{
	scanf( "%d", &n );
	
	pom = new int [n];
	
	t = new int [n];
	
	REP(i,0,n-1)
	{
		scanf( "%d", &t[i] );
	}
}


void merge(int *t, int a, int sr, int b, int *pom)
{
	int i_lewy = a, i_prawy = sr + 1, i = a;
	
	while( i_lewy <= sr  &&  i_prawy <= b )
	{
		if( t[ i_lewy ] <= t[ i_prawy ] )
		{
			pom[i] = t[ i_lewy ];
			
			++i_lewy;
		}
		else // t[ i_lewy ] > t[ i_prawy ]
		{
			pom[i] = t[ i_prawy ];
			
			++i_prawy;
		}
		
		++i;
	}
	
	while( i_lewy <= sr )
	{
		pom[i] = t[ i_lewy ];
		
		++i_lewy;
		
		++i;
	}
	
	while( i_prawy <= b )
	{
		pom[i] = t[ i_prawy ];
		
		++i_prawy;
		
		++i;
	}
	
	REP(i,a,b)
	{
		t[i] = pom[i];
	}
}


int min(int x, int y)
{
	return (x < y) ? x : y;	
}


void mergesort(int *t, int a, int b, int *pom) // sortujemy tablice liczb calkowitych "t" na przedziale indeksow [a,b]
{
	int d = 2; // aktualna dlugosc blokow, ktore chcemy miec posortowane ( niezmiennik: bloki dlugosci d/2 juz sa posortowane )
	while( d < 2*n )
	{
		int pocz = a;
		while( pocz < b )
		{
			int kon = pocz + d - 1;
			int sr = (pocz + kon) / 2;
			
			merge(t, pocz, min(sr, b), min(kon, b), pom);
			
			pocz += d;
		}
		
		d *= 2;
	}
}


void oblicz()
{
	mergesort( t, 0, n - 1, pom );
}


void wypisz()
{
	REP(i,0,n-1)
	{
		printf( "%d ", t[i] );
	}
	
	printf( "\n" );
	
	delete [] pom;
	
	delete [] t;
}


void solve()
{
	wczytaj();
	
	oblicz();
	
	wypisz();
}


int main()
{
	solve();
	
	return 0;
}


/*

Test 1:
5
7 4 8 1 6

Test 2:
8
89 73 -728 93 -384 -28 83478 -99

Test 3:
8
9 7 64 7 -18 9 -48 6

Test 4:
10
7 6 3 1 9 1 5 1 9 7

Test 5:
5
6 9 0 1 2



*/
