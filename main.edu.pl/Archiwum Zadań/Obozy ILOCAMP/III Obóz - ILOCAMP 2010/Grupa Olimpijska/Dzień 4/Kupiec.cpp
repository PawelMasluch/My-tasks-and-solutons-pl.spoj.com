#include<cstdio> // 100 pkt
#include<vector>


using namespace std;


typedef long long LL;

typedef pair < int, int > PII;

typedef vector < PII > VPII;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define MP make_pair

#define ST first

#define ND second

#define PB push_back

#define S size


const int MAX_N = 1000000;


VPII G[MAX_N];

LL d1[MAX_N], d2[MAX_N], wyn = 0;

int n;


LL max(LL a, LL b)
{
	return ( a > b ) ? a : b ;
}


void wczytaj()
{
	scanf( "%d", &n );
	
	int u, v, w;
	
	REP(i,1,n-1)
	{
		scanf( "%d %d %d", &u, &v, &w );
		
		--u;    --v;
		
		G[u].PB( MP( w, v ) );
		
		G[v].PB( MP( w, u ) );
	}
}


void oblicz(int u, int ojciec)
{
	int r = G[u].S(), v, w;
	
	REP(i,0,r-1)
	{
		w = G[u][i].ST;
		
		v = G[u][i].ND;
		
		if( v != ojciec )
		{
			oblicz( v, u );
			
			if( d1[v] + w > d1[u] )
			{
				d2[u] = d1[u];
				
				d1[u] = d1[v] + w;
			}
			else
			{
				d2[u] = max( d2[u], d1[v] + w );
			}
		}
	}
	
	wyn = max( wyn, d1[u] + d2[u] );
}


void wypisz()
{
	printf( "%lld\n", wyn );
}


int main()
{
	wczytaj();
	
	oblicz( 0, -1 );
	
	wypisz();
	
	return 0;
}
