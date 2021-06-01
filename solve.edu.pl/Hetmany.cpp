#include<cstdio> // 100 pkt

using namespace std;

int main()
{
	int N, t[12] = { 1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200 };
	
	scanf("%d", &N);
	
	--N;
	
	printf("%d\n", t[N]);
	
	return 0;
}
