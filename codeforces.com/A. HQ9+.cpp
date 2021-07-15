#include<iostream> // AC
#include<string>
 
 
using namespace std;
 
 
#define REP(i,n) for(int i=0; i<n; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, pom, ile = 0;
	
	string s;
	
	cin >> s;
	
	n = s.size();
	
	REP(i,n)
	{
		pom = (int)( s[i] );
		
		if( pom == 72  ||  pom == 81  ||  pom == 57 )
		{
			++ile;
		}
	}
	
	if( ile > 0 )
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
	
	return 0;
}
