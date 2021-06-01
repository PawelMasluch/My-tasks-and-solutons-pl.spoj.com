#include<cstdio> // 100 pkt
#include<algorithm>


using namespace std;


typedef long long LL;

typedef pair < LL, LL > PLL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)

#define MP make_pair

#define ST first

#define ND second


const LL MAX_N = 100000;


LL n;

PLL T[MAX_N];


void wczytaj()
{
	scanf( "%lld", &n );
	
	REP(i,0,n-1)
	{
		scanf( "%lld %lld", &T[i].ST, &T[i].ND );
	}
}


void oblicz()
{
	sort( T, T + n );
}


void wypisz()
{
	REP(i,0,n-1)
	{
		printf( "%lld %lld\n", T[i].ST, T[i].ND );
	}
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
