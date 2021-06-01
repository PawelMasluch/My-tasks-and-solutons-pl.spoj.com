#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b) for(int i=a; i<=b; ++i)


const int MAX_SIZE = 1000000;


int n, k, ile[MAX_SIZE+1], a, wyn = 0;


int max(int a, int b)
{
	return (a>b) ? a : b ;
}


int main()
{
	scanf( "%d %d", &n, &k );
	
	while( n )
	{
		scanf( "%d", &a );
		
		++ile[a];
		
		--n;
	}
	
	REP(i,1,MAX_SIZE)
	{
		ile[i] += ile[ i - 1 ];
	}
	
	REP(i,1,MAX_SIZE)
	{
		wyn = max( wyn, ile[i] - ile[ max( 0, i - k - 1 ) ] );
	}
	
	printf( "%d\n", wyn );
	
	return 0;
}
