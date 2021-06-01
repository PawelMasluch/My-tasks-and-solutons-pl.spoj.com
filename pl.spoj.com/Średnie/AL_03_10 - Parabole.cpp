#include<cstdio> // AC
#include<cmath>


using namespace std;


int A, B, C;


double F(double x)
{
	return x * ( ( ( ( A * x / 3. ) + ( B / 2. ) ) * x ) + C );
}


int main()
{
	double x1, x2;
	
	int q, a1, b1, c1, a2, b2, c2, delta;
	
	scanf( "%d", &q );
	
	while( q )
	{
		scanf( "%d%d%d%d%d%d", &a1, &b1, &c1, &a2, &b2, &c2 );
		
		A = a2 - a1;
		
		B = b2 - b1;
		
		C = c2 - c1;
		
		delta = ( B * B ) - ( 4 * A * C );
		
		if( delta > 0 )
		{
			x2 = ( -B - sqrt( delta ) ) / 2. / A;
			
			x1 = ( -B + sqrt( delta ) ) / 2. / A;
			
			printf( "%.2lf\n", F( x2 ) - F( x1 ) );
		}
		else
		{
			printf( "0.00\n" );
		}
		
		--q;
	}
	
	return 0;
}
