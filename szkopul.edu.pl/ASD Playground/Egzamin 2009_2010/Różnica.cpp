#include<cstdio> // 100 pkt
#include<map>


using namespace std;


typedef map < int, int > MII;


void solve()
{
	MII M;
	
	int n, d, x, DaSie = 0;
	
	scanf( "%d %d", &n, &d );
	
	while( n )
	{
		scanf( "%d", &x );
		
		if( DaSie == 0 )
		{
			if( M[ x + d ] == 1 )
			{
				printf( "%d %d\n", x + d, x );
				
				DaSie = 1;
			}
			else
			{
				if( M[ x - d ] == 1 )
				{
					printf( "%d %d\n", x, x - d );
				
					DaSie = 1;
				}
			}
		}
		
		M[x] = 1;
		
		--n;
	}
	
	if( DaSie == 0 )
	{
		printf( "NIE\n" );
	}
}


int main()
{
	solve();
	
	return 0;
}
