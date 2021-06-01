#include<cstdio> // 100 pkt

using namespace std;

int main()
{
	int n, i, j;
	
	scanf("%lld", &n);
	
	for(i=0; i<=2*n; ++i)
	{
		for(j=0; j<=2*n; ++j)
		{
			if( (n-i)*(n-i) + (n-j)*(n-j) <= n*n )
			{
				printf("#");
			}
			else
			{
				printf(".");
			}
		}
		
		printf("\n");
	}
	
	return 0;
}