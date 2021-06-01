#include<cstdio> // 100 pkt
#include<iostream>

using namespace std;

int main()
{
	char z;
	
	double T;
	
	cin >> z >> T;
	
	if(z == 'C')
	{
		printf("F\n%.7lf\n", ( 1.8 * T ) + 32. );
	}
	else // z == 'F'
	{
		printf("C\n%.7lf\n", ( 5. / 9. ) * (T - 32.) );
	}
	
	return 0;
}
