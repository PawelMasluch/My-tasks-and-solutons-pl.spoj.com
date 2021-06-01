#include<cstdio> // AC
#include<new>


using namespace std;


#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)


int NWD(int a, int b)
{
	int temp;
	
	while( b )
	{
		temp = a % b;
		
		a = b;
		
		b = temp;
	}
	
	return a;
}


int main()
{
	int *czy = new int [1000001], pom, q, k;
	
	REP(i,0,1000000,1)
	{
		czy[i] = 0;
	}
	
	REP(m,2,999,1)
	{
		REP(n,1,m-1,1)
		{
			pom = m * m + n * n;
			
			if( pom <= 1000000  &&  NWD( m, n ) == 1 )
			{
				REP(k,pom,1000000,pom)
				{
					czy[ k ] = 1;
				}
			}
		}
	}
	
	scanf( "%d", &q );
	
	REP(i,1,q,1)
	{
		scanf( "%d", &k );
		
		if( czy[k] == 1 )
		{
			printf( "TAK\n" );
		}
		else
		{
			printf( "NIE\n" );
		}
	}
	
	return 0;
}
