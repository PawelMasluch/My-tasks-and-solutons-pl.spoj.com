#include<cstdio> // 100 pkt
#include<new>


#define REP(i,a,b) for(i=a; i<=b; ++i)

#define FORD(i,b,a) for(i=b; i>=a; --i)


using namespace std;


typedef long long LL;


LL fpm(LL a, LL b, LL p)
{
	LL wyn = 1;
	
	while( b )
	{
		if( b % 2 )
		{
			wyn = ( wyn * a ) % p;
		}
		
		a = ( a * a ) % p;
		
		b /= 2;
	}
	
	return wyn;
}


int main()
{
	LL N, *F = new LL [63], *ile = new LL [60], i, S = 0, temp = (LL)576460752303423488, pom, p = 1000000007, wyn1 = 0, wyn2 = 1;
	
	REP(i,0,59)
	{
		ile[i] = 0;
	}
	
	F[0] = 0;  F[1] = 1;
	
	REP(i,2,62)
	{
		ile[i] = 0;
		
		F[i] = ( F[ i - 1 ] + F[ i - 2 ] ) % p;
	}
	
	scanf("%lld", &N);
	
	FORD(i,59,0)
	{
		pom = N / temp;
		
		pom = ( pom + 1 ) / 2;
		
		pom -= S;
		
		ile[i] = pom;
		
		S += pom;
		
		temp /= 2;
	}
	
	REP(i,0,59)
	{
		wyn1 += ile[i] * ( ( i + 2 ) / 2 );
		
		wyn2 = ( wyn2 * fpm( F[ i + 3 ], ile[i], p ) ) % p;
	}
	
	printf("%lld\n%lld\n", wyn1, wyn2);
	
	return 0;
}
