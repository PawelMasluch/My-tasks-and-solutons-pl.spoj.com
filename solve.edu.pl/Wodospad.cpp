#include<cstdio> // 100 pkt
#include<cmath>

using namespace std;

int main()
{
	double H, g = 9.80665;
	
	scanf("%lf", &H);
	
	printf( "%.7lf\n", sqrt( 2. * g * H ) );
	
	return 0;
}
