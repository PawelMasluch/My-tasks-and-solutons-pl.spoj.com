#include<cstdio> // AC


using namespace std;


#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)


const int MAX_N = 10000, M = 1000000;


int q, n, a, ile[M+1], tmp = 0, wyn = 0, m = 0;


int max(int x, int y)
{
	return ( x > y ) ? x : y ;
}


int main()
{
	scanf( "%d", &q );
	
	while( q )
	{
		scanf( "%d", &n );
		
		REP(i,0,n-1,1)
		{
			scanf( "%d", &a );
			
			m = max( m, a );
			
			++ile[a];
		}
		
		REP(i,2,m,1)
		{
			REP(j,i,m,i)
			{
				tmp += ile[j];
			}
			
			wyn = max( wyn, tmp );
			
			tmp = 0;
		}
		
		printf( "%d\n", wyn );
		
		m = 0;
		
		wyn = 0;
		
		REP(i,0,M,1)
		{
			ile[i] = 0;
		}
		
		--q;
	}
	
	return 0;
}
