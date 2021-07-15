#include<iostream> // AC
#include<new>
 
 
using namespace std;
 
 
typedef long long LL;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	LL n;
	
	cin >> n;
	
	if( n % 2 == 0 )
	{
		cout << n / 2 << endl;
	}
	else
	{
		cout << ( ( n - 1 ) / 2 ) - n << endl;
	}
	
	return 0;
}
