#include<cstdio> // AC
#include<new>
#include<vector>


using namespace std;


typedef vector < int > VI;


#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)

#define PB push_back

#define C clear 


VI v;

int MAX_N = 8000000, *d = new int [MAX_N+1], zakres, q, a, r = 0;

bool *czy = new bool [MAX_N+1];


void sito()
{
	zakres = 2828;
	
	REP(i,0,1,1)
	{
		czy[i] = false;
		
		d[i] = 1;
	}
	
	REP(i,2,MAX_N,1)
	{
		czy[i] = true;
		
		d[i] = i;
	}
	
	REP(i,2,zakres,1)
	{
		if( czy[i] == true )
		{
			REP(j,i*i,MAX_N,i)
			{
				if( czy[j] == true )
				{
					czy[j] = false;
					
					d[j] = i;
				}
			}
		}
	}
}


void f(int a)
{
	if( a == 1 )
	{
		printf( "1\n" );
		
		return;
	}
	
	while( a > 1 )
	{
		v.PB( d[a] );
		
		++r;
		
		a /= d[a];
	}
		
	REP(i,0,r-2,1)
	{
		printf( "%d*", v[i] );
	}
		
	printf( "%d\n", v[ r - 1 ] );
		
	v.C();
		
	r = 0;
}


int main()
{
	sito();
	
	scanf( "%d", &q );
	
	REP(i,1,q,1)
	{
		scanf( "%d", &a );
		
		f( a );
	}
	
	return 0;
}

