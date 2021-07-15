#include<iostream> // AC
#include<string>
 
 
using namespace std;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	string s;
	
	cin >> s;
	
	s = "0" + s;
	
	int r = s.size();
	
	int S = 10 * (int)( s[ r - 2 ] ) + (int)( s[ r - 1 ] );
	
	if( S % 4 == 0 )
	{
		cout << "4\n";
	}
	else
	{
		cout << "0\n";
	}
	
	return 0;
}
