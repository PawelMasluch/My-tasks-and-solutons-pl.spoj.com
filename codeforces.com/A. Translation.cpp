#include<iostream> // AC
#include<string>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	bool czy = true;
	
	int n;
	
	string a, b;
	
	cin >> a >> b;
	
	n = a.size();
	
	REP(i,0,n-1)
	{
		if( a[ i ] != b[ n - 1 - i ] )
		{
			czy = false;	
		}
	}
	
	if( czy == true )
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
	
	return 0;
}
