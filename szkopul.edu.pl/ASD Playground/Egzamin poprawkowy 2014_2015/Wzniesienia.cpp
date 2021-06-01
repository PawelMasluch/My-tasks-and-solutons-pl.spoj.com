#include<cstdio> // 100 pkt
#include<vector>
#include<algorithm>


using namespace std;


typedef long long LL;

typedef pair < int, int > PII;

typedef vector < PII > VPII;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back

#define S size

#define B begin

#define E end

#define MP make_pair

#define ST first

#define ND second


const int MAX_N = 500000;


VPII G[MAX_N];

LL wyn = 0;

int n, m;


void wczytaj()
{
	scanf( "%d %d", &n, &m );
	
	int u, v, w;
	
	REP(i,1,m)
	{
		scanf( "%d %d %d", &u, &v, &w );
		
		--u;    --v;
		
		G[u].PB( MP( w, v ) );
		
		G[v].PB( MP( w, u ) );
	}
}


void oblicz()
{
	int r, w_akt, w, ile;
	
	REP(u,0,n-1)
	{
		sort( G[u].B(), G[u].E() );
		
		r = G[u].S();
		
		if( r > 0 )
		{
			w_akt = G[u][0].ST;
			
			ile = 1;
			
			REP(i,1,r-1)
			{
				w = G[u][i].ST;
				
				if( w == w_akt )
				{
					++ile;
				}
				else
				{
					wyn += (LL)( i - ile ) * ile;
					
					ile = 1;
					
					w_akt = w;
				}
			}
			
			wyn += (LL)( r - ile ) * ile;
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
