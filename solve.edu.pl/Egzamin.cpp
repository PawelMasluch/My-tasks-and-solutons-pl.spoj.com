#include<cstdio> // 100 pkt

using namespace std;

int main()
{
	int K[3], E, ile_zal_K = 0, S = 0, i;
	
	for(i=0; i<=2; ++i)
	{
		scanf("%d", &K[i]);
		
		S += K[i];
		
		if( K[i] >= 40 )
		{
			++ile_zal_K;
		}
	}
	
	scanf("%d", &E);
	
	if( ile_zal_K < 2  ||  E < 40 )
	{
		printf("NIEZDANY\n");
		return 0;
	}
	
	S += ( 2 * E );
	
	if( S >= 250 )
	{
		printf("ZDANY\n");
	}
	else
	{
		printf("DOPYTKA\n");
	}
		
	return 0;
}
