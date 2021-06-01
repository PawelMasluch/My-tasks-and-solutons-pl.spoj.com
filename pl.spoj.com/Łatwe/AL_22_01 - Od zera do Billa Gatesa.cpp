#include<cstdio> // AC
#include<new>
#include<algorithm>


using namespace std;


typedef long long LL;


#define REP(i,a,b,skok) for(LL i=a; i<=b; i+=skok)

#define D delete


int main()
{
	LL q, *t, n, k, r, wyn = 0;
	
	scanf( "%lld", &q );
	
	REP(l,1,q,1)
	{
		scanf( "%lld%lld", &n, &k );
		
		r = n % k;
		
		t = new LL [n];
		
		REP(i,0,n-1,1)
		{
			scanf( "%lld", &t[i] );
		}
		
		sort( t, t + n );
		
		REP(i,r,n-1,k)
		{
			wyn += t[i];
		}
		
		D [] t;
		
		printf( "%lld\n", wyn );
		
		wyn = 0;
	}
	
	return 0;
}
