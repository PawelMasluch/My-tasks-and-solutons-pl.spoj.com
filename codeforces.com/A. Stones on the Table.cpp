#include<iostream> // AC
#include<string>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int f(string &s, int n)
{
	int ile = 1;
	
	REP(i,1,n-1)
	{
		if( s[i] != s[ i - 1 ] )
		{
			++ile;
		}
	}
	
	return n - ile;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n;
	
	string s;
	
	cin >> n >> s;
	
	cout << f( s, n ) << endl;
	
	return 0;
}
