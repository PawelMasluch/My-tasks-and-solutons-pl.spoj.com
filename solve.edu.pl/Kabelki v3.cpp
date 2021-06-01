#include<cstdio> // 88/100 pkt;  zaliczylem wszystkie testy
#include<new>


#define REP(i,n) for(i=0; i<n; ++i)


using namespace std;


typedef long long LL;

typedef long double LD;


const LD EPS = 1e-9;


LL ile(LD *t, LL N, LD sr)
{
	LL i, wyn = 0;
	
	REP(i,N)
	{
		wyn += (LL)( t[i] / sr );
	}
	
	return wyn;
}


LD bin(LD *t, LL N, LL K)
{
	LL pom;
	
	LD pocz = EPS, kon = 1e9, sr, wyn;
	
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
	LD *t;
	
	LL N, i, K;
	
	scanf("%lld%lld", &N, &K);
	
	t = new LD [N];
	
	REP(i,N)
	{
		scanf( "%Lf", &t[i] );
	}
	
	printf( "%.6Lf\n", bin( t, N, K ) );
	
	return 0;
}
