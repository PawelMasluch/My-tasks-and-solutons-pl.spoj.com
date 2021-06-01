#include<cstdio> // 100 pkt

using namespace std;

int main()
{
	long long A, B;
	
	scanf("%lld%lld", &A, &B);
	
	if( A %2 == 1  &&  B % 2 == 1 )
	{
		printf("BOB\n");
	}
	else
	{
		printf("ALICJA\n");
	}
	
	return 0;
}