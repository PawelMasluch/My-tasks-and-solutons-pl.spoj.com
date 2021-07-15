#include<iostream> // AC
 
 
using namespace std;
 
 
int NWD(int a, int b)
{
	int temp;
	
	while( b )
	{
		temp = a % b;
		
		a = b;
		
		b = temp;
	}
	
	return a;
}
 
 
int f(int a, int b, int n)
{
	int pom;
	
	while( true )
	{
		pom = NWD( n, a );
		
		if( n < pom )
		{
			return 1;
		}
		else
		{
			n -= pom;
		}
		
		pom = NWD( n, b );
		
		if( n < pom )
		{
			return 0;
		}
		else
		{
			n -= pom;
		}
	}
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int a, b, n;
	
	cin >> a >> b >> n;
	
	cout << f( a, b, n ) << endl;
	
	return 0;
}
