#include<cstdio> // 100 pkt
#include<algorithm>
#include<map>
#include<vector>


using namespace std;


typedef long long LL;

typedef pair < int, int > PII;

typedef vector < PII > VPII;

typedef map < int, VPII > MI_VPII;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define MP make_pair

#define ST first

#define ND second

#define PB push_back

#define S size

#define B begin

#define E end


MI_VPII M;

LL wyn = 0;

int n;


void wczytaj()
{
	scanf( "%d", &n );
	
	int x, y1, y2;
	
	while( n )
	{
		scanf( "%d %d %d", &x, &y1, &y2 );
		
		M[x].PB( MP( y1, 1 ) );
		
		M[x].PB( MP( y2, -1 ) );
		
		--n;
	}
}


void oblicz()
{
	int r, ile, zm;
	
	for(MI_VPII::iterator it = M.B(); it != M.E(); ++it) // przelatujemy wszystkie wartosci 'x'
	{
		r = ( it -> ND ).S();
		
		ile = 0;
		
		sort( ( it -> ND ).B(), ( it -> ND ).E() );
		
		REP(i,0,r-1)
		{
			zm = ( it -> ND )[i].ND;
			
			if( zm == 1 )
			{
				++ile;
			}
			else // zm == -1
			{
				wyn += --ile;
			}
		}
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
