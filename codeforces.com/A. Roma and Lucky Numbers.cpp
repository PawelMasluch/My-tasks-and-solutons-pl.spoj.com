#include<iostream> // AC
#include<string>
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	string s;
	
	int n, k, r, ile = 0, wyn = 0;
	
	cin >> n >> k;
	
	REP(i,1,n)
	{
		cin >> s;
		
		r = s.size();
		
		REP(i,0,r-1)
		{
			if( s[i] == '4'  ||  s[i] == '7' )
			{
				++ile;
			}
		}
		
		if( ile <= k )
		{
			++wyn;
		}
		
		ile = 0;
	}
	
	cout << wyn << endl;
	
	return 0;
}
