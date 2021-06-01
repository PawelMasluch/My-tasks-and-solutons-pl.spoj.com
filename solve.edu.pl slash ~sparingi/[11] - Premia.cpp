#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_N = 500000, MX = 2500;


int n, t[MAX_N], S = 0, dzielnik[MX], r = 0;


bool DaSie(int x)
{
	int tmp = 0, i = 0;
	
	while( i <= n - 1 )
	{
		tmp += t[i];
		
		if( tmp > x )
		{
			return false;
		}
		
		if( tmp == x )
		{
			tmp = 0;
		}
		
		++i;
	}
	
	if( tmp == 0 )
	{
		return true;
	}
	
	return false;
}


int main()
{
	scanf( "%d", &n );
	
	REP(i,0,n-1)
	{
		scanf( "%d", &t[i] );
		
		S += t[i];
	}
	
	REP(i,1,S)
	{
		if( S % i == 0 )
		{
			dzielnik[ r ] = i;
			
			++r;
		}
	}
	
	REP(i,0,r-1)
	{
		if( DaSie( dzielnik[i] ) )
		{
			printf( "%d ", dzielnik[i] );
		}
	}
	
	printf( "\n" );
	
	return 0;
}
