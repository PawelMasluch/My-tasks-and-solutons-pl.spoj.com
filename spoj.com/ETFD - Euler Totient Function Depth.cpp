#include<cstdio> // AC
#include<vector> // sprawdziA?em, A1e maksymalna gA?Ä?bokoA?Ä? (dla liczb do miliona) wynosi 20
 
 
using namespace std;
 
 
typedef vector < int > VI;
 
 
#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)
 
#define PB push_back
 
 
const int MAX_N = 1e6, ZAKRES = 1e3, MAX_K = 20;
 
 
VI v, pom[MAX_K+1];
 
bool czy[MAX_N+1];
 
int q, m, n, k, fi[MAX_N+1], d[MAX_N+1], r = 0, rpom[MAX_K+1], i1, i2, pocz, kon, wyn, sr;
 
 
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
 
 
void depth_function()
{
	d[1] = 0;
	
	pom[0].PB( 1 );
		
	++rpom[0];
	
	REP(i,2,MAX_N,1)
	{
		d[i] = 1 + d[ fi[i] ];
		
		pom[ d[i] ].PB( i );
		
		++rpom[ d[i] ];
	}
}
 
 
void preprocessing()
{
	sieve();
	
	totient_function();
	
	depth_function();
}
 
 
int bin1()
{
	pocz = 0;  kon = rpom[k] - 1;  wyn = -1;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( pom[k][sr] >= m )
		{
			wyn = sr;
			
			kon = sr - 1;
		}
		else
		{
			pocz = sr + 1;
		}
	}
	
	return wyn;
}
 
 
int bin2()
{
	pocz = 0;  kon = rpom[k] - 1;  wyn = -1;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( pom[k][sr] <= n )
		{
			wyn = sr;
			
			pocz = sr + 1;
		}
		else
		{
			kon = sr - 1;
		}
	}
	
	return wyn;
}
 
 
int query()
{
	i1 = bin1();
	
	i2 = bin2();
	
	return ( i1 == -1  ||  i2 == -1  ||  i1 > i2 ) ? 0 : i2 - i1 + 1 ;
}
 
 
int main()
{
	preprocessing();
	
	scanf( "%d", &q );
	
	while( q )
	{
		scanf( "%d %d %d", &m, &n, &k );
		
		printf( "%d\n", query() );
		
		--q;
	}
	
	return 0;
} 
