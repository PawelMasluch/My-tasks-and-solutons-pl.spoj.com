#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


int main()
{
	LL n, tmp = 1, i = 0;
	
	scanf( "%lld", &n );
	
	while( i <= n )
	{
		printf( "%lld ", tmp );
		
		tmp *= 2;
		
		++i;
	}
	
	printf( "\n" );
	
	return 0;
}
