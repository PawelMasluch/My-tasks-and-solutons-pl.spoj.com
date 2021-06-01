#include<cstdio> // AC

using namespace std;

int main()
{
	int D;
	
	double X, Y, Z;
	
	scanf("%d", &D);
	
	while( D )
	{
		scanf("%lf%lf%lf", &X, &Y, &Z);
		
		printf("%.0lf\n", 12. * (Y * Z - X - Y) / ( Z - 1 ) );
		
		--D;
	}
	
	return 0;
}
