#include<cstdio> // 100 pkt
#include<algorithm>


using namespace std;


typedef pair < int, int > PII;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define MP make_pair

#define ST first

#define ND second


const int MAX_N = 500000, INF = 1000000000 + 199;


PII t[MAX_N];

int n, wyn = INF;


void wczytaj()
{
	scanf( "%d", &n );
	
	REP(i,0,n-1)
	{
		scanf( "%d %d", &t[i].ST, &t[i].ND );
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


void oblicz()
{
	sort( t, t + n );
	
	REP(i,1,n-1)
	{
		wyn = min( wyn, max( 0, t[i].ST - t[ i - 1 ].ND ) );
	}
}


void wypisz()
{
	printf( "%d\n", wyn );
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
