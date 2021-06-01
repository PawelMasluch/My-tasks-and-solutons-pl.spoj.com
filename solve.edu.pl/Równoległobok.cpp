#include<cstdio> // 100 pkt


using namespace std;


double a, b, pa, qa, pb, qb;


int main()
{
	scanf( "%lf %lf %lf %lf %lf %lf", &a, &b, &pa, &qa, &pb, &qb );
	
	printf( "%.7lf\n", a * b * ( pa * qb + qa * pb ) / ( pa + qa ) / ( pb + qb ) );
	
	return 0;
}
