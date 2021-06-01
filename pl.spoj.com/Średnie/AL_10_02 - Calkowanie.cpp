#include<cstdio> // AC
#include<cmath>


using namespace std;


int main()
{
	double a, P_pasek, P_kropka, P_kratka;
	
	/*
	
	P_pasek = a * a * ( 1 - sqrt( 3 ) + ( pi / 3 ) )
	
	P_kropka = a * a * ( -1 + ( sqrt( 3 ) / 2 ) + ( pi / 12 ) )
	
	P_kratka = a * a * ( 1 - ( sqrt( 3 ) / 4 ) - ( pi / 6 ) )
	
	*/
	
	while( scanf( "%lf", &a ) != EOF )
	{
		P_pasek = a * a * ( 1. - sqrt( 3. ) + ( M_PI / 3. ) );
	
		P_kropka = a * a * ( -1. + ( sqrt( 3. ) / 2. ) + ( M_PI / 12. ) );
		
		P_kratka = a * a * ( 1. - ( sqrt( 3. ) / 4. ) - ( M_PI / 6. ) );
		
		printf( "%.3lf %.3lf %.3lf\n", P_pasek, 4 * P_kropka, 4 * P_kratka );
	}
	
	return 0;
}
