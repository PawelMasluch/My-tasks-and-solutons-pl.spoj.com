#include<cstdio> // do sprawdzenia

using namespace std;

int main()
{
	int a, b, c;
	
	scanf("%d%d%d", &a, &b, &c);
	
	if( a + b == c )
	{
		printf("%d + %d == %d\n", a, b, c);
	}
	
	if( a - b == c )
	{
		printf("%d - %d == %d\n", a, b, c);
	}
	
	if( a * b == c )
	{
		printf("%d * %d == %d\n", a, b, c);
	}
	
	if( b != 0 )
	{
		if( a / b == c )
		{
			printf("%d / %d == %d\n", a, b, c);
		}
	}
	
	if( b != 0 )
	{
		if( a % b == c )
		{
			printf("%d %% %d == %d\n", a, b, c);
		}
	}
	
	return 0;
}