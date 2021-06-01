#include<cstdio> // AC


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


void g(int a)
{
	if( a % 3 == 0 )
	{
		if( a % 5 == 0 )
		{
			printf( "SPOKOKOKO\n" );
		}
		else
		{
			printf( "KOKO\n" );
		}
	}
	else
	{
		if( a % 5 == 0 )
		{
			printf( "SPOKO\n" );
		}
		else
		{
			printf( "%d\n", a );
		}
	}
}


int main()
{
	int a;
	
	REP(i,1,100)
	{
		scanf( "%d", &a );
		
		g( a );
	}
	
	return 0;
}
