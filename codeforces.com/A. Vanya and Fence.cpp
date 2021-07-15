#include<iostream> // AC
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, h, a, wyn = 0;
	
	cin >> n >> h;
	
	REP(i,1,n)
	{
		cin >> a;
		
		if( a > h )
		{
			wyn += 2;
		}
		else
		{
			++wyn;
		}
	}
	
	cout << wyn << endl;
	
	return 0;
}
