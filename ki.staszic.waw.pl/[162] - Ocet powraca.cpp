#include<cstdio> // 100 pkt
#include<vector>


using namespace std;


typedef vector < int > VI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back

#define C clear


const int MAX_CENA = 5000000, B = 10, r = 524288;


VI V;

int ile[MAX_CENA+1], DP[2*r], n, num_oper, rozm = 0;


int blok(int x)
{
	return ( x + B - 1 ) / B;
}


void aktualizuj(int v, int val)
{
	while( v > 0 )
	{
		DP[v] += val;
		
		v /= 2;
	}
}


void bazowe(int v, int lewy, int prawy, int a, int b)
{
	if ( lewy == a  &&  prawy == b )
	{
		V.PB( v );
		
		++rozm;
		
		return;
	}

	int sr = ( a + b ) / 2;
	
	if( prawy <= sr )
	{
		bazowe( 2 * v, lewy, prawy, a, sr );
	}
	else
	{
		if ( lewy > sr )
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


int oblicz(int a, int b)
{
	bazowe( 1, a, b, 0, r - 1 );
	
	int wyn = 0;
	
	REP(i,0,rozm-1)
	{
		wyn += DP[ V[i] ];
	}
	
	V.C();
	
	rozm = 0;
	
	return wyn;
}


int fun(int a, int b)
{
	int wyn = 0;
	
	REP(i,a,b)
	{
		wyn += ile[i];
	}
	
	return wyn;
}


int query(int a, int b)
{
	int pocz = blok( a ), kon = blok( b );
	
	return oblicz( pocz, kon ) - fun( ( pocz - 1 ) * B + 1, a - 1 ) - fun( b + 1, kon * B );
}


void zmiana(int a, int b, int zm)
{
	ile[b] += a * zm;
				
	aktualizuj( r + blok( b ), a * zm );
}


int main()
{
	int a, b;
	
	scanf( "%d", &n );
	
	while( n )
	{
		scanf( "%d %d %d", &num_oper, &a, &b );
		
		switch( num_oper )
		{
			case 0:
				
				printf( "%d\n", query( a, b ) );
				
				break;
				
				
			case 1:
				
				zmiana( a, b, 1 );
				
				break;
				
				
			case 2:
				
				if( ile[b] >= a )
				{
					printf( "OK\n" );
					
					zmiana( a, b, -1 );
				}
				else
				{
					printf( "NIE\n" );
				}
				
				break;
		}
		
		--n;
	}
	
	return 0;
}
