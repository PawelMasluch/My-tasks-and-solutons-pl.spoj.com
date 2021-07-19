#include<cstdio> // 100 pkt
#include<algorithm>


using namespace std;


typedef long long LL;

typedef pair < LL, LL > PLL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)

#define MP make_pair

#define ST first

#define ND second


const LL MAX_N = 500000;


PLL T[MAX_N+1];

LL n, c, r = 0, PREF[MAX_N+1];


LL max(LL a, LL b)
{
	return ( a > b ) ? a : b ;
}


void wczytaj()
{
	scanf( "%lld %lld", &n, &c );
	
	LL t, z;
	
	REP(i,1,n)
	{
		scanf( "%lld %lld", &t, &z );
		
		T[i] = MP( t, z );
	}	
}


void operacje_pomocnicze()
{
	sort( T + 1, T + n + 1 );
	
	PREF[0] = 0;
	
	REP(i,1,n)
	{
		PREF[i] = PREF[ i - 1 ] + T[i].ND;
	}
}


void oblicz()
{
	LL pocz = 1, kon = pocz, tmp = T[1].ND - c, wyn = tmp;
	
	REP(i,2,n)
	{
		kon = i;
		
		tmp = ( PREF[ kon ] - PREF[ pocz - 1 ] ) - c * ( T[ kon ].ST - T[ pocz ].ST + 1 );
		
		if( T[i].ND - c > tmp )
		{
			tmp = T[i].ND - c;
			
			pocz = kon;
		}
		
		wyn = max( wyn, tmp );
	}
	
	wyn = max( wyn, 0 );
	
	printf( "%lld\n", wyn );
}


int main()
{
	wczytaj();
	
	operacje_pomocnicze();
	
	oblicz();
	
	return 0;
}
