#include<iostream> // 79/100 pkt; zaliczylem wszystke testy
#include<new>
#include<vector>
#include<string>


#define REP(i,n) for(i=0; i<n; ++i)

#define PB push_back


using namespace std;


typedef long long LL;

typedef vector < int > VI;


VI V;

int num = 0, rozm = 0;


void oblicz(int u, VI *G, int *rG, bool *odw, int *fun, int *subtree) // rozmiary poddrzew + przenumerowanie wierzchołków
{
	int i, v;
	
	REP(i,rG[u])
	{
		v = G[u][i];
		
		if( !odw[v] )
		{
			odw[v] = true;
			
			++num;
			
			fun[v] = num;
			
			oblicz( v, G, rG, odw, fun, subtree );
			
			subtree[u] += subtree[v];
		}
	}
}


int f(int n)
{
	int wyn = 1;
	
	while( wyn < n )
	{
		wyn <<= 1;
	}
	
	return wyn;
}


void aktualizuj(LL *DP, int r, int u, LL val)
{
	do
	{
		DP[u] += val;
		
		u >>= 1;
	}
	while( u );
}


void bazowe(int v, int lewy, int prawy, int a, int b)
{
	if( lewy == a  &&  prawy == b )
	{
		V.PB(v);
		
		++rozm;
		
		return;	
	}
	
	int sr = ( a + b ) >> 1;
	
	if( prawy <= sr )
	{
		bazowe( ( v << 1 ), lewy, prawy, a, sr );
	}
	else
	{
		if( lewy > sr )
		{
			bazowe( ( v << 1 ) + 1, lewy, prawy, sr + 1, b );
		}
		else
		{
			bazowe( ( v << 1 ), lewy, sr, a, sr );
			
			bazowe( ( v << 1 ) + 1, sr + 1, prawy, sr + 1, b);
		}
	}
}


LL query(LL *DP, int r, int pocz, int kon)
{
	int i;
	
	LL wyn = 0;
	
	bazowe( 1, pocz, kon, 0, r - 1 );
	
	REP(i,rozm)
	{
		wyn += DP[ V[i] ];
	}
	
	V.clear();
	
	rozm = 0;
	
	return wyn;
}


int main()
{
	ios_base::sync_with_stdio(0);
	
	string s;
	
	VI *G;
	
	bool *odw;
	
	int N, *rG, u, v, *fun, *subtree, i, r, Q, c;
	
	LL *DP;
	
	cin >> N >> Q;
	
	r = f( N );
	
	DP = new LL [2*r];
	
	REP(i,(r << 1)-1)
	{
		DP[ i + 1 ] = 0;
	}
	
	G = new VI [N];
	
	rG = new int [N];
	
	fun = new int [N];
	
	odw = new bool [N];
	
	subtree = new int [N];
	
	REP(i,N)
	{
		rG[i] = 0;
		
		subtree[i] = 1;
		
		odw[i] = false;
	}
	
	REP(i,N-1)
	{
		cin >> u >> v;
		
		--u;  --v;
		
		G[u].PB(v);  G[v].PB(u);
		
		++rG[u];  ++rG[v];
	}
	
	odw[0] = true;
	
	fun[0] = 0;
	
	oblicz( 0, G, rG, odw, fun, subtree );
	
	while( Q )
	{
		cin >> s >> u;
		
		--u;
		
		if( s == "Count" )
		{
			cout << query( DP, r, fun[u], fun[u] + subtree[u] - 1 ) << endl;
		}
		else // s == "Add"
		{
			cin >> c;
			
			aktualizuj( DP, r, fun[u] + r, c);
		}
		
		--Q;
	}
	
	return 0;
}
