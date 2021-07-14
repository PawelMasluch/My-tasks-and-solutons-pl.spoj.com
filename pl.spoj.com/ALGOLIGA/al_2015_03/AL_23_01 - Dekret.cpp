#include<cstdio> // 100 pkt
#include<new>
#include<vector>
 
 
using namespace std;
 
 
typedef long long LL;
 
typedef pair < LL, LL > pLL;
 
typedef vector < pLL > VpLL;
 
 
#define REP(i,a,b) for(LL i=a; i<=b; ++i)
 
#define PB push_back
 
#define MP make_pair
 
#define ST first
 
#define ND second
 
 
const LL MAX_TIME = 1000030;
 
 
LL max(LL a, LL b)
{
	return (a>b) ? a : b ;
}
 
 
int main()
{	
	VpLL v;
	
	LL k, *ile = new LL [MAX_TIME+1], a, r = 0, pocz = -1, num;
	
	REP(i,0,MAX_TIME)
	{
		ile[i] = 0;
	}
	
	scanf( "%lld", &k );
	
	while( scanf( "%lld", &a ) != EOF )
	{
		++ile[a];
	}
	
	REP(i,1,MAX_TIME)
	{
		ile[i] += ile[ i - 1 ];
	}
	
	REP(i,1,MAX_TIME)
	{
		num = ile[i] - ile[ max( 0, i - 30 ) ];
		
		if( num > k )
		{
			if( pocz == -1 )
			{
				pocz = i;
			}
		}
		else
		{
			if( pocz != -1 )
			{
				v.PB( MP( pocz, i ) );
				
				++r;
				
				pocz = -1;
			}
		}
	}
	
	REP(i,0,r-1)
	{
		printf( "[%lld - %lld)\n", v[i].ST, v[i].ND );
	}
	
	return 0;
} 
