#include<cstdio> // AC
#include<map>
#include<vector>
#include<bitset>


using namespace std;


typedef long long LL;

typedef vector < int > VI;

typedef map < int, int > MII;


#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)

#define PB push_back


const int p = 1000000007, N = 31623, ZAKRES = 178;


MII M;

VI d;

bitset < N + 1 > czy;

int n, MX = 0;


void sito()
{
	czy[0] = czy[1] = 0;
	
	REP(i,2,N,1)
	{
		czy[i] = 1;
	}
	
	REP(i,2,ZAKRES,1)
	{
		if( czy[i] == 1 )
		{
			REP(j,i*i,N,i)
			{
				czy[j] = 0;
			}
		}
	}
	
	REP(i,2,N,1)
	{
		if( czy[i] == 1 )
		{
			d.PB( i );
			
			++MX;
		}
	}
}


int max(int a, int b)
{
	return ( a > b ) ? a : b ;
}


void rozloz(int x)
{
	int i = 0, tmp = x, ile = 0;
	
	while( d[i] * d[i] <= x  &&  tmp > 1  &&  i < MX )
	{
		while( tmp % d[i] == 0 )
		{
			++ile;
			
			tmp /= d[i];
		}
		
		if( ile > 0 )
		{
			M[ d[i] ] = max( M[ d[i] ], ile );
		}
		
		ile = 0;
		
		++i;
	}
	
	if( tmp > 1 )
	{
		M[ tmp ] = max( M[ tmp ], 1 );
	}
}


void wczytaj()
{
	scanf( "%d", &n );
	
	int a;
	
	REP(i,1,n,1)
	{
		scanf( "%d", &a );
		
		rozloz( a );
	}
}


void oblicz()
{
	LL wyn = 1;
	
	for(MII::iterator it = M.begin(); it != M.end(); ++it)
	{
		wyn = ( wyn * ( ( it -> second ) + 1 ) ) % p;
	}
	
	wyn = ( wyn - n + p ) % p;
	
	printf( "%lld\n", wyn );
}


int main()
{
	sito();
	
	wczytaj();
	
	oblicz();
	
	return 0;
}
