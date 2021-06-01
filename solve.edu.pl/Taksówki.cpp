#include<cstdio> // 100 pkt


using namespace std;


int ile[5], n, wyn = 0, a, pom;


int min(int a, int b)
{
	return ( a < b ) ? a : b ;
}


int main()
{
	scanf( "%d", &n );
	
	while( n )
	{
		scanf( "%d", &a );
		
		++ile[a];
		
		--n;
	}
	
	
	// Czwórki
	
	wyn += ile[4];
	
	ile[4] = 0;
	
	
	// Trójki
	
	pom = min( ile[3], ile[1] );
	
	wyn += pom;
	
	ile[3] -= pom;
	
	ile[1] -= pom;
	
	if( ile[3] > 0 )
	{
		wyn += ile[3];
		
		ile[3] = 0;
	}
	
	
	// Dwójki
	
	wyn += ( ile[2] / 2 );
	
	ile[2] %= 2;
	
	if( ile[2] == 1 )
	{
		pom = min( 2, ile[1] );
		
		++wyn;
		
		ile[2] = 0;
		
		ile[1] -= pom;
	}
	
	
	// Jedynki
	
	wyn += ( ile[1] + 3 ) / 4;
	
	
	printf( "%d\n", wyn );
	
	return 0;
}
