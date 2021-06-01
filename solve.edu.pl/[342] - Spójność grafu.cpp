#include<cstdio> // 100 pkt
#include<vector>
#include<stack>


using namespace std;


typedef vector < int > VI;

typedef stack < int > SI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back

#define S size

#define C clear

#define P push

#define p pop

#define T top

#define E empty


const int MAX_N = 1000000;


SI stos;

VI G[MAX_N];

bool odw[MAX_N];

int q, n, m;


void wczytaj()
{
	scanf( "%d %d", &n, &m );
	
	int a, b;
	
	REP(i,1,m)
	{
		scanf( "%d %d", &a, &b );
		
		--a;  --b;
		
		G[a].PB( b );
		
		G[b].PB( a );
	}
}


int DFS(int u) // ta funkcja zwraca rozmiar skladowej (w liczbie wierzcholkow), w ktorej jest wierzcholek "u"
{
	odw[u] = true;
	
	stos.P( u );
	
	int r, v, wyn = 1;
	
	while( !stos.E() )
	{
		u = stos.T();   stos.p();
		
		r = G[u].S();
		
		REP(i,0,r-1)
		{
			v = G[u][i];
			
			if( !odw[v] )
			{
				odw[v] = true;
				
				++wyn;
				
				stos.P( v );
			}
		}
	}
	
	return wyn;
}


void czysc()
{
	REP(u,0,n-1)
	{
		odw[u] = false;
		
		G[u].C();
	}
}


void query()
{
	if( DFS( 0 ) == n )
	{
		printf( "TAK\n" );
	}
	else
	{
		printf( "NIE\n" );
	}
	
	czysc();
}


void zapytania()
{
	scanf( "%d", &q );
	
	while( q )
	{
		wczytaj();
		
		query();
		
		--q;
	}
}


int main()
{
	zapytania();
	
	return 0;
}
