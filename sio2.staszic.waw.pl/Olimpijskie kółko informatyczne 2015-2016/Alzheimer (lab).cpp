#include<cstdio> // 100 pkt
#include<queue>


using namespace std;


typedef queue < int > QI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define P push

#define F front

#define E empty

#define p pop


const int MAX_N = 1000, MAX_M = 1000, INF = 1000099;


QI Q;

char T[MAX_N][MAX_M];

bool odw[MAX_N][MAX_M];

int n, m, x[4] = { 1, -1, 0, 0 }, y[4] = { 0, 0, -1, 1 }, DP[MAX_N][MAX_M];


int min(int a, int b)
{
	return ( a < b ) ? a : b ; 
}


int main()
{
	scanf( "%d %d", &m, &n );
	
	int pocz, kon;
	
	REP(i,0,n-1)
	{
		REP(j,0,m-1)
		{
			scanf( " %c", &T[i][j] );
			
			if( T[i][j] == 'P' )
			{
				pocz = i * m + j;
			}
			
			if( T[i][j] == 'W' )
			{
				kon = i * m + j;
			}
			
			DP[i][j] = INF;
			
			odw[i][j] = false;
		}
	}
	
	int WIE = pocz / m, KOL = pocz % m, wie, kol, u, v;
	
	DP[ WIE ][ KOL ] = 0;
	
	odw[ WIE ][ KOL ] = 0;
	
	Q.P( pocz );
	
	while( !Q.E() )
	{
		u = Q.F();
		
		Q.p();
		
		WIE = u / m;
	
		KOL = u % m;
		
		REP(i,0,3)
		{
			wie = WIE + x[i];
			
			kol = KOL + y[i];
			
			v = wie * m + kol;
			
			if( 0 <= wie  &&  wie <= n - 1  &&  0 <= kol  &&  kol <= m - 1 ) // jeśli jestem nadal na planszy
			{
				if( T[ wie ][ kol ] != '#' ) // jeśli jestem na polu dozwolonym
				{
					if( !odw[ wie ][ kol ] ) // jeśli na tym polu nigdy jeszcze nie byłem
					{
						odw[ wie ][ kol ] = true;
						
						Q.P( v );
					}
					
					DP[ wie ][ kol ] = min( DP[ wie ][ kol ], DP[ WIE ][ KOL ] + 1 );
				}
			}
		}
	}
	
	WIE = kon / m;
	
	KOL = kon % m;
	
	if( DP[ WIE ][ KOL ] == INF )
	{
		printf( "NIE\n" );
	}
	else
	{
		printf( "%d\n", DP[ WIE ][ KOL ] );
	}
	
	return 0;
}
