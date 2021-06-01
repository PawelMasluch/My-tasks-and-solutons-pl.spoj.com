#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)


LL N, wyn = 0;


int main()
{
	scanf( "%lld", &N );
	
	LL a_i;
	
	REP(i,1,N)
	{
		scanf( "%lld", &a_i );
		
		wyn += a_i * i * ( N - i + 1 );
	}
	
	printf( "%lld\n", wyn );
	
	return 0;
}
