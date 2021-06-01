#include<iostream> // 100 pkt


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)


const int ILE = 19, CYFRY = 10, WIERSZE = 5, KOLUMNY = 8; // parametrow tych (poza parametrem ILE) nie radze zmieniac (nie liczac parametru ILE, wprowadzilem te nazwy dla czytelnosci, ktory indeks tablicy 'T' co oznacza)


char T[CYFRY][WIERSZE][KOLUMNY]; // dla kazdej cyfry mamy jej mape

int t[ILE], r = 0; // cyfry liczby N oraz liczba cyfr liczby N

LL N; // liczba do przerobienia na kropki i hasze


void init() // ustawianie tablicy 'T'
{
	// zainicjowanie tablicy 'T' kropkami
	
	REP(i,0,CYFRY-1)
	{
		REP(j,0,WIERSZE-1)
		{
			REP(k,0,KOLUMNY-1)
			{
				T[i][j][k] = '.' ;
			}
		}
	}
	
	
	// 0
	
	REP(k,2,5) // kolumny
	{
		T[0][0][k] = '#' ;
		
		T[0][WIERSZE-1][k] = '#' ;
	}
	
	REP(j,1,3) // wiersze
	{
		T[0][j][1] = T[0][j][2] = '#' ;
		
		T[0][j][5] = T[0][j][6] = '#' ;
	}
	
	
	// 1
	
	T[1][1][2] = '#' ;
	
	REP(j,0,3) // wiersze
	{
		T[1][j][3] = T[1][j][4] = '#' ;
	}
	
	REP(k,1,6) // kolumny
	{
		T[1][WIERSZE-1][k] = '#' ;
	}
	
	
	// 2
	
	REP(k,2,5) // kolumny
	{
		T[2][0][k] = T[2][2][k] = '#' ;	
	}
	
	T[2][1][5] = T[2][1][6] = '#' ; 
	
	T[2][3][1] = T[2][3][2] = '#' ;
	
	REP(k,1,6) // kolumny
	{
		T[2][WIERSZE-1][k] = '#' ;
	}
	
	
	// 3
	
	REP(k,1,6) // kolumny
	{
		T[3][0][k] = '#' ;
	}
	
	T[3][1][4] = T[3][1][5] = '#' ;
	
	T[3][2][3] = T[3][2][4] = T[3][2][5] = '#' ;
	
	T[3][3][5] = T[3][3][6] = '#' ;
	
	REP(k,1,5) // kolumny
	{
		T[3][WIERSZE-1][k] = '#' ;
	}
	
	
	// 4
	
	REP(j,0,1) // wiersze
	{
		T[4][j][1] = T[4][j][2] = '#' ;
	}
	
	REP(k,1,4) // kolumny
	{
		T[4][2][k] = '#' ;
	}
	
	REP(j,0,WIERSZE-1) // wiersze
	{
		T[4][j][5] = T[4][j][6] = '#' ;
	}
	
	
	// 5
	
	REP(k,1,6) // kolumny
	{
		T[5][0][k] = '#' ;
	}
	
	T[5][1][1] = T[5][1][2] = T[5][3][5] = T[5][3][6] = '#' ;
	
	REP(k,2,5) // kolumny
	{
		T[5][2][k] = '#' ;
	}
	
	REP(k,1,5) // kolumny
	{
		T[5][WIERSZE-1][k] = '#' ;
	}
	
	
	// 6
	
	REP(j,0,1) // wiersze
	{
		T[6][j][3-j] = T[6][j][4-j] = '#' ;
	}
	
	REP(k,1,5) // kolumny
	{
		T[6][2][k] = '#' ;
	}
	
	T[6][3][1] = T[6][3][2] = T[6][3][5] = T[6][3][6] = '#' ;
	
	REP(k,2,5) // kolumny
	{
		T[6][WIERSZE-1][k] = '#' ;
	}
	
	
	// 7
	
	REP(k,1,4) // kolumny
	{
		T[7][0][k] = '#' ;
	}
	
	REP(j,0,WIERSZE-1) // wiersze
	{
		T[7][j][5-j] = T[7][j][6-j] = '#' ;
	}
	
	
	// 8
	
	REP(k,2,5) // kolumny
	{
		T[8][0][k] = T[8][2][k] = T[8][4][k] = '#' ;
	}
	
	REP(k,1,2) // kolumny
	{
		T[8][1][k] = T[8][3][k] = '#' ;
	}
	
	REP(k,5,6) // kolumny
	{
		T[8][1][k] = T[8][3][k] = '#' ;
	}
	
	
	// 9
	
	REP(k,2,5) // kolumny
	{
		T[9][0][k] = '#' ;
	}
	
	REP(j,1,2) // wiersze
	{
		T[9][j][j] = T[9][j][j+1] = '#' ;
	}
	
	REP(j,1,WIERSZE-1) // wiersze
	{
		T[9][j][6-j] = T[9][j][7-j] = '#' ;
	}
}


void wczytaj()
{
	cin >> N;
}


void rozloz(LL x)
{
	do
	{
		t[r] = x % 10;
		
		++r;
		
		x /= 10;
	}
	while( x > 0 );
}


void oblicz()
{
	rozloz( N );
}


void wypisz()
{
	REP(i,0,WIERSZE-1) // kazdy wiersz
	{
		FORD(j,r-1,0) // kazda cyfra
		{
			REP(k,0,KOLUMNY-1) // kazda kolumna
			{
				cout << T[ t[j] ][i][k] ;
			}
		}
		
		cout << endl;
	}
	
	cout << endl;
}


void solve()
{
	init();
	
	wczytaj();
	
	oblicz();
	
	wypisz();
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	solve();
	
	return 0;
}
