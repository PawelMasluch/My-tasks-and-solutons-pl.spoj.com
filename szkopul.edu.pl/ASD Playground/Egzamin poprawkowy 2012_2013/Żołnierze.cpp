#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 500000, UNDEF = -1;


int n, lewy[MAX_N+1], prawy[MAX_N+1];


void wczytaj()
{
	scanf( "%d", &n );
}


void init()
{
	REP(i,1,n)
	{
		lewy[i] = i - 1;
		
		prawy[i] = i + 1;
	}
	
	lewy[1] = prawy[n] = UNDEF;
}


void query()
{
	int x;
	
	scanf( "%d", &x );
	
	printf( "%d %d\n", lewy[x], prawy[x] );
	
	if( lewy[x] != UNDEF )
	{
		prawy[ lewy[x] ] = prawy[x];
	}
	
	if( prawy[x] != UNDEF )
	{
		lewy[ prawy[x] ] = lewy[x];
	}
}


void obsluz_zapytania()
{
	REP(i,1,n)
	{
		query();
	}
}


void solve()
{
	wczytaj();
	
	init();
	
	obsluz_zapytania();
}


int main()
{
	solve();
	
	return 0;
}
