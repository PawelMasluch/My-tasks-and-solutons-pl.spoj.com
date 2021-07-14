#include<cstdio> // AC
 
 
using namespace std;
 
 
typedef long long LL;
 
 
#define REP(i,a,b,skok) for(LL i=a; i<=b; i+=skok)
 
 
const LL MAX_N = 1e7, ZAKRES = 32e3;
 
 
LL a[MAX_N+1], q, n;
 
 
void preprocessing()
{
	REP(i,2,MAX_N,1)
	{
		a[i] = i;
	}
	
	REP(i,2,ZAKRES,1)
	{
		if( a[i] == i )
		{
			REP(j,i*i,MAX_N,i)
			{
				if( a[j] == j )
				{
					a[j] = i;
				}
			}
		}
	}
	
	REP(i,2,MAX_N,1)
	{
		a[i] += a[ i - 1 ];
	}
}
 
 
int main()
{
	preprocessing();
	
	scanf( "%lld", &q );
	
	while( q )
	{
		scanf( "%lld", &n );
		
		printf( "%lld\n", a[n] );
		
		--q;
	}
	
	return 0;
} 
