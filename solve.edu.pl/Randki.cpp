#include<cstdio> // 100 pkt
#include<new>
#include<algorithm>


using namespace std;


typedef long long LL;


struct elem
{
	LL pocz, kon, val;
};


#define REP(i,a,b) for(LL i=a; i<=b; ++i)


bool cmp(const elem &a, const elem &b)
{
	return ( a.kon < b.kon );
}


LL max(LL a, LL b)
{
	return (a>b) ? a : b ;
}


LL bin(elem *t, LL n, LL val)
{
	LL pocz = 0, kon = n - 1, wyn, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( t[ sr ].kon <= val )
		{
			wyn = sr;
			
			pocz = sr + 1;
		}
		else
		{
			kon = sr - 1;
		}
	}
	
	return wyn;
}


int main()
{
	elem *t;
	
	LL n, *DP, ind;
	
	scanf( "%lld", &n );
	
	DP = new LL [n+1];
	
	DP[0] = 0;
	
	t = new elem [n+1];
	
	t[0].pocz = t[0].kon = -1;  t[0].val = 0;
	
	REP(i,1,n)
	{
		scanf( "%lld%lld%lld", &t[i].pocz, &t[i].kon, &t[i].val );
	}
	
	sort( t, t + n + 1, cmp );
	
	REP(i,1,n)
	{
		ind = bin( t, n + 1, t[i].pocz - 1 );
		
		DP[i] = max( DP[ i - 1 ], DP[ ind ] + t[i].val );
	}
	
	printf( "%lld\n", DP[n] );
	
	return 0;
}
