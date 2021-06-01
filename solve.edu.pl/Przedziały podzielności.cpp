#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


int S(int x) // x >= 0
{
	int wyn = 0;
	
	while( x > 0 )
	{
		wyn += x % 10;
		
		x /= 10;
	}
	
	return wyn;
}


int f(int a, int b)
{
	if( a == 0 )
	{
		++a;
	}
	
	if( b == 0 )
	{
		--b;
	}
	
	int wyn = 0;
	
	REP(i,a,b)
	{
		if( i % S( i ) == 0 )
		{
			++wyn;
		}
	}
	
	return wyn;
}


int main()
{
	int a, b;
	
	scanf( "%d %d", &a, &b );
	
	printf( "%d\n", f( a, b ) );
	
	return 0;
}
