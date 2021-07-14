#include<cstdio> // AC
 
 
using namespace std;
 
 
#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)
 
 
const int MAX_N = 1e6, ILE = 25;  // ILE - tyle jest liczb pierwszych do 100
 
 
int q, n, tmp, czy[MAX_N+1], p[ILE] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
 
 
void preprocessing()
{
	REP(i,1,MAX_N,1)
	{
		czy[i] = 1;
	}
	
	REP(i,0,ILE-1,1)
	{
		tmp = p[i] * p[i] * p[i];
		
		REP(j,tmp,MAX_N,tmp)
		{
			czy[j] = 0;
		}
	}
	
	REP(i,1,MAX_N,1)
	{
		czy[i] += czy[ i - 1 ];
	}
}
 
 
int main()
{
	preprocessing();
	
	scanf( "%d", &q );
	
	REP(i,1,q,1)
	{
		scanf( "%d", &n );
		
		printf( "Case %d: ", i );
		
		if( czy[n] == czy[ n - 1 ] )
		{
			printf( "Not Cube Free\n" );
		}
		else
		{
			printf( "%d\n", czy[n] );
		}
	}
	
	return 0;
} 
