#include<cstdio> // AC
#include<cmath>
 
using namespace std;
 
int main()
{
	int t;
	
	double r, c, w, h;
	
	scanf("%d", &t);
	
	while( t )
	{
		scanf("%lf%lf%lf%lf", &r, &c, &w, &h);
		
		if(   ( w < c )    &&    (  h + w  <  r + sqrt( ( r + c ) * ( r - c ) ) )   )
		{
			printf("TAK\n");
		}
		else
		{
			printf("NIE\n");
		}
		
		--t;
	}
	
	return 0;
} 
