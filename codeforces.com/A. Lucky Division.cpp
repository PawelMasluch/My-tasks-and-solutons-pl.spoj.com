#include<iostream> // AC
 
 
using namespace std;
 
 
#define REP(i,n) for(int i=0; i<n; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int t[14] = { 4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777 }, n;
	
	cin >> n;
	
	REP(i,14)
	{
		if( n % t[i] == 0 )
		{
			cout << "YES\n";
			
			return 0;
		}
	}
	
	cout << "NO\n";
	
	return 0;
}
