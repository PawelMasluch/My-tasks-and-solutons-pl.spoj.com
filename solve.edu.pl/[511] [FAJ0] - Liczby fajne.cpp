#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


LL ile(LL N)
{
	return ( N / 2 ) + ( N / 5 ) - ( N / 6 ) - ( N / 10 ) - ( N / 15 ) + ( N / 30 );
}


int main()
{
	LL N;
	
	scanf( "%lld", &N );
	
	printf( "%lld\n", ile( N ) );
	
	return 0;
}
