#include<cstdio> // AC
#include<vector>
 
 
using namespace std;
 
 
typedef long long LL;
 
typedef vector < LL > VLL;
 
 
#define REP(i,a,b,skok) for(LL i=a; i<=b; i+=skok)
 
#define PB push_back
 
 
const LL MAX_N = 5e4, ZAKRES = 230, p = 1e9 + 7;
 
 
VLL v;
 
bool czy[MAX_N+1];
 
LL r = 0, n, q;
 
 
void sito()
{
	REP(i,2,MAX_N,1)
	{
		czy[i] = true;
	}
	
	REP(i,2,ZAKRES,1)
	{
		if( czy[i] )
		{
			REP(j,i*i,MAX_N,i)
			{
				czy[j] = false;
			}
		}
	}
	
	REP(i,2,MAX_N,1)
	{
		if( czy[i] )
		{
			v.PB( i );
			
			++r;
		}
	}
}
 
 
LL fun(LL x)
{
	LL wyn = 0, tmp = x;
	
	while( tmp <= n )
	{
		wyn += ( n / tmp );
		
		tmp *= x;
 	}
 	
 	return wyn;
}
 
 
LL f()
{
	LL wyn = 1;
	
	REP(i,0,r-1,1)
	{
		wyn = ( wyn * ( fun( v[i] ) + 1 ) ) % p;
	}
	
	return wyn;
}
 
 
int main()
{
	sito();
	
	scanf( "%lld", &q );
	
	while( q )
	{
		scanf( "%lld", &n );
		
		printf( "%lld\n", f() );
		
		--q;
	}
	
	return 0;
} 
