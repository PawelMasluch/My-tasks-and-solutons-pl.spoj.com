#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)


const int MAX_N = 1000000;


int A[MAX_N], B[MAX_N], ile[MAX_N], n;


void init(int a, int b) // dla przedzia?u [a..b] : sr = (a+b)/2 oraz ile[sr] oznacza liczb? jedynek na przedziale [a..sr]
{
	if( a <= b )
	{
		int sr = ( a + b ) / 2;
		
		ile[ sr ] = sr - a + 1;
		
		init( a, sr - 1 );
		
		init( sr + 1, b );
	}
}


int znajdz(int x) // min i : S[0..i] == x
{
	int pocz = 0, kon = n - 1, wyn, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( ile[ sr ] >= x )
		{
			wyn = sr;
		
			--ile[ sr ];
			
			kon = sr - 1;
		}
		else
		{
			x -= ile[ sr ];
			
			pocz = sr + 1;
		}
	}
	
	return wyn;
}


int main()
{
	scanf( "%d", &n );
	
	init( 0, n - 1 );
	
	REP(i,0,n-1)
	{
		scanf( "%d", &B[i] );
	}
	
	FORD(i,n-1,0)
	{
		A[i] = znajdz( B[i] + 1 );
	}
	
	REP(i,0,n-1)
	{
		printf( "%d ", A[i] + 1 );
	}
	
	printf( "\n" );
	
	return 0;
}
