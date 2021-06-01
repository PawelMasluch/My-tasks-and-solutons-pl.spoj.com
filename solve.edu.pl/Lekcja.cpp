#include<cstdio> // 100 pkt


using namespace std;


int main()
{
	char zn;
	
	int h, m, ile;
	
	scanf( "%d %c %d", &h, &zn, &m );
	
	ile = 60 * h + m + 45;
	
	h = ile / 60; 
	
	h %= 24; 
	
	m = ile % 60;
	
	if( h < 10 )
	{
		printf( "0" );
	}
	
	printf( "%d:", h );
	
	if( m < 10 )
	{
		printf( "0" );
	}
	
	printf( "%d\n", m );
	
	return 0;
}
