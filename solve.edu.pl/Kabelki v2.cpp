#include<cstdio> // 89/100 pkt;  zaliczylem wszystkie testy
#include<new>


#define REP(i,n) for(i=0; i<n; ++i)


using namespace std;


typedef long long LL;

typedef double D;


const D EPS = 1e-9;


LL ile(D *t, LL N, D sr)
{
	LL i, wyn = 0;
	
	REP(i,N)
	{
		wyn += (LL)( t[i] / sr );
	}
	
	return wyn;
}


D bin(D *t, LL N, LL K)
{
	LL pom;
	
	D pocz = EPS, kon = 1e9, sr, wyn;
	
	while( kon - pocz > EPS )
	{
		sr = ( pocz + kon ) / 2;
		
		pom = ile( t, N, sr );
		
		if( pom >= K )
		{
			wyn = sr;
			
			pocz = sr + EPS;
		}
		else
		{
			kon = sr - EPS;
		}
	}
	
	return wyn;
}


int main()
{
	D *t;
	
	LL N, i, K;
	
	scanf("%lld%lld", &N, &K);
	
	t = new D [N];
	
	REP(i,N)
	{
		scanf( "%lf", &t[i] );
	}
	
	printf( "%.6lf\n", bin( t, N, K ) );
	
	return 0;
}
