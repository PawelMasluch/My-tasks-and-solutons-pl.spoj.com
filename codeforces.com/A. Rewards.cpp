#include<iostream> // AC
 
 
using namespace std;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int a1, a2, a3, b1, b2, b3, n, ile;
	
	cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;
	
	ile = ( ( a1 + a2 + a3 + 4 ) / 5 ) + ( ( b1 + b2 + b3 + 9 ) / 10 );
	
	if( ile > n )
	{
		cout << "NO\n";
	}
	else
	{
		cout << "YES\n";
	}
	
	return 0;
}
