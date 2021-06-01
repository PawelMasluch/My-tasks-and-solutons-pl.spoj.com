#include<cstdio> // 100 pkt
#include<stack>


using namespace std;


typedef stack < int > SI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)


const int MAX_N = 5000;


SI S;

int t[MAX_N+1], DP[MAX_N+1], last[MAX_N+1], n, k, q, wyn = 0, ind = 0; // t[1..MAX_N], last[1..MAX_N]


int f(int x)
{
	return (x>=0) ? x : -x ;
}


int main()
{
	scanf( "%d", &q );
	
	while( q )
	{
		scanf( "%d %d", &n, &k );
		
		REP(i,1,n)
		{
			scanf( "%d", &t[i] );
			
			FORD(j,i-1,1)
			{
				if( f( t[i] - t[j] ) <= k  &&  DP[j] >= DP[i] )
				{
					DP[i] = DP[j];
					
					last[i] = j;
				}
			}
			
			++DP[i];
			
			if( DP[i] > wyn )
			{
				wyn = DP[i];
				
				ind = i;
			}
		}
		
		printf( "%d\n", wyn );
	
		while( ind > 0 )
		{
			S.push( ind );
			
			ind = last[ ind ];
		}
		
		while( !S.empty() )
		{
			printf( "%d ", t[ S.top() ] );
			
			S.pop();
		}
		
		printf( "\n" );
		
		wyn = ind = 0;
		
		REP(i,1,n)
		{
			last[i] = DP[i] = 0;
		}
		
		--q;
	}
	
	return 0;
}
