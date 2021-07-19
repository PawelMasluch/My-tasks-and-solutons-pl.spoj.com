#include<cstdio> // 100 pkt


using namespace std;


void f(int x)
{
	if( x < 0 )
	{
		printf( "(%d)", x );
	}
	else
	{
		printf( "%d", x );	
	}
}


int main()
{
	char zn = '+';
	
	int a, b, ile = 1, tmp, best;
	
	scanf( "%d %d", &a, &b );
	
	best = a + b;
	
	tmp = a - b;
	
	if( tmp > best )
	{
		zn = '-';
		
		best = tmp;
	}
	else
	{
		if( tmp == best )
		{
			++ile;
		}
	}
	
	tmp = a * b;
	
	if( tmp > best )
	{
		zn = '*';
		
		best = tmp;
	}
	else
	{
		if( tmp == best )
		{
			++ile;
		}
	}
	
	if( ile > 1 )
	{
		printf( "NIE\n" );
		
		return 0;
	}
	
	f( a );
	
	printf( "%c", zn );
	
	f( b );
	
	printf( "=" );
	
	f( best );
	
	return 0;
}
