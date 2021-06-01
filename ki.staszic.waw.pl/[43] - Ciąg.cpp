#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


const LL MAX_M = 100000;


LL n, A, B, p, ciag[MAX_M+2], ktory[MAX_M];


void wczytaj()
{
	scanf( "%lld %lld %lld %lld", &n, &A, &B, &p );
	
	A %= p;
	
	B %= p;
}


void oblicz()
{
	LL nr = 1, val = A, pocz, kon;
	
	ciag[ nr ] = val;
	
	ktory[ val ] = nr;
	
	++nr;
	
	while( 1 )
	{
		val = ( ciag[ nr - 1 ] * ciag[ nr - 1 ] + B ) % p;
		
		if( ktory[ val ] != 0 )
		{
			pocz = ktory[ val ]; 
			
			kon = --nr;
			
			break;
		}
		else
		{
			ciag[ nr ] = val;
			
			ktory[ val ] = nr;
			
			++nr;
		}
	}
	
	if( n < pocz )
	{
		printf( "%lld\n", ciag[n] );
	}
	else
	{
		int d = kon - pocz + 1,  alfa = ( n - pocz ) / d;
		
		printf( "%lld\n", ciag[ n - alfa*d ] );
	}
}


int main()
{
	wczytaj();
	
	oblicz();
	
	return 0;
}
