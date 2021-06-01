#include<cstdio> // 5 pkt; nie jestem pewien, czy zaliczylem wszystkie testy
#include<new>
#include<algorithm>


using namespace std;


typedef long long LL;

typedef long double LD;


#define REP(i,n) for(LL i=0; i<n; ++i)


void wczytaj(LD *t, LL n)
{
	REP(i,n)
	{
		scanf( "%Lf", &t[i] );
	}
}


LL f(LD *t, LL n, LD a)
{
	LL pocz = 0, kon = n - 1, wyn = -1, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( t[ sr ] < a )
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


int main()
{
	LD *t, a;
	
	LL n, q;
	
	scanf( "%lld", &n );
	
	t = new LD [n];
	
	wczytaj( t, n );
	
	sort( t, t + n );
	
	scanf( "%lld", &q );
	
	REP(i,q)
	{
		scanf( "%Lf", &a );
		
		printf( "%lld\n", f( t, n, a ) );
	}
	
	return 0;
}
