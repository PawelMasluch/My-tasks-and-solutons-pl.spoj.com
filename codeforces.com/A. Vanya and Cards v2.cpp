#include<iostream> // AC
 
 
using namespace std;
 
 
#define REP(i,a,b) for(int i=a; i<=b; ++i)
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, x, S = 0, a;
	
	cin >> n >> x;
	
	REP(i,1,n)
	{
		cin >> a;
		
		S += a;
	}
	
	if( S < 0 )
	{
		S *= -1;
	}
	
	cout << ( S + x - 1 ) / x << endl;
	
	return 0;
}
