#include<cstdio> // AC
 
using namespace std;
 
bool czy_pierwsza(int &x)
{
	if(x == 0  ||  x == 1)
	{
		return false;
	}
	
	int i;
	
	for(i=2; i*i<=x; ++i)
	{
		if( x % i == 0 )
		{
			return false;
		}
	}
	
	return true;
}
 
int main()
{
	int t, a, b, i;
	
	scanf("%d", &t);
	
	while( t > 0 )
	{
		scanf("%d%d", &a, &b);
		
		for(i=a; i<=b; ++i)
		{
			if(czy_pierwsza(i) == true)
			{
				printf("%d\n", i);
			}
		}
		
		printf("\n");
		
		--t;
	}
	
	return 0;
} 
