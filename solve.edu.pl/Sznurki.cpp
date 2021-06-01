#include<cstdio> // 100 pkt

using namespace std;

int main()
{
	int N, W, wyn = 0, a, temp = 0;
	
	scanf("%d%d", &N, &W);
	
	while( N )
	{
		scanf("%d", &a);
		
		if( temp + a < W )
		{
			temp += a;
		}
		else
		{
			++wyn;
			
			temp = 0;
		}
		
		--N;
	}
	
	printf("%d\n", wyn);
	
	return 0;
}
