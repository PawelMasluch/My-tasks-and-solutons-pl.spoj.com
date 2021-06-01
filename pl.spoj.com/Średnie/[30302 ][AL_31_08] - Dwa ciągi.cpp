#include<cstdio> // AC


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)


const int MAX_N = 100000, INF = 10000000 + 199; // maksymalna dlugosc ciagu oraz umowna wartosc nieskonczonosci


int q, n, t[MAX_N+1], pref[MAX_N+1], suf[MAX_N+2], S[MAX_N+1];


void wczytaj()
{
	scanf( "%d", &n ); // dlugosc ciagu
	
	REP(i,1,n)
	{
		scanf( "%d", &t[i] ); // i-ty wyraz ciagu
	}
}


int min(int a, int b)
{
	return ( a < b ) ? a : b ;
}


int max(int a, int b)
{
	return ( a > b ) ? a : b ;
}


void ustaw()
{
	S[0] = -INF;
	
	REP(i,1,n)
	{
		S[i] = INF;
	}
}


int bin(int x) // wynik to takie 'i' (zawsze istnieje), ze S[i-1] < x <= S[i]
{
	int pocz = 1, kon = n, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( S[sr-1] < x )
		{
			if( x <= S[sr] )
			{
				return sr;
			}
			
			pocz = sr + 1;
		}
		else
		{
			kon = sr - 1;
		}
	}
}

void preprocessing() // obliczenie tablic 'pref', suf'
{
	// obliczenie tablicy pref'
	
	ustaw();
	
	pref[0] = 0;
	
	int dlugosc;
	
	REP(i,1,n)
	{
		dlugosc = bin( t[i] ); // dlugosc najdluzszego podciagu rosnacego dla ciagu t[1..i], o koncu na pozycji 'i'
		
		S[ dlugosc ] = t[i];
		
		pref[i] = max( pref[ i - 1 ], dlugosc );
	}
	
	
	// obliczenie tablicy 'suf'
	
	ustaw();
	
	suf[n+1] = 0;
	
	FORD(i,n,1)
	{
		dlugosc = bin( t[i] ); // dlugosc najdluzszego podciagu rosnacego dla ciagu t[n..i], o koncu na pozycji 'i'
		
		S[ dlugosc ] = t[i];
		
		suf[i] = max( suf[ i + 1 ], dlugosc );
	}
}


void oblicz()
{
	preprocessing();
	
	int wyn = n; // wynik dla aktualnego zapytania (tj. ciagu liczbowego) - poczatkowo zakladamy, ze usuwamy caly ciag liczbowy
	
	REP(i,0,n)
	{
		wyn = min( wyn, n - pref[i] - suf[i+1] );
	}
	
	printf( "%d\n", wyn );
}


void query()
{
	wczytaj();
	
	oblicz();
}


void obsluz_zapytania()
{
	scanf( "%d", &q ); // liczba zapytan
	
	while( q )
	{
		query();
		
		--q;
	}
}


int main()
{
	obsluz_zapytania();
	
	return 0;
}
