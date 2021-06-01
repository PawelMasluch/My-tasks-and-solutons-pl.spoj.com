#include<cstdio> // 100 pkt


using namespace std;


#define REP(i,a,b,skok) for(int i=a; i<=b; i+=skok)


const int MAX = 1000000;


int n, a, ile[MAX+1], wyn = 0;


int max(int a, int b)
{
	return ( a > b ) ? a : b ;
}


int main()
{
	scanf( "%d", &n );
	
	REP(i,0,n-1,1)
	{
		scanf( "%d", &a );
		
		++ile[a];
	}
	
	int tmp = 0;
	
	REP(d,2,MAX,1)
	{
		REP(m,d,MAX,d)
		{
			tmp += ile[m];
		}
		
		wyn = max( wyn, tmp );
		
		tmp = 0;
	}
	
	printf( "%d\n", n - wyn );
	
	return 0;
}
