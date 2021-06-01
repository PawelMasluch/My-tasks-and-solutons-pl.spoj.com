#include<cstdio> // 100 pkt

using namespace std;

int main()
{
	int n, a, wyn = 0;
	
	scanf("%d", &n);
	
	while(n)
	{
		scanf("%d", &a);
		
		if( a >= 18 )
		{
			++wyn;
		}
		
		--n;
	}
	
	printf("%d\n", wyn);
	
	return 0;
}
