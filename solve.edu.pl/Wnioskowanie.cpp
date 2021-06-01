#include<cstdio> // 100 pkt
#include<algorithm>


using namespace std;


typedef long long LL;


#define REP(i,n) for(int i=0; i<n; ++i)


const LL MAX_L = 100000;


LL L, t[MAX_L];


int main()
{
	scanf( "%lld", &L );
	
	REP(i,L)
	{
		scanf( "%lld", &t[i] );
	}
	
	sort( t, t + L );
	
	printf( "%lld\n", t[0] * t[ L - 1 ] );
	
	return 0;
}
