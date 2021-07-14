#include<cstdio> // 100 pkt
 
using namespace std;
 
bool czy_pierwsza(int &x)
{
	if(x == 0  ||  x == 1)
	{
		return false;
	}
	
	if( x % 2 == 0  &&  x > 2 )
	{
		return false;
	}
	
	if( x % 3 == 0  &&  x > 3 )
	{
		return false;
	}
	
	int k;
	
	for(k=1; ((6*k)-1)*((6*k)-1) <= x; ++k)
	{
		if( x % ((6*k)-1) == 0 )
		{
			return false;
		}
		
		if( x % ((6*k)+1) == 0 )
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
