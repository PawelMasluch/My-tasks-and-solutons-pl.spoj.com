#include<cstdio> // 88 pkt na 100 mo?liwych ; rozwiazanie przeszlo wszystkie testy


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_B = 20, MAX_P = 600, modulo = 1000000007;


int DP[MAX_P][MAX_B][2], n, b, p; // DP[r][a][i] - liczba dodatnich liczb i-cyfrowych (system o podstawie b, cyfry uporzadkowane nierosnaco) dajacych reszte r z dzielenia przez p, ostatnia cyfra to a


void wczytaj()
{
	scanf( "%d%d%d", &n, &b, &p );
}


void oblicz()
{
	// 1. faza - dodatnie liczby 1-cyfrowe (nie robie mod modulo, bo nie musze)
	
	REP(a,1,b-1) // dla kazdej dodatniej cyfry
	{
		++DP[a%p][a][1];
	}
	
	
	// 2. faza - dodatnie liczby i-cyfrowe (i >= 2)
	
	int r_nowe;
	
	REP(i,2,n) // teraz liczymy liczby i-cyfrowe
	{
		REP(r,0,p-1)
		{
			REP(a,0,b-1)
			{
				DP[r][a][i&1] = 0;
			}
		}
		
		REP(r,0,p-1) // reszta dla liczby (i-1)-cyfrowej to r
		{
			REP(a,0,b-1) // ostatnia cyfra liczby (i-1)-cyfrowej to a
			{
				r_nowe = ( b * r ) % p;
				
				REP(a_nowe,0,a) // kazda mozliwa kolejna cyfra
				{
					DP[ ( r_nowe + a_nowe ) % p ][a_nowe][i&1]    =    (   DP[ ( r_nowe + a_nowe ) % p ][a_nowe][i&1]   +   DP[r][a][(i-1)&1]   ) % modulo;
				} 
			}
		}
	} 
}


void wypisz()
{
	int wyn = 0;
	
	REP(a,0,b-1)
	{
		wyn = ( wyn + DP[0][a][n&1] ) % modulo;
	}
	
	printf( "%d\n", wyn );
}


int main()
{
	wczytaj();
	
	oblicz();
	
	wypisz();
	
	return 0;
}
