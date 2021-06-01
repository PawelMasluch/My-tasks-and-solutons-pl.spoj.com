#include<cstdio> // 100 pkt
#include<queue>


using namespace std;


typedef pair < int, int > PII;

typedef priority_queue < PII > PQ_PII;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define MP make_pair

#define ST first

#define ND second

#define T top

#define P push

#define p pop

#define E empty


const int MAX_N = 100000;


PQ_PII PQ;

bool odw[MAX_N+1];

int ile[MAX_N+1], q, n;


int main()
{
	scanf( "%d", &n );
	
	REP(i,1,n)
	{
		scanf( "%d", &ile[i] );
		
		PQ.P(  MP( ile[i], i )  );
	}
	
	scanf( "%d", &q );
	
	char zn;
	
	int nr, liczba;
	
	while( q )
	{
		scanf( " %c", &zn );
		
		if( zn == 'R' )
		{
			scanf( "%d %d", &nr, &liczba );
			
			ile[ nr ] -= liczba;
			
			PQ.P(  MP( ile[ nr ], nr )  );
		}
		else // zn == 'M'
		{
			while( !PQ.E() )
			{
				liczba = PQ.T().ST;
				
				nr = PQ.T().ND;
				
				PQ.p();
				
				if( !odw[ nr ]  &&  ile[ nr ] == liczba )
				{
					printf( "%d ", nr );
					
					odw[ nr ] = true;
					
					break;
				}
			}
		}
		
		--q;
	}
	
	printf( "\n" );
	
	return 0;
}
