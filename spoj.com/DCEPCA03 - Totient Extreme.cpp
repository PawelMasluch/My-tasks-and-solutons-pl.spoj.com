#include<cstdio> // AC
#include<vector>
 
 
using namespace std;
 
 
typedef long long LL;
 
typedef vector < LL > VLL;
 
 
#define REP(i,a,b,skok) for(LL i=a; i<=b; i+=skok)
 
#define PB push_back
 
 
const LL MAX_N = 1e4, ZAKRES = 1e2;
 
 
VLL v;
 
bool czy[MAX_N+1];
 
LL q, n, fi[MAX_N+1], r = 0;
 
 
void sieve()
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
 
 
void totient_function()
{
	REP(i,1,MAX_N,1)
	{
		fi[i] = i;
	}
	
	REP(i,0,r-1,1)
	{
		REP(j,v[i],MAX_N,v[i])
		{
			fi[j] /= v[i];
			
			fi[j] *= ( v[i] - 1 );
		}
	}
}
 
 
void compute_answers()
{
	REP(i,1,MAX_N,1)
	{
		fi[i] += fi[ i - 1 ];
	}
	
	REP(i,1,MAX_N,1)
	{
		fi[i] *= fi[i];
	}
}
 
 
void preprocessing()
{
	sieve();
	
	totient_function();
	
	compute_answers();
}
 
 
int main()
{
	preprocessing();
	
	scanf( "%lld", &q );
	
	while( q )
	{
		scanf( "%lld", &n );
		
		printf( "%lld\n", fi[n] );
		
		--q;
	}
	
	return 0;
} 
