#include<cstdio> // 100 pkt

using namespace std;

int main()
{
	double M, v1, v0, P;
	
	scanf("%lf%lf%lf%lf", &M, &v1, &v0, &P);
	
	printf("%.6lf\n", M * ( v1 + v0 ) * ( v1 - v0 ) / 2. / P );
	
	return 0;
}
