#include<iostream> // 71/100 pkt; zaliczylem wszystkie testy
#include<new>
#include<vector>
#include<string>


#define REP(i,n) for(i=0; i<n; ++i)

#define PB push_back


using namespace std;


typedef long long LL;

typedef vector < LL > VLL;


VLL V;

LL num = 0, rozm = 0;


void oblicz(LL u, VLL *G, LL *rG, bool *odw, LL *fun, LL *subtree) // rozmiary poddrzew + przenumerowanie wierzchołków
{
	LL i, v;
	
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


LL f(LL n)
{
	LL wyn = 1;
	
	while( wyn < n )
	{
		wyn *= 2;
	}
	
	return wyn;
}


void aktualizuj(LL *DP, LL r, LL u, LL val)
{
	do
	{
		DP[u] += val;
		
		u /= 2;
	}
	while( u );
}


void bazowe(LL v, LL lewy, LL prawy, LL a, LL b)
{
	if( lewy == a  &&  prawy == b )
	{
		V.PB(v);
		
		++rozm;
		
		return;	
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
			
			bazowe( 2 * v + 1, sr + 1, prawy, sr + 1, b);
		}
	}
}


LL query(LL *DP, LL r, LL pocz, LL kon)
{
	LL i, wyn = 0;
	
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
	
	VLL *G;
	
	bool *odw;
	
	LL N, *rG, u, v, *fun, *subtree, i, *DP, r, Q, c;
	
	cin >> N >> Q;
	
	r = f( N );
	
	DP = new LL [2*r];
	
	REP(i,2*r-1)
	{
		DP[ i + 1 ] = 0;
	}
	
	G = new VLL [N];
	
	rG = new LL [N];
	
	fun = new LL [N];
	
	odw = new bool [N];
	
	subtree = new LL [N];
	
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
