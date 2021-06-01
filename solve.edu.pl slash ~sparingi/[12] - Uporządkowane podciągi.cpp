#include<cstdio> // 100 pkt
#include<map>


using namespace std;


typedef map < int, int > MII;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)


const int MAX_R = 524288, INF = 1000000099, MX = 30;


int q, n, R, rozm = 0, DP[3][2*MAX_R], V[MX];


/*

dla i-tego elementu ci¹gu, nastêpnik(i) oznacza takie j > i, ¿e j-ty element ci¹gu równy jest i-temu elementowi ci¹gu (jeœli takie 'j' nie istnieje, to przyjmujemy j = INF)

DP[0][v] - minimalny element ci¹gu, bêd¹cy w poddrzewie 'v'
DP[1][v] - maksymalny element ci¹gu, bêd¹cy w poddrzewie 'v'
DP[2][v] - minimalna wartoœæ funkcji nastêpnik, bêd¹ca w poddrzewie 'v'

*/


int min(int a, int b)
{
	return ( a < b ) ? a : b ;
}


int max(int a, int b)
{
	return ( a > b ) ? a : b ;
}


int f(int x)
{
	int wyn = 1;
	
	while( wyn < x )
	{
		wyn <<= 1;
	}
	
	return wyn;
}


void wczytaj()
{
	scanf( "%d %d", &n, &q );
	
	R = f( n );
	
	REP(i,R,R+n-1)
	{
		scanf( "%d", &DP[0][i] );
		
		DP[1][i] = DP[0][i];
	}
	
	
	// Wyznaczanie funkcji nastêpnik
	
	MII M;
	
	int tmp, pom;
	
	FORD(i,R+n-1,R)
	{
		pom = DP[0][i];
		
		tmp = M[ pom ];
		
		if( tmp == 0 )
		{
			DP[2][i]    =    INF;
		}
		else
		{
			DP[2][i]    =    tmp;
		}
		
		M[ pom ]   =   i - R;
	}
	
	FORD(i,R-1,1)
	{
		DP[0][i] = min(   DP[0][ i << 1 ],   DP[0][ ( i << 1 ) + 1 ]   );
		
		DP[1][i] = max(   DP[1][ i << 1 ],   DP[1][ ( i << 1 ) + 1 ]   );
		
		DP[2][i] = min(   DP[2][ i << 1 ],   DP[2][ ( i << 1 ) + 1 ]   );
	}
}


void bazowe(int v, int L, int R, int a, int b)
{
	if( L == a  &&  R == b )
	{
		V[ rozm ] = v;
		
		++rozm;
		
		return;
	}
	
	int sr = ( a + b ) >> 1;
	
	if( R <= sr )
	{
		bazowe( v << 1, L, R, a, sr );
	}
	else
	{
		if( L > sr )
		{
			bazowe( ( v << 1 ) + 1, L, R, sr + 1, b );
		}
		else
		{
			bazowe( v << 1, L, sr, a, sr );
			
			bazowe( ( v << 1 ) + 1, sr + 1, R, sr + 1, b );
		}
	}
}


void query(int a, int b)
{
	--a;   --b;
	
	int wyn0 = INF, wyn1 = -INF, wyn2 = INF;
	
	bazowe( 1, a, b, 0, R - 1 );
	
	REP(i,0,rozm-1)
	{
		wyn0 = min( wyn0, DP[0][ V[i] ] );
		
		wyn1 = max( wyn1, DP[1][ V[i] ] );
		
		wyn2 = min( wyn2, DP[2][ V[i] ] );
	}
	
	if( wyn1 - wyn0 == b - a  &&  wyn2 > b )
	{
		printf( "TAK\n" );
	}
	else
	{
		printf( "NIE\n" );
	}
	
	rozm = 0;
}


void obsluz()
{
	int a, b;
	
	while( q )
	{
		scanf( "%d %d", &a, &b );
		
		query( a, b );
		
		--q;
	}
}


int main()
{
	wczytaj();
	
	obsluz();
	
	return 0;
}
