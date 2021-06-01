#include<cstdio> // 100 pkt

using namespace std;

int main()
{
	double P, U1, U2;
	
	scanf("%lf%lf%lf", &P, &U1, &U2);
	
	printf("%.7lf\n", P * U2 * U2 / U1 / U1);
	
	return 0;
}
