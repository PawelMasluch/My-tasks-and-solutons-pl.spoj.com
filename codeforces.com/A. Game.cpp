#include<iostream> // AC
 
 
using namespace std;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n1, n2, k1, k2;
	
	cin >> n1 >> n2 >> k1 >> k2;
	
	if( n1 > n2 )
	{
		cout << "First\n";
	}
	else
	{
		cout << "Second\n";
	}
	
	return 0;
}
