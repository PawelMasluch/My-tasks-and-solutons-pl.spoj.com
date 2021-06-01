#include<cstdio> // 100 pkt
#include<algorithm>


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 100000;


int n, s[MAX_N];


void wczytaj()
{
	scanf( "%d", &n );
	
	REP(i,0,n-1)
	{
		scanf( "%d", &s[i] );
	}
}


int max(int a, int b)
{
	return ( a > b ) ? a : b ;
}


void oblicz()
{
	sort( s, s + n );
	
	int dlugosc = 1, wyn = 1;
	
	REP(i,1,n-1)
	{
		if( s[i] - s[ i - 1 ] <= 1 )
		{
			++dlugosc;
		}
		else
		{
			dlugosc = 1;
		}
		
		wyn = max( wyn, dlugosc );
	}
	
	printf( "%d\n", wyn );
}


void solve()
{
	wczytaj();
	
	oblicz();
}


int main()
{
	solve();
	
	return 0;
}
