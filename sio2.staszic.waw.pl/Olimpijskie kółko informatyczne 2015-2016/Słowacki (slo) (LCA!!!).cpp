#include<cstdio> // 100 pkt
#include<vector>


using namespace std;


typedef long long LL;

typedef pair < LL, LL > PLL;

typedef vector < LL > VLL;

typedef vector < PLL > VPLL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)

#define FORD(i,b,a) for(LL i=b; i>=a; --i)

#define PB push_back

#define S size

#define C clear

#define MP make_pair

#define ST first

#define ND second


const LL MAX_N = 500000, MAX_R = 1048576, INF = 1000099, UNDEF = -1;


VLL V;

VPLL G[MAX_N];

bool odw[MAX_N];

LL n, R, fun[MAX_N], num = 0, d[MAX_N], ind = 0, DP[2*MAX_R], gdzie[MAX_N], rozm = 0;


LL min(LL a, LL b)
{
	return ( a < b ) ? a : b ;
}


void wczytaj()
{
	scanf( "%lld", &n );
	
	LL a, b, c;
	
	REP(i,1,n-1)
	{
		scanf( "%lld %lld %lld", &a, &b, &c );
		
		--a;  --b;
		
		G[a].PB( MP( c, b ) );
		
		G[b].PB( MP( c, a ) );
	}
}


void DFS(LL ojciec, LL u)
{
	LL v, w, r = G[u].S();
	
	REP(i,0,r-1)
	{
		v = G[u][i].ND;
		
		w = G[u][i].ST;
		
		if( v != ojciec )
		{
			DP[ R + ind ] = v;
					
			++ind;
			
			if( !odw[v] )
			{
				odw[v] = true;
				
				fun[v] = num;
				
				++num;
				
				d[ fun[v] ] = d[ fun[u] ] + w;
				
				DFS( u, v );
				
				DP[ R + ind ] = u;
					
				++ind;
			}
		}
	}
}


LL f(LL x)
{
	LL wyn = 1;
	
	while( wyn < x )
	{
		wyn *= 2;
	}
	
	return wyn;
}


void preprocessing()
{
	odw[0] = true;
	
	fun[0] = num;
	
	++num;
	
	d[ fun[0] ] = 0;
	
	R = f( 2 * n - 1 );
	
	REP(i,1,2*R-1)
	{
		DP[i] = INF;
	}
	
	DP[ R + ind ] = 0;
	
	++ind;
}


void uaktualnij_drzewo()
{
	REP(i,0,2*n-2)
	{
		DP[ R + i ] = fun[ DP[ R + i ] ];
		
		gdzie[ DP[ R + i ] ] = i;
	}
	
	FORD(i,R-1,1)
	{
		DP[i] = min( DP[ 2 * i ], DP[ 2 * i + 1 ] );
	}
}


void obliczenia_wstepne()
{
	preprocessing();
	
	DFS( UNDEF, 0 );
	
	uaktualnij_drzewo();
}


void bazowe(LL v, LL lewy, LL prawy, LL a, LL b)
{
	if( lewy == a  &&  prawy == b )
	{
		V.PB( v );   ++rozm;   return;
	}
	
	LL sr = ( a + b ) / 2;
	
	if( prawy <= sr )
	{
		bazowe( 2 * v, lewy, prawy, a, sr );
	}
	else
	{
		if( lewy > sr )
		{
			bazowe( 2 * v + 1, lewy, prawy, sr + 1, b );	
		}
		else
		{
			bazowe( 2 * v, lewy, sr, a, sr );
			
			bazowe( 2 * v + 1, sr + 1, prawy, sr + 1, b );
		}
	}
}


LL LCA(LL a, LL b)
{
	a = gdzie[a];
	
	b = gdzie[b];
	
	if( a > b )
	{
		LL tmp = a;
		
		a = b;
		
		b = tmp;
	}
	
	bazowe( 1, a, b, 0, R - 1 );
	
	LL wyn = INF;
	
	REP(i,0,rozm-1)
	{
		wyn = min( wyn, DP[ V[i] ] );
	}
	
	V.C();
	
	rozm = 0;
	
	return wyn;
}


LL odl(LL a, LL b)
{
	--a;  --b;
	
	a = fun[a];   b = fun[b];
	
	LL v = LCA( a, b );
	
	return d[a] + d[b] - 2 * d[v];
}


void zapytania()
{
	LL a, b;
	
	scanf( "%lld", &a );
	
	while( a != -1 )
	{
		scanf( "%lld", &b );
		
		printf( "%lld\n", odl( a, b ) );
		
		scanf( "%lld", &a );
	}
}


int main()
{
	wczytaj();
	
	obliczenia_wstepne();
	
	zapytania();
	
	return 0;
}
