#include<cstdio> // 100 pkt
using namespace std;
int main()
{
	int n,i,a,wyn=0;
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &a);
		if(a%2==0)
		{
			wyn++;
		}
	}
	printf("%d\n", wyn);
	return 0;
}