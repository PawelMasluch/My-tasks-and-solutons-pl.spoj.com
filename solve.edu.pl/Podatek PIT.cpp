#include<cstdio> // 100 pkt

using namespace std;

int main()
{
	double D, r;
	
	scanf("%lf", &D);
	
	if( D <= 3089.00 )
	{
		printf("0\n");
	}
	else
	{
		if( D <= 85528.00 )
		{
			r = D - 3089.00;
			printf("%.0lf\n", 0.18 * r );
		}
		else
		{
			r = D - 85528.00;
			printf("%.0lf\n", ( 0.32 * r ) + 14839.02 );
		}
	}
	
	return 0;
}
