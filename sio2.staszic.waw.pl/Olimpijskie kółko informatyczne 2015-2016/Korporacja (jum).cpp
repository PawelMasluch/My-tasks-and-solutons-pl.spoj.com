#include<cstdio> // 100 pkt
#include<vector>


using namespace std;


typedef vector < int > VI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back

#define S size


const int MAX_N = 500000, UNDEF = -1;


VI G[MAX_N];

int n, ojciec[MAX_N], pre[MAX_N], post[MAX_N], czas = 0, odw[MAX_N];


void wczytaj()
{
	scanf( "%d", &n );
	
	ojciec[0] = UNDEF;
	
	int u;
	
	REP(v,1,n-1)
	{
		scanf( "%d", &u );
		
		ojciec[v] = u;
		
		G[u].PB( v );
		
		G[v].PB( u );
	}
}


void DFS(int u)
{
	pre[u] = czas;
	
	++czas;
	
	odw[u] = true;
	
	int r = G[u].S(), v;
	
	REP(i,0,r-1)
	{
		v = G[u][i];
		
		if( !odw[v] )
		{
			DFS( v );
		}
	}
	
	post[u] = czas;
	
	++czas;
}


void obliczenia_wstepne()
{
	DFS( 0 );
}


bool f(int a, int b)
{
	if( pre[a] < pre[b]  &&  post[a] > post[b] )
	{
		return true;	
	}
	
	return false;
}


void query(int a, int b)
{
	if( f( a, b ) == true )
	{
		printf( "TAK\n" );
	}
	else
	{
		printf( "NIE\n" );
	}
}


void zapytania()
{
	int a, b;
	
	scanf( "%d", &a );
	
	while( a != -1 )
	{
		scanf( "%d", &b );
		
		query( a, b );
		
		scanf( "%d", &a );
	}
}


int main()
{
	wczytaj();
	
	obliczenia_wstepne();
	
	zapytania();
	
	return 0;
}
