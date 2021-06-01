#include<cstdio> // 100 pkt

using namespace std;

int main()
{
	double m, h;
	scanf("%lf%lf", &m, &h);
	printf("%.6lf\n", m/h/h);
	if(m/h/h < 20.)
	{
		printf("NIEDOWAGA\n");
	}
	else
	{
		if(m/h/h <= 25.)
		{
			printf("NORMA\n");
		}
		else
		{
			if(m/h/h <= 30.)
			{
				printf("NADWAGA\n");
			}
			else
			{
				printf("OTYLOSC\n");
			}
		}
	}
	
	return 0;
}
