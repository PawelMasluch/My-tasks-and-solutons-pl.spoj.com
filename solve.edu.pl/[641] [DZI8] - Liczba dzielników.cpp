#include<cstdio> // 100 pkt
#include<vector>


using namespace std;


typedef pair < int, int > PII;


#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)

#define MP make_pair

#define ST first

#define ND second


const int MAX_N = 500000, MAX_Q = 1000000;


PII dz[MAX_N+1];

int q, ile[MAX_N+1], query[MAX_Q];


void init()
{
	REP(i,1,MAX_N,1)
	{
		dz[i] = MP( i, 1 ); // maksymalny dzielnik pierwszy
	}
	
	ile[1] = 1;
}


int fp(int a, int b)
{
	int wyn = 1;
	
	while( b )
	{
		if( b & 1 )
		{
			wyn *= a;
		}
		
		b >>= 1;
		
		if( b )
		{
			a *= a;
		}
	}
	
	return wyn;
}


void sito()
{
	init();
	
	int p, exp;
	
	REP(i,2,MAX_N,1)
	{
		if( dz[i].ST == i ) // liczba pierwsza
		{
			REP(j,2*i,MAX_N,i)
			{
				dz[j].ST = i;
				
				if( dz[ j / i ].ST == i )
				{
					dz[j].ND = dz[ j / i ].ND + 1;
				}
				else
				{
					dz[j].ND = 1;
				}
			}
		}
		
		p = dz[i].ST;
		
		exp = dz[i].ND;
		
		ile[i] = ile[ i / fp( p, exp ) ] * ( exp + 1 );
	}
}


void preprocessing()
{
	sito();
}


void obsluz_zapytania()
{
	scanf( "%d", &q );
	
	REP(i,1,q,1)
	{
		scanf( "%d", &query[i] );
	}
	
	REP(i,1,q,1)
	{
		printf( "%d ", ile[ query[i] ] );
	}
	
	printf( "\n" );
}


void solve()
{
	preprocessing();
	
	obsluz_zapytania();
}


int main()
{
	solve();
	
	return 0;
}
