#include<cstdio> // 100 pkt
using namespace std;
inline int max(int a, int b)
{
	return (a>b) ? a : b ;
}
inline int min(int a, int b)
{
	return (a<b) ? a : b ;
}
int main()
{
	int n,i,a,wyn=0,MIN=1000000001,WYN=0;
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &a);
		wyn=max(0,a-MIN);
		WYN=max(WYN,wyn);
		MIN=min(MIN,a);
	}
	printf("%d\n", WYN);
	return 0;
}
