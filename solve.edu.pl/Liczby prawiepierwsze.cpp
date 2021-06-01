#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


LL ile(LL x)
{
	return ( x / 2 ) + ( x / 3 ) + ( x / 5 ) - ( x / 6 ) - ( x / 10 ) - ( x / 15 ) + ( x / 30 );
}


LL bin(LL N)
{
	LL pocz = 7, kon = (LL)3750000000000000001, wyn, sr, pom;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		pom = sr - ile(sr) - 1;
		
		if( pom < N )
		{
			pocz = sr + 1;
		}
		else
		{
			if( pom == N )
			{
				wyn = sr;
			}
			
			kon = sr - 1;
		}
	}
	
	return wyn;
}


int main()
{
	LL N;
	
	scanf("%lld", &N);
	
	printf( "%lld\n", bin(N) );
	
	return 0;
}
