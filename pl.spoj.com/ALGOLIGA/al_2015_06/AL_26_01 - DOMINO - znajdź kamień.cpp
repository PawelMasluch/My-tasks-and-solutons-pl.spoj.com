#include<cstdio> // AC
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int czy[7][7];
 
 
int main()
{
	int q, a, b, zn;
	
	scanf( "%lld", &q );
	
	while( q )
	{
		REP(i,1,27)
		{
			scanf( "%d %c %d", &a, &zn, &b );
			
			if( a <= b )
			{
				czy[b][a] = 1;
			}
			else
			{
				czy[a][b] = 1;
			}
		}
		
		REP(i,0,6)
		{
			REP(j,0,i)
			{
				if( czy[i][j] == 0 )
				{
					printf( "%d|%d\n", j, i );
				}
			}
		}
		
		REP(i,0,6)
		{
			REP(j,0,i)
			{
				czy[i][j] = 0;
			}
		}
		
		--q;
	}
	
	return 0;
} 
