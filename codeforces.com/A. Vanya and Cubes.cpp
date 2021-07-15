#include<iostream> // AC
 
 
using namespace std;
 
 
typedef long long LL;
 
 
LL f(LL n)
{
	return ( ( n * ( n + 1 ) / 2 ) + ( n * ( n + 1 ) * ( 2 * n + 1 ) / 6 ) ) / 2;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, pocz = 1, kon, wyn, sr;
	
	cin >> n;
	
	kon = n;
	
	while( pocz <= kon )
	{
		sr = ( pocz + kon ) / 2;
		
		if( f( sr ) <= n )
		{
			wyn = sr;
			
			pocz = sr + 1;
		}
		else
		{
			kon = sr - 1;
		}
	}
	
	cout << wyn << endl;
	
	return 0;
}
