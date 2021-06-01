#include<cstdio> // 100 pkt
#include<new>
#include<vector>


using namespace std;


typedef pair < int, int > PII;

typedef vector < PII > VPII;


#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)

#define PB push_back

#define C clear

#define MP make_pair

#define ST first

#define ND second


VPII v;

int MAX_N = 8000000, zakres, q, a, r = 0;

PII *d = new PII [MAX_N+1];

bool *czy = new bool [MAX_N+1];


void sito()
{
	zakres = 2828;
	
	REP(i,0,1,1)
	{
		czy[i] = false;
		
		d[i] = MP( 1, 1 );
	}
	
	REP(i,2,MAX_N,1)
	{
		czy[i] = true;
		
		d[i] = MP( i, 1 );
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
					
					if( d[ j / i ].ST == i )
					{
						d[j] = MP( i, d[ j / i ].ND + 1 );
					}
					else
					{
						d[j] = MP( i, 1 );
					}
				}
			}
		}
	}
}


int fast_power(int a, int b)
{
	int wyn = 1;
	
	while( b )
	{
		if( b % 2 == 1 )
		{
			wyn *= a;
		}
		
		b /= 2;
		
		if( b )
		{
			a *= a;
		}
	}
	
	return wyn;
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
		
		a /= fast_power( d[a].ST, d[a].ND );
	}
		
	REP(i,0,r-2,1)
	{
		REP(j,1,v[i].ND,1)
		{
			printf( "%d*", v[i].ST );	
		}
	}
		
	REP(i,1,v[ r - 1 ].ND-1,1)
	{
		printf( "%d*", v[ r - 1 ].ST );
	}
	
	printf( "%d\n", v[ r - 1 ].ST );
		
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
