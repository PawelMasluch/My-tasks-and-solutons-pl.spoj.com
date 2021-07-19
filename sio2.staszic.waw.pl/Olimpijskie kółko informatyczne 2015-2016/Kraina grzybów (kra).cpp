#include<cstdio> // 100 pkt
#include<vector>


using namespace std;


typedef long long LL;

typedef vector < int > VI;


#define REP(i,a,b) for(int i=a; i<=b; ++i)

#define PB push_back

#define pb pop_back

#define S size

#define E empty


const int MAX_N = 1000000, p = 1000000009;


VI H[MAX_N], pom;

int n, m, A, B, DP[MAX_N], out[MAX_N], in[MAX_N], topo[MAX_N], inv[MAX_N];


void preprocessing()
{
	REP(i,0,n-1)
	{
		DP[i] = out[i] = in[i] = 0;
	}
}


void wczytaj()
{
	scanf( "%d %d %d %d", &n, &m, &A, &B );
	
	--A;  --B;
	
	preprocessing();
	
	LL a, b;
	
	REP(i,0,m-1)
	{
		scanf( "%d %d", &a, &b );
		
		--a;  --b;
		
		H[b].PB( a );
		
		++out[a];
		
		++in[b];
	}
}


void obliczenia_wstepne()
{
	REP(i,0,n-1)
	{
		if( out[i] == 0 )
		{
			pom.PB( i );
		}
	}
	
	LL ind = 0, u, v, r;
	
	while( !pom.E() )
	{
		u = pom.back();
		
		pom.pb();
		
		topo[ ind ] = u;    ++ind;
		
		r = H[u].S();
		
		REP(i,0,r-1)
		{
			v = H[u][i];
			
			--out[v];
			
			if( out[v] == 0 )
			{
				pom.PB( v );
			}
		}
	}
	
	LL tmp;
	
	REP(i,0,(n-1)/2)
	{
		tmp = topo[i];
		
		topo[i] = topo[ n - 1 - i ];
		
		topo[ n - 1 - i ] = tmp; 
	}
	
	REP(i,0,n-1)
	{
		inv[ topo[i] ] = i;
	}
}


void oblicz()
{
	LL ind = inv[A], r, u, v;
	
	DP[A] = 1;
	
	REP(i,ind+1,n-1)
	{
		v = topo[i];
		
		r = in[v];
		
		REP(i,0,r-1)
		{
			u = H[v][i];
			
			DP[v] = ( DP[v] + DP[u] ) % p;
		}
	}
	
	printf( "%d\n", DP[B] );
}


int main()
{
	wczytaj();
	
	obliczenia_wstepne();
	
	oblicz();
	
	return 0;
}
