#include<cstdio> // 100 pkt

using namespace std;

int main()
{
	double x, p, q;
	
	scanf("%lf%lf%lf", &x, &p, &q);
	
	printf( "%.7lf\n", 2. * p * q * x * x / ( p * p  +  q * q ) );
	
	return 0;
}
