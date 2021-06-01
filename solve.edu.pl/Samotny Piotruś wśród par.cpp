#include<cstdio> // 100 pkt


using namespace std;


#define s(x) scanf( "%d", &x )

#define p(x) printf( "%d\n", x )


int main()
{
	int n, a, wyn = 0;
	
	s( n );
	
	n = 2 * n + 1;
	
	while( n )
	{
		s( a );
		
		wyn ^= a;
		
		--n;
	}
	
	p( wyn );
	
	return 0;
}
