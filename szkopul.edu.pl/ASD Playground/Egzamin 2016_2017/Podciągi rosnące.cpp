#include<cstdio> // 100 pkt


using namespace std;


typedef long long LL;


#define REP(i,a,b) for(LL i=a; i<=b; ++i)


LL n, ile1 = 0, ile2 = 0, ile3 = 0, ile12 = 0, ile13 = 0, ile23 = 0, ile123 = 0, wyn = 0;


void solve()
{
	scanf( "%lld", &n );
	
	LL x;
	
	REP(i,1,n)
	{
		scanf( "%lld", &x );
		
		switch( x )
		{
			case 1:
				++ile1;
				break;
				
			case 2:
				ile12 += ile1;
				++ile2;
				break;
			
			case 3:
				ile13 += ile1;
				ile23 += ile2;
				ile123 += ile12;
				++ile3;
				break;
				
		}
	}
	
	wyn = ile1 + ile2 + ile3 + ile12 + ile13 + ile23 + ile123;
	
	printf( "%lld\n", wyn );
}


int main()
{
	solve();
	
	return 0;
}
