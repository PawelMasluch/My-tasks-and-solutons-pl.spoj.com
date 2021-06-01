#include<cstdio> // 100 pkt

using namespace std;

typedef long long LL;

int main()
{
	LL N, wyn = 0;
	
	scanf("%lld", &N);
	
	while( N > 0 )
	{
		wyn += ( N % 10 );
		N /= 10;
	}
	
	printf("%lld\n", wyn);
	
	return 0;
}
