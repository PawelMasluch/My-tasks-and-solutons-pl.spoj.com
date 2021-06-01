#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,N) for(int i=0; i<N; ++i)


const int MAX_N = 1e6, INF = 1e9 + 99;


int n, m, a[MAX_N+1], x, pocz, kon, wyn, sr;


int f()
{
	pocz = 0;  kon = n;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) >> 1;
		
		if( a[ sr ] >= x )
		{
			wyn = sr;
			
			kon = sr - 1;
		}
		else
		{
			pocz = sr + 1;
		}
	}
	
	return n - wyn;
}


int main()
{
	scanf( "%d", &n );
	
	REP(i,n)
	{
		scanf( "%d", &a[i] );
	}
	
	a[n] = INF;
	
	scanf( "%d", &m );
	
	while( m )
	{
		scanf( "%d", &x );
		
		printf( "%d\n", f() );
		
		--m;
	}
	
	return 0;
}
