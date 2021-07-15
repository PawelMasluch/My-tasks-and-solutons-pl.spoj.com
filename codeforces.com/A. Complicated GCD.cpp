#include<iostream> // AC
#include<string>
 
 
using namespace std;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	string a, b;
	
	cin >> a >> b;
	
	if( a == b )
	{
		cout << a << endl;
	}
	else
	{
		cout << "1\n";
	}
	
	return 0;
}
