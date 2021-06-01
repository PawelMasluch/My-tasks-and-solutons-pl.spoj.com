#include<cstdio> // 100 pkt


using namespace std;


int main()
{
	int p, q;
	
	scanf( "%d %d", &p, &q );
	
	printf( "%d\n", ( p + q - 1 ) / q );
	
	return 0;
}
