#include<iostream> // AC

 
using namespace std;
 
 
#define REP(i,n) for(int i=0; i<n; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, a, ile = 0, wyn = 0;
	
	cin >> n;
	
	REP(i,n)
	{
		REP(j,3)
		{
			cin >> a;
			
			ile += a;
		}
		
		if( ile >= 2 )
		{
			++wyn;
		}
		
		ile = 0;
	}
	
	cout << wyn << endl;
	
	return 0;
}
