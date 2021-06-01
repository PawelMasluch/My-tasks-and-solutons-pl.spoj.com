#include<cstdio> // AC


using namespace std;


typedef long long LL;


struct prostokat
{
	LL s[4];
};


#define REP(i,n) for(int i=0; i<n; ++i)

#define x1 s[0]

#define y1 s[1]

#define x2 s[2]

#define y2 s[3]


prostokat t[2];


void wczytaj()
{
	REP(i,2)
	{
		REP(j,4)
		{
			scanf( "%lld", &t[i].s[j] );
		}
	}
}


LL pole(prostokat &P)
{
	LL a = P.x2 - P.x1;
	
	LL b = P.y2 - P.y1;
	
	if( a <= 0  ||  b <= 0 )
	{
		return 0;
	}
	
	return a * b;
}


LL min(LL a, LL b)
{
	return ( a < b ) ? a : b ;
}


LL max(LL a, LL b)
{
	return ( a > b ) ? a : b ;
}


LL pole_wspolne(prostokat &P1, prostokat &P2)
{
	prostokat P;
	
	P.x1 = max( P1.x1, P2.x1 );
	
	P.y1 = max( P1.y1, P2.y1 );
	
	P.x2 = min( P1.x2, P2.x2 );
	
	P.y2 = min( P1.y2, P2.y2 );
	
	return pole( P );
}


void oblicz()
{
	printf( "%lld\n", pole( t[0] ) + pole( t[1] ) - pole_wspolne( t[0], t[1] ) );
}


int main()
{
	wczytaj();
	
	oblicz();
	
	return 0;
}
