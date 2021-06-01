#include<cstdio> // 100 pkt
#include<map>


using namespace std;


typedef long long LL;

typedef map < int, int > MII;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 500000;


LL wyn = 0;

int n, k, t[MAX_N];


void wczytaj()
{
	scanf( "%d %d", &n, &k );
	
	REP(i,0,n-1)
	{
		scanf( "%d", &t[i] );
	}
}


void oblicz()
{
	MII M;
	
	int i = 0, j = 1, ile_roznych = 1;
	
	M[ t[0] ] = 1;
	
	while( i < n )
	{
		while( j < n )
		{
			if( M[ t[j] ] > 0 )
			{
				++M[ t[j] ];
				
				++j;
			}
			else // M[ t[j] ] == 0
			{
				if( ile_roznych < k )
				{
					++ile_roznych;
					
					++M[ t[j] ];
					
					++j;
				}
				else
				{
					break;
				}
			}
		}
		
		wyn += ( j - i );
		
		if( M[ t[i] ] == 1 )
		{
			--ile_roznych;
		}
		
		--M[ t[i] ];
		
		++i;
	}
}


void wypisz()
{
	printf( "%lld\n", wyn );
}


void solve()
{
	wczytaj();
	
	oblicz();
	
	wypisz();
}


int main()
{
	solve();
	
	return 0;
}
