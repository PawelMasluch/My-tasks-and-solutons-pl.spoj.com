#include<cstdio> // AC
#include<new>


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)


const LL MAX_N = 10000;


void wczytaj(LL *t, LL n)
{
	REP(i,0,n-1)
	{
		scanf( "%lld", &t[i] );
	}
}


void inicjuj(LL *t, LL n, LL val)
{
	REP(i,1,n-1)
	{
		t[i] = val;
	}
	
	t[0] = 1;
}


int main()
{
	LL n, *t, *DP = new LL[MAX_N+1], q, a;
	
	inicjuj( DP, MAX_N + 1, 0 );
	
	scanf( "%lld", &n );
	
	t = new LL [n];
	
	wczytaj( t, n );
	
	REP(i,0,n-1)
	{
		REP(j,t[i],MAX_N)
		{
			DP[j] += DP[ j - t[i] ];
		}
	}
	
	scanf( "%lld", &q );
	
	REP(i,1,q)
	{
		scanf( "%lld", &a );
		
		printf( "%lld\n", DP[a] );
	}
	
	return 0;
}
