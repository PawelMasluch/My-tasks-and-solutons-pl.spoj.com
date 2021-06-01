#include<cstdio> // 100 pkt


using namespace std;


int fpm(int a, int b, int p)
{
	int wyn = 1;
	
	while( b )
	{
		if( b & 1 )
		{
			wyn = ( wyn * a ) % p;
		}
		
		b >>= 1;
		
		a = ( a * a ) % p;
	}
	
	return wyn;
}


int main()
{
	int a, b;
	
	scanf( "%d %d", &a, &b );
	
	printf( "%d\n", fpm( a, b, 101 ) );
	
	return 0;
}
