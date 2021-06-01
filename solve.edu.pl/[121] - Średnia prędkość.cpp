#include<cstdio> // 100 pkt
using namespace std;
int main()
{
	double a,b;
	scanf("%lf%lf", &a, &b);
	printf("%.6lf\n", (2.*a*b)/(a+b));
	return 0;
}
