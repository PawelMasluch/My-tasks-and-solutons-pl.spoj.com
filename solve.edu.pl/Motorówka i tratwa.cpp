#include<cstdio> // 100 pkt


using namespace std;


int main()
{
	double A, B;
	
	scanf( "%lf %lf", &A, &B );
	
	printf( "%.6lf\n", 2. / ( ( 1. / A ) - ( 1. / B ) ) );
	
	return 0;
}
