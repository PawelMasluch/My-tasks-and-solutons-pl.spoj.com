#include<cstdio> // AC


using namespace std;


typedef long long LL;


#define REP(i,n) for(LL i=0; i<n; ++i)


LL max(LL a, LL b)
{
	return (a>b) ? a : b ;
}


int main()
{
	LL n, a, temp = 0, wyn = 0;
	
	scanf( "%lld", &n );
	
	REP(i,n)
	{
		scanf( "%lld", &a );
		
		temp = max( 0, temp + a );
		
		wyn = max( wyn, temp );
	}
	
	printf( "%lld\n", wyn );
	
	return 0;
}
