#include<iostream> // AC
 
 
using namespace std;
 
 
typedef long long LL;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	LL n, k;
	
	cin >> n >> k;
	
	if( k <= ( n + 1 ) / 2 )
	{
		cout << 2 * k - 1 << endl;
	}
	else
	{
		cout << ( k - ( ( n + 1 ) / 2 ) ) * 2 << endl;
	}
	
	return 0;
}
