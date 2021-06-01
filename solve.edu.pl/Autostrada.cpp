#include<cstdio> // 100 pkt


using namespace std;


int main()
{
	int Q;
	
	double T;
	
	scanf( "%d", &Q );
	
	while( Q )
	{
		scanf( "%lf", &T );
		
		printf( "%.9lf\n", 360. / T );
		
		--Q;
	}
	
	return 0;
}
