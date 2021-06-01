#include<cstdio> // 100 pkt
#include<vector>
#include<algorithm>
using namespace std; 
typedef long long LL;
int main()
{
	LL n;
	scanf("%lld", &n);
	if(!n)
	{
		printf("1\n");
	}
	else
	{
		switch(n%4)
		{
			case 0: 
				printf("6\n");
				break;
			
			case 1:
				printf("2\n");
				break;
			
			case 2:
				printf("4\n");
				break;
				
			case 3:
				printf("8\n");
				break;	
		}
	}
	return 0;
}
