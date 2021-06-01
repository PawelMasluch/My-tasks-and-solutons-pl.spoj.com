#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MX = 500000 + 30;


int n, t[MX+1], ile1 = 0;


void f(int x)
{
	++t[x];
	
	if( t[x] == 1 )
	{
		++ile1;
	}
	
	while( t[x] > 1 )
	{
		t[x] = 0;
		
		--ile1;
		
		++t[ x + 1 ];
		
		if( t[ x + 1 ] == 1 )
		{
			++ile1;	
		}
		
		++x;
	}
	
	printf( "%d\n", ile1 );
}


void solve()
{
	scanf( "%d", &n );
	
	int x;
	
	while( n )
	{
		scanf( "%d", &x );
		
		f( x );
		
		--n;
	}
}


int main()
{
	solve();
	
	return 0;
}
