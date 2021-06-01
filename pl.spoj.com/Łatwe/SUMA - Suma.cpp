#include<cstdio> // AC


using namespace std;


int main()
{
	int a, S = 0;
	
	while( scanf( "%d", &a ) != EOF )
	{
		S += a;
		
		printf( "%d\n", S );
	}
	
	return 0;
}
