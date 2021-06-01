#include<cstdio> // 100 pkt

using namespace std;

int main()
{
	double M, m, v, a;
	
	scanf("%lf%lf%lf%lf", &M, &m, &v, &a);
	
	printf( "%.6lf\n", m * m * v * v / 2. / M / M / a );
	
	return 0;
}
