#include<iostream> // AC
#include<string>
#include<vector>
#include<algorithm>
 
 
using namespace std;
 
 
typedef vector < char > VC;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
#define PB push_back
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	VC v;
	
	int n, r = 0;
	
	string s;
	
	cin >> s;
	
	n = s.size();
	
	REP(i,0,n-1)
	{
		if( s[i] != '+' )
		{
			v.PB( s[i] );
			
			++r;
		}
	}
	
	sort( v.begin(), v.begin() + r );
	
	REP(i,0,r-2)
	{
		cout << v[i] << '+';
	}
	
	cout << v[ r - 1 ] << endl;
	
	return 0;
}
