#include<cstdio> // AC
#include<vector>
 
 
using namespace std;
 
 
typedef vector < int > VI;
 
 
#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)
 
#define PB push_back
 
 
const int MAX_N = 1e6, ZAKRES = 1e3;
 
 
VI v;
 
bool czy[MAX_N+1];
 
int q, n, fi[MAX_N+1], r = 0;
 
 
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
 
 
void compute_answers()
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
 
 
void preprocessing()
{
	sieve();
	
	compute_answers();
}
 
 
int main()
{
	preprocessing();
	
	scanf( "%d", &q );
	
	while( q )
	{
		scanf( "%d", &n );
		
		printf( "%d\n", fi[n] );
		
		--q;
	}
	
	return 0;
} 
