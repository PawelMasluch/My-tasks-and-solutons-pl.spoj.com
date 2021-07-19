#include<cstdio> // 95/100 pkt; nie jestem pewien, czy rozwiazanie przeszlo wszystkie testy
#include<iostream>
#include<vector>
#include<string>


using namespace std;


typedef vector < int > VI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)

#define PB push_back

#define S size

#define C clear


const int MAX_N = 500000, MAX_R = 524288;


VI V;

int rozm = 0, R, q, n, DP[2*MAX_R];


int f(int x)
{
	int wyn = 1;
	
	while( wyn < x )
	{
		wyn *= 2;
	}
	
	return wyn;
}


void wczytaj()
{
	scanf( "%d %d", &n, &q );
	
	R = f( n );
	
	REP(i,0,n-1)
	{
		scanf( "%d", &DP[ R + i ] );
	}
	
	REP(i,n,R-1)
	{
		DP[ R + i ] = 0;
	}
	
	FORD(i,R-1,1)
	{
		DP[i] = DP[ 2 * i ] ^ DP[ 2 * i + 1 ];
	}
}


void bazowe(int v, int lewy, int prawy, int a, int b)
{
	if( lewy == a  &&  prawy == b )
	{
		V.PB( v );   ++rozm;   return;
	}
	
	int sr = ( a + b ) / 2;
	
	if( prawy <= sr )
	{
		bazowe( 2 * v, lewy, prawy, a, sr );
	}
	else
	{
		if( lewy > sr )
		{
			bazowe( 2 * v + 1, lewy, prawy, sr + 1, b );	
		}
		else
		{
			bazowe( 2 * v, lewy, sr, a, sr );
			
			bazowe( 2 * v + 1, sr + 1, prawy, sr + 1, b );
		}
	}
}


void aktualizuj(int x, int val)
{
	DP[ x ] = val;
	
	x /= 2;
	
	while( x >= 1 )
	{
		DP[ x ] = DP[ 2 * x ] ^ DP[ 2 * x + 1 ];
		
		x /= 2;
	}
}


void modyfikuj(int a, int b)
{
	--a;  --b;
	
	int va = R + a, vb = R + b, tmp = DP[ va ];
	
	aktualizuj( va, DP[ vb ] );
	
	aktualizuj( vb, tmp );
}


void query(int a, int b)
{
	--a;  --b;
	
	bazowe( 1, a, b, 0, R - 1 );
	
	int wyn = 0;
	
	REP(i,0,rozm-1)
	{
		wyn = wyn ^ DP[ V[i] ];
	}
	
	V.C();
	
	rozm = 0;
	
	printf( "%d\n", wyn );
}


void zdarzenia()
{
	string s;
	
	int a, b;
	
	while( q )
	{
		cin >> s;
		
		scanf( "%d %d", &a, &b );
		
		if( s == "czytaj" )
		{
			query( a, b );	
		}
		else // s == "zamien"
		{
			modyfikuj( a, b );
		}
		
		--q;
	}
}


int main()
{
	wczytaj();
	
	zdarzenia();
	
	return 0;
}
