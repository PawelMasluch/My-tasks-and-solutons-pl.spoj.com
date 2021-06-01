#include<cstdio> // 100 pkt
#include<vector>

using namespace std;


typedef vector < int > VI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back

#define S size


const int MAX_N = 100000, UNDEF = -1;


VI G[MAX_N];

int n, odw[MAX_N], ojciec[MAX_N], preorder[MAX_N], postorder[MAX_N], czas = 0;


void wczytaj()
{
	scanf( "%d", &n );
	
	ojciec[0] = UNDEF;
	
	REP(u,1,n-1)
	{
		scanf( "%d", &ojciec[u] );
		
		G[u].PB( ojciec[u] );
		
		G[ ojciec[u] ].PB( u );
	}
}


void zapytania()
{
	int A, B;
	
	scanf( "%d", &A );
	
	while( A != -1 )
	{
		scanf( "%d", &B );
		
		if( preorder[A] < preorder[B]  &&  postorder[A] > postorder[B] )
		{
			printf( "TAK\n" );
		}
		else
		{
			printf( "NIE\n" );
		}
		
		scanf( "%d", &A );
	}
}


void oblicz(int u, int father)
{
	odw[u] = true;
	
	preorder[u] = czas;
	
	++czas;
	
	int r = G[u].S(), v;
	
	REP(i,0,r-1)
	{
		v = G[u][i];
		
		if( !odw[v]  &&  v != father )
		{
			oblicz( v, u );
		}
	}
	
	postorder[u] = czas;
	
	++czas;
}


void solve()
{
	wczytaj();
	
	oblicz( 0, ojciec[0] );
	
	zapytania();
}


int main()
{
	solve();
		
	return 0;
}
