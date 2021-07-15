#include<iostream> // AC
#include<string>
 
 
using namespace std;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	string s;
	
	int n, r;
	
	cin >> n;
	
	while( n )
	{
		cin >> s;
		
		r = s.size();
		
		if( r >= 11 )
		{
			cout << s[0] << r - 2 << s[ r - 1 ] << endl;
		}
		else
		{
			cout << s << endl;
		}
		
		--n;
	}
	
	return 0;
}
