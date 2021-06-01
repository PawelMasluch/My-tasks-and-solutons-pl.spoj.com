#include<cstdio> // 100 pkt


using namespace std;


int main()
{
	int n;
	
	scanf( "%d", &n );
	
	if( n % 3 == 0 )
	{
		printf( "NIE\n" );
	}
	else
	{
		printf( "TAK\n" );
	}
	
	return 0;
}
