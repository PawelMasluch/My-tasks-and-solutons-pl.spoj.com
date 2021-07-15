#include<iostream> // AC
#include<string>
 
 
using namespace std;
 
 
bool f(string &a, string &b)
{
	int r1 = a.size(), r2 = b.size(), i = 0, j = 0;
	
	while( i <= r1 - 1  &&  j <= r2 - 1 )
	{
		if( a[i] == b[j] )
		{
			++j;
		}
		
		++i;
	}
	
	if( j == r2 )
	{
		return true;
	}
	
	return false;
}
 
 
void g(string &a, string &b)
{
	if( f( a, b ) == true )
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	string a, b = "hello";
	
	cin >> a;
	
	g( a, b );
	
	return 0;
}
