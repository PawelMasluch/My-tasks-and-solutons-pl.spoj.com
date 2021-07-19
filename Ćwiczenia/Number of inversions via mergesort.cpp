#include<cstdio>
#include<new>


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


int *pom; // pomocnicza tablica do algorytmu Mergesort

int *t; // tablica liczb calkowitych

int n; // liczba elementow w tablicy "t"

LL wyn = 0; // wynikowa liczba inwersji


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


LL merge(int *t, int a, int sr, int b, int *pom)
{
	LL wyn = 0;
	
	int i_lewy = a, i_prawy = sr + 1, i = a;
	
	while( i_lewy <= sr  &&  i_prawy <= b )
	{
		while( t[ i_lewy ] > t[ i_prawy ]  &&  i_prawy <= b ){
			
			pom[i] = t[ i_prawy ];
			
			++i_prawy;
		}
		
		wyn += ( i_prawy - sr - 1 );
		
		pom[i] = t[ i_lewy ];
			
		++i_lewy;
		
		++i;
	}
	
	while( i_lewy <= sr )
	{
		wyn += i_prawy - sr - 1;
		
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
	
	return wyn;
}


int min(int x, int y)
{
	return (x < y) ? x : y;	
}


LL mergesort(int *t, int a, int b, int *pom) // sortujemy tablice liczb calkowitych "t" na przedziale indeksow [a,b]
{
	LL wyn = 0;
	
	int d = 2; // aktualna dlugosc blokow, ktore chcemy miec posortowane ( niezmiennik: bloki dlugosci d/2 juz sa posortowane )
	while( d < 2*n )
	{
		int pocz = a;
		while( pocz < b )
		{
			int kon = pocz + d - 1;
			int sr = (pocz + kon) / 2;
			
			wyn += merge(t, pocz, min(sr, b), min(kon, b), pom);
			
			pocz += d;
		}
		
		d *= 2;
	}
	
	return wyn;
}


void oblicz()
{
	wyn = mergesort( t, 0, n - 1, pom );
}


void wypisz()
{
	printf( "Liczba inwersji: %lld\n", wyn );
	
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
