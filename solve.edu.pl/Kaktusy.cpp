#include<cstdio> // 100 pkt
#include<new>
#include<vector>


#define REP(i,a,b) for(i=a; i<=b; ++i)


using namespace std;


typedef long long LL;


const LL INF = (LL)1000900000 * 1000000000;


vector < int > V;

int rozm = 0;


LL min(LL a, LL b)
{
	return (a<b) ? a : b ;
}


int max(int a, int b)
{
	return (a>b) ? a : b ;
}


void wczytaj(int *t, int n)
{
	LL i;
	
	REP(i,1,n-1)
	{
		scanf( "%d", &t[i] );
	}
}


int f(int n)
{
	LL wyn = 1;
	
	while( wyn < n )
	{
		wyn *= 2;
	}
	
	return wyn;
}


void inicjuj(LL *DP, int r, LL val)
{
	LL i;
	
	REP(i,1,2*r-1)
	{
		DP[i] = val;
	}
}


void ustaw(LL *DP, int v, LL val)
{
	DP[v] = val;
	
	v /= 2;
	
	while( v )
	{
		DP[v] = min( DP[2*v], DP[2*v+1] );
		
		v /= 2;
	}
}


void bazowe(int v, int lewy, int prawy, int a, int b) //'v' jest numerem węzła w drzewie
{
	if ( lewy == a  &&  prawy == b )
	{
		V.push_back(v);
		
		++rozm;
		
		return;
	}

	int sr = ( a + b ) / 2;
	
	if ( prawy <= sr )
	{
		bazowe( 2*v, lewy, prawy, a, sr );
	}
	else
	{
		if ( lewy > sr )
		{
			bazowe( 2*v+1, lewy, prawy, sr+1, b );
		}
		else
		{
			bazowe( 2*v, lewy, sr, a, sr );
			
			bazowe( 2*v+1, sr+1, prawy, sr+1, b );
		}
	}
}


LL query(LL *DP, int r, int pocz, int kon)
{
	int i; 
	
	LL wyn = INF;
	
	bazowe(1,pocz,kon,0,r-1);
	
	REP(i,0,rozm-1)
	{
		wyn = min( wyn, DP[ V[i] ] );
	}
	
	V.clear();
	
	rozm = 0;
	
	return wyn;
}


int main()
{
	int N, i, *t, K, r;
	
	LL *DP, *wyn;
	
	scanf("%d%d", &N, &K);
	
	wyn = new LL [N+2];
	
	t = new int [N+2];
	
	t[0] = t[N+1] = wyn[0] = 0;
	
	wczytaj( t, N + 1 );
	
	r = f( N + 2 );
	
	DP = new LL [2*r];
	
	inicjuj(DP,r,INF);
	
	ustaw(DP,r,0);
	
	REP(i,1,N+1)
	{
		wyn[i] = t[i] + query( DP, r, max( 0, i - K ), i - 1 );
		
		ustaw( DP, r + i, wyn[i] );
	}
	
	printf( "%lld\n", wyn[N+1] );
	
	return 0;
}
