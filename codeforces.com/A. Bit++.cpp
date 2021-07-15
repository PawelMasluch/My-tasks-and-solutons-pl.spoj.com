#include<iostream> // AC
#include<string>
 
 
using namespace std;
 
 
#define REP(i,n) for(int i=0; i<n; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	string s;
	
	int n, wyn = 0;
	
	cin >> n;
	
	REP(i,n)
	{
		cin >> s;
		
		if( s == "X++"  ||  s == "++X" )
		{
			++wyn;
		}
		else // s == "X--"  ||  s == "--X"
		{
			--wyn;
		}
	}
	
	cout << wyn << endl;
	
	return 0;
}
