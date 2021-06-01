#include<cstdio> // 100 pkt
#include<new>


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)


const int INF = 1000000001, MAX_N = 100000;


int *S = new int [MAX_N+1], *t = new int [MAX_N+2], *lewo = new int [MAX_N+2], *prawo = new int [MAX_N+2], r = -1, n;

LL wyn = 0;


LL max(LL a, LL b)
{
	return (a>b) ? a : b ;	
}


void wrzuc(int x)
{
	S[ ++r ] = x;
}


void zdejmij()
{
	--r;
}


void czysc()
{
	r = -1;
}


LL szczyt()
{
	return S[r];
}


int main()
{
	scanf( "%d", &n ); // 1 <= n <= 10^5
	
	t[0] = t[n+1] = -INF; // wartownicy
	
	
	// Wczytanie ciągu
	
	REP(i,1,n)
	{
		scanf( "%d", &t[i] ); // 1 <= t[i] <= 10^9
	}
	
	
	// Wyznaczenie tablicy "lewo"
	
	wrzuc( 0 );
	
	REP(i,1,n)
	{
		while( t[ szczyt() ] >= t[i] )
		{
			zdejmij();
		}
		
		lewo[i] = szczyt();
		
		wrzuc( i );
	}
	
	
	// Czyszczenie stosu
	
	czysc();
	
	
	// Wyznaczenie tablicy "prawo"
	
	wrzuc( n + 1 );
	
	FORD(i,n,1)
	{
		while( t[ szczyt() ] >= t[i] )
		{
			zdejmij();
		}
		
		prawo[i] = szczyt();
		
		wrzuc( i );
	}
	
	REP(i,1,n)
	{
		wyn = max( wyn, (LL)t[i] * ( prawo[i] - lewo[i] - 1 ) );
	}
	
	printf( "%lld\n", wyn );
	
	return 0;
}
