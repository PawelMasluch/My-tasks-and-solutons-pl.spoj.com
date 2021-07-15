#include<iostream> // AC
#include<string>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
bool f(string &s)
{
	int n = s.size(), ile = 1;
	
	REP(i,1,n-1)
	{
		if( s[i] == s[ i - 1 ] )
		{
			++ile;
			
			if( ile == 7 )
			{
				return true;
			}
		}
		else
		{
			ile = 1;
		}
	}
	
	return false;
}
 
 
void g(string &s)
{
	if( f( s ) == true )
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
	
	string s;
	
	cin >> s;
	
	g( s );
	
	return 0;
}
