#include<iostream> // AC
 
 
using namespace std;
 
 
#define REP(i,n) for(int i=0; i<n; ++i)
 
 
int max(int a, int b)
{
	return (a>b) ? a : b ;
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, a, b, wyn = 0, temp = 0;
	
	cin >> n;
	
	REP(i,n)
	{
		cin >> a >> b;
		
		temp -= a;
		
		temp += b;
		
		wyn = max( wyn, temp );
	}
	
	cout << wyn << endl;
	
	return 0;
}
