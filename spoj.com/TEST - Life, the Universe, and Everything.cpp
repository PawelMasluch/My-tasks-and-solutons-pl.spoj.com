#include<cstdio> // AC
 
using namespace std;
 
int main()
{	
	bool czy = false;
	
	int a;
	
	while( scanf("%d", &a) != EOF )
	{
		if( czy == false )
		{
			if( a != 42 )
			{
				printf("%d\n", a);
			}
			else
			{
				czy = true;
			}
		}
	}
	
	return 0;
} 
