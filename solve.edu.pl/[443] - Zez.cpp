#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


const LL MAX_WYNIK = ( 1 << 21 ) - 1; // MAX_WYNIK = (2^21) - 1


LL bin(LL n) // min x: x^3 >= n
{
	LL pocz = 0, kon = MAX_WYNIK, wyn, sr;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) >> 1;
		
		if( sr * sr * sr >= n )
		{
			wyn = sr;
			
			kon = sr - 1;
		}
		else
		{
			pocz = sr + 1;
		}
	}
	
	return wyn;
}


void query()
{
	LL n;
	
	scanf( "%lld", &n );
	
	printf( "%lld\n", bin( n ) );
}


void zapytania()
{
	LL q;
	
	scanf( "%lld", &q );
	
	while( q )
	{
		query();
		
		--q;
	}
}


int main()
{
	zapytania();
	
	return 0;
}
