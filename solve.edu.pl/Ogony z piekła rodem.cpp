#include<cstdio> // 100 pkt


using namespace std;


int main()
{
	int a, b, c;
	
	scanf( "%d %d %d", &a, &b, &c );
	
	int B = ( a + c - b ) / 2, R = ( b + c - a ) / 2, L = ( a + b - c ) / 2;
	
	printf( "%d %d %d", B, R, L );
	
	return 0;
}
