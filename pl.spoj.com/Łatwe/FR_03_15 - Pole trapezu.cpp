#include<cstdio> // AC
#include<cmath>


using namespace std;


int main()
{
	int q;
	
	double a, b;
	
	scanf( "%d", &q );
	
	while( q )
	{
		scanf( "%lf%lf", &a, &b );
		
		printf( "%.2lf\n", ( a + b ) * sqrt( a * b ) / 2. );
		
		--q;
	}
	
	return 0;
}
