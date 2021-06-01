#include<cstdio> // 100 pkt
#include<vector>


using namespace std;


typedef pair < int, int > PII;

typedef vector < PII > VPII;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define FORD(i,b,a) for(int i=b; i>=a; --i)

#define PB push_back

#define S size

#define MP make_pair

#define ST first

#define ND second


const int MAX_N = 500000, MAX_R = 524288, INF = 1000000000 + 199;


VPII G[MAX_N];

int n, m, a[MAX_N], DP[2*MAX_R], wyn = INF, R;


void wczytaj()
{
	scanf( "%d", &n );
	
	REP(u,0,n-1)
	{
		scanf( "%d", &a[u] );
	}
	
	scanf( "%d", &m );
	
	int u, v, b;
	
	REP(i,1,m)
	{
		scanf( "%d %d %d", &u, &v, &b );
		
		--u;    --v;
		
		G[u].PB( MP( b, v ) );
		
		G[v].PB( MP( b, u ) );	
	}
}


int f(int x)
{
	int wyn = 1;
	
	while( wyn < x )
	{
		wyn *= 2;
	}
	
	return wyn;
}


int min(int x, int y)
{
	return ( x < y ) ? x : y ;
}


void init() // inicjacja drzewa przedzialowego ( zbudowanego nad wartosciami ciagu 'a' ) typu min
{
	R = f( n );
	
	REP(i,1,2*R-1)
	{
		DP[i] = INF;
	}
	
	REP(u,0,n-1)
	{
		DP[ R + u ] = a[u];
	}
	
	FORD(i,R-1,1)
	{
		DP[i] = min( DP[ 2*i ], DP[ 2*i + 1 ] );
	}
}


void ins(int u, int val)
{
	int x = R + u;
	
	DP[x] = val;
	
	x /= 2;
	
	while( x > 0 )
	{
		DP[x] = min( DP[ 2*x ], DP[ 2*x + 1 ] );
		
		x /= 2;
	}
}


int query(int u)
{
	int r = G[u].S(), v;
	
	
	// usuwanie wierzcholka 'u' oraz sasiadow wierzcholka 'u'
	
	ins( u, INF );
	
	REP(i,0,r-1)
	{
		v = G[u][i].ND;
		
		ins( v, INF );
	}
	
	
	int best = DP[1]; // wynik
	
	
	// wstawianie wierzcholka 'u' oraz sasiadow wierzcholka 'u' , z powrotem
	
	ins( u, a[u] );
	
	REP(i,0,r-1)
	{
		v = G[u][i].ND;
		
		ins( v, a[v] );
	}
	
	
	return best;
}


void oblicz()
{
	/* 1. faza - prelegenci nielubiacy sie nawzajem,
	czyli wierzcholki polaczone krawedzia */
	
	int r, v, b;
	
	REP(u,0,n-1)
	{
		r = G[u].S();
		
		REP(i,0,r-1)
		{
			b = G[u][i].ST;
			
			v = G[u][i].ND;
			
			if( u < v )
			{
				wyn = min( wyn, a[u] + a[v] + 2*b );
			}
		}
	} 
	
	
	/* 2. faza - kazdemu prelegentowi okreslam innego prelegenta,
	tak ze obaj sie lubia nawzajem oraz ich laczna suma wartosci
	z tablicy 'a' jest minimalna ; oczywiscie takie wartosci
	porownujemy z najlepszym dotychczasowym wynikiem */
	
	init();
	
	int tmp;
	
	REP(u,0,n-1)
	{
		tmp = query( u );
		
		if( tmp != INF ) // nie trzeba tego sprawdzac
		{
			wyn = min( wyn, a[u] + tmp );
		}
	}
}


void wypisz()
{
	printf( "%d\n", wyn );
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
