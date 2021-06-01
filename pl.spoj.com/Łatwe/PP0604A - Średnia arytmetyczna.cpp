#include<cstdio> // AC
#include<new>


using namespace std;


typedef long long LL;

typedef long double LD;


#define REP(i,n) for(LL i=0; i<n; ++i)

#define D delete


const LD INF = 1000000009.;


LD f(LD x)
{
	return (x>=0) ? x : -x ;
}


void wczytaj(LD *t, LL n)
{
	REP(i,n)
	{
		scanf( "%Lf", &t[i] );
	}
}


LD fun(LD *t, LL n)
{
	LD S = 0.;
	
	REP(i,n)
	{
		S += t[i];
	}
	
	return S / n;
}


LD znajdz(LD *t, LL n)
{
	LD sr = fun( t, n ), roznica = INF, wyn;
	
	REP(i,n)
	{
		if( f( t[i] - sr ) < roznica )
		{
			roznica = f( t[i] - sr );
			
			wyn = t[i];
		}
	}
	
	return wyn;
}


int main()
{
	LD *t, sr;
	
	LL q, n;
	
	scanf( "%lld", &q );
	
	REP(i,q)
	{
		scanf( "%lld", &n );
		
		t = new LD [n];
		
		wczytaj( t, n );
		
		printf( "%.0Lf\n", znajdz( t, n ) );
		
		D [] t;
	}
	
	return 0;
}
