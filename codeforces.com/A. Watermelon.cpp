#include<iostream> // AC
 
 
using namespace std;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int w;
	
	cin >> w;
	
	if( w % 2 == 0  &&  w >= 4 )
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
	
	return 0;
}
