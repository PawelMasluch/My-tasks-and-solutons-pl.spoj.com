#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)


const LL INF = (LL)1000000099 * 1000000009, MAX_WYN = 60;


LL S[MAX_WYN+1], N, dl = 0;


void init()
{
	S[0] = -INF;
	
	REP(i,1,MAX_WYN)
	{
		S[i] = INF;
	}
}


LL bin_search(LL x)
{
	LL pocz = 0, kon = dl, wyn, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( 2 * S[ sr ] <= x )
		{
			wyn = sr;
			
			pocz = sr + 1;
		}
		else
		{
			kon = sr - 1;
		}
	}
	
	return wyn + 1;
}


void solve()
{
	scanf( "%lld", &N );
	
	LL A_i, index;
	
	REP(i,1,N)
	{
		scanf( "%lld", &A_i );
		
		index = bin_search( A_i );
		
		if( A_i < S[ index ] )
		{
			if( S[ index ] == INF )
			{
				++dl;
			}
			
			S[ index ] = A_i;
		}
	}
	
	printf( "%lld\n", N - dl );
}


int main()
{
	init();
	
	solve();
	
	return 0;
}
